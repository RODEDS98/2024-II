#include <iostream>
using namespace std;

void imprimir(int* arr, size_t t){
    for (int* i=arr; i< arr+t; i++) {
        cout << *i << ", ";
    }
    cout <<endl;
    cout <<endl;
}

void merge(int* p, int* q) {     
	int* posfin =q+(q - p);  
	
	while(p!=q && q<posfin){ 
	    
	    if ( *p > *q) {
	        int tmp_q=*q;
    		for (int* i = q; i > p; i--) { 
                *i=*(i-1);
			}
			*p=tmp_q;
			q++;
		}//imprimir(arr,t);
		p++;

	}
}


//funcion para imprimir


// Funcion para contar los pares  (solo para verificacion)
int count_par_impar(int* A, size_t t) {  // contar cuantos pares tiene el arreglo
	int pares = 0;
	for (int* p = A; p < (A + t); p++) {
		*p % 2 == 0 ? pares++ : pares = pares;
	}
	return pares;
}


int main() {
    
    //int Arr_1[] = { 0,2,4,6,8,10,12,14,1,3,5,7,9,11,13,15 };
    int Arr_1[] = { 2,4,6,8,1,3,5,7 };
    
    //generalizacion del tamaño
    size_t tam = sizeof(Arr_1);
    tam= tam/4;
    int mitad=tam/2;
    cout<<"verificando tamaño: "<<tam<<endl;
    cout<<"verificando pares: "<<count_par_impar(Arr_1,tam)<<endl<<endl;
    
    cout <<"array original"<<endl; //Array original
    imprimir(Arr_1,tam);
    
    cout <<"array ordenado (Merge)"<<endl; //Array ordenado
    merge(Arr_1,Arr_1 + mitad);
    imprimir(Arr_1,tam);
}
