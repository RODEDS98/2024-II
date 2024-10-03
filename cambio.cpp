#include <iostream>
using namespace std;

int main() {
    // Trabajar con enteros que representen centavos (en lugar de soles)
    int A[11] = {20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10}; // Monedas en centavos

    float dinero;
    int copia;
    int cociente;

    cout << "Ingrese una cantidad en soles\n";
    cin >> dinero;

    // Convertir el dinero a centavos (usando enteros)
    copia = static_cast<int>(dinero * 100 + 0.5); // Redondear para evitar errores
    cout << "Cantidad en centavos: " << copia << endl;

    for (int* p = A; p < A + 11; p++) {
        cociente = copia / (*p);  // Dividir para encontrar cuántas monedas de *p se pueden dar

        if (copia > 0) {
            cout << "Unidades de - " << *p / 100.0 << " soles: " << cociente << endl;  // Mostrar monedas en soles
            copia -= cociente * (*p);  // Restar el valor de las monedas usadas
        }
    }

    return 0;
}
