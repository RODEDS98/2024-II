#include <iostream>  
#include <string>    
#include <stdexcept> 

using namespace std; 

// Función para calcular el máximo común divisor (MCD) entre dos números a y b usando el algoritmo de Euclides.
int gcd(int a, int b) {  
    while (b != 0) {  // Mientras el valor de 'b' no sea 0, se repite el proceso.
        int temp = b;  // Primero se guarda el valor de 'b' en una variable temporal.
        b = a % b;  // Se actualiza el valor de 'b' con el residuo de dividir 'a' entre 'b'.
        a = temp;  // Se actualiza 'a' con el valor anterior de 'b'.
    }
    return a;  // Cuando 'b' llega a ser 0, 'a' es el MCD y se retorna.
}

// Función para verificar si 'a' es coprimo con 'N' (si el MCD de 'a' y 'N' es 1).
bool esCoprimo(int a, int N) {
    return gcd(a, N) == 1;  // Devuelve 'true' si 'a' y 'N' son coprimos (MCD = 1), de lo contrario devuelve 'false'.
}

// Función para calcular el inverso modular de 'a' en módulo 'N' usando el algoritmo extendido de Euclides.
int inversoModular(int a, int N) {
    int t = 0, nuevoT = 1;  // Se inicializan dos variables para seguir el proceso de cálculo de inverso.
    int r = N, nuevoR = a;  // 'r' es el valor de 'N' y 'nuevoR' es el valor de 'a'.

    // Mientras 'nuevoR' no sea 0, se repite el proceso.
    while (nuevoR != 0) {
        int cociente = r / nuevoR;  // Se calcula el cociente entre 'r' y 'nuevoR'.
        int tempT = t;  // Se guarda temporalmente el valor de 't'.
        t = nuevoT;  // Se actualiza 't' con el valor de 'nuevoT'.
        nuevoT = tempT - cociente * nuevoT;  // Se calcula el nuevo valor de 'nuevoT'.

        int tempR = r;  // Se guarda temporalmente el valor de 'r'.
        r = nuevoR;  // Se actualiza 'r' con el valor de 'nuevoR'.
        nuevoR = tempR - cociente * nuevoR;  // Se calcula el nuevo valor de 'nuevoR'.
    }

    // Si el valor de 'r' es mayor que 1, no existe inverso modular.
    if (r > 1) {
        throw invalid_argument("No hay inverso modular para 'a' con este 'N'");  // Lanza una excepción si no hay inverso modular.
    }
    
    if (t < 0) {  // Si el valor de 't' es negativo, se ajusta sumando 'N' para que quede dentro del rango.
        t += N;
    }
    return t;  // Se retorna el inverso modular de 'a' en módulo 'N'.
}

// Función para cifrar un mensaje usando el cifrado afín.
string cifrarAfin(const string& mensaje, int a, int b, int N = 26) {
    if (!esCoprimo(a, N)) {  // Se verifica si 'a' es coprimo con 'N'.
        throw invalid_argument("'a' no es coprimo con 'N', elige otro valor.");  // Si no es coprimo, lanza una excepción.
    }

    string cifrado = "";  // Se inicializa una cadena vacía para guardar el mensaje cifrado.
    for (char letra : mensaje) {  // Se recorre cada letra del mensaje.
        if (isalpha(letra)) {  // Si el carácter es una letra.
            char base = isupper(letra) ? 'A' : 'a';  // Se determina si la letra es mayúscula o minúscula.
            int p = letra - base;  // Se convierte la letra en un número basado en su posición en el alfabeto.
            int c = (a * p + b) % N;  // Se aplica la fórmula del cifrado afín.
            cifrado += base + c;  // Se convierte el número cifrado de nuevo a un carácter y se agrega a la cadena cifrada.
        } else {
            cifrado += letra;  // Si no es una letra, se agrega el carácter tal cual está (por ejemplo, espacios o puntuación).
        }
    }
    return cifrado;  // Se retorna el mensaje cifrado.
}

// Función para descifrar un mensaje cifrado con el cifrado afín.
string descifrarAfin(const string& cifrado, int a, int b, int N = 26) {
    int a_inv = inversoModular(a, N);  // Se calcula el inverso modular de 'a' en módulo 'N'.
    string mensaje = "";  // Se inicializa una cadena vacía para el mensaje descifrado.

    for (char letra : cifrado) {  // Se recorre cada letra del mensaje cifrado.
        if (isalpha(letra)) {  // Si el carácter es una letra.
            char base = isupper(letra) ? 'A' : 'a';  // Se determina si la letra es mayúscula o minúscula.
            int c = letra - base;  // Se convierte la letra cifrada en su número correspondiente.
            int p = (a_inv * (c - b + N)) % N;  // Se aplica la fórmula del descifrado afín.
            mensaje += base + p;  // Se convierte el número descifrado de nuevo a carácter y se agrega al mensaje.
        } else {
            mensaje += letra;  // Si no es una letra, se agrega el carácter tal cual está.
        }
    }
    return mensaje;  // Se retorna el mensaje descifrado.
}

// Función principal para interactuar con el usuario y ejecutar las opciones.
int main() {

    int opcion;  // Variable para almacenar la opción seleccionada por el usuario.
    int a, b, N = 26;  // Variables para almacenar 'a', 'b' y el valor de 'N' (por defecto 26).
    string texto;  // Variable para almacenar el mensaje ingresado por el usuario.

    cout << "Seleccione una opción:\n";  // Muestra el menú de opciones.
    cout << "1. Cifrar mensaje\n";  // Opción para cifrar el mensaje.
    cout << "2. Descifrar mensaje\n";  // Opción para descifrar el mensaje.
    cout << "3. Calcular inversa de 'a'\n";  // Opción para calcular el inverso modular de 'a'.
    cout << "Opción: ";
    cin >> opcion;  // Se lee la opción seleccionada por el usuario.

    try {
        if (opcion == 1) {  // Si el usuario selecciona la opción para cifrar el mensaje.
            cout << "Ingrese el valor de 'a': ";
            cin >> a;  // Se pide el valor de 'a'.
            cout << "Ingrese el valor de 'b': ";
            cin >> b;  // Se pide el valor de 'b'.
            cin.ignore();  // Se limpia el buffer para evitar problemas con getline.

            cout << "Ingrese el mensaje: ";
            getline(cin, texto);  // Se lee el mensaje a cifrar.
            string mensajeCifrado = cifrarAfin(texto, a, b, N);  // Se llama a la función de cifrado.
            cout << "Mensaje cifrado: " << mensajeCifrado << endl;  // Se imprime el mensaje cifrado.

        } else if (opcion == 2) {  // Si el usuario selecciona la opción para descifrar el mensaje.
            cout << "Ingrese el valor de 'a': ";
            cin >> a;  // Se pide el valor de 'a'.
            cout << "Ingrese el valor de 'b': ";
            cin >> b;  // Se pide el valor de 'b'.
            cin.ignore();  // Se limpia el buffer.

            cout << "Ingrese el mensaje: ";
            getline(cin, texto);  // Se lee el mensaje cifrado.
            string mensajeDescifrado = descifrarAfin(texto, a, b, N);  // Se llama a la función de descifrado.
            cout << "Mensaje descifrado: " << mensajeDescifrado << endl;  // Se imprime el mensaje descifrado.

        } else if (opcion == 3) {  // Si el usuario selecciona la opción para calcular la inversa de 'a'.
            cout << "Ingrese el valor de 'a': ";
            cin >> a;  // Se pide el valor de 'a'.
            cout << "Ingrese el valor de 'N' (por defecto 26): ";
            cin >> N;  // Se pide el valor de 'N'.
            int inversa = inversoModular(a, N);  // Se calcula el inverso modular de 'a'.
            cout << "El inverso modular de " << a << " en modulo " << N << " es: " << inversa << endl;  // Se muestra el inverso.
        } else {
            cout << "Opción no válida." << endl;  // Si la opción no es válida, se muestra un mensaje.
        }
    } catch (const invalid_argument& e) {  // Si se lanza una excepción (por ejemplo, cuando no hay inverso modular).
        cout << "Error: " << e.what() << endl;  // Se muestra el mensaje de error.
    }

    return 0;  // Se termina el programa.
}
