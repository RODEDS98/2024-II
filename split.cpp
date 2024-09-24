#include <iostream>
using namespace std;

//funcion para imprimir
void imprimir(int* arr, size_t t){
    for (int* i=arr; i< arr+t; i++) {
        cout << *i << ", ";
    }
    cout <<endl;

}
//     0 1? 2 3  4 5 6* 7     0 2 3?  4 5 6 1 7    0 2  4 5? 6  3 1 7    0 2  4  6  3 1 7              2468 1357    12(4)6 8(3)57     1234 6857
void split(int* p, int* q,int* arr, size_t t) {   
    int temp_rango= q-p;
    cout<<temp_rango<<endl;
    int j=0;
	while(q>p){     
	    
		if  ((*p)%2!=0 && (*q)%2==0 )  {
		    //cout <<"x"<<endl;
			int tmp_p = *p;	
			
			for (int* i = p; i < q; i++) {  				
				*i = *(i+1);
				
			}
			
			//*(q+())=tmp_p;        //0    1 2 3 4 5
			*(q+j)=tmp_p;        //0    1 2 3 4 5
			//*q=tmp_p;

			
			imprimir( arr, t);
			//cout<<q-p<<endl;
		}

    		p++;
		    q--;
		} 
		
		cout<<endl;

		j++;
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
    
    //int Arr_1[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    int Arr_1[] = { 0,1,2,3,4 ,5,6,7,8,9 };
    
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
    split(Arr_1,Arr_1 + tam-1,Arr_1, tam);
    imprimir(Arr_1,tam);
}
