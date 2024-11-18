// Analizando el comportamiento del nodo con template
//se realizaron diferentes instancias y punteros a nodo
#include <iostream>
using namespace std;

template <class T>
struct nodo {
    public:
        T valor;
        nodo* next;
        nodo(T valor,nodo* next=nullptr){
            this->valor=valor;
            this->next=next;
        }
        //nodo(T valor,nodo* next=nullptr):valor(valor),next(next){ }
};

template <class T>
struct LEC {
    public:
    nodo<T>* head=nullptr;
    
    void print();
    bool find(T v,nodo<T>* &pos);
    void find_cola(nodo<T>* &cola);
    void add(T v);
    void del(T v);
    ~LEC();
};

template <class T>
void LEC<T>::print(){
    
    nodo<T>* primer_valor = head;
    if(head){
        cout<<head->valor;
        cout<<"->"; 
        for(nodo<T>* p= (head->next) ;  p!=head ; p=p->next){
            cout<<p->valor;
            cout<<"->"; 
        }
    }
    cout<<endl;
}

template <class T>
bool LEC<T>::find(T v,nodo<T>* &pos){
    pos=nullptr;                        // 1 2 3  4          // 3
    nodo<T>* primer_valor = head;

    if(head){
        if(head->valor==v){  // hecho para que aun si hay un unico elemento retornara true
            return true; // post anterior sera null, se declara en add
        }
        else if(head->valor > v){  // hecho para que aun si hay un unico elemento retornara true
            return false; // post anterior sera null, se declara en add
        }
        else{   //condicion de stop por final de lista     //condicion por encontrar valor
            pos=head;  //al pasar al else, ya se evaluo el primer nodo, entonces se le pasa el de la cabeza
            for(nodo<T>* p=(head->next) ;p!=head && (p->valor <= v) ; p=p->next){
 
                if(p->valor == v){
                    return true;
                }
                pos=p; // si lo encuentra no actualiza por el return y guarda la pos anterior
            }
            return false;  //si no lo encuentra y no llega hasta el final por ser (p->valor) <= v
        }        
    }              //entonces pos tomara el valor del anterior tambien
    return false;
}                  //si no lo encuentra y va hasta el final del for pues p habria
                   //sido nillptr y se guardaria en pos.   
                   
template<class T>
void LEC<T>::find_cola(nodo<T>* &cola){
    if(head->next != head){
        nodo<T>* i=(head->next);
        for( ; i!=head ; i=i->next ){
            cola=i;
        }
        
    }
}


template <class T>
void LEC<T>::add(T v){

    nodo<T>* posicion_anterior=nullptr;
    bool busqueda = find(v,posicion_anterior);
    
    if(busqueda && !posicion_anterior){// Si lo encontro y esta al principio

        nodo<int>* cola=nullptr; 
        find_cola(cola);
        head=new nodo<T>(v,head);
        cola->next=head;
    }
    else if(busqueda){// admite elementos repetidos  // Si solamente lo encontro y no esta al inicio
        posicion_anterior->next = new nodo<T>(v,posicion_anterior->next);  // usar truco del hombre araña
    } 
    //  s{,h}  h{V,q}  q{v,} 
    else{                                 //  (!busqueda)   // Si no lo encontro
        if (posicion_anterior==nullptr && head==nullptr){ //si esta vacio
            head=new nodo<T>(v,head);
            head->next=head;
        }
        else if (posicion_anterior==nullptr){   // si el numero no se encontro ni en la cabeza
           
            nodo<int>* cola=nullptr;
            find_cola(cola);
            head=new nodo<T>(v,head); // se crea un nodo, al ser vacio, head del nodo creado== nullptr
            cola->next=head;
   
            if (head->next==nullptr){  // pertenece al unico caso de q la lista este vacia
                head->next=head;
            }
                                      // ya que si hubiera un elemento busqueda=True, pero es False
        }
        
        else{                        //(posicion_anterior->next==nullptr) si no lo encuentra pero llego a recorrer toda la lista:
                                     // pos anterior no sera nullptr, si no el elemento anterior.
            posicion_anterior->next= new nodo<T>(v,posicion_anterior->next);
        }

    }
}

template<class T>
void LEC<T>::del(T v){
    nodo<T>* pos_ant;
    bool busqueda =find(v,pos_ant);
    
    if(busqueda && !pos_ant){// Si lo encontro y esta al principio
        nodo<int>* cola=nullptr;
        find_cola(cola);
        head= head->next;
        
        cola->next=head;

    }
    else if(busqueda){
         pos_ant->next = pos_ant->next->next ;  // usar truco del hombre araña
    } 
    
}

template<class T>
LEC<T>::~LEC(){
    cout<<" "<<endl;
    //while(head){
    //    del(head->valor);
    //}
}



int main() {
    
    // Ingresando manualmente elementos a lista
    LEC<int> lista;
    cout<<lista.head<<endl;
    lista.print();
    
    lista.add(2);  //1
    lista.print();
    
    lista.add(3);    //2
    lista.print();
    lista.add(4);//3
    lista.print();
    lista.add(5);//4
    lista.print();
    lista.add(1);//5
    lista.print();
    lista.add(1);//6
    lista.print();
    lista.add(6);//7
    lista.print();
    lista.add(6);//8
    lista.print();
    lista.add(1);//9
    lista.print();
    
    cout<<"borrando"<<endl;
    
    
    lista.del(1);//9
    lista.print();
    lista.del(1);//9
    lista.print();
    lista.del(1);//9
    lista.print();
    
    lista.del(6);//9
    lista.print();
    lista.del(6);//9
    lista.print();
    lista.del(4);//9
    lista.print();
    
    cout<<"probando la circularidad de la lista circular: ";
    cout<<"buscando la cola:       ";
    nodo<int>* cola_1=nullptr;
    lista.find_cola(cola_1);
    cout<<cola_1->valor<<endl;
    cout<<"\nAccediendo al siguiente valor de la cola ( COLA->next = HEAD) :        ";
    cout<<cola_1->next->valor<<endl;
    
    return 0;
    
}
