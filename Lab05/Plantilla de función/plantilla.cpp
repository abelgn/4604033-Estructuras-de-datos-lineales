#include <iostream>

using namespace std;

template <typename T>
T minGenerico(T a, T b) {
    return (a < b ? a : b);
}

int main() {
    cout << minGenerico(3, 4) << endl;
    cout << minGenerico(1.1, 3.1) << endl;
    cout << minGenerico('t', 'g') << endl;
}
