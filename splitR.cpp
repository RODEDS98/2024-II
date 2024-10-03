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
void split(int* p, int* q) { //,int* arr, size_t t
    
    int* temp_mitad= p+ (q-p)/2;
    temp_mitad++;
    int tmp_p_anterior = *p;
    
	while(p<temp_mitad){ 
	    
	    int tmp_p = *p;
		if  ((*p)%2!=0 && tmp_p_anterior<=tmp_p )  {  //si el pivote es impar
			for (int* i = p; i < q; i++) {  	     // y el anterior era menor			
				*i = *(i+1);                  // que el nuevo siendo analizando
				//imprimir( arr, t);
			}
			*q=tmp_p;
		}
		    			
			//imprimir( arr, t);
			//cout<<endl;
    	p++;
    	tmp_p_anterior=tmp_p;
		} 
		//cout<<endl;
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
    
    //int Arr_1[] = { 1,2,3,4,5,6,7,8   ,9,10,11,12,13,14,15,16 };
    int Arr_1[] = { 0,1,2,3,4   ,5,6,7,8,9 };
    
    //generalizacion del tamaño
    size_t tam = sizeof(Arr_1);
    tam= tam/4;
    //int mitad=tam/2;
    cout<<"verificando tamano: "<<tam<<endl;
    cout<<"verificando pares: "<<count_par_impar(Arr_1,tam)<<endl<<endl;
    
    cout <<"array original"<<endl; //Array original
    imprimir(Arr_1,tam);
    cout <<tam<<endl;
    
    cout <<"reagrupando (Split)"<<endl; //Array ordenado
    split(Arr_1,Arr_1 + tam-1);  //,Arr_1, tam
    imprimir(Arr_1,tam);
}
