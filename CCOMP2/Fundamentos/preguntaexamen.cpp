#include <iostream>
using namespace std;
int main()
{
    //char arr[3][1][]= {{"hola"},{"caja"},{"rana"}} ;
    int A[2][3][5]= {{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}},
                     {{30,30,30,30,30},{30,30,30,30,30},{30,30,30,30,31}}};
    
    for(int(* i)[3][5]=A ; i<A+2 ; i++ ){  //pregunta, redescubrir porque  *
        for(int(* j)[5]=*i ; j<*i+3 ; j++ ){
            for(int(* k)=*j ; k<*j+5 ; k++ ){
                cout<<*k<<" ";
            }
        }
    }
    cout<<endl;
    cout<<endl;     //p<*(*A+1)
    cout<<endl;     //p<(**A+1)
    for(int* p=**A ; p<**(A+2) ; p++ ){  // se crea el puntero que accede a la capa mas interna
        cout<<*p<<" ";                   // esto se logro con **A ya que es bidimensional
    }                                    // el limite es hasta el fin del array **(A+1)   [{A+0}{}{}       
                                         //                                                {A+1}{}{}] 
                                         //                                               A+2          
                                         // Entonces (A+2) te permitira moverte al mismo espacio de **(A+2)
                            // pero con el primero te moveras cada 3x5x4bits pero con **(a+2) aparte de que
                                                                                                
    cout<<"IMPRIMIR LETRA POR LETRA CON UN SOLO FOR"<<endl;
    cout<<endl;
    cout<<endl;
    char MATCAD[3][10]= {"ABCABCABC","CDFCDFCDF","HIJHIJHIJ"};
    int MATTAM = 3;
    for(char(* p)[10] = MATCAD ; p< (MATCAD+MATTAM) ; p++ ){
        cout<<*p;
    }
    cout<<endl;
    cout<<endl;
    for(char(* q) = *MATCAD ; q< *(MATCAD+MATTAM) ; q++ ){
        cout<<*q;
    }
    cout<<endl;
    cout<<endl;
    
    int a[2][3]={{1,2,3},{4,5,6}};
    for(int(* i)=*a ; i<*(a+2) ; i++ ){
        cout<<*i<<" ";
    }
    
    char b[3][5]= {"Hugo","Paco","Luis"};
    cout<<endl;
    cout<<endl;
    for(char(* p) = *b ; p < *(b+3) ; p++ ){
        cout<<*p<<" ";
    }
    cout<<endl;
    cout<<endl;
    for(char(* p) = (char *)b ; p <= &b[2][4] ; p++ ){
        cout<<p<<" ";
    }
    return 0;
    
    
}