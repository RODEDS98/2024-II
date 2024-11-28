#include <iostream>
using namespace std;


struct asc {  //  1 2 (3) 4 5
    bool operator()(int a, int b) {
        return a < b;
    }
};

struct desc {    //    5 4 (3) 2 1
    bool operator()(int a, int b) {
        return a > b;
    }
};


template<class Sntdo,class T>
struct Pivot { // pivote
    int piv;
    Sntdo snt;
    Pivot(int x):piv(x){}
    
    Pivot& operator=(T a) {
        piv = a;
        return *this;
    }
    
    void operator()(T* A,T* B){
        T* p=A;
        T* q=B;
        cout<<*p<<endl;
        cout<<*q<<endl;
        while(q>p){
            //cout<<"1er if"<<endl;
            
            if(snt(*p , piv)){ //cout<<piv<<" < "<< *i <<endl;
               // cout<<"1er if"<<endl;
                p++;
                continue;
            }
            if(snt(piv ,*q)){
                //cout<<"1er if"<<endl;
                q--;
                continue;
            }
            else{
                //cout<<"1er if"<<endl;
                int tmp=*p;
                *p=*q;
                *q=tmp;
            }
        }   
    }
};

template <class T>
void print(T* A, T tam){
    for(int* i=A;i<A+tam;i++){
        cout<< *i <<" ";
    }
    cout<<endl;
}



int main(){
    
    int A[] = {10,9,7,42,1,100};
    
    int tam = sizeof(A)/sizeof(A[0]);
    
    cout<<tam<<endl;
    print<int>(A,tam);
    Pivot<desc,int> Piv(42);
    Piv(A,A+tam-1);
    print<int>(A,tam);
    return 0;
}
