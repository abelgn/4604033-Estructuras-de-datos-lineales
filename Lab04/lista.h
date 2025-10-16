#include <string>

#include "nodo.h"

class Lista {
public:
    Lista();
    ~Lista();
    virtual bool insertar(int x, int p);
    virtual bool eliminar(int p);
    virtual int buscar(int x) const;
    virtual int obtener(int p) const;
    virtual void hacerVacia();
    virtual bool esVacia() const;
    int getNumElementos() const;
    
private:
    friend std::ostream& operator<<(std::ostream&, const Lista&);
    Nodo *sentinela;
    Nodo *ultimo;
    Nodo *encontrarNodo(int p) const;
    void insertarVacia(int x);
    bool insertar(int x, Nodo *p);
    bool eliminar(Nodo *p);
    int numElementos;
};


Lista::Lista()
    :   sentinela(new Nodo(0,NULL)),
        ultimo(NULL),
        numElementos(0) {
}


/*
 Libera la memoria ocupada por todos los nodos de la lista.
 */
Lista::~Lista() {
    // implementar
}


void Lista::insertarVacia(int x) {
    Nodo *nuevo = new Nodo(x, NULL);
    sentinela->setSiguiente(nuevo);
    ultimo = nuevo;
}


bool Lista::insertar(int x, Nodo *p) {
    bool exito = true;
    if (numElementos == 0)
        insertarVacia(x);
    else {
        p->setSiguiente(new Nodo(x, p->getSiguiente()));
    }
    numElementos += 1;
    return exito;
}


Nodo *Lista::encontrarNodo(int p) const {
    Nodo *q = sentinela;
    int i = 0;
    while (i < p) {
        q = q->getSiguiente();
        i++;
    }
    return q;
}


bool Lista::insertar(int x, int p) {
    Nodo *q = encontrarNodo(p);
    return insertar(x, q);
}


bool Lista::eliminar(Nodo *p) {
    // implementar
    return true;
}


bool Lista::eliminar(int p) {
    Nodo *q = encontrarNodo(p);
    return eliminar(q);
}


int Lista::buscar(int x) const {
    // implementar
    return numElementos;
}


int Lista::obtener(int p) const {
    if (p >= numElementos)
        return std::numeric_limits<int>::max();
    Nodo *q = encontrarNodo(p);
    return q->getSiguiente()->getElemento();
}


/*
 Liberar la memoria ocupada por todos los nodos de la lista.
 */
void Lista::hacerVacia() {
    // implementar
}


bool Lista::esVacia() const {
    return (numElementos == 0);
}


int Lista::getNumElementos() const {
    return numElementos;
}


std::ostream& operator<<(std::ostream &strm, const Lista &lista) {
    std::string elem = "";
    Nodo *pos = lista.sentinela;
    int i = 0;
    if (!lista.esVacia()) {
        while (i < lista.getNumElementos()) {
            elem += std::to_string(pos->getSiguiente()->getElemento()) + ", ";
            i++;
            pos = pos->getSiguiente();
        }
        elem += "\b\b";
    }
    return strm << "(" << elem << ")";
}
