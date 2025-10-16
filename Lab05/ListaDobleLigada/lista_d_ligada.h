#include <string>

#include "nodo_d.h"

class ListaDLigada {
public:
    ListaDLigada();
    ~ListaDLigada();
    bool insertar(std::string x, int p);
    bool eliminar(int p);
    int buscar(std::string x) const;
    std::string obtener(int p) const;
    void hacerVacia();
    bool esVacia() const;
    int getNumElementos() const;
    
private:
    NodoD *encontrarNodo(int p) const;
    bool insertar(std::string x, NodoD *p);
    bool eliminar(NodoD *p);
    NodoD *cabeza;
    NodoD *cola;
    int numElementos;
    friend std::ostream& operator<<(std::ostream &, const ListaDLigada &);
};


ListaDLigada::ListaDLigada() :
    cabeza(new NodoD()),
    cola(new NodoD()),
    numElementos(0) {
    cabeza->siguiente = cola;
    cola->anterior = cabeza;
}


/*
 Libera la memoria ocupada por todos los nodos de la lista.
 */
ListaDLigada::~ListaDLigada() {
    hacerVacia();
    delete cabeza;
    delete cola;
}


NodoD *ListaDLigada::encontrarNodo(int p) const {
    NodoD *q = cabeza;
    int i = 0;
    while (i < p) {
        q = q->siguiente;
        i++;
    }
    return q;
}


bool ListaDLigada::insertar(std::string x, NodoD *p) {
    NodoD *nuevo = new NodoD();
    nuevo->elemento = x;
    nuevo->siguiente = p->siguiente;
    nuevo->anterior = p;
    p->siguiente = nuevo;
    nuevo->siguiente->anterior = nuevo;
    return true;
}


bool ListaDLigada::insertar(std::string x, int p) {
    NodoD *q = encontrarNodo(p);
    numElementos++;
    return insertar(x, q);
}



bool ListaDLigada::eliminar(NodoD *p) {
    p->siguiente = p->siguiente->siguiente;
    delete p->siguiente->anterior;
    p->siguiente->anterior = p;
    return true;
}


bool ListaDLigada::eliminar(int p) {
    if (p >= 0 && p < numElementos) {
        NodoD *q = encontrarNodo(p);
        numElementos--;
        return eliminar(q);
    }
    return false;
}


int ListaDLigada::buscar(std::string x) const {
    int i = 0;
    NodoD *p = cabeza->siguiente;
    while (p != cola && p->elemento != x) {
        p = p->siguiente;
        i++;
    }
    return i;
}


std::string ListaDLigada::obtener(int p) const {
    if (p >= 0 && p < numElementos) {
        NodoD *q = encontrarNodo(p);
        return q->siguiente->elemento;
    }
    return NULL;
}


void ListaDLigada::hacerVacia() {
    while (!esVacia()) {
        cabeza = cabeza->siguiente;
        delete cabeza->anterior;
    }
    cabeza->anterior = NULL;
    numElementos = 0;
}


bool ListaDLigada::esVacia() const {
    return (cabeza->siguiente == cola);
}


int ListaDLigada::getNumElementos() const {
    return numElementos;
}


std::ostream& operator<<(std::ostream &strm, const ListaDLigada &lista) {
    std::string elem = "";
    if (!lista.esVacia()) {
        NodoD *pos = lista.cabeza->getSiguiente();
        while (pos != lista.cola) {
            elem += pos->getElemento() + ", ";
            pos = pos->getSiguiente();
        }
        elem += "\b\b";
    }
    return strm << "(" << elem << ")";
}
