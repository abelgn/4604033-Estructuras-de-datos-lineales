#ifndef PILA_DINAMICA_H
#define PILA_DINAMICA_H

#include <string>
#include "nodo.h"


/**
 * Definición de clase RuntimeExeption
 */
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


/**
 * Definición de clase StackEmptyException
 */
class StackEmptyException : public RuntimeException {
public:
    StackEmptyException(const std::string& err)
    : RuntimeException(err) { }
};


/**
 * Clase Pila implementada con memoria dinámica y haciendo
 * uso de excepciones.
 */
template <typename T>
class Pila {
public:
    Pila();
    ~Pila();
    void push(T x);
    void pop() throw(StackEmptyException);
    T top() const throw(StackEmptyException);
    bool esVacia() const;
    int getNumElementos() const;
      
    
    /**
     * Inserta los elementos de <code>s<\code> en la
     * <code>Pila<\code>. El tope de <code>s<\code> queda como
     * el tope de la <code>Pila<\code>.
     */
    void push(Pila<T> &s);
    
    /**
     * Elimina <code>k<\code> elementos de la <code>Pila<\code>.
     * Si la cantidad de elementos en la <code>Pila<\code> es
     * menor que <code>k<\code>, la <code>Pila<\code> queda vacía.
     *
     * @throws StackEmptyException si la <code>Pila<\code> esta
     * vacía.
     */
    void pop(int k) throw(StackEmptyException);
    
    /**
     * Invierte el orden de los elementos en la <code>Pila<\code>.
     */
    void invertir();

private:
    Nodo<T> *tope;
    int numElementos;
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Pila<U> &);
};


template <typename T>
Pila<T>::Pila() {
    tope = NULL;
    numElementos = 0;
}


template <typename T>
Pila<T>::~Pila() {
    while (!esVacia())
        pop();
}


template <typename T>
void Pila<T>::push(T x) {
    Nodo<T>* nuevo = new Nodo<T>(x, tope);
    tope = nuevo;
    numElementos++;
}


template <typename T>
void Pila<T>::pop() throw(StackEmptyException) {
    if (esVacia())
        throw StackEmptyException("Eliminando de una pila vacía");
    Nodo<T> *p = tope;
    tope = p->siguiente;
    delete p;
    numElementos--;
}


template <typename T>
T Pila<T>::top() const throw(StackEmptyException) {
    if (esVacia())
        throw StackEmptyException("Solicitando el tope de una pila vacía");
    return tope->elemento;
}


template <typename T>
bool Pila<T>::esVacia() const {
    return (tope == NULL);
}


template <typename T>
int Pila<T>::getNumElementos() const {
    return numElementos;
}


template <typename T>
void Pila<T>::push(Pila<T> &s) {
    // implementar
}


template <typename T>
void Pila<T>::pop(int k) throw(StackEmptyException) {
    // implementar
}


template <typename T>
void Pila<T>::invertir() {
    // implementar
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
std::ostream& operator<<(std::ostream &strm, const Pila<T> &pila) {
    std::string elem = "";
    Nodo<T> *p = pila.tope;
    while (p != NULL) {
        elem += convertir(p->getElemento()) + ", ";
        p = p->getSiguiente();
    }
    if (!pila.esVacia())
        elem += "\b\b";
    return strm << "(" << elem << ")";
}

#endif // PILA_DINAMICA_H
