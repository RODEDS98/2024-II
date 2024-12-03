#include <iostream>
using namespace std;

// Máximo tamaño del array
const int MAX_SIZE = 20;

// Declaración de funciones
void imprimirarray(int* A, int tam){
    for(int i=0; i<tam; i++){
        cout << A[i] << " ";
    }
}

// Contar los errores entre la palabra codificada y la palabra recibida
int contar_errores(int* arr1, int tam){
    int errores = 0;
    for (int i = 0; i < tam; i++) {
        if (arr1[i] == 1) {
            errores++;
        }
    }
    return errores;
}
int contar_digitos(int numero) {
    int digitos = 0;
    while (numero > 0) {
        digitos++;
        numero /= 10;  // Elimina el último dígito
    }
    return digitos;
}
// Desglosar un número en su secuencia de bits
void desglosar_numero(int numero, int* arr, int size) {
    for (int i = size - 1; i >= 0; i--) {
        arr[i] = numero % 10;  // Obtener el bit menos significativo
        numero /= 10;  // Eliminar el bit menos significativo
    }
}

void Determinar3erTermino_2(int arr1[], int arr2[], int size, int* A);
float calcular_probabilidad_1(float p, int size, int cantidad, int* A);
float calcular_probabilidad_2(float p, int size, int cantidad, int* A);

void opcion1() {
    cout << "\nDeterminar el tercer término:\n";

    // Arrays para almacenar palabras (llenados con 9 por defecto)
    int arr1[MAX_SIZE] = {9}, arr2[MAX_SIZE] = {9}, arr3[MAX_SIZE] = {9};

    // Tamaño de la palabra
    int size;
    cout << "\nIngrese el tamaño de la cadena de bits (máximo " << MAX_SIZE << "): ";
    cin >> size;

    if (size > MAX_SIZE || size <= 0) {
        cout << "\nTamaño inválido. Intente nuevamente.\n";
        return;
    }

    while(true){
        // Entrada de palabras como números binarios
    
        int num1, num2;
        cout << "\nIngrese la palabra 1 como número binario: ";
        cin >> num1;
        desglosar_numero(num1, arr1, size);  // Desglosamos el número en bits
    
        
        cout << "\nIngrese la palabra 2 como número binario: ";
        cin >> num2;
        desglosar_numero(num2, arr2, size);  // Desglosamos el número en bits
    
        // Llamar a la función para calcular el tercer término
        Determinar3erTermino_2(arr1, arr2, size, arr3);
        cout << endl; imprimirarray(arr3, size);cout << endl;
    }

    
}

// Función principal para la opción 2
void opcion2() {
    cout << "\nOpciones de Probabilidad de Errores:\n";
    cout << "1. Recibamos la palabra (x)\n";
    cout << "2. Ocurra un error (x)\n";

    int subopcion;
    cout << "Seleccione una opción: ";
    cin >> subopcion;

    if (subopcion == 1) {
        // Entrada de datos para la primera opción
        float p;
        cout << "\nIngrese la probabilidad de transmisión incorrecta p: ";
        cin >> p;

        if (p < 0 || p > 1) {
            cout << "\nProbabilidad inválida. Intente nuevamente.\n";
            return;
        }

        int arr1[MAX_SIZE] = {9}, arr2[MAX_SIZE] = {9}, A[MAX_SIZE] = {9};
        int size;

        // Entrada de la palabra codificada como número binario
        cout << "\nIngrese el tamaño de la palabra codificada (máximo " << MAX_SIZE << "): ";
        cin >> size;
        if (size > MAX_SIZE || size <= 0) {
            cout << "\nTamaño inválido. Intente nuevamente.\n";
            return;
        }

        int num1;
        cout << "\nIngrese la palabra codificada como número binario: ";
        cin >> num1;
        desglosar_numero(num1, arr1, size);  // Desglosamos el número en bits
        cout << endl; imprimirarray(arr1, size);

        // Entrada de la palabra recibida como número binario
        while (true) {
            int num2;
            cout << "\nIngrese la palabra recibida como número binario: ";
            cin >> num2;
            desglosar_numero(num2, arr2, size);  // Desglosamos el número en bits
            cout << endl; imprimirarray(arr2, size);cout << endl;

            // Determinar el tercer término y calcular la probabilidad
            Determinar3erTermino_2(arr1, arr2, size, A);
            cout << endl; imprimirarray(A, size);cout << endl;

            int errores_encontrados = contar_errores(A, size);

            float probab = calcular_probabilidad_1(p, size, errores_encontrados, A);
            cout << "\nProbabilidad: " << probab << endl;
        }
    } else if (subopcion == 2) {
        // Entrada de datos para la segunda opción
        float p;
        int cantidad;
        cout << "\nIngrese la probabilidad de transmisión incorrecta p (0 <= p <= 1): ";
        cin >> p;

        if (p < 0 || p > 1) {
            cout << "\nProbabilidad inválida. Intente nuevamente.\n";
            return;
        }

        int arr1[MAX_SIZE] = {9}, arr2[MAX_SIZE] = {9}, A[MAX_SIZE] = {9};
        int size;

        cout << "\nIngrese el tamaño de la palabra codificada (máximo " << MAX_SIZE << "): ";
        cin >> size;
        if (size > MAX_SIZE || size <= 0) {
            cout << "\nTamaño inválido. Intente nuevamente.\n";
            return;
        }

        int num1;
        cout << "\nIngrese la palabra codificada como número binario: ";
        cin >> num1;
        desglosar_numero(num1, arr1, size);  // Desglosamos el número en bits
        cout << endl; imprimirarray(arr1, size);cout << endl;
        
        while (true) {
            cout << "\nIngrese el valor de errores esperados (cantidad): \n";
            cin >> cantidad;

            float probab = calcular_probabilidad_2(p, size, cantidad, A);
            cout << "\nProbabilidad: " << probab << endl;
            cout << "\nLa probabilidad de ocurrir un error de cantidad " << cantidad << " es: " << probab << "\n";
        }
    } else {
        cout << "\nOpción inválida. Intente nuevamente.\n";
    }
}


// Determinar el tercer término y actualizar A
void Determinar3erTermino_2(int arr1[], int arr2[], int size, int* A) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] == 9 || arr2[i] == 9) break; // Terminar si se encuentra un 9
        A[i] = (arr1[i] + arr2[i]) % 2;          // Sumar bit a bit con módulo 2
    }
}

// Calcular la probabilidad de una palabra dada
float calcular_probabilidad_1(float p, int size, int errores, int* A) {
    int i = 0;
    float prob_correcta = 1.0 - p;
    float prob_resultado = 1.0;

    for (; i < errores; i++) {
        prob_resultado = prob_resultado * p;  
    }

    for (; i < size; i++) {
        prob_resultado = prob_resultado * prob_correcta;
    }
    return prob_resultado;   
}

float calcular_probabilidad_2(float p, int size, int errores, int* A) {
    int i = 0;
    float prob_correcta = 1.0 - p;
    float prob_resultado = 1.0;

    for (; i < errores; i++) {
        prob_resultado = prob_resultado * p;  
    }

    for (; i < size; i++) {
        prob_resultado = prob_resultado * prob_correcta;
    }

    // Calcular la combinación
    int combinatoria = 1;
    for (int j = 0; j < errores; j++) {
        combinatoria *= (size - j);
        combinatoria /= (j + 1);
    }

    return prob_resultado * combinatoria;   
}
// Determinar el valor predominante en cada columna
int calcular_valor_predominante(int* arr, int filas, int columnas) {
    int resultado = 0;

    for (int col = 0; col < columnas; col++) {
        int contador_1 = 0, contador_0 = 0;

        // Contamos cuántos 1's y cuántos 0's hay en la columna
        for (int row = 0; row < filas; row++) {
            if (arr[row * columnas + col] == 1) {
                contador_1++;
            } else {
                contador_0++;
            }
        }

        // Si hay más 1's que 0's, el valor predominante es 1
        if (contador_1 > contador_0) {
            resultado = resultado * 10 + 1;  // Agregar un 1 al final
        } else {
            resultado = resultado * 10 + 0;  // Agregar un 0 al final
        }
    }

    return resultado;  // Retornamos el número binario resultante
}


void opcion3() {

    cout << "\nOpciones :\n";
    cout << "1. Decodificar (xm,m)\n";
    cout << "2. Ocurra un error (x)\n";

    int subopcion;
    cout << "Seleccione una opción: ";
    cin >> subopcion;
    
    if (subopcion == 1) {
        int x,m;
        cout << "\nIngrese (x) de (mx,x) \n";
        cin >> x;
        cout << "\nIngrese (m) de (mx,x) \n";
        cin >> m;
        cout << "\nIngreste ("<< x* m<<","<< x<<")"<<endl;
        
        while(true){
            // Entrada de palabras como números binarios
            int arr1[MAX_SIZE] = {9};
            int solucion[x] = {9};
            int num1;
            cout << "\nIngrese la palabra 1 como número binario: ";
            cin >> num1;
            desglosar_numero(num1, arr1, m*x);  // Desglosamos el número en bits
            
            
            cout << endl; imprimirarray(arr1, m*x);cout << endl;
           
            int valor_predominante = calcular_valor_predominante(arr1, x, m);
            cout <<valor_predominante<<endl;
             
            int copia_valor=valor_predominante;
            
            if (valor_predominante==0){
                for(int i=0;i<x;i++){
                    solucion[i]=0;
                }
                cout << endl; imprimirarray(solucion, x);cout << endl;
            }
            else{
                desglosar_numero(valor_predominante, solucion, x);
                cout << endl; imprimirarray(solucion, x);cout << endl;
            }
        }
        

    }
    if (subopcion == 1) {
        int arr1[MAX_SIZE] = {9};
        int x,m;
        cout << "\nIngrese (x) de (mx,x) \n";
        cin >> x;
        cout << "\nIngrese (m) de (mx,x) \n";
        cin >> m;
        cout << "\nIngreste ("<< x* m<<","<< x<<")"<<endl;
    }
}

int main() {
    while (true) {
        int opcion;
        cout << "\nSelecciona una opción:\n";
        cout << "1. Determinar el tercer término\n";
        cout << "2. Calcular la probabilidad de errores\n";
        cout << "3. Por repeticion\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            opcion1();
        } else if (opcion == 2) {
            opcion2();
        } else if (opcion == 3) {
            opcion3();
            break;
        } else {
            cout << "Opción inválida. Intente nuevamente.\n";
        }
    }
}
