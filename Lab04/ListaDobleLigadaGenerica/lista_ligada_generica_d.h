#include <string>

#include "nodo_generico_d.h"

template <typename T>
class ListaLigadaD {
public:
    ListaLigadaD();
    ~ListaLigadaD();
    NodoD<T> *fin() const;
    bool insertar(T x, NodoD<T> *p);
    bool eliminar(NodoD<T> *p);
    NodoD<T> *buscar(T x) const;
    T obtener(NodoD<T> *p) const;
    NodoD<T> *primera() const;
    NodoD<T> *siguiente(NodoD<T> *p) const;
    NodoD<T> *anterior(NodoD<T> *p) const;
    void hacerVacia();
    bool esVacia() const;
    int getNumTlementos() const;
    
private:
    NodoD<T> *cabeza;
    NodoD<T> *cola;
    int numTlementos;
    friend std::ostream& operator<<(std::ostream &, const ListaLigadaD<T> &);
};


template <typename T>
ListaLigadaD<T>::ListaLigadaD() {
    cabeza = new NodoD<T>();
    cola = new NodoD<T>();
    cabeza->siguiente = cola;
    cola->previo = cabeza;
    numTlementos = 0;
}


/*
 Libera la memoria ocupada por todos los nodos de la lista.
 */
template <typename T>
ListaLigadaD<T>::~ListaLigadaD() {
    hacerVacia();
    delete cabeza;
    delete cola;
}


template <typename T>
NodoD<T> *ListaLigadaD<T>::fin() const {
    return cola;
}


template <typename T>
bool ListaLigadaD<T>::insertar(T x, NodoD<T> *p) {
    // implementar
    return true;
}


template <typename T>
bool ListaLigadaD<T>::eliminar(NodoD<T> *p) {
    // implementar
    return true;
}


template <typename T>
NodoD<T> *ListaLigadaD<T>::buscar(T x) const {
    // implementar
    return p;
}


template <typename T>
T ListaLigadaD<T>::obtener(NodoD<T> *p) const {
    return p->elem;
}


template <typename T>
NodoD<T> *ListaLigadaD<T>::primera() const {
    return cabeza->siguiente;
}


template <typename T>
NodoD<T> *ListaLigadaD<T>::siguiente(NodoD<T> *p) const {
    return p->siguiente;
}


template <typename T>
NodoD<T> *ListaLigadaD<T>::anterior(NodoD<T> *p) const {
    return p->previo;
}


template <typename T>
void ListaLigadaD<T>::hacerVacia() {
    // implementar
}


template <typename T>
bool ListaLigadaD<T>::esVacia() const {
    // implementar
}


template <typename T>
int ListaLigadaD<T>::getNumTlementos() const {
    return numTlementos;
}



template <typename T>
std::ostream& operator<<(std::ostream &strm, const ListaLigadaD<T> &lista) {
    std::string elem = "";
    NodoD<T> *pos = lista.primera();
    while (pos != lista.fin()) {
        elem += lista.obtener(pos) + ", ";
        pos = lista.siguiente(pos);
    }
    elem += "\b\b";
    return strm << "(" << elem << ")";
}

