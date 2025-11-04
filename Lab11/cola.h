#ifndef COLA_H
#define COLA_H

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
class Cola {
public:
    Cola<T>(int tam);
    void enqueue(T x);
    void dequeue();
    T frente() const;
    bool esVacia() const;
    int getNumElementos() const;
    
private:
    const int TAM_MAX;
    T *cola;
    int num_elementos;
    int primero;
    int ultimo;
    template <typename U>
    friend std::ostream& operator<<(std::ostream &, const Cola<U> &);
};


template <typename T>
Cola<T>::Cola(int tam) : TAM_MAX(tam) {
    cola = new T[TAM_MAX];
    num_elementos = 0;
    primero = 0;
    ultimo = -1;
}


template <typename T>
void Cola<T>::enqueue(T x) {
    if (num_elementos == TAM_MAX)
        throw QueueFullException("Insertando en una cola llena.");
    ultimo = (ultimo + 1) % TAM_MAX;
    cola[ultimo] = x;
    num_elementos++;
}


template <typename T>
void Cola<T>::dequeue() {
    if (esVacia())
        throw QueueEmptyException("Eliminando de una cola vacía.");
    primero = (primero + 1) % TAM_MAX;
    num_elementos--;
}


template <typename T>
T Cola<T>::frente() const {
    if (esVacia())
        throw QueueEmptyException("Solicitando el frente de una cola vacía.");
    return cola[primero];
}


template <typename T>
bool Cola<T>::esVacia() const {
    return num_elementos == 0;
}


template <typename T>
int Cola<T>::getNumElementos() const {
    return num_elementos;
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
    if (cola.num_elementos == 1) {
        elem += convertir(cola.cola[cola.primero]);
    }
    else if (cola.num_elementos > 1) {
        int pos = cola.primero;
        while (pos != cola.ultimo) {
            elem += convertir(cola.cola[pos]) + ", ";
            pos = (pos + 1) % cola.TAM_MAX;
        }
        elem += convertir(cola.cola[pos]);
    }
    return strm << "(" << elem << ")";
}

#endif // COLA_H
