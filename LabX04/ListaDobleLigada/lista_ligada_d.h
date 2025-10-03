#include <string>

#include "nodo_d.h"

class ListaLigadaD {
public:
    ListaLigadaD();
    ~ListaLigadaD();
    NodoD *fin() const;
    bool insertar(std::string x, NodoD *p);
    bool eliminar(NodoD *p);
    NodoD *buscar(std::string x) const;
    std::string obtener(NodoD *p) const;
    NodoD *primera() const;
    NodoD *siguiente(NodoD *p) const;
    NodoD *anterior(NodoD *p) const;
    void hacerVacia();
    bool esVacia() const;
    int getNumElementos() const;
    
private:
    NodoD *cabeza;
    NodoD *cola;
    int numElementos;
    friend std::ostream& operator<<(std::ostream &, const ListaLigadaD &);
};


ListaLigadaD::ListaLigadaD() {
    cabeza = new NodoD();
    cola = new NodoD();
    cabeza->siguiente = cola;
    cola->previo = cabeza;
    numElementos = 0;
}


/*
 Libera la memoria ocupada por todos los nodos de la lista.
 */
ListaLigadaD::~ListaLigadaD() {
    hacerVacia();
    delete cabeza;
    delete cola;
}


NodoD *ListaLigadaD::fin() const {
    return cola;
}


bool ListaLigadaD::insertar(std::string x, NodoD *p) {
    NodoD *nuevo = new NodoD();
    nuevo->elem = x;
    nuevo->siguiente = p;
    nuevo->previo = p->previo;
    p->previo->siguiente = nuevo;
    p->previo = nuevo;
    return true;
}


bool ListaLigadaD::eliminar(NodoD *p) {
    p->previo->siguiente = p->siguiente;
    p->siguiente->previo = p->previo;
    delete p;
    return true;
}


NodoD *ListaLigadaD::buscar(std::string x) const {
    NodoD *p = cabeza->siguiente;
    while (p->elem != x
           && p->siguiente != cola)
        p = p->siguiente;
    if (p->elem != x)
        p = NULL;
    return p;
}


std::string ListaLigadaD::obtener(NodoD *p) const {
    return p->elem;
}


NodoD *ListaLigadaD::primera() const {
    return cabeza->siguiente;
}


NodoD *ListaLigadaD::siguiente(NodoD *p) const {
    return p->siguiente;
}


NodoD *ListaLigadaD::anterior(NodoD *p) const {
    return p->previo;
}


void ListaLigadaD::hacerVacia() {
    while (!esVacia()) {
        cabeza = cabeza->siguiente;
        delete cabeza->previo;
    }
    cabeza->previo = NULL;
}


bool ListaLigadaD::esVacia() const {
    return (cabeza->siguiente == cola);
}


int ListaLigadaD::getNumElementos() const {
    return numElementos;
}


std::ostream& operator<<(std::ostream &strm, const ListaLigadaD &lista) {
    std::string elem = "";
    NodoD *pos = lista.primera();
    while (pos != lista.fin()) {
        elem += lista.obtener(pos) + ", ";
        pos = lista.siguiente(pos);
    }
    elem += "\b\b";
    return strm << "(" << elem << ")";
}
