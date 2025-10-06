class ILista {
public:
    
    /*
     Devuelve la posición siguiente al último elemento en la lista.
     */
    virtual int fin() const = 0;
    
    /*
     Inserta a x en la posición p de L, moviendo los elementos en p y 
     en las posiciones posteriores a la siguiente posición. Es decir, 
     si L es a1, a2, ..., ap-1, ap, ap+1, ..., an, entonces, después 
     de insertar a x en la posición p de L, L queda a1, a2, ..., ap-1, 
     x, ap, ap+1, ..., an. Si p es fin(), entonces L queda a1, a2, ..., 
     an, x. Si la inserción fue exitosa, devuelve true. Si L no tiene 
     posición p, devuelve false.
     */
    virtual bool insertar(int x, int p) = 0;
    
    
    /*
     Elimina al elemento en la posición p de L. Si L es  a1, a2, ..., 
     ap-1, ap, ap+1, ..., an, entonces, después de eliminar al elemento 
     en la posición p de L, L queda a1, a2, ..., ap-1, ap+1, ..., an. 
     El resultado es false si L no tiene posición p o si p es fin().
     */
    virtual bool eliminar(int p) = 0;
    
    /*
     Devuelve la posición de x en L. Si x está más de una vez en L, 
     entonces devuelve la posición de la primera ocurrencia. Si x no 
     está en L, se devuelve fin().
     */
    virtual int buscar(int x) const = 0;
    
    /*
     Devuelve el elemento en la posición p de L. El resultado es 
     indefinido si p es fin() o si L no tiene posición p.
     */
    virtual int obtener(int p) const = 0;
    
    /*
     Hace que L se convierta en una lista vacía.
     */
    virtual void hacerVacia() = 0;
    
    /*
     Devuelve true si la lista no contiene elementos, false en otro caso.
     */
    virtual bool esVacia() const = 0;
    

protected:
    int num_elementos;
};
