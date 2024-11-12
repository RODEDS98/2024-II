#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// FunciC3n para calcular el mC!ximo comC:n divisor (mcd)
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// FunciC3n para exponenciaciC3n modular
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

// FunciC3n para encontrar el inverso modular de d respecto a phi
int modInverse(int d, int phi) {
	for (int x = 1; x < phi; x++) {
		if ((d * x) % phi == 1)
			return x;
	}
	return -1; // No hay inverso modular si se retorna -1
}

// FunciC3n para convertir un mensaje en texto al formato "libro"
string textoAModoLibro(const string& mensaje) {
	string resultado;
	for (char c : mensaje) {
		if (c >= 'A' && c <= 'Z') {
			int valor = c - 'A';
			if (valor < 10) resultado += "0";
			resultado += to_string(valor);
		} else {
			cout << "Mensaje no vC!lido. Solo se permiten letras mayC:sculas sin C.\n";
			exit(1);
		}
	}
	return resultado;
}

// FunciC3n para cifrar en modo "Libro"
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

// FunciC3n para descifrar nC:meros en modo libro y convertirlos a letras
void descifrarModoLibro(int p, int q, int d, const string& mensaje) {
	int n = p * q;
	cout << "Mensaje descifrado en modo libro (nC:meros): ";
	string mensajeNumerico;

	for (size_t i = 0; i < mensaje.length(); i += 4) {
		string bloque = mensaje.substr(i, 4);
		int numero = stoi(bloque);
		int descifrado = modExp(numero, d, n);

		// Asegurarse de que el bloque descifrado tenga 4 dC-gitos
		if (descifrado < 1000) {
			mensajeNumerico += string(4 - to_string(descifrado).length(), '0') + to_string(descifrado);
		} else {
			mensajeNumerico += to_string(descifrado);
		}
		cout << descifrado << " ";
	}

	// Convertir nC:meros descifrados a letras
	cout << "\nMensaje descifrado en modo libro (texto): ";
	for (size_t i = 0; i < mensajeNumerico.length(); i += 2) {
		int numero = stoi(mensajeNumerico.substr(i, 2));
		char letra = 'A' + numero;
		cout << letra;
	}
	cout << endl;
}

// FunciC3n para cifrar en modo ASCII
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

// FunciC3n para descifrar en modo ASCII
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

bool es_primo(int numero) {
    if (numero <= 1) {
        return false; // Números menores o iguales a 1 no son primos
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false; // Si encontramos un divisor, no es primo
        }
    }
    return true; // No se encontraron divisores, es primo
}

void descomponer(int numero, int factores[], int& cantidad_factores) {
    cantidad_factores = 0; // Inicializamos el contador de factores

    // Comenzamos con el número 2 (el primer primo)
    for (int i = 2; i <= numero; i++) {
        // Mientras i sea divisor de numero, lo agregamos al array y dividimos
        while (numero % i == 0 && es_primo(i)) {
            factores[cantidad_factores] = i; // Añadimos el factor primo al array
            cantidad_factores++; // Incrementamos la cantidad de factores
            numero /= i; // Dividimos el número por i
        }
    }
}

int main() {
	int p, q, e, d, opcion, opcionModo;
    int factores[100]; // Array para almacenar los factores primos
    int cantidad_factores = 0; // Contador para la cantidad de factores encontrados
    
	string mensaje;
	cout<<" 1819"<<endl;
	int abc;
	abc=modExp(1819, 109, 551);
	cout<<abc <<endl;
	cout<<" 1415"<<endl;
	int cda;
	cda=modExp(1415, 473, 551);
	cout<<cda <<endl;
	cout<<endl;


	// ElecciC3n entre cifrar y descifrar
	cout << "Seleccione una opciC3n:\n0. Es primo? \n1. Descomponer numero \n2.Valores para (e) \n3. Exponenciacion modular \n4. Cifrar\n5. Descifrar\n";
	cin >> opcion;
    
    if (opcion == 0) { // Es primo?
        int num;
        cout << "Ingrese el numero para saber si es primo o no :" <<endl;
        cin>>num;
        bool cond= es_primo(num);
        cond?cout<<"Es primo":cout<<"No es primo"  ;
	}
	
	else if (opcion == 1) { // Descomponer?

        int num;
        cout << "Ingrese el numero a descomponer :" <<endl;         
        cin>>num;
        descomponer(num, factores, cantidad_factores);
        
        for (int i = 0; i < cantidad_factores; i++) {
            cout << factores[i] << " ";
        }

	}
	
	else if (opcion == 2) { // Numero de posibles valores para (e) .
	    int clave;
        cout << "Ingrese la clave para descomponer :" <<endl;         
        cin>>clave;
	    descomponer(clave, factores, cantidad_factores);
	    cout<<endl; 
	    cout << "Los factores de la clave son :" <<endl; 
	    for (int i = 0; i < cantidad_factores; i++) {
            cout << factores[i] << " ";
        }
        cout<<endl;
	    cout << "Hallando phi :" <<endl; 
	    
        int numer=0;
        int phi= (factores[0]-1)*(factores[1]-1);
        cout << "phi : "<<phi<<endl;
        
	    cout<<endl; 
	    cout << "Los valores posibles para la clave (coprimos) son :" <<endl;         
        
        int contador_coprimos=1;
        
        for (int j = 0; j <clave; j++) {
            if ( es_primo(j) && gcd(j, phi) == 1) {
                cout << j << " ";
                contador_coprimos++;
            }
        }
        
        cout<<endl; 
        cout << "La cantidad de valores disponibles para e son :" <<endl; 
	    cout<< " ==>\t\t\t"<< contador_coprimos <<endl;   
	    
        cout<<endl; 
        cout << "Ingrese el valor a analizar para (e):" <<endl;
        while(numer>=0){
            cin >> numer;
            if (gcd(numer, phi) == 1) {
                cout << "En numero "<<numer <<" y "<<phi<<" (SI)  SON COPRIMOS"<<endl;
            }
            else{
                cout << "En numero "<<numer <<" y "<<phi<<" (NO)  SON COPRIMOS"<<endl;
            }
        
        }
	}
       
	else if (opcion == 3) { // Sacar exponenciacion modular.
		int M;
		int base;
		int n;
        cout << "Ingrese la base :" <<endl;
        cin >> base;
		cout << "Ingrese (e) o (d) :" <<endl;
		cin >> e;
		cout << "Ingrese (n) :" <<endl;
		cin >> n;
		M = modExp(base, e, n);
		cout << "El valor de M es :"<< M <<endl;
	}

	else if (opcion == 4) {
		// CIFRAR
		cout << "Ingrese los valores de p y q (nC:meros primos): ";
		cin >> p >> q;
		int phi = (p - 1) * (q - 1);

		do {
			cout << "Ingrese el valor de e (coprimo con (p-1)*(q-1)): ";
			cin >> e;
			if (gcd(e, phi) != 1) {
				cout << "El valor de e no es coprimo con phi(n). Elija otro valor.\n";
			}
		} while (gcd(e, phi) != 1); // Repetir hasta que e sea vC!lido

		cout << "Seleccione el modo de cifrado:\n1. Modo Libro\n2. Modo ASCII\n";
		cin >> opcionModo;

		if (opcionModo == 1) {
			cout << "Ingrese el mensaje a cifrar (solo letras mayC:sculas, sin C): ";
			cin >> mensaje;
			cifrarModoLibro(p, q, e, mensaje);
		} else if (opcionModo == 2) {
			cout << "Ingrese el mensaje a cifrar (caracteres ASCII permitidos): ";
			cin >> mensaje;
			cifrarModoASCII(p, q, e, mensaje);
		} else {
			cout << "OpciC3n invC!lida.\n";
		}
	} else if (opcion == 5) {
		// DESCIFRAR
		cout << "Ingrese los valores de p, q y d: ";
		cin >> p >> q >> d;
		int phi = (p - 1) * (q - 1);

		// CC!lculo del inverso de d para verificar si coincide con e
		int inversoDeD = modInverse(d, phi);
		if (inversoDeD == -1) {
			cout << "Error: No se encontrC3 un inverso modular vC!lido para d.\n";
			return 1;
		} else {
			cout << "El valor de e calculado a partir de d es: " << inversoDeD << endl;
		}

		cout << "Seleccione el modo de descifrado:\n1. Modo Libro\n2. Modo ASCII\n";
		cin >> opcionModo;

		if (opcionModo == 1) {
			cout << "Ingrese el mensaje a descifrar (bloques de 4 dC-gitos): ";
			cin >> mensaje;
			descifrarModoLibro(p, q, d, mensaje);
		} else if (opcionModo == 2) {
			cout << "Ingrese el mensaje a descifrar (valores cifrados separados por espacios): ";
			cin.ignore(); // Limpiar el buffer
			getline(cin, mensaje);
			descifrarModoASCII(p, q, d, mensaje);
		} else {
			cout << "OpciC3n invC!lida.\n";
		}
	} else {
		cout << "OpciC3n invC!lida. Elija 1 o 2.\n";
	}

	return 0;
}
