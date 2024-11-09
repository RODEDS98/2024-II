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

/*
merge(nodo *&head1,nodo *&head2){
    int i,j=0;
    bool start=true;
    while(start){
        if(head1->valor==head2->valor){
            nodo *temp=head2;
            head2->next
        }
    }
}*/  
    
//    {13,17,19,21,28};
void ArrayToLe(int *begin,int *end,nodo *&head){ //crea una serie de estructuras para cada elemento
    
    for(int* i=end ;i>=begin ; i--){  // recorre de forma inversa la lista
        head=new nodo(*i,head);       // ingresa (*i):cada elemento y (head):
        //    objeto1 =   objeto2(*i,head);
        //couthead.valor
        cout<<*i<<" ";
        cout<<head<<endl;
    }                                 // reemplaza/crea los valores con su mismo
    
    /*
    nodo *temp;
    for(int *i=begin, i<=end ; i++){
        if(!head){
            head=new nodo(*i);
            temp=head;
        }
        else{
            temp->next=new nodo(*i);
            temp=temp->next;
        }
    }
    */
}


void print(nodo *head){
    cout<< "HEAD ->" ;
    for(nodo* p=head; p; p=p->next){
        cout<< p->valor<< "->";
    }
    cout<<"NULL"<<endl;
}


void func(int *p , int* R){
    p = R;  // no se modifica en el main porque p y R son copias
            //de los punteros pasados por parametro
}


void func2(int* &q , int* &R){   //  q=f100  R=f200     aa,*q => 10  bb,*R  => 20 
    q = R;    //  q=f200  R=f200
    // teoria es que al modificar...
    *q=0;      //*R, bb  => 0 
    *R=*R+1;  //*R, bb  => 1 
    // se perdio el puntero hacia aa, entonces no se puede modificar
}

int main()
{
    
    nodo *head1=nullptr;
    nodo *head2=nullptr;
    
    int A[] = {13,17,19,21,28};
    int B[] = {11,14,17,18,19,22,24,27};
    
    cout<<endl;
    cout<<"Imprimiendo direcciones de nodo"<<endl;
    cout<<"head1: " << head1 <<endl;
    cout<<"head2: " << head2 <<endl;
    cout<<endl;
    cout<<"& head1: " << &head1 <<endl;
    cout<<"& head2: " << &head2 <<endl;
    cout<<endl;
    cout<<"& head1: " << *&head1 <<endl;
    cout<<"& head2: " << *&head2 <<endl;
    cout<<endl;
    
    ArrayToLe(A,A+5,head1);
    cout<<endl;
    ArrayToLe(B,B+8,head2);
    
    cout<<endl;
    
    
    print(head1);
    print(head2);
    cout<<endl;cout<<endl;
    
    int aa=10;
    int bb=20;
    int* jj= &aa;
    int* kk= &bb;
    
    cout<<jj <<endl;
    cout<<kk <<endl;
    
    cout<<endl;cout<<endl;
    
    func(jj , kk);
    cout<<"( * : ) " <<endl;

    cout<<jj <<aa<<endl;
    cout<<kk <<bb<<endl;
    
    func2(jj , kk);
    
    cout<<endl;
    cout<<aa<<endl;
    cout<<bb<<endl;
    cout<<"( *& : ) " <<endl;
    cout<<jj<<" "<<aa <<endl;
    cout<<kk<<" "<<bb <<endl;
    
    cout<<endl;cout<<endl;
    
    return 0;
}
