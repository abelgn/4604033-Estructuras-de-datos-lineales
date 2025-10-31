#ifndef LISTA_GENERICA_H
#define LISTA_GENERICA_H

#include <string>
#include "nodo_generico.h"

template <typename T>
class Lista {
public:
    Lista();
    ~Lista();
    bool insertar(T x, int p);
    bool eliminar(int p);
    int buscar(T x) const;
    T obtener(int p) const;
    void hacerVacia();
    bool esVacia() const;
    int getNumElementos() const;
    
private:
    Nodo<T> *centinela;
    Nodo<T> *ultimo;
    Nodo<T> *encontrarNodo(int p) const;
    void insertarVacia(T x);
    bool insertar(T x, Nodo<T> *p);
    bool eliminar(Nodo<T> *p);
    int numElementos;
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Lista<U> &);
};


template <typename T>
Lista<T>::Lista() {
    centinela = new Nodo<T>();
    ultimo = centinela;
    numElementos = 0;
}


/*
 Libera la memoria ocupada por todos los nodos de la lista.
 */
template <typename T>
Lista<T>::~Lista() {
    if (numElementos > 0) {
        Nodo<T> *p = centinela;
        Nodo<T> *q = centinela->getSiguiente();
        while (q !=  NULL) {
            delete p;
            p = q;
            q = q->getSiguiente();
        }
        delete p;
    }
}


template <typename T>
Nodo<T> *Lista<T>::encontrarNodo(int p) const {
    Nodo<T> *q = centinela;
    int i = 0;
    while (i < p) {
        q = q->siguiente;
        i++;
    }
    return q;
}


template <typename T>
void Lista<T>::insertarVacia(T x) {
    Nodo<T> *nuevo = new Nodo<T>();
    nuevo->elemento = x;
    nuevo->siguiente = NULL;
    centinela->siguiente = nuevo;
    ultimo = nuevo;
}


template <typename T>
bool Lista<T>::insertar(T x, Nodo<T> *p) {
    bool exito = true;
    if (numElementos == 0)
        insertarVacia(x);
    else {
        Nodo<T> *nuevo = new Nodo<T>();
        nuevo->elemento = x;
        nuevo->siguiente = p->siguiente;
        if (p == ultimo)
            ultimo = nuevo;
        p->siguiente = nuevo;
    }
    numElementos++;
    return exito;
}


template <typename T>
bool Lista<T>::insertar(T x, int p) {
    Nodo<T> *q = encontrarNodo(p);
    return insertar(x, q);
}


template <typename T>
bool Lista<T>::eliminar(Nodo<T> *p) {
    Nodo<T> *q = p->siguiente;
    p->siguiente = q->siguiente;
    if (q == ultimo)
        ultimo = p;
    delete q;
    numElementos--;
    return true;
}


template <typename T>
bool Lista<T>::eliminar(int p) {
    if (p >= 0 && p < numElementos) {
        Nodo<T> *q = encontrarNodo(p);
        return eliminar(q);
    }
    return false;
}


template <typename T>
int Lista<T>::buscar(T x) const {
    int i = 0;
    Nodo<T> *p = centinela->siguiente;
    while (p != NULL && p->elemento != x) {
        p = p->siguiente();
        i++;
    }
    return i;
}


template <typename T>
T Lista<T>::obtener(int p) const {
    if (p >= 0 && p < numElementos) {
        Nodo<T> *q = encontrarNodo(p);
        return q->siguiente->elemento;
    }
    return NULL;
}


template <typename T>
void Lista<T>::hacerVacia() {
    while (!esVacia()) {
        Nodo<T> *p = centinela->siguiente;
        centinela->siguiente = p->siguiente;
        delete p;
    }
    ultimo = centinela;
    numElementos = 0;
}


template <typename T>
bool Lista<T>::esVacia() const {
    return (numElementos == 0);
}


template <typename T>
int Lista<T>::getNumElementos() const {
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
std::ostream& operator<<(std::ostream &strm, const Lista<T> &lista) {
    std::string elem = "";
    Nodo<T> *pos = lista.centinela->getSiguiente();
    if (!lista.esVacia()) {
        while (pos != lista.ultimo) {
            elem += convertir(pos->getElemento()) + ", ";
            pos = pos->getSiguiente();
        }
        elem += convertir(pos->getElemento());
    }
    return strm << "(" << elem << ")";
}

#endif // LISTA_GENERICA_H
