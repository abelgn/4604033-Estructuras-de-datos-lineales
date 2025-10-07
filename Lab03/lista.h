#include <string>
#include <climits>

#include "ilista.h"

class Lista : public ILista {
public:
    Lista(int tam);
    ~Lista();
    int fin() const;
    bool insertar(int x, int p);
    bool eliminar(int p);
    int buscar(int x) const;
    int obtener(int p) const;
    void hacerVacia();
    bool esVacia() const;

private:
    friend std::ostream& operator<<(std::ostream&, const Lista&);
    const int TAM_MAX;
    int *elementos;
    int num_elementos;
};


Lista::Lista(int tam):
    TAM_MAX(tam) {
    elementos = new int[TAM_MAX];
    num_elementos = 0;
}


Lista::~Lista() {
    delete [] elementos;
}


int Lista::fin() const {
    return num_elementos;
}


bool Lista::insertar(int x, int p) {
    bool exito = false;
    if(num_elementos < TAM_MAX && p >= 0 && p <= num_elementos) {
        int i = num_elementos-1;
        while(i >= p) {
            elementos[i+1] = elementos[i];
            i--;
        }
        elementos[p] = x;
        num_elementos++;
        exito = true;
    }
    return(exito);
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
    int elemento = std::numeric_limits<int>::max();
    if (p >= 0 && p <= ultimo)
        elemento = elementos[p];
    return elemento;
}


void Lista::hacerVacia() {
    // implementar
}


bool Lista::esVacia() const {
    // implementar
    return true;
}



/**
Se define el operador << para enviar el contenido de la lista a la 
pantalla como salida estándar.
 */
std::ostream& operator<<(std::ostream &strm, const Lista &lista) {
    std::string elem = "";
    int pos = 0;
    while (pos != lista.fin()) {
        elem += std::to_string(lista.obtener(pos)) + ", ";
        pos++;
    }
    elem += "\b\b";
    return strm << "(" << elem << ")";
}
