#ifndef COLA_DINAMICA_H
#define COLA_DINAMICA_H

#include <string>

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
class Nodo {
public:
    T getElemento() { return elemento; }
    Nodo<T> *getSiguiente() { return siguiente; }
    
private:
    Nodo();
    T elemento;
    Nodo<T> *siguiente;
    template <typename U>
    friend class Cola;
};


template <typename T>
Nodo<T>::Nodo() {
    siguiente = nullptr;
}


template <typename T>
class Cola {
public:
    Cola<T>();
    Cola<T>(const Cola<T> &q);
    ~Cola<T>();
    void enqueue(T x);
    void dequeue();
    T frente() const;
    bool esVacia() const;
    int getNumElementos() const;
    Cola<T>& operator=(const Cola<T> &q);
    bool operator==(const Cola<T> &q);
    Cola<T>& operator+(const Cola<T> &q);
    Cola<T>& operator-(const int k);

private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;
    int numElementos;
    template <typename U>
    friend std::ostream& operator<<(std::ostream &, const Cola<U> &);
};


template <typename T>
Cola<T>::Cola() {
    primero = new Nodo<T>();
    ultimo = primero;
    numElementos = 0;
}


template <typename T>
Cola<T>::Cola(const Cola<T> &q) {
    // implementar
}


template <typename T>
Cola<T>::~Cola() {
    while (!esVacia())
        dequeue();
}


template <typename T>
void Cola<T>::enqueue(T x) {
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->elemento = x;
    ultimo->siguiente = nuevo;
    ultimo = nuevo;
    numElementos++;
}


template <typename T>
void Cola<T>::dequeue() {
    if (esVacia())
        throw QueueEmptyException("Eliminando de una cola vacía");
    Nodo<T> *p = primero;
    primero = primero->siguiente;
    delete p;
    numElementos--;
}


template <typename T>
T Cola<T>::frente() const {
    if (esVacia())
        throw QueueEmptyException("Solicitando el primeronte de una cola vacía");
    return primero->siguiente->elemento;
}


template <typename T>
bool Cola<T>::esVacia() const {
    return (primero == ultimo);
}


template <typename T>
int Cola<T>::getNumElementos() const {
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
std::ostream& operator<<(std::ostream &strm, const Cola<T> &cola) {
    std::string elem = "";
    Nodo<T> *p = cola.primero;
    while (p->getSiguiente() != nullptr) {
        elem += convertir(p->getSiguiente()->getElemento()) + ", ";
        p = p->getSiguiente();
    }
    if (!cola.esVacia())
        elem += "\b\b";
    return strm << "(" << elem << ")";
}


template <typename T>
Cola<T> &Cola<T>::operator=(const Cola<T> &q) {
    while (!esVacia())
        dequeue();
    Nodo<T> *p = q.primero->siguiente;
    while (p != nullptr) {
        enqueue(p->elemento);
        p = p->siguiente;
    }
    return *this;
}


template <typename T>
bool Cola<T>::operator==(const Cola<T> &q) {
    bool iguales = true;
    // implementar
    return iguales;
}


template <typename T>
Cola<T>& Cola<T>::operator+(const Cola<T> &q) {
    Cola<T> *r = new Cola<T>();
    // implementar
    return *r;
}


template <typename T>
Cola<T>& Cola<T>::operator-(const int k) {
    Cola<T> *q = new Cola();
    // implementar
    return *q;
}

#endif // COLA_DINAMICA_H
