#ifndef NODO_GENERICO_H
#define NODO_GENERICO_H

template <typename T>
class Nodo {
public:
    Nodo();
    T getElemento() const;
    Nodo *getSiguiente() const;

private:
    T elemento;
    Nodo<T> *siguiente;
    template <typename U>
    friend class Lista;
};


template <typename T>
Nodo<T>::Nodo() {
    siguiente = NULL;
}

template <typename T>
T Nodo<T>::getElemento() const {
    return elemento;
}

template <typename T>
Nodo<T> *Nodo<T>::getSiguiente() const {
    return siguiente;
}

#endif // NODO_GENERICO_H
