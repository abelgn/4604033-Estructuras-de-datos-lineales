#include <string>

template <typename T>
class Cola {
public:
    Cola<T>(int N);
    ~Cola<T>();
    bool enqueue(T x);
    bool dequeue();
    T frente() const;
    bool esVacia() const;
    int tamaño() const;
    
private:
    int TAM_MAX;
    T *cola;
    int numElementos;
    int primero;
    int ultimo;
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Cola<U>&);
};


template <typename T>
Cola<T>::Cola(int N) {
    TAM_MAX = N;
    cola = new T[TAM_MAX];
    numElementos = 0;
    primero = 0;
    ultimo = -1;
}


template <typename T>
Cola<T>::~Cola() {
    delete cola;
}


template <typename T>
bool Cola<T>::enqueue(T x) {
    bool exito = false;
    if (numElementos < TAM_MAX) {
        ultimo = (ultimo + 1) % TAM_MAX;
        cola[ultimo] = x;
        numElementos += 1;
        exito = true;
    }
    return exito;
}


template <typename T>
bool Cola<T>::dequeue() {
    bool exito = false;
    if (!esVacia()) {
        primero = (primero + 1) % TAM_MAX;
        numElementos -= 1;
        exito = true;
    }
    return exito;
}


template <typename T>
T Cola<T>::frente() const {
    T elemento;
    if (!esVacia()) {
        elemento = cola[primero];
    }
    return elemento;
}


template <typename T>
bool Cola<T>::esVacia() const {
    return numElementos == 0;
}


template <typename T>
int Cola<T>::tamaño() const {
    return numElementos;
}


template <typename T>
std::ostream& operator<<(std::ostream &strm, const Cola<T> &q) {
    std::string elem = "";
    if (!q.esVacia()) {
        int pos = q.primero;
        int i = 0;
        while (i < q.tamaño()) {
            elem += std::to_string(q.cola[pos]) + ", ";
            pos = (pos + 1) % q.TAM_MAX;
            i += 1;
        }
        elem += "\b\b";
    }
    return strm << "(" << elem << ")";
}
