#include <string>
#include <climits>

#include "ilista.h"

class Lista : public ILista {
public:
    Lista();
    int fin() const;
    bool insertar(int x, int p);
    bool eliminar(int p);
    int buscar(int x) const;
    int obtener(int p) const;
    int primera() const;
    int siguiente(int p) const;
    int anterior(int p) const;
    void hacerVacia();
    bool esVacia() const;

private:
    friend std::ostream& operator<<(std::ostream&, const Lista&);
    static const int TAM_MAX = 100;
    int elementos[TAM_MAX];
    int ultimo;
};


Lista::Lista() {
    ultimo = -1;
}


int Lista::fin() const {
    return ultimo+1;
}


bool Lista::insertar(int x, int p) {
    bool exito = false;
    if (ultimo < TAM_MAX-1 && p >= 0 && p <= ultimo+1) {
        for (int i = ultimo; i >= p; i--)
            elementos[i+1] = elementos[i];
        elementos[p] = x;
        ultimo += 1;
        exito = true;
    }
    return exito;
}


bool Lista::eliminar(int p) {
    // implementar
    return true;
}


int Lista::buscar(int x) const {
    // implementar
    return 0;
}


int Lista::obtener(int p) const {
    int elemento = INT_MAX;
    if (p >= 0 && p <= ultimo)
        elemento = elementos[p];
    return elemento;
}


int Lista::primera() const {
    // implementar
    return 0;
}


int Lista::siguiente(int p) const {
    // implementar
    return 0;
}


int Lista::anterior(int p) const {
    // implementar
    return 0;
}


void Lista::hacerVacia() {
    // implementar
}


bool Lista::esVacia() const {
    // implementar
    return true;
}



std::ostream& operator<<(std::ostream &strm, const Lista &lista) {
    std::string elem = "";
    int pos = lista.primera();
    while (pos != lista.fin()) {
        elem += std::to_string(lista.obtener(pos)) + ", ";
        pos = lista.siguiente(pos);
    }
    elem += "\b\b";
    return strm << "(" << elem << ")";
}
