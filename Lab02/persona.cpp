#include <iostream>

using namespace std;

class Persona {                // Persona (superclase)
    public:
        // ...
        Persona(string nm, int id);
        void imprimir();        // imprime información
        string getNombre();    // recupera el nombre
    private:
        string nombre;
        int numId;            // número de identificación
};

Persona::Persona(string nm, int id)
: nombre(nm),                // inicializa nombre
  numId(id) { }                 // inicializa número de id.


void Persona::imprimir() {        // definición de imprimir de Persona
    cout << "Nombre " << nombre << endl;
    cout << "IDnum " << numId << endl;
}

string Persona::getNombre() {
    return nombre;
}



// clase Estudiante (derivada de Persona)
class Estudiante : public Persona {
    public:
        // ...
        Estudiante(string nm, int id, string car, int año);
        void imprimir();             // imprime información
        // cambia de carrera
        void cambiarCarrera(string nuevaCarrera);
    private:
        string carrera;
    int añoGraduación;
    
};

Estudiante::Estudiante(string nm, int id, string car, int año)
: Persona(nm, id),        // inicializa atributos de Persona
  carrera(car),             // inicializa carrera
  añoGraduación(año) { }     // inicializa año de graduación


void Estudiante::imprimir() {    // definición de imprimir de Estudiante
    Persona::imprimir();     // primero imprime información de Persona
    cout << "Carrera " << carrera << endl;
    cout << "Año " << añoGraduación << endl;
}

void Estudiante::cambiarCarrera(string nuevaCarrera) {
    carrera = nuevaCarrera;
}




int main() {
    Persona persona("Carmen", 12345);       // declara una Persona
    // declara un Estudiante
    Estudiante estudiante("Roberto", 98764, "Matemáticas", 2020);
    cout << estudiante.getNombre() << endl; // invoca Persona::getNombre()
    persona.imprimir();                     // invoca Persona::imprimir()
    estudiante.imprimir();                  // invoca Estudiante::imprimir()
//    persona.cambiarCarrera("Física");       // ¡ERROR!
    estudiante.cambiarCarrera("Biología");  // Todo bien
    estudiante.imprimir();                  // invoca Estudiante::imprimir()
    return EXIT_SUCCESS;
}
