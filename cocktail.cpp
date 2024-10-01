#include <iostream>
using namespace std;

//funcion para imprimir
void imprimir(int* arr, size_t t){
    for (int* i=arr; i< arr+t; i++) {
        cout << *i << ", ";
    }
    cout <<endl;

}// i                   q
//  0  2   4  6  8 9 xxxx//   0 2 4 5 6 7 1 3   
void cocktail(int* p, int* q) { //,int* arr, size_t t
    
    int* temp_mitad= p+ (q-p)/2;
    temp_mitad++;
    int tmp_p_anterior = *p;
    
	while(p<q){ 
	    
		for (int* i = p; i < q; i++) {  
		    if (*(i+1)<*i){
		        int tmp_p=*i;
			    *i = *(i+1);
			    *(i+1)=tmp_p;
			    //imprimir( arr, t);
			}
		}
		cout<<endl;
		//imprimir( arr, t);
		q--;

	} 
		//cout<<endl;
}


// Funcion para contar los pares  (solo para verificacion)
int count_par_impar(int* A, size_t t) {  // contar cuantos pares tiene el arreglo
	int pares = 0;
	for (int* p = A; p < (A + t); p++) {
		*p % 2 == 0 ? pares++ : pares = pares;
	}
	return pares;  }


int main() {
    
    //int Arr_1[] = { 2,3,1,4,6    ,5,7,0,8,9, };
    int Arr_1[] = { 10,9,8,7,6,  5,4,3,2,1 };
    
    //generalizacion del tamaño
    size_t tam = sizeof(Arr_1);
    tam= tam/4;
    //int mitad=tam/2;
    cout<<"verificando tamano: "<<tam<<endl;
    cout<<"verificando pares: "<<count_par_impar(Arr_1,tam)<<endl<<endl;
    
    cout <<"array original"<<endl; //Array original
    imprimir(Arr_1,tam);
    cout <<tam<<endl;
    
    cout <<"ordenando (cocktail)"<<endl; //Array ordenado
    cocktail(Arr_1,Arr_1 + tam-1);  //,Arr_1, tam
    imprimir(Arr_1,tam);
}
