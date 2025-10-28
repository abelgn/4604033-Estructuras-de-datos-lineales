#ifndef PILA_ESTATICA_H
#define PILA_ESTATICA_H

template <typename T>
class Pila {
public:
    Pila<T>(int tam);
    ~Pila<T>();
    bool push(T x);
    bool pop();
    T top();
    bool esVacia();
    int getNumElementos() const;

private:
    const int TAM_MAX;
    T *pila;
    int tope;
    template <typename U>
    friend std::ostream& operator<<(std::ostream &strm, const Pila<U> &);
};


template <typename T>
Pila<T>::Pila(int tam):
    TAM_MAX(tam) {
    pila = new T[TAM_MAX];
    tope = -1;
}


template <typename T>
Pila<T>::~Pila() {
    delete [] pila;
}


template <typename T>
bool Pila<T>::push(T x) {
    bool exito = false;
    if (tope < TAM_MAX - 1) {
        tope++;
        pila[tope] = x;
        exito = true;
    }
    return exito;
}


template <typename T>
bool Pila<T>::pop() {
    bool exito = false;
    if (!esVacia()) {
        tope--;
        exito = true;
    }
    return exito;
}


template <typename T>
T Pila<T>::top() {
    T elem;
    if (!esVacia())
        elem = pila[tope];
    return elem;
}


template <typename T>
bool Pila<T>::esVacia() {
    return tope == -1;
}


template <typename T>
int Pila<T>::getNumElementos() const {
    return tope+1;
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
    if (pila.tope >= 0) {
        int pos = 0;
        while (pos <= pila.tope) {
            elem += convertir(pila.pila[pos]) + ", ";
            pos++;
        }
        elem += "\b\b";
    }
    return strm << "(" << elem << ")";
}

#endif // PILA_ESTATICA_H
