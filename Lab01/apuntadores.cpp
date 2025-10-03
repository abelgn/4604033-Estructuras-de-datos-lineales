#include <iostream>
using namespace std;

/* Muestra el funcionamiento de los apuntadores. */
int main() {
    char ch = 'Q';
    char *p = &ch;  // p contiene la dirección de ch
    cout << *p << endl;     // muestra el carácter 'Q'
    ch = 'Z';               // ch ahora contiene 'Z'
    cout << *p << endl;     // muestra el carácter 'Z'
    *p = 'X';               // ch ahora contiene 'X'
    cout << ch << endl;     // muestra el carácter 'X'
    
    cout << (void *) &ch << endl;     // muestra la dirección de la variable ch
    cout << (void *) &p << endl;     // muestra la dirección de la variable p
    return EXIT_SUCCESS;
}
