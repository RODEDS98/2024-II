#include <iostream>
#include <string>
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

// Función para encontrar el inverso modular de d respecto a phi
int modInverse(int d, int phi) {
    for (int x = 1; x < phi; x++) {
        if ((d * x) % phi == 1)
            return x;
    }
    return -1; // No hay inverso modular si se retorna -1
}

// Función para convertir un mensaje en texto al formato "libro"
string textoAModoLibro(const string& mensaje) {
    string resultado;
    for (char c : mensaje) {
        if (c >= 'A' && c <= 'Z') {
            int valor = c - 'A';
            if (valor < 10) resultado += "0";
            resultado += to_string(valor);
        } else {
            cout << "Mensaje no válido. Solo se permiten letras mayúsculas sin Ñ.\n";
            exit(1);
        }
    }
    return resultado;
}

// Función para cifrar en modo "Libro"
void cifrarModoLibro(int p, int q, int e, const string& mensaje) {
    int n = p * q;
    string numeros = textoAModoLibro(mensaje);

    cout << "Mensaje cifrado en modo libro: ";
    for (size_t i = 0; i < numeros.length(); i += 4) {
        string bloque = numeros.substr(i, 4);
        int numero = stoi(bloque);
        int cifrado = modExp(numero, e, n);
        cout << cifrado << " ";
    }
    cout << endl;
}

// Función para descifrar números en modo libro y convertirlos a letras
void descifrarModoLibro(int p, int q, int d, const string& mensaje) {
    int n = p * q;
    cout << "Mensaje descifrado en modo libro (números): ";
    string mensajeNumerico;

    for (size_t i = 0; i < mensaje.length(); i += 4) {
        string bloque = mensaje.substr(i, 4);
        int numero = stoi(bloque);
        int descifrado = modExp(numero, d, n);

        // Asegurarse de que el bloque descifrado tenga 4 dígitos
        if (descifrado < 1000) {
            mensajeNumerico += string(4 - to_string(descifrado).length(), '0') + to_string(descifrado);
        } else {
            mensajeNumerico += to_string(descifrado);
        }
        cout << descifrado << " ";
    }

    // Convertir números descifrados a letras
    cout << "\nMensaje descifrado en modo libro (texto): ";
    for (size_t i = 0; i < mensajeNumerico.length(); i += 2) {
        int numero = stoi(mensajeNumerico.substr(i, 2));
        char letra = 'A' + numero;
        cout << letra;
    }
    cout << endl;
}

// Función para cifrar en modo ASCII
void cifrarModoASCII(int p, int q, int e, const string& mensaje) {
    int n = p * q;
    cout << "Mensaje cifrado en modo ASCII: ";
    for (char c : mensaje) {
        int ascii = static_cast<int>(c);
        int cifrado = modExp(ascii, e, n);
        cout << cifrado << " ";
    }
    cout << endl;
}

// Función para descifrar en modo ASCII
void descifrarModoASCII(int p, int q, int d, const string& mensaje) {
    int n = p * q;
    cout << "Mensaje descifrado en modo ASCII: ";
    string resultado;
    size_t pos = 0;
    while (pos < mensaje.length()) {
        string bloque;
        while (pos < mensaje.length() && mensaje[pos] != ' ') {
            bloque += mensaje[pos++];
        }
        pos++;
        int numero = stoi(bloque);
        int descifrado = modExp(numero, d, n);
        resultado += static_cast<char>(descifrado);
    }
    cout << resultado << endl;
}

int main() {
    int p, q, e, d, opcion, opcionModo;
    string mensaje;

    // Elección entre cifrar y descifrar
    cout << "Seleccione una opción:\n1. Cifrar\n2. Descifrar\n";
    cin >> opcion;

    if (opcion == 1) {
        // CIFRAR
        cout << "Ingrese los valores de p y q (números primos): ";
        cin >> p >> q;
        int phi = (p - 1) * (q - 1);

        do {
            cout << "Ingrese el valor de e (coprimo con (p-1)*(q-1)): ";
            cin >> e;
            if (gcd(e, phi) != 1) {
                cout << "El valor de e no es coprimo con phi(n). Elija otro valor.\n";
            }
        } while (gcd(e, phi) != 1); // Repetir hasta que e sea válido

        cout << "Seleccione el modo de cifrado:\n1. Modo Libro\n2. Modo ASCII\n";
        cin >> opcionModo;

        if (opcionModo == 1) {
            cout << "Ingrese el mensaje a cifrar (solo letras mayúsculas, sin Ñ): ";
            cin >> mensaje;
            cifrarModoLibro(p, q, e, mensaje);
        } else if (opcionModo == 2) {
            cout << "Ingrese el mensaje a cifrar (caracteres ASCII permitidos): ";
            cin >> mensaje;
            cifrarModoASCII(p, q, e, mensaje);
        } else {
            cout << "Opción inválida.\n";
        }
    } else if (opcion == 2) {
        // DESCIFRAR
        cout << "Ingrese los valores de p, q y d: ";
        cin >> p >> q >> d;
        int phi = (p - 1) * (q - 1);
        
        // Cálculo del inverso de d para verificar si coincide con e
        int inversoDeD = modInverse(d, phi);
        if (inversoDeD == -1) {
            cout << "Error: No se encontró un inverso modular válido para d.\n";
            return 1;
        } else {
            cout << "El valor de e calculado a partir de d es: " << inversoDeD << endl;
        }

        cout << "Seleccione el modo de descifrado:\n1. Modo Libro\n2. Modo ASCII\n";
        cin >> opcionModo;

        if (opcionModo == 1) {
            cout << "Ingrese el mensaje a descifrar (bloques de 4 dígitos): ";
            cin >> mensaje;
            descifrarModoLibro(p, q, d, mensaje);
        } else if (opcionModo == 2) {
            cout << "Ingrese el mensaje a descifrar (valores cifrados separados por espacios): ";
            cin.ignore(); // Limpiar el buffer
            getline(cin, mensaje);
            descifrarModoASCII(p, q, d, mensaje);
        } else {
            cout << "Opción inválida.\n";
        }
    } else {
        cout << "Opción inválida. Elija 1 o 2.\n";
    }

    return 0;
}
