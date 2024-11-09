#include <iostream>
using namespace std;

struct nodo{  
    
    int valor;
    nodo* next;
    
    nodo(int v,nodo* n=nullptr ){    // ingresas el valor de cada v
        valor=v;                     // y un puntero del siguiente elemento
        next=n;
    };
};

//    {13,17,19,21,28};
void ArrayToLe(int *begin,int *end,nodo *&head){ //crea una serie de estructuras para cada elemento
    
    for(int* i=end ;i>=begin ; i--){  // recorre de forma inversa la lista
        head=new nodo(*i,head);       // ingresa (*i):cada elemento y (head):
    }   // reemplaza/crea los valores con su mismo
}


void print(nodo *head){
    cout<< "HEAD ->" ;
    for(nodo* p=head; p; p=p->next){
        cout<< p->valor<< "->";
    }
    cout<<"NULL"<<endl;
}

void merge(nodo* &A,nodo* &B){
    cout<<"creacion de punteros"<<endl;
    nodo* p= A;
    nodo* q= B;
    nodo* r= nullptr;
    
    if(p->valor < q->valor){  //   (p)  <   (q)

        if((p->next)->valor < q->valor){    //   (p) < (p+1)  <  (q)
            A=p;       // La cabeza de A se iguala al menor
            p=p->next; // se mueve p al siguiente elemento.
        }
        else{                   //   (p) < (q) < (p+1)
            A=p;        // la cabeza es p, el menor.
            r=p->next;  // guardamos el siguiente elemento de la lista A , ya q la cambiaremos.
            p->next=q;  // cambiamos el elemento siguiente, "q" cabeza de B se pierde
            q=r;        // la nueva q , cabeza sera la continuacion de lo que era la lista A
            p=p->next;   // nos movemos 2 posiciones
        }    
    }
    else{   //   (q)  <   (p)
        //cout<<p->valor <<" v "<<q->valor <<endl;
        
        if((q->next)->valor < p->valor){    //   (q) < (q+1)  <  (p)
            
            A=q;
            q=q->next;
            

        }
        else{   //   (q)   <  (p)  < (q+1)

            A=q;
            r=q->next;  //en enlace de q se quedara roto, se guarda en r su siguiente elemento
            q->next=p;  //se rompe el enlace de q y se lo enlaza con p.
            p=r;        //la cabeza de p ahora sera la continuacion de q, que estaba sin cabeza
            q=q->next;   // nos movemos 2 posiciones
            
        }
    } 
    

    cout<<endl;
    cout<<" CONDICIONAL"<<endl;
    cout<<(p && q) <<endl;
    cout<<"p ";
    print(p);
    cout<<"q ";
    print(q);cout<<endl;
    cout<<"CABEZA ";print(A);cout<<endl;
    cout<<"WHILE "<<endl;
    cout<<(p->next) <<" if "<<(p->next) <<endl;
    while(p && q){   //  p= 14  q = 13 
        cout<<"iteracion "<<endl;
        if((p->next)==nullptr && (q->next)==nullptr){
            if(p->valor < q->valor){    //  p < q 
                p->next=q;
                break;
            }
            else{                   //  p < q 
                q->next=p;
                break;
            }

        }

        if(p->valor < q->valor ){  //   (p)  <   (q)
            cout<<p->valor <<" ifx "<<q->valor <<endl;
            if((p->next)==nullptr){ p->next=q; break;}
            if((p->next)->valor < q->valor  ){    //   (p) < (p+1)  <  (q)
                    
                p=p->next; // se mueve p al siguiente elemento.
                cout<<"p->next ifo ";
                cout<<endl;
                
            }
            else{                   //   (p) < (q) < (p+1)
                r=p->next;  // guardamos el siguiente elemento de la lista A , ya q la cambiaremos.
                p->next=q;  // cambiamos el elemento siguiente, "q" cabeza de B se pierde
                q=r;        // la nueva q , cabeza sera la continuacion de lo que era la lista A
                cout<<"cambio "<<endl;;
                cout<<"p ";
                print(p);
                cout<<"q ";
                print(q);
                
                p=p->next;   // nos movemos 2 posiciones
                cout<<"p->next ";
                cout<<endl;
                    
            }
        }     
        
        else{   //   (q)  <   (p)
            cout<<p->valor <<" else "<<q->valor <<endl;
            if((q->next)==nullptr){ q->next=p;break;   }
            if((q->next)->valor < p->valor){    //   (q) < (q+1)  <  (p)
                    
                q=q->next;
                cout<<"q->next ";
                cout<<endl;
                    
            }
            else{   //   (q)   <  (p)  < (q+1)
                r=q->next;  //en enlace de q se quedara roto, se guarda en r su siguiente elemento
                q->next=p;  //se rompe el enlace de q y se lo enlaza con p.
                p=r;        //la cabeza de p ahora sera la continuacion de q, que estaba sin cabeza
                cout<<"cambio "<<endl;;
                cout<<"p ";
                print(p);
                cout<<"q ";
                print(q);
                    
                q=q->next;   // nos movemos 2 posiciones
                cout<<"q->next ";
                cout<<endl;
                    
            }
        }
         
        cout<<endl;
        cout<<p->valor <<" fin while "<<q->valor <<endl;
                        cout<<"p ";
                print(p);
                cout<<"q ";
                print(q);
                cout<<"CABEZA ";print(A);cout<<endl;
        cout<<endl;
    }
    cout<<endl;
    cout<<"termina el while ";print(A);cout<<endl;
}



int main()
{
    
    nodo *head1=nullptr;
    nodo *head2=nullptr;
    
    //int A[] = {13,15,19,21,28};
    //int B[] = {11,14,17,18,20,22,24,27};

    int A[] = {11,12,13,14,15,20,55,70};
    int B[] = {1,2,3,4,5,6,7,8,100};

    int tamA=sizeof(A)/4;
    int tamB=sizeof(B)/4;

    ArrayToLe(A,A+tamA-1,head1);
    ArrayToLe(B,B+tamB-1,head2);

    print(head1);
    print(head2);
    cout<<endl;cout<<endl;
    cout<<"main "<<endl;
    merge(head1,head2);
    
    cout<<"main "<<endl;
    print(head1);
    //print(head2);
    
    cout<<endl;cout<<endl;

    return 0;
}
