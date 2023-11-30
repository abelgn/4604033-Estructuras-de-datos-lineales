template <typename T>
class NodoD {
public:
    NodoD();
    T elem;
    NodoD<T>* siguiente;
    NodoD<T>* previo;
};

template <typename T>
NodoD<T>::NodoD() {
    siguiente = NULL;
    previo = NULL;
}
