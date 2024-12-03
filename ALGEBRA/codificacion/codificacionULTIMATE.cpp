#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <iomanip> // Para formato de salida
using namespace std;

// Máximo tamaño del array
const int MAX_SIZE = 80;

// Función para imprimir un vector con etiquetas
void imprimir_vector(const vector<int>& vec, const string& etiqueta) {
    cout << etiqueta << ": ";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << (i < vec.size() - 1 ? ", " : "\n");
    }
}

// Multiplicación de matriz H por un vector palabra
// Función para multiplicar H por una palabra
vector<int> multiplicar_matriz_vector(const vector<vector<int>>& H, const vector<int>& palabra) {
    vector<int> resultado(H.size(), 0);
    for (size_t i = 0; i < H.size(); i++) {
        for (size_t j = 0; j < palabra.size(); j++) {
            resultado[i] ^= (H[i][j] * palabra[j]); // XOR para módulo 2
        }
    }
    return resultado;
}
// Multiplica G por una palabra
vector<int> multiplicar_matriz_vector_2(const vector<vector<int>>& G, const vector<int>& palabra) {
    vector<int> resultado(G[0].size(), 0);
    for (size_t i = 0; i < G.size(); i++) {
        for (size_t j = 0; j < G[0].size(); j++) {
            resultado[j] ^= (G[i][j] * palabra[i]); // XOR para módulo 2
        }
    }
    return resultado;
}
// Declaración de funciones
void imprimirarray(int* A, int tam){
    for(int i=0; i<tam; i++){
        cout << A[i] << " ";
    }
}
// Función para calcular la distancia Hamming entre dos arreglos
int calcularDistanciaHamming(vector<int>& arr1, vector<int>& arr2, int size) {
    int distancia = 0;
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            distancia++; // Aumentamos la distancia si los bits son diferentes
        }
    }
    return distancia;
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

void desglosar_numero_2(int num, vector<int>& arr, int size) {
    for (int i = size - 1; i >= 0; i--) {
        arr[i] = num % 10;  // Obtener el bit menos significativo
        num /= 10;  // Eliminar el bit menos significativo
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
                cout <<"solucion decodificacion: "<< endl;
                imprimirarray(solucion, x);
                cout << endl;
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

void opcion4() {
    
    const int MAX_SIZE = 30; // Definir el tamaño máximo de las palabras
    int n_palabras, size;
    
    cout << "Ingrese el tamaño de la cadena de bits (máximo " << MAX_SIZE << "): ";
    cin >> size;

    cout << "\nCuantas palabras se analizaran? : ";
    cin >> n_palabras;

    vector<vector<int>> palabras(n_palabras, vector<int>(MAX_SIZE)); // Vector de palabras

    // Leer las palabras y almacenarlas en los arreglos
    for (int i = 0; i < n_palabras; i++) {
        int num1;
        cout << "\nIngresa la palabra " << i + 1 << " (en formato binario): ";
        cin >> num1;
        
        // Crear un arreglo de bits para almacenar la palabra
        desglosar_numero_2(num1, palabras[i], size); // Guardar la palabra en el vector
    }
    
    // Calcular las distancias entre todas las palabras
    int distanciaMinima = INT_MAX; // Valor inicial muy alto para encontrar la mínima
    for (int i = 0; i < n_palabras - 1; i++) {
        for (int j = i + 1; j < n_palabras; j++) {
            int distancia = calcularDistanciaHamming(palabras[i], palabras[j], size);
            distanciaMinima = min(distanciaMinima, distancia); // Actualizar distancia mínima
        }
    }

    cout << "\nLa distancia mínima entre las palabras es: " << distanciaMinima << endl;
}
    
// Generar todas las posibles palabras codificadas
void generar_palabras_codificadas(const vector<vector<int>>& G) {
    int filas = G.size();
    int num_palabras = pow(2, filas); // 2^filas posibles palabras
    cout << "\nPosibles palabras codificadas:\n";

    for (int i = 0; i < num_palabras; i++) {
        vector<int> w(filas, 0);

        // Convertir número a vector de bits
        for (int j = 0; j < filas; j++) {
            w[j] = (i >> j) & 1;
        }

        // Codificar usando G
        vector<int> codificado = multiplicar_matriz_vector_2(G, w);

        // Imprimir resultado
        cout << "w" << i + 1 << " = ";
        for (int bit : w) {
            cout << bit;
        }
        cout << " -> ";
        for (int bit : codificado) {
            cout << bit;
        }
        cout << endl;
    }
}

// Pedir al usuario una palabra para codificar y mostrar su resultado
void codificar_palabra(const vector<vector<int>>& G) {
    string palabra_str;

    cout << "\nIngrese una palabra de " << G.size() << " bits para codificar: ";
    cin >> palabra_str;

    if (palabra_str.length() != static_cast<size_t>(G.size())) {
        cout << "Error: La palabra debe tener longitud " << G.size() << ". Intente de nuevo.\n";

    }

    // Convertir palabra a vector<int>
    vector<int> palabra(G.size());
    for (size_t i = 0; i < palabra_str.length(); i++) {
        palabra[i] = palabra_str[i] - '0';
    }

    // Codificar usando G
    vector<int> codificado = multiplicar_matriz_vector_2(G, palabra);

    // Imprimir resultado
    cout << "Palabra codificada: ";
    for (int bit : codificado) {
        cout << bit;
    }
    cout << endl;
}

void opcion5() { 
    int filas, columnas;
    cout << "Ingrese el número de filas de G (bits de información): ";
    cin >> filas;
    cout << "Ingrese el número de columnas de G (bits totales): ";
    cin >> columnas;

    // Validar que columnas > filas
    if (columnas <= filas) {
        cout << "La matriz G debe tener más columnas que filas (columnas > filas).\n";
        return;
    }

    vector<vector<int>> G(filas, vector<int>(columnas, 0)); // Matriz G

    // Ingreso de G
    cout << "Ingrese las filas de la matriz generadora G como cadenas de bits (ejemplo: 101100):\n";
    for (int i = 0; i < filas; i++) {
        string fila;
        cout << "Fila " << i + 1 << ": ";
        cin >> fila;
        for (int j = 0; j < columnas; j++) {
            G[i][j] = fila[j] - '0'; // Convertir char a int
        }
    }

    // Extraer P de G
    vector<vector<int>> P(filas, vector<int>(columnas - filas));
    for (int i = 0; i < filas; i++) {
        for (int j = filas; j < columnas; j++) {
            P[i][j - filas] = G[i][j];
        }
    }

    // Construir H
    int n_k = columnas - filas; // Número de columnas de H
    vector<vector<int>> H(n_k, vector<int>(columnas, 0));

    // P^T (Transpuesta de P)
    for (int i = 0; i < n_k; i++) {
        for (int j = 0; j < filas; j++) {
            H[i][j] = P[j][i];
        }
    }

    // I_(n-k) (Matriz identidad)
    for (int i = 0; i < n_k; i++) {
        H[i][filas + i] = 1;
    }

    // Mostrar H
    cout << "\nMatriz H:\n";
    for (const auto& fila : H) {
        for (int bit : fila) {
            cout << bit;
        }
        cout << endl;
    }

    cout << "\nELIGIR OPCION:\n";   
    cout << "\n1. Generar palabras codificadas apartir de (w):\n"; 
    cout << "\n2. Probar codificacion (G):\n"; 
    cout << "\n3. Probar Decodificacion (H):\n";
    int opcion_mat=0;
    cin>>opcion_mat;
    
    while(true){
        if (opcion_mat == 1) {
            generar_palabras_codificadas(G);
            cout << "\n Ingrese la opcion , la misma para continuar esta\n";
            cin>>opcion_mat;
            continue;
        } else if (opcion_mat == 2) {

                codificar_palabra(G);
                cout << "\n Ingrese la opcion , la misma para continuar esta\n";
                cin>>opcion_mat;
                continue;

        } else if (opcion_mat == 3) {
                // Probar palabras en un bucle infinito
                while (true) {
                    string palabra_str;
                    cout << "\nIngrese una palabra para probar (o 'salir' para terminar): ";
                    cin >> palabra_str;
            
                    if (palabra_str == "salir") {
                        cout << "Saliendo.\n";
                        break;
                    }
            
                    if (palabra_str.length() != static_cast<size_t>(columnas)) {
                        cout << "Error: La palabra debe tener longitud " << columnas << ". Intente de nuevo.\n";
                        continue;
                    }
            
                    // Convertir palabra a vector<int>
                    vector<int> palabra(columnas);
                    for (size_t i = 0; i < palabra_str.length(); i++) {
                        palabra[i] = palabra_str[i] - '0';
                    }
            
                    // Multiplicar H por la palabra
                    vector<int> resultado = multiplicar_matriz_vector(H, palabra);
            
                    // Mostrar el resultado
                    cout << "Resultado de H * palabra: ";
                    for (int bit : resultado) {
                        cout << bit;
                    }
                    cout << endl;
                }
        }  cout << "\n Ingrese la opcion , la misma para continuar esta\n";
        cin>>opcion_mat;
    }   
    
}
    


    
    



int main() {
    while (true) {
        int opcion;
        cout << "\nSelecciona una opción:\n";
        cout << "1. Determinar el tercer término\n";
        cout << "2. Calcular la probabilidad de errores\n";
        cout << "3. Por repeticion\n";
        cout << "4. Distancia minima\n";
        cout << "5. Matriz generadora\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            opcion1();
        } else if (opcion == 2) {
            opcion2();
        } else if (opcion == 3) {
            opcion3();

        } else if (opcion == 4) {
            opcion4();
            
        } else if (opcion == 5) {
            opcion5();


        } else {
            cout << "Opción inválida. Intente nuevamente.\n";
        }
    }
}
