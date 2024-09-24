#include <iostream>
using namespace std;

//funcion para imprimir
void imprimir(int* arr, size_t t){
    for (int* i=arr; i< arr+t; i++) {
        cout << *i << ", ";
    }
    cout <<endl;

}

void split(int* p, int* q, int* arr, size_t t) {      //      p                             q            
                                  //      0  1  2  3  4     5  6  7  8  9
                                    //   10 11 12 13 14    15 16 17 18 19
	while(q!=(p+((q-p+1)/2)-1)){                
		for (int* i = p; i < q-1; i++) {   
			if  ((*i)%2!=0 && *(i+1)%2==0)  {
				int tmp = *(i+1);
				*(i+1) = *i;
				*i = tmp;
			}
            //imprimir(arr,t);
		}
        //cout <<endl;
		q--;
	}
}




// Funcion para contar los pares  (solo para verificacion)
int count_par_impar(int* A, size_t t) {  // contar cuantos pares tiene el arreglo
	int pares = 0;
	for (int* p = A; p < (A + t); p++) {
		*p % 2 == 0 ? pares++ : pares = pares;
	}
	return pares;
}


int main() {
    
    int Arr_1[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    //int Arr_1[] = { 0,1,2,3,4 ,5,6,7,8,9 };
    
    //generalizacion del tamaño
    size_t tam = sizeof(Arr_1);
    tam= tam/4;
    //int mitad=tam/2;
    cout<<"verificando tamano: "<<tam<<endl;
    cout<<"verificando pares: "<<count_par_impar(Arr_1,tam)<<endl<<endl;
    
    cout <<"array original"<<endl; //Array original
    imprimir(Arr_1,tam);
    cout <<endl;
    
    cout <<"reagrupando (Split)"<<endl; //Array ordenado
    split(Arr_1,Arr_1 + tam,Arr_1,tam);
    imprimir(Arr_1,tam);
}
