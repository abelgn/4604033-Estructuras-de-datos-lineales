#include <string>

class ILista {
public:
    virtual bool insertar(int x, int p) = 0;
    virtual bool eliminar(int p) = 0;
    virtual int buscar(int x) const = 0;
    virtual int obtener(int p) const = 0;
    virtual void hacerVacia() = 0;
    virtual bool esVacia() const = 0;
    virtual int getNumElementos() const = 0;
};
