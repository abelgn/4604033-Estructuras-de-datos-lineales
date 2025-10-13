class Nodo {
public:
    Nodo(int x, Nodo *sig);
    int getElemento() const;
    Nodo *getSiguiente() const;
    void setElemento(int x);
    void setSiguiente(Nodo *sig);

private:
    int elemento;
    Nodo *siguiente;
};


Nodo::Nodo(int x, Nodo *sig)
    : elemento(x), siguiente(sig) {
    
}

int Nodo::getElemento() const {
    return elemento;
}

Nodo *Nodo::getSiguiente() const {
    return siguiente;
}

void Nodo::setElemento(int x) {
    elemento = x;
}

void Nodo::setSiguiente(Nodo *sig) {
    siguiente = sig;
}
