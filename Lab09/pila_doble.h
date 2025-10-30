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
    void push(T x, int id_pila);
    void pop(int id_pila);
    T top(int id_pila) const;
    bool esVacia(int id_pila) const;
    int getNumElementos(int id_pila) const;
    
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


/**
 * Agrega el elemento <code>x<\code> a la pila indicada por <code>id_pila<\code>.
 * @param x Elemento a agregar.
 * @param id_pila Identificador de la pila (1 o 2).
 * @throws WrongStackIdException si el identificador de pila es inválido.
 * @throws StackFullException si la pila doble está llena.
 */
template <typename T>
void PilaDoble<T>::push(T x, int id_pila) {
    // implementar
}


/**
 * Elimina el elemento en el tope de la pila indicada por <code>id_pila<\code>.
 * @param id_pila Identificador de la pila (1 o 2).
 * @throws WrongStackIdException si el identificador de pila es inválido.
 * @throws StackEmptyException si la pila indicada está vacía.
 */
template <typename T>
void PilaDoble<T>::pop(int id_pila) {
    // implementar
}


/**
 * Regresa el elemento en el tope de la pila indicada por <code>id_pila<\code>.
 * @param id_pila Identificador de la pila (1 o 2).
 * @return Elemento en el tope de la pila.
 * @throws WrongStackIdException si el identificador de pila es inválido.
 * @throws StackEmptyException si la pila indicada está vacía.
 */
template <typename T>
T PilaDoble<T>::top(int id_pila) const {
    // implementar
}


/**
 * Indica si la pila indicada por <code>id_pila<\code> está vacía.
 * @param id_pila Identificador de la pila (1 o 2).
 * @return <code>true<\code> si la pila está vacía, <code>false<\code> en otro caso.
 * @throws WrongStackIdException si el identificador de pila es inválido.
 */
template <typename T>
bool PilaDoble<T>::esVacia(int id_pila) const {
    // implementar
}


/**
 * Regresa el número de elementos en la pila indicada por <code>id_pila<\code>.
 * @param id_pila Identificador de la pila (1 o 2).
 * @return Número de elementos en la pila.
 * @throws WrongStackIdException si el identificador de pila es inválido.
 */
template <typename T>
int PilaDoble<T>::getNumElementos(int id_pila) const {
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
