class Nodo {
public:
    Nodo(int x, Nodo *sig);
    int getElemento() const;
    Nodo *getSiguiente() const;
    void setSiguiente(Nodo *sig);

private:
    int elemento;
    Nodo *siguiente;
    friend std::ostream& operator<<(std::ostream&, const Nodo&);
};


Nodo::Nodo(int x, Nodo *sig) {
    elemento = x;
    siguiente = sig;
}


int Nodo::getElemento() const {
    return elemento;
}

Nodo *Nodo::getSiguiente() const {
    return siguiente;
}

void Nodo::setSiguiente(Nodo *sig) {
    siguiente = sig;
}

std::ostream& operator<<(std::ostream &strm, const Nodo &nodo) {
    return strm << std::to_string(nodo.getElemento());
}
