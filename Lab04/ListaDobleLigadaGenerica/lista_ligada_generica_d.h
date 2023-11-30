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
    template <typename U>
    friend std::ostream& operator<<(std::ostream &, const ListaLigadaD<U> &);
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
    NodoD<T> *nuevo = new NodoD<T>();
    nuevo->elem = x;
    nuevo->siguiente = p;
    nuevo->previo = p->previo;
    p->previo->siguiente = nuevo;
    p->previo = nuevo;
    return true;
}


template <typename T>
bool ListaLigadaD<T>::eliminar(NodoD<T> *p) {
    p->previo->siguiente = p->siguiente;
    p->siguiente->previo = p->previo;
    delete p;
    return true;
}


template <typename T>
NodoD<T> *ListaLigadaD<T>::buscar(T x) const {
    NodoD<T> *p = cabeza->siguiente;
    while (p->elem != x
           && p->siguiente != cola)
        p = p->siguiente;
    if (p->elem != x)
        p = NULL;
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
    while (!esVacia()) {
        cabeza = cabeza->siguiente;
        delete cabeza->previo;
        cabeza->previo = NULL;
    }
}


template <typename T>
bool ListaLigadaD<T>::esVacia() const {
    return (cabeza->siguiente == cola);
}


template <typename T>
int ListaLigadaD<T>::getNumTlementos() const {
    return numTlementos;
}


template <typename T>
std::ostream& operator<<(std::ostream &strm, const ListaLigadaD<T> &lista) {
    std::string elem = "";
    NodoD<T> *pos = lista.primera();
    if (std::string(typeid(T).name()).compare("c") != 0) {
        while (pos != lista.fin()) {
            elem += std::to_string(lista.obtener(pos)) + ", ";
            pos = lista.siguiente(pos);
        }
    }
    else {
        while (pos != lista.fin()) {
            elem += (char) lista.obtener(pos);
            elem += ", ";
            pos = lista.siguiente(pos);
        }
    }
    elem += "\b\b";
    return strm << "(" << elem << ")";
}
