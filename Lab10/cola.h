#ifndef COLA_H
#define COLA_H

#include <string>
#include "lista_generica.h"


class RuntimeException {
public:
    RuntimeException(const std::string& err) {
        errorMsg = "Error: " + err + "\n";
    }
    
    std::string getMessage() const {
        return errorMsg;
    }
    
private:
    std::string errorMsg;
};


class QueueEmptyException : public RuntimeException {
public:
    QueueEmptyException(const std::string& err)
    : RuntimeException(err) { }
};


class QueueFullException : public RuntimeException {
public:
    QueueFullException(const std::string& err)
    : RuntimeException(err) { }
};



template <typename T>
class Cola {
public:
    Cola();
    void enqueue(T x);
    void dequeue();
    T frente() const;
    bool esVacia() const;
    int getNumElementos() const;

private:
    Lista<T> lista;
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Cola<U> &);
};


template <typename T>
Cola<T>::Cola() {
}


template <typename T>
void Cola<T>::enqueue(T x) {
    lista.insertar(x, lista.getNumElementos());
}


template <typename T>
void Cola<T>::dequeue() {
    if (esVacia())
        throw QueueEmptyException("Eliminando de una cola vacía");
    lista.eliminar(0);
}


template <typename T>
T Cola<T>::frente() const {
    if (esVacia())
        throw QueueEmptyException("Solicitando el frente de una cola vacía");
    return lista.obtener(0);
}


template <typename T>
bool Cola<T>::esVacia() const {
    return lista.esVacia();
}


template <typename T>
int Cola<T>::getNumElementos() const {
    return lista.getNumElementos();
}


template <typename T>
std::ostream& operator<<(std::ostream &strm, const Cola<T> &cola) {
    return strm << cola.lista;
}

#endif // COLA_H
