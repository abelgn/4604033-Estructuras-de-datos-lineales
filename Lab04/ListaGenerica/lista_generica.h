#include <string>

template <typename T>
class Lista {
public:
    Lista(int tam = 10);
    int fin() const;
    bool insertar(T x, int p);
    bool eliminar(int p);
    int buscar(T x) const;
    T obtener(int p) const;
    int primera() const;
    int siguiente(int p) const;
    int anterior(int p) const;
    void hacerVacia();
    bool esVacia() const;

private:
    int tamaño;
    T *elementos;
    int ultimo;
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Lista<U>&);
};


template <typename T>
Lista<T>::Lista(int tam) {
    tamaño = tam;
    elementos = new T[tam];
    ultimo = -1;
}


template <typename T>
int Lista<T>::fin() const {
    return ultimo+1;
}


template <typename T>
bool Lista<T>::insertar(T x, int p) {
    bool exito = false;
    if (ultimo < tamaño-1 && p >= 0 && p <= ultimo+1) {
        for (int i = ultimo; i >= p; i--)
            elementos[i+1] = elementos[i];
        elementos[p] = x;
        ultimo += 1;
        exito = true;
    }
    return exito;
}


template <typename T>
bool Lista<T>::eliminar(int p) {
    bool exito = false;
    if (p >= 0 && p <= ultimo) {
        for (int i = p; i < ultimo; i++)
            elementos[i] = elementos[i+1];
        ultimo -= 1;
        exito = true;
    }
    return exito;
}


template <typename T>
int Lista<T>::buscar(T x) const {
    int pos = ultimo+1;
    int i = 0;
    while (i <= ultimo) {
        if (x == elementos[i]) {
            pos = i;
            i = ultimo;
        }
        i += 1;
    }
    return pos;
}


template <typename T>
T Lista<T>::obtener(int p) const {
    T elemento;
    if (p >= 0 && p <= ultimo)
        elemento = elementos[p];
    return elemento;
}


template <typename T>
int Lista<T>::primera() const {
    int p = -1;
    if (ultimo != -1)
        p = 0;
    return p;
}


template <typename T>
int Lista<T>::siguiente(int p) const {
    int sig = fin();
    if (p >= 0 && p <= ultimo) {
        sig = p+1;
    }
    return sig;
}


template <typename T>
int Lista<T>::anterior(int p) const {
    int ant = -1;
    if (p >= 0 && p <= ultimo) {
        ant = p-1;
    }
    return ant;
}


template <typename T>
void Lista<T>::hacerVacia() {
    ultimo = -1;
}


template <typename U>
std::ostream& operator<<(std::ostream &strm, const Lista<U> &lista) {
    std::string elem = "";
    int pos = lista.primera();
    while (pos != lista.fin()) {
        elem += std::to_string(lista.obtener(pos)) + ", ";
        pos = lista.siguiente(pos);
    }
    elem += "\b\b";
    return strm << "(" << elem << ")";
}
