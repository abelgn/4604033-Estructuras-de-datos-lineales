#ifndef NODO_D_GENERICO_H
#define NODO_D_GENERICO_H

template <typename T>
class NodoDG {
private:
    T elemento;
    NodoDG<T>* anterior;
    NodoDG<T>* siguiente;
    template <typename U>
    friend class ListaDLigadaG;
    
public:
    NodoDG();
    T getElemento() const;
    NodoDG<T>* getAnterior() const;
    NodoDG<T>* getSiguiente() const;
};

template <typename T>
NodoDG<T>::NodoDG() {
    siguiente = NULL;
    anterior = NULL;
}

template <typename T>
T NodoDG<T>::getElemento() const {
    return elemento;
}

template <typename T>
NodoDG<T>* NodoDG<T>::getAnterior() const {
    return anterior;
}

template <typename T>
NodoDG<T>* NodoDG<T>::getSiguiente() const {
    return siguiente;
}

#endif // NODO_D_GENERICO_H
