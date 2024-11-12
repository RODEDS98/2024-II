
// Analizando el comportamiento del nodo con template
//se realizaron diferentes instancias y punteros a nodo
#include <iostream>
using namespace std;

template <class T>
class nodo {
    public:
        T valor;
        nodo* next;
        
        nodo(T v, nodo* n = nullptr) {
            valor = v;
            next = n;
        }
};

template <class T>
class LE {
    public:
    nodo<T>* head=nullptr;
    
        void print();
        bool find(T v,nodo<T>* &pos);
        void add(T v);
        //void del(T v);
        //~LE();
};

template <class T>
void LE<T>::print(){
    cout<<"Head ->";
    for(nodo<T>* p=head; p ;p=p->next){
        cout<<p->valor<<"->";
    }
    cout<<"Nullptr"<<endl;;
}

template <class T>
bool LE<T>::find(T v,nodo<T>* &pos){
    pos=nullptr;   // 1 2 3  5           // 4
    for(nodo<T>* p=head ; p && (p->valor)<=v ;p=p->next){
        if(p->valor == v){
            return true;
        }
        pos=p; // si lo encuentra no actualiza por el return y guarda la pos anterior
    }
    return false;  //si no lo encuentra y no llega hasta el final por ser (p->valor) <= v
                   //entonces pos tomara el valor del anterior tambien
}                  //si no lo encuentra y va hasta el final del for pues p habria
                   //sido nillptr y se guardaria en pos.   
                   
template <class T>
void LE<T>::add(T v){

    nodo<T>* posicion_anterior=nullptr;
    nodo<T>* r=nullptr;
    bool busqueda = find(v,posicion_anterior);

    if(busqueda){                  //          r
        //r=posicion_anterior->next; //  s{,q}   q{v,}   // r=q                   add (V )
        //posicion_anterior->next= new nodo<T>(v,r); //  s{,h}   q{v,}       new ( h {V,q} )
        posicion_anterior->next= new nodo<T>(v,posicion_anterior->next);
    }                                               //  s{,h}  h{V,q}  q{v,} 
    else{  //  (!busqueda)
        if (posicion_anterior==nullptr){ head = new nodo<T>(v,head); }  // si el numero no se encontro ni en la cabeza
        
        else{
            if (posicion_anterior->next==nullptr){ // si pos_ant ==
            posicion_anterior->next= new nodo<T>(v,posicion_anterior->next);
            }
            else{
    
                posicion_anterior->next =new nodo<T>(v,posicion_anterior->next);
            }
        }

    }
}

//template <class T>
//void LE<T>::del(){
    
//}

int main() {
    
    // Probando intancias con nodo
    nodo<int> unnodo(5, nullptr);   // Declaración de un nodo con tipo int
    nodo<int> unnodo2(10, nullptr); // Otra declaración con tipo int
    nodo<int>* a = &unnodo;   // Puntero al nodo 'unnodo'
    nodo<int>* b = &unnodo2;  // Puntero al nodo 'unnodo2'
    nodo<int>* A = nullptr;
    nodo<int>* B = nullptr;
    A = new nodo<int>(6, nullptr);   // Puntero al nodo 'unnodo'
    B = new nodo<int>(7, nullptr);  // Puntero al nodo 'unnodo2'
    cout << "Valor de unnodo:  "  << a -> valor << endl;
    cout << "Valor de unnodo2: "  << b -> valor << endl;
    cout << "Valor de unnodo:  "  << A -> valor << endl;
    cout << "Valor de unnodo2: "  << B -> valor << endl;
    
    // Probando intancias con LE
    LE<int> lista;
    
    lista.print();
    //lista.add(5);
    
    nodo<int>* c = nullptr;
    cout<<endl;
    lista.add(5);
    lista.print();
    lista.add(3);
    lista.print();
    lista.add(4);
    lista.print();
    lista.add(9);
    lista.print();
    lista.add(1);
    lista.print();
    lista.add(3);
    lista.print();
    lista.add(5);
    lista.print();
    cout<<"ingresando valores prohibidos"<<endl;
    lista.add(1);
    lista.print();
    

    
    return 0;
    
}
