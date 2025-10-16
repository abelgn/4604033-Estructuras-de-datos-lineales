class NodoD {
private:
    std::string elemento;
    NodoD* anterior;
    NodoD* siguiente;
    friend class ListaDLigada;
    
public:
    std::string getElemento() const;
    NodoD* getAnterior() const;
    NodoD* getSiguiente() const;
};

std::string NodoD::getElemento() const {
    return elemento;
}

NodoD* NodoD::getAnterior() const {
    return anterior;
}

NodoD* NodoD::getSiguiente() const {
    return siguiente;
}
