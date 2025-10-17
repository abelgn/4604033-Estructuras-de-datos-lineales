#ifndef LISTA_LIGADA_C_H
#define LISTA_LIGADA_C_H

#include <string>
#include "nodo_c.h"

class ListaLigadaC {
public:
    ListaLigadaC();
    ~ListaLigadaC();
    void insertar(Elem e);
    void eliminar();
    void avanzar();
    Elem frente() const;
    Elem ultimo() const;
    bool esVacia() const;

private:
    NodoC* cursor;
    friend std::ostream& operator<<(std::ostream &, const ListaLigadaC &);
};



ListaLigadaC::ListaLigadaC()
    : cursor(NULL) { }


/*
 Libera la memoria ocupada por todos los nodos de la lista.
 */
ListaLigadaC::~ListaLigadaC() {
    // implementar
}


void ListaLigadaC::insertar(Elem e) {
    // implementar
}


void ListaLigadaC::eliminar() {
    // implementar
}


void ListaLigadaC::avanzar() {
    cursor = cursor->siguiente;
}


Elem ListaLigadaC::ultimo() const {
    return cursor->elemento;
}


Elem ListaLigadaC::frente() const {
    return cursor->siguiente->elemento;
}


bool ListaLigadaC::esVacia() const {
    // implementar
    return NULL;
}


std::ostream& operator<<(std::ostream &strm, const ListaLigadaC &lista) {
    std::string elem = "";
    NodoC *aux = lista.cursor;
    
    if (aux != NULL) {
        while (aux->siguiente != lista.cursor) {
            elem += aux->siguiente->elemento + ", ";
            aux = aux->siguiente;
        }
        elem += aux->siguiente->elemento + "*";
    }
    return strm << "(" << elem << ")";
}

#endif // LISTA_LIGADA_C_H
