#ifndef PILA_DOBLE_H
#define PILA_DOBLE_H

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


class StackEmptyException : public RuntimeException {
public:
    StackEmptyException(const std::string& err)
    : RuntimeException(err) { }
};


class StackFullException : public RuntimeException {
public:
    StackFullException(const std::string& err)
    : RuntimeException(err) { }
};


class WrongStackIdException : public RuntimeException {
public:
    WrongStackIdException(const std::string& err)
    : RuntimeException(err) { }
};


template <typename T>
class PilaDoble {
public:
    PilaDoble<T>(int tam);
    void push(T x, int id_pila) throw(StackFullException, WrongStackIdException);
    void pop(int id_pila) throw(StackEmptyException, WrongStackIdException);
    T top(int id_pila) const throw(StackEmptyException, WrongStackIdException);
    bool esVacia(int id_pila) const throw(WrongStackIdException);
    int getNumElementos(int id_pila) const throw(WrongStackIdException);
    
private:
    const int TAM_MAX;
    T *elementos;
    int tope1, tope2;
    template <typename U>
    friend std::ostream& operator<<(std::ostream &, const PilaDoble<U> &);

};


template <typename T>
PilaDoble<T>::PilaDoble(int tam) {
    // implementar
}


template <typename T>
void PilaDoble<T>::push(T x, int id_pila) throw(StackFullException, WrongStackIdException) {
    // implementar
}


template <typename T>
void PilaDoble<T>::pop(int id_pila) throw(StackEmptyException, WrongStackIdException) {
    // implementar
}


template <typename T>
T PilaDoble<T>::top(int id_pila) const throw(StackEmptyException, WrongStackIdException) {
    // implementar
}


template <typename T>
bool PilaDoble<T>::esVacia(int id_pila) const throw (WrongStackIdException) {
    // implementar
}


template <typename T>
int PilaDoble<T>::getNumElementos(int id_pila) const throw (WrongStackIdException) {
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
std::ostream& operator<<(std::ostream &strm, const PilaDoble<T> &pd) {
    std::string elem = "";
    if (!pd.esVacia(1)) {
        int pos = 0;
        while (pos <= pd.tope1) {
            elem += convertir(pd.elementos[pos]) + ", ";
            pos++;
        }
        elem += "\b\b*";
    }
    elem += ")(";
    if (!pd.esVacia(2)) {
        elem += "*";
        int pos = pd.tope2;
        while (pos < pd.TAM_MAX) {
            elem += convertir(pd.elementos[pos]) + ", ";
            pos++;
        }
        elem += "\b\b";
    }
    return strm << "(" << elem << ")";
}

#endif // PILA_DOBLE_H
