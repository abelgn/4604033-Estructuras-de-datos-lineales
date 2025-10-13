#include <string>

#include "nodo.h"

class Lista {
public:
    Lista();
    ~Lista();
    Nodo *fin() const;
    bool insertar(int x, Nodo *p);
    bool eliminar(Nodo *p);
    Nodo *buscar(int x) const;
    int obtener(Nodo *p) const;
    Nodo *primera() const;
    Nodo *siguiente(Nodo *p) const;
    Nodo *anterior(Nodo *p) const;
    void hacerVacia();
    bool esVacia() const;
    int getNumElementos() const;
    
private:
    Nodo *cabeza;
    Nodo *cola;
    void insertarInicio(int x);
    void insertarFinal(int x);
    void insertarVacia(int x);
    void eliminarInicio();
    int numElementos;
    friend std::ostream& operator<<(std::ostream &strm, const Lista &lista);
};


Lista::Lista() {
    cabeza = NULL;
    cola = NULL;
    numElementos = 0;
}


Lista::~Lista() {
    hacerVacia();
}

Nodo *Lista::fin() const {
    return cola;
}


void Lista::insertarVacia(int x) {
    cabeza = new Nodo(x, NULL);
    cola = cabeza;
}


void Lista::insertarInicio(int x) {
    cabeza = new Nodo(x, cabeza);
}


void Lista::insertarFinal(int x) {
    cola->setSiguiente(new Nodo(x, NULL));
    cola = cola->getSiguiente();
}


bool Lista::insertar(int x, Nodo *p) {
    bool exito = true;
    numElementos += 1;
    if (p == NULL)
        if (esVacia())
            insertarVacia(x);
        else
            insertarFinal(x);
    else if (p == cabeza)
            insertarInicio(x);
    else {
        Nodo *q = cabeza;
        while (q->getSiguiente() != p
               && q->getSiguiente() != NULL)
            q = q->getSiguiente();
        if (q->getSiguiente() != NULL)
            q->setSiguiente(new Nodo(x, p));
        else {
            exito = false;
            numElementos -= 1;
        }
    }
    return exito;
}


void Lista::eliminarInicio() {
    Nodo *p = cabeza;
    cabeza = p->getSiguiente();
    delete p;
}


bool Lista::eliminar(Nodo *p) {
    bool exito = true;
    numElementos -= 1;
    if (p == NULL)
        exito = false;
    else if (p == cabeza)
        eliminarInicio();
    else {
        Nodo *q = cabeza;
        while (q->getSiguiente() != p
               && q->getSiguiente() != NULL)
            q = q->getSiguiente();
        if (q->getSiguiente() != NULL) {
            if (p == cola)
                cola = q;
            q->setSiguiente(p->getSiguiente());
            delete p;
        } else {
            exito = false;
            numElementos += 1;
        }
    }
    return exito;
}


Nodo *Lista::buscar(int x) const {
    Nodo *p = cabeza;
    while (p->getElemento() != x
           && p->getSiguiente() != NULL)
        p = p->getSiguiente();
    if (p->getElemento() != x)
        p = NULL;
    return p;
}


int Lista::obtener(Nodo *p) const {
    return p->getElemento();
}


Nodo *Lista::primera() const {
    return cabeza;
}


Nodo *Lista::siguiente(Nodo *p) const {
    Nodo *q = NULL;
    if (p != NULL)
        q = p->getSiguiente();
    return q;
}


Nodo *Lista::anterior(Nodo *p) const {
    Nodo *q = NULL;
    if (p != NULL && p != cabeza) {
        q = cabeza;
        while (q->getSiguiente() != p
               && q->getSiguiente() != NULL)
            q = q->getSiguiente();
        if (q->getSiguiente() == NULL)
            q = NULL;
    }
    return q;
}


void Lista::hacerVacia() {
    while (!esVacia())
        eliminarInicio();
}


bool Lista::esVacia() const {
    return (cabeza == NULL);
}


int Lista::getNumElementos() const {
    return numElementos;
}


std::ostream& operator<<(std::ostream &strm, const Lista &lista) {
    std::string elem = "";
    Nodo *pos = lista.primera();
    while (pos != NULL) {
        elem += std::to_string(lista.obtener(pos)) + ", ";
        pos = lista.siguiente(pos);
    }
    elem += "\b\b";
    return strm << "(" << elem << ")";
}
