#include <iostream>
#include <bitset>
#include <string>
#include <cstdint> // Incluir esta librería para uint64_t

using namespace std;

// Función para imprimir el patrón de bits
void printBits(const string& binary) {
    cout << bitset<32>(bitset<32>(binary).to_ulong()) << endl;
}

// Función para extraer las partes de un número flotante en formato binario
void extractParts(const string& binary, int &sign, int &exponent, uint32_t &significand) {
    sign = binary[0] - '0'; // Bit de signo
    string exponentBits = binary.substr(1, 8); // Bits de exponente
    string significandBits = binary.substr(9, 23); // Bits de significando

    exponent = bitset<8>(exponentBits).to_ulong(); // Convertir a número entero
    significand = bitset<23>(significandBits).to_ulong(); // Convertir a número entero
}

// Función para multiplicar dos números binarios en punto flotante
string multiplyFloatBinary(const string& binary1, const string& binary2) {
    int signA, signB, exponentA, exponentB;
    uint32_t significandA, significandB;

    // Extraer las partes de los números
    extractParts(binary1, signA, exponentA, significandA);
    extractParts(binary2, signB, exponentB, significandB);

    // 1. Verificar si alguno de los números es 0
    if (binary1 == "00000000000000000000000000000000" || binary2 == "00000000000000000000000000000000") {
        return "00000000000000000000000000000000"; // Retornar 0
    }

    // 2. Sumar los exponentes (en representación biased)
    int newExponent = (exponentA - 127) + (exponentB - 127) + 127;

    // Verificación de overflow y underflow
    if (newExponent <= 0) {
        return "00000000000000000000000000000000"; // Underflow
    } else if (newExponent >= 255) {
        newExponent = 255; // Overflow
    }

    // 3. Multiplicación de los significandos (sin signo)
    uint64_t significandProduct = (static_cast<uint64_t>(significandA | 0x800000) * (significandB | 0x800000)); // Añadir el bit implícito

    // Normalización
    uint32_t finalSignificand;
    if (significandProduct & 0x80000000) { // Si el resultado tiene más de 1
        finalSignificand = significandProduct >> 1; // Desplazar a la derecha
        newExponent++; // Incrementar el exponente
    } else {
        finalSignificand = significandProduct; // Mantener el significando
    }

    // Asegurarse de que el significando tenga solo 23 bits
    finalSignificand &= 0x7FFFFF;

    // 4. Ensamblaje del resultado final
    uint32_t resultBits = (signA ^ signB) << 31 | (newExponent << 23) | finalSignificand;

    // Convertir a binario
    return bitset<32>(resultBits).to_string();
}

int main() {
    string binary1, binary2;

    // Ingreso de dos números binarios
    cout << "Ingrese el primer número binario (32 bits): ";
    cin >> binary1;
    cout << "Ingrese el segundo número binario (32 bits): ";
    cin >> binary2;

    // Mostrar patrones de bits
    cout << "Patrones de bits del primer número: ";
    printBits(binary1);
    cout << "Patrones de bits del segundo número: ";
    printBits(binary2);

    // Multiplicación usando el algoritmo personalizado
    string customResult = multiplyFloatBinary(binary1, binary2);
    cout << "Resultado de la multiplicación (algoritmo personalizado): " << customResult << endl;

    return 0;
}
