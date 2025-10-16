#include <string>

template <typename T>
class Lista {
public:
    Lista(int tam = 10);
    ~Lista();
    bool insertar(T x, int p);
    bool eliminar(int p);
    int buscar(T x) const;
    T obtener(int p) const;
    void hacerVacia();
    bool esVacia() const;
    int getNumElementos() const;

private:
    int TAM_MAX;
    T *elementos;
    int num_elementos;
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Lista<U>&);
};


template <typename T>
Lista<T>::Lista(int tam)
: TAM_MAX(tam), num_elementos(0) {
    elementos = new T[tam];
}


template <typename T>
Lista<T>::~Lista() {
    delete [] elementos;
}


template <typename T>
int Lista<T>::getNumElementos() const {
    return num_elementos;
}


template <typename T>
bool Lista<T>::insertar(T x, int p) {
    bool exito = false;
    if (num_elementos < TAM_MAX && p >= 0 && p <= num_elementos) {
        for (int i = num_elementos; i > p; i--)
            elementos[i] = elementos[i-1];
        elementos[p] = x;
        num_elementos++;
        exito = true;
    }
    return exito;
}


template <typename T>
bool Lista<T>::eliminar(int p) {
    bool exito = false;
    if (p >= 0 && p < num_elementos) {
        for (int i = p; i < num_elementos-1; i++)
            elementos[i] = elementos[i+1];
        num_elementos--;
        exito = true;
    }
    return exito;
}


template <typename T>
int Lista<T>::buscar(T x) const {
    int i = 0;
    while (i < num_elementos && elementos[i] != x)
        i++;
    return i;
}


template <typename T>
T Lista<T>::obtener(int p) const {
    T elemento;
    if (p >= 0 && p < num_elementos)
        elemento = elementos[p];
    return elemento;
}


template <typename T>
void Lista<T>::hacerVacia() {
    num_elementos = 0;
}


template <typename T>
bool Lista<T>::esVacia() const {
    return (num_elementos == 0);
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

template <typename U>
std::ostream& operator<<(std::ostream &strm, const Lista<U> &lista) {
    std::string elem = "";
    int pos = 0;
    while (pos < lista.getNumElementos()) {
        elem += convertir(lista.obtener(pos)) + ", ";
        pos++;
    }
    elem += "\b\b";
    return strm << "(" << elem << ")";
}
