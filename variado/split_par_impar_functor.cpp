#include <iostream>
using namespace std;

template<class T>
struct nodo{
    T valor;
    nodo<T>* next = nullptr;
    nodo(T x,nodo<T>* y):valor(x),next(y){}
};

class par{
    public:
        bool operator()(int b){
            return !(b % 2);
        }    
};

class tres{
    public:
        bool operator()(int b){
            return !(b % 3);
        }    
};


void listar(int* A,int* B, nodo<int>* &head){
    /*pila
    for(int* i = B ; i>=A ; i--){
        head  = new nodo<int>(*i,head); 
        cout<<*i<<" ";
    }
    cout<<endl;
    */
    //cola
    int* i=A;
    head  = new nodo<int>(*i,head);
    i++; nodo<int>* p=head;
    for( ; i<B ; i++){
        p->next  = new nodo<int>(*i,nullptr);
        p=p->next;
    }
}

template<class T>
void split(nodo<int>* &ListaA , nodo<int>* &ListaB, T criterio){
    
    nodo<int>* p=ListaA;
    nodo<int>* q=ListaB;
    nodo<int>* r=nullptr;
    while(p){
        if(criterio(p->valor)){
            r->next=p->next;
            q->next  =  p;
            q->next->next=nullptr;
            p=r->next;
        }
        else{
            r=p;
            p=p->next;
        }
    }
        
};

void print(int*A, int*B){
    for(int* i=A; i<B ; i++){
        cout<<*i <<" ";
    }
     cout<<endl;
}

int main(){
    int A[]= {1,2,3,5,4,8,9,11,33};
    int tam= sizeof(A)/sizeof(A[0]);

    
    print(A,A+tam);
    
    nodo<int>* head= nullptr;
    nodo<int>* head2= nullptr;

    listar(A,A+tam-1,head);
    cout<<"S"<<endl;
    split(head,head2,par() );
    cout<<"S"<<endl;
    print(A,A+tam);
    return 0;

}