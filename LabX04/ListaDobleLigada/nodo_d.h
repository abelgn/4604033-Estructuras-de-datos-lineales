#include <string>

class NodoD {
private:
    std::string elem;
    NodoD* previo;
    NodoD* siguiente;
    friend class ListaLigadaD;
};
