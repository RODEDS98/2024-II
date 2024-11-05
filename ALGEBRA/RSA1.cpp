#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Función para calcular el máximo común divisor (mcd)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Función para exponenciación modular
int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Función para convertir un mensaje en texto al formato "libro"
vector<int> textoAModoLibro(const string& mensaje) {
    vector<int> resultado;
    for (char c : mensaje) {
        if (c >= 'A' && c <= 'Z') {
            resultado.push_back(c - 'A');
        } else {
            cout << "Mensaje no válido. Solo se permiten letras mayúsculas sin Ñ.\n";
            exit(1);
        }
    }
    return resultado;
}

// Función para dividir el vector de números en bloques de 4 dígitos
vector<int> dividirEnBloques(vector<int> numeros) {
    vector<int> bloques;
    int bloque = 0;
    for (size_t i = 0; i < numeros.size(); i++) {
        bloque = bloque * 100 + numeros[i]; // Agrupa cada letra como 2 dígitos
        if ((i + 1) % 2 == 0) { // Cada bloque tiene 4 dígitos (2 letras)
            bloques.push_back(bloque);
            bloque = 0;
        }
    }
    if (numeros.size() % 2 != 0) { // Agrega un bloque incompleto si el tamaño es impar
        bloques.push_back(bloque);
    }
    return bloques;
}

// Función para cifrar en modo libro
void cifrarModoLibro(int p, int q, int e, const string& mensaje) {
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    if (gcd(e, phi) != 1) {
        cout << "El valor de e no es coprimo con phi(n). Elija otro valor.\n";
        return;
    }

    vector<int> mensajeNumerico = textoAModoLibro(mensaje);
    vector<int> bloques = dividirEnBloques(mensajeNumerico);

    cout << "Mensaje cifrado en modo libro: ";
    for (int m : bloques) {
        int cifrado = modExp(m, e, n);
        cout << cifrado << " ";
    }
    cout << endl;
}

int main() {
    int p, q, e, opcionModo;
    string mensaje;

    cout << "Ingrese los valores de p y q (números primos): ";
    cin >> p >> q;
    cout << "Ingrese el valor de e (coprimo con (p-1)*(q-1)): ";
    cin >> e;
    cout << "Ingrese el mensaje a cifrar (solo letras mayúsculas, sin Ñ): ";
    cin >> mensaje;

    cout << "Seleccione el modo de cifrado:\n1. Modo Libro\n2. Modo ASCII (no disponible)\n";
    cin >> opcionModo;

    if (opcionModo == 1) {
        cifrarModoLibro(p, q, e, mensaje);
    } else if (opcionModo == 2) {
        cout << "Modo ASCII no disponible.\n";
    } else {
        cout << "Opción inválida.\n";
    }

    return 0;
}
