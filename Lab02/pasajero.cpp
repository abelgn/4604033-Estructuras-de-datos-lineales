#include <iostream>

using namespace std;

enum TipoComida { SIN_PREFERENCIA, REGULAR, BAJA_EN_GRASA, VEGETARIANA };

class Pasajero {
    public:
        Pasajero();                         // constructor
        Pasajero(string nm, TipoComida tc, string nvf = "NINGUNO");
        Pasajero(Pasajero &pas);
        bool esViajeroFrecuente() const;    // ¿viajero frecuente?
        // hace a este pasajero un viajero frecuente
        void hacerViajeroFrecuente(string numViajeroFrec);
        void mostrar();

        // ... otros métodos

    private:
        string nombre;                  // nombre pasajero
        TipoComida prefComida;    // preferencias de alimentos
        bool esViajeroFrec;        // ¿es viajero frecuente?
        string numViajeroFrec;     // no. de viajero frecuente
};


Pasajero::Pasajero() {             // constructor predeterminado
    nombre = "--SIN NOMBRE--";
    prefComida = SIN_PREFERENCIA;
    esViajeroFrec = false;
    numViajeroFrec = "NINGUNO";
}
                // constructor con valores para los atributos
Pasajero::Pasajero(string nm, TipoComida tc, string nvf) {
    nombre = nm;
    prefComida = tc;
    esViajeroFrec = (nvf != "NINGUNO");// verdadero sólo si se da nvf
    numViajeroFrec = nvf;
}
// constructor de copia
Pasajero::Pasajero(Pasajero &pas) {
    nombre = pas.nombre;
    prefComida = pas.prefComida;
    esViajeroFrec = pas.esViajeroFrec;
    numViajeroFrec = pas.numViajeroFrec;
}

void Pasajero::mostrar() {
    cout << "Nombre: " << nombre << "; Comida: " << prefComida << "; No. VF: " << numViajeroFrec << endl;
}


int main() {
    Pasajero p1;                         // constructor predeterminado
    p1.mostrar();
    Pasajero p2("Frodo", VEGETARIANA, "293145");    // 2o constructor
    p2.mostrar();
    Pasajero p3("Moana", REGULAR);            // no es viajero frecuente
    p3.mostrar();
    Pasajero p4(p3);                        // copiado de p3
    p4.mostrar();
    Pasajero p5 = p2;                        // copiado de p2
    p5.mostrar();
    Pasajero *pp1 = new Pasajero;                // constructor predeterminado
    pp1->mostrar();
    Pasajero *pp2 = new Pasajero("Anakin", SIN_PREFERENCIA);     // 2o constructor
    pp2->mostrar();
    Pasajero ap[20];                    // usa constructor predeterminado
    
    return EXIT_SUCCESS;
}
