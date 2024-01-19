#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/**
 Devuelve true si la secuencia de letras entre los índices i y j del string S es un palíndromo, false en caso contrario.
 */
bool esPalindromo(string S, int i, int j) {
    // implementar
    return true;
}


/*
 Invierte el contenido del arreglo de enteros A entre los índices i y j.
 */
void invertir(int A[], int i, int j) {
    // implementar
}


/*
 Toma un string S de longitud n y produzca su inverso a partir del índice i.
 */
void invertirString(string &S, int i, int n) {
    // implementar
}


/*
 Suma los elementos del arreglo A entre los índices i y j.
 */
int sumar(int A[], int i, int j) {
    // implementar
    return 0;
}


/*
 Encuentra y devuelve el elemento máximo en el arreglo A entre los índices i y j.
 */
int maximo(int A[], int i, int j) {
    // implementar
    return 0;
}


/*
 Convierte un string S de dígitos, a partir del dígito en la posición i, en el entero que representa.
 */
int str2int(string S, int i) {
    // implementar
    return 0;
}



int main(int argc, char const *argv[])
{

    // Ejercicio 1
    string S("anitalavalatina");
    cout << esPalindromo(S, 0, S.size()-1) << endl;
    
    // Ejercicio 2
    int A[] = {0,1,2,3,4,5,6,7,8,9};
    invertir(A, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
    cout << endl;
    
    // Ejercicio 3
    S = "anita";
    invertirString(S, 0, 5);
    cout << S << endl;
    
    // Ejercicio 4
    cout << sumar(A, 0, 9) << endl;

    // Ejercicio 5
    cout << maximo(A, 0, 9) << endl;
    
    // Ejercicio 6
    cout << str2int("13531", 0) << endl;
    
	return EXIT_SUCCESS;
}
