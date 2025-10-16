#ifndef LISTA_D_LIGADA_GENERICA_H
#define LISTA_D_LIGADA_GENERICA_H

#include <iostream>
#include <string>
#include "nodo_d_generico.h"

template <typename T>
class ListaDLigadaG {
public:
    ListaDLigadaG();
    ~ListaDLigadaG();
    bool insertar(T x, int p);
    bool eliminar(int p);
    int buscar(T x) const;
    T obtener(int p) const;
    void hacerVacia();
    bool esVacia() const;
    int getNumElementos() const;
    
private:
    NodoDG<T> *encontrarNodo(int p) const;
    bool insertar(T x, NodoDG<T> *p);
    bool eliminar(NodoDG<T> *p);
    NodoDG<T> *cabeza;
    NodoDG<T> *cola;
    int numElementos;
    template <typename U>
    friend std::ostream& operator<<(std::ostream &, const ListaDLigadaG<U> &);
};


template <typename T>
ListaDLigadaG<T>::ListaDLigadaG() {
    cabeza = new NodoDG<T>();
    cola = new NodoDG<T>();
    cabeza->siguiente = cola;
    cola->anterior = cabeza;
    numElementos = 0;
}


/*
 Libera la memoria ocupada por todos los nodos de la lista.
 */
template <typename T>
ListaDLigadaG<T>::~ListaDLigadaG() {
    hacerVacia();
    delete cabeza;
    delete cola;
}


template <typename T>
NodoDG<T> *ListaDLigadaG<T>::encontrarNodo(int p) const {
    NodoDG<T> *q = cabeza->siguiente;
    int i = 0;
    while (i < p) {
        q = q->siguiente;
        i++;
    }
    return q;
}


template <typename T>
bool ListaDLigadaG<T>::insertar(T x, NodoDG<T> *p) {
    // implementar
    return true;
}


template <typename T>
bool ListaDLigadaG<T>::insertar(T x, int p) {
    NodoDG<T> *q = encontrarNodo(p);
    numElementos++;
    return insertar(x, q);
}


template <typename T>
bool ListaDLigadaG<T>::eliminar(NodoDG<T> *p) {
    // implementar
    return true;
}


template <typename T>
bool ListaDLigadaG<T>::eliminar(int p) {
    if (p >= 0 && p < numElementos) {
        NodoDG<T> *q = encontrarNodo(p);
        numElementos--;
        return eliminar(q);
    }
    return false;
}


template <typename T>
int ListaDLigadaG<T>::buscar(T x) const {
    // implementar
    return NULL;
}


template <typename T>
T ListaDLigadaG<T>::obtener(int p) const {
    // implementar
    return NULL;
}


template <typename T>
void ListaDLigadaG<T>::hacerVacia() {
    // implementar
}


template <typename T>
bool ListaDLigadaG<T>::esVacia() const {
    return (cabeza->siguiente == cola);
}


template <typename T>
int ListaDLigadaG<T>::getNumElementos() const {
    return numElementos;
}


std::string convertir(int elem) {
    return std::to_string(elem);
}

std::string convertir(double elem) {
    return std::to_string(elem);
}

std::string convertir(char elem) {
    std::string s(1, elem);
    return s;
}

std::string convertir(std::string elem) {
    return elem;
}

template <typename T>
std::ostream& operator<<(std::ostream &strm, const ListaDLigadaG<T> &lista) {
    std::string elem = "";
    NodoDG<T> *pos = lista.cabeza->getSiguiente();
    if (!lista.esVacia()) {
        while (pos != lista.cola) {
            elem += convertir(pos->getElemento()) + ", ";
            pos = pos->getSiguiente();
        }
        elem += "\b\b";
    }
    return strm << "(" << elem << ")";
}

#endif // LISTA_D_LIGADA_GENERICA_H
