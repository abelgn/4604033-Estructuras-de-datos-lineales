#ifndef PILA_GENERICA_H
#define PILA_GENERICA_H

#include <string>
#include "lista_generica.h"


template <typename T>
class Pila {
public:
    Pila();
    bool push(T x);
    bool pop();
    T top() const;
    bool esVacia() const;
    int getNumElementos() const;

private:
    Lista<T> lista;
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Pila<U> &);
};


template <typename T>
Pila<T>::Pila() {
}


template <typename T>
bool Pila<T>::push(T x) {
    return lista.insertar(x, lista.getNumElementos());
}


template <typename T>
bool Pila<T>::pop() {
    return lista.eliminar(lista.getNumElementos()-1);
}


template <typename T>
T Pila<T>::top() const {
    T tope;
    if (!esVacia())
        tope = lista.obtener(lista.getNumElementos()-1);
    return tope;
}


template <typename T>
bool Pila<T>::esVacia() const {
    return lista.esVacia();
}


template <typename T>
int Pila<T>::getNumElementos() const {
    return lista.getNumElementos();
}


template <typename U>
std::ostream& operator<<(std::ostream &strm, const Pila<U> &pila) {
    return strm << pila.lista;
}

#endif // PILA_GENERICA_H
