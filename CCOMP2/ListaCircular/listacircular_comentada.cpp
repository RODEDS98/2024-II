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
    //cout<<"( Head.valor =  ";                  
    nodo<T>* primer_valor = head;
    if(head){
        cout<<"El valor de head es: "<<head<<endl; 
        cout<<head->valor;              cout<<" /  "<<head<<" ) ,"; 
        cout<<"->"; 
        int i=0;
        for(nodo<T>* p= (head->next) ; i<20  && p!=head ; p=p->next){
            i++;
            cout<<" ( ";
            cout<<p->valor;             cout<<" /  "<<p<<" ) ,"; 
            cout<<"->"; 
        }
    }
    cout<<endl;

    //delete primer_valor;
}

template <class T>
bool LEC<T>::find(T v,nodo<T>* &pos){
    pos=nullptr;                        // 1 2 3  4          // 3
    nodo<T>* primer_valor = head;
    cout<<"\t\t- - - - - - - - - - - -"<<endl;
    cout<<"\t\tantes de if(head) FIND: HEAD: "<<head<<endl;
    if(head){
        cout<<"\t\tdespues de if(head) FIND: "<<head<<endl;
        //cout<<"no bucle 1 ";
        if(head->valor==v){  // hecho para que aun si hay un unico elemento retornara true
            //cout<<"if 1 ";
            cout<<"\t\tif(head->valor==v)"<<head<<endl;
            cout<<"\t\tHEAD(2): "<<head<<endl;
            cout<<"\t\t- - - - - IF , retorno cuando es el 1er valor (2)- - -"<<endl;
            return true; // post anterior sera null, se declara en add
        }
        
        else if(head->valor > v){  // hecho para que aun si hay un unico elemento retornara true
            //cout<<"if 1 ";
            cout<<"\t\tif(head->valor > v)"<<head<<endl;
            cout<<"\t\tHEAD(1): "<<head<<endl;
            cout<<"\t\t- - - - - IF , retorno cuando es el 1er valor (1)- - -"<<endl;
            return false; // post anterior sera null, se declara en add
        }
        
        else{                             //condicion de stop por final de lista     //condicion por encontrar valor
            //cout<<"no bucle 2";
            pos=head;  //al pasar al else, ya se evaluo el primer nodo, entonces se le pasa el de la cabeza
            for(nodo<T>* p=(head->next) ;    p!=head    &&  (p->valor <= v)      ;   p=p->next){
                //cout<<" bucle ";
                if(p->valor == v){
                    cout<<"\t\t- - - - IF del for - - - - - - - -"<<endl;
                    return true;
                }
                pos=p; // si lo encuentra no actualiza por el return y guarda la pos anterior
            }
            cout<<"\t\t- - - - - -FUERA DEL FOR - - - - -"<<endl;
            return false;  //si no lo encuentra y no llega hasta el final por ser (p->valor) <= v
        }        
    }              //entonces pos tomara el valor del anterior tambien
    cout<<"\t\t- - - - - retorno de lista vacia - - - - -"<<endl;
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
    cout<<"LA DIRECCION ANTERIOR A ESE NODO: " << posicion_anterior <<endl;
    cout<<"Antes de  entrar al if "<<head<<endl;
    if(busqueda && !posicion_anterior){// Si lo encontro y esta al principio
        cout<<"prueba 1 " <<endl;
        cout<<"Antes de crear el nodo "<<head<<endl;
        cout<<"Antes de crear el nodo head->next"<<head->next<<endl;
        nodo<int>* cola=nullptr; 
        cout<<"COLA "<<cola<<endl;
        find_cola(cola);
        cout<<"COLA LUEGO DE FIND "<<cola<<endl;
        cout<<"HEAD LUEGO DE FIND COLA "<<head<<endl;
        head=new nodo<T>(v,head);
        cout<<"HEAD LUEGO DE nuevo nodo "<<head<<endl;
        cola->next=head;
        cout<<"cola->next "<<cola->next<<endl;
        cout<<"heaa->next "<<head->next<<endl;
        
        cout<<"luego de crear el nodo "<<head<<endl;
        //head->next=head;
        //cout<<"luego de crear el nodo "<<head<<endl;
        cout<<"Imrpime a donde apunta head, head->next "<<head->next<<endl;
    }
    else if(busqueda){// admite elementos repetidos  // Si solamente lo encontro y no esta al inicio
    //cout<<"encontro el 1"<<endl;
        //r=posicion_anterior->next; //  s{,q}   q{v,}   // r=q                   add (V )
        //posicion_anterior->next= new nodo<T>(v,r); //  s{,h}   q{v,}       new ( h {V,q} )
        cout<<"prueba 2 " <<endl;
        posicion_anterior->next = new nodo<T>(v,posicion_anterior->next);  // usar truco del hombre araña
    } 
    //  s{,h}  h{V,q}  q{v,} 
    else{    //  (!busqueda)   // Si no lo encontro 
        cout<<"prueba else " <<endl;
        if (posicion_anterior==nullptr){     // si el numero no se encontro ni en la cabeza
            cout<<"if (posicion_anterior==nullptr)" <<endl;
            
            nodo<int>* cola=nullptr;   
            cout<<"COLA "<<cola<<endl;
            find_cola(cola);
            cout<<"COLA LUEGO DE FIND "<<cola<<endl;
            cout<<"HEAD LUEGO DE FIND COLA "<<head<<endl;
            head=new nodo<T>(v,head); // se crea un nodo, al ser vacio, head del nodo creado== nullptr
            cout<<"HEAD LUEGO DE nuevo nodo "<<head<<endl;
            cola->next=head;
            cout<<"cola->next "<<cola->next<<endl;
            cout<<"heaa->next "<<head->next<<endl;
            
   
            if (head->next==nullptr){     // pertenece al unico caso de q la lista este vacia
                cout<<"if (head->next==nullptr) " <<endl;
                head->next=head;
            }
                         // ya que si hubiera un elemento busqueda=True, pero es False
        }
        
        else{  //(posicion_anterior->next==nullptr) si no lo encuentra pero llego a recorrer toda la lista:
            // pos anterior no sera nullptr, si no el elemento anterior.
            cout<<"prueba   else " <<endl;
            posicion_anterior->next= new nodo<T>(v,posicion_anterior->next);
        }

    }
}

template<class T>
void LEC<T>::del(T v){
    nodo<T>* pos_ant;
    bool busqueda =find(v,pos_ant);
    
    if(busqueda && !pos_ant){// Si lo encontro y esta al principio
        head= head->next;
        nodo<int>* cola=nullptr;
        find_cola(cola);
        cola->next=head;

    }
    else if(busqueda){
         pos_ant->next = new nodo<T>(v,pos_ant->next);  // usar truco del hombre araña
    } 
    
}

template<class T>
LEC<T>::~LEC(){
    cout<<"borrado"<<endl;
    //while(head){
    //    del(head->valor);
    //}
}



int main() {
    
    // Ingresando manualmente elementos a lista
    LEC<int> lista;
    nodo<int>* a =nullptr;
    lista.head = new nodo<int>(5,nullptr);
    lista.head = new nodo<int>(4,lista.head);
    lista.head = new nodo<int>(3,lista.head);
    lista.head = new nodo<int>(2,lista.head);
    ((lista.head->next->next->next->next))=lista.head;
    
    cout<<lista.head->next<<endl;
    cout<<lista.head->valor<<endl;
    //Probando print
    //lista.print();
    cout<<"probando "<<endl;
    cout<<lista.head->valor<<endl;
    
    //Probando el funcionamiento de find circular
    cout<<"buscando"<<endl;
    nodo<int>* pos_ant1=nullptr;
    cout<<"posicion real :" <<(lista.head->next->next)->valor<<" "<<(lista.head->next->next)<<endl;
    cout<<"posicion anterior :" <<(lista.head->next)<<endl;
    cout<<"Entonces si buscamos en find daria la posicion anterior , la misma : ";
    lista.find(1,pos_ant1);
    cout<<pos_ant1<<endl;
    
    cout<<"Antes de añadir "<<endl;
                cout<<"dibujado original { 2 3 4 5 }: "<<endl;
    cout<<lista.head<<" ";
    cout<<lista.head->valor<<" ";cout<<endl;
    cout<<(lista.head->next)<<" ";
    cout<<(lista.head->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next)<<" ";
    cout<<(lista.head->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next)<<" ";
    cout<<(lista.head->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next)->valor<<" R1 ";cout<<endl;

    cout<<"buscando 6 ___________________________________________________________"<<endl;
    //Añadir elementos con el metodo add
    lista.add(6);
            cout<<"dibujado manual: "<<endl;
    cout<<lista.head<<" ";
    cout<<lista.head->valor<<" ";cout<<endl;
    cout<<(lista.head->next)<<" ";
    cout<<(lista.head->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next)<<" ";
    cout<<(lista.head->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next)<<" ";
    cout<<(lista.head->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next)->valor<<"R ";cout<<endl;

 
    cout<<"____________________________________________________________"<<endl;
    //lista.print();
    cout<<"head: " <<lista.head;
    cout<<"next de ultimo valor: " <<lista.head->next->next->next->next->next;
    cout<<endl;
    cout<<"bucando 7____________________________________________________________"<<endl;
    lista.add(7);
            cout<<"dibujado manual: "<<endl;
    cout<<lista.head<<" ";
    cout<<lista.head->valor<<" ";cout<<endl;
    cout<<(lista.head->next)<<" ";
    cout<<(lista.head->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next)<<" ";
    cout<<(lista.head->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next)<<" ";
    cout<<(lista.head->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next)->valor<<" ";cout<<endl;


 
    
    cout<<"_____________________________________________________________"<<endl;
    //lista.print();
    cout<<"buscando 2____________________________________________________________"<<endl;
    lista.add(2);
        cout<<"dibujado manual: "<<endl;
    cout<<lista.head<<" ";
    cout<<lista.head->valor<<" ";cout<<endl;
    cout<<(lista.head->next)<<" ";
    cout<<(lista.head->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next)<<" ";
    cout<<(lista.head->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next)<<" ";
    cout<<(lista.head->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next->next)->valor<<" R";cout<<endl;
    
    
    cout<<"buscando 2____________________________________________________________"<<endl;
    lista.add(2);
    cout<<"dibujado manual: "<<endl;
    cout<<lista.head<<" ";
    cout<<lista.head->valor<<" ";cout<<endl;
    cout<<(lista.head->next)<<" ";
    cout<<(lista.head->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next)<<" ";
    cout<<(lista.head->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next)<<" ";
    cout<<(lista.head->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next->next->next)->valor<<" Rs";cout<<endl;


    
    
    cout<<"buscando 3____________________________________________________________"<<endl;
    lista.add(3);
    cout<<"_____________________________________________________________"<<endl;
    //lista.print();
    cout<<"dibujado manual: "<<endl;
    cout<<lista.head<<" ";
    cout<<lista.head->valor<<" ";cout<<endl;
    cout<<(lista.head->next)<<" ";
    cout<<(lista.head->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next)<<" ";
    cout<<(lista.head->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next)<<" ";
    cout<<(lista.head->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next->next->next->next)->valor<<" R ";cout<<endl;

    cout<<"buscando 1____________________________________________________________"<<endl;
    lista.add(1);
    cout<<"_____________________________________________________________"<<endl;
    //lista.print();
    cout<<"dibujado manual: "<<endl;
    cout<<lista.head<<" ";
    cout<<lista.head->valor<<" ";cout<<endl;
    cout<<(lista.head->next)<<" ";
    cout<<(lista.head->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next)<<" ";
    cout<<(lista.head->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next)<<" ";
    cout<<(lista.head->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next->next->next)->valor<<" ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next->next->next->next)->valor<<"  ";cout<<endl;
    cout<<(lista.head->next->next->next->next->next->next->next->next->next->next)<<" ";
    cout<<(lista.head->next->next->next->next->next->next->next->next->next->next)->valor<<"  ";cout<<endl;

    
    cout<<endl;
    cout<<lista.head<<" ";cout<<endl;
    lista.print();
    

    return 0;
    
}
