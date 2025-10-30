#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
public:
    Nodo(T x, Nodo<T> *sig);
    T getElemento() const;
    Nodo<T> *getSiguiente() const;

private:
    T elemento;
    Nodo<T> *siguiente;
    template <typename U>
    friend class Pila;
};


template <typename T>
Nodo<T>::Nodo(T x, Nodo<T> *sig) {
    elemento = x;
    siguiente = sig;
}


template <typename T>
T Nodo<T>::getElemento() const {
    return elemento;
}


template <typename T>
Nodo<T> *Nodo<T>::getSiguiente() const {
    return siguiente;
}

#endif // NODO_H
