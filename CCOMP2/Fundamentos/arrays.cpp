
#include <iostream>
using namespace std;

int main()
{   
    
    int Arr_6[6]         ={1,2,3,4,5,6};
    
    
    int Arr_43[4][3]     ={{11,12,13},{21,22,23},{31,32,33},{41,42,43}};;
    
    
    int Arr_343[3][4][3] ={{{11,12,13},{21,22,23},{31,32,33},{41,42,43}},
                           {{11,12,13},{21,22,23},{31,32,33},{41,42,43}},
                           {{11,12,13},{21,22,23},{31,32,33},{41,42,43}}};
    
    char Arr_a4[5] ={"hola"};
    char Arr_a43[4][3] ={"ab","cd","ef","gh"};
    
    char Arr_b[4][4][3]= {{"AB","CD","EF","GH"},{"IJ","KL","MN","OP"},
                {"QR","ST","UV","WX"},{"YZ","ab","bc","de"}};
    
    //array  Arr_31={{{11,12,13},{21,22,23},{31,32,33},{41,42,43}},
    //              {{11,12,13},{21,22,23},{31,32,33},{41,42,43}},
    //              {{11,12,13},{21,22,23},{31,32,33},{41,42,43}}}
    
    int* p= Arr_6;
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<endl;cout<<endl;cout<<endl;cout<<endl;
    //cout<<"Arr_43: "<<sizeof(Arr_6)<<endl;
    //Escribir funciones que recorra todos los elementos de array de 1 dimension:
    cout<<"primeros array:  int Arr_6[6]"<<endl;
    for(int* i=Arr_6; i<Arr_6+6;i++){ // se crea *i a  A = A[0], se mueve cada 4 bits porque es la capa externa
        cout<<"dir: "<<i<<";  n: "<<*i<<endl;//  i  = A     = [4]
    }cout<<endl;                             // *i  = n     = 1,2,3,4,5,6
    for(int* i=p; i<Arr_6+6;i++){ // se crea *i a  A = A[0], se mueve cada 4 bits porque es lo ultimo 
        cout<<"dir: "<<i<<";  n: "<<*i<<endl;//  i  = A     = [4]
    }cout<<endl; 
    
    //Escribir funciones que recorra todos los elementos primeros elementos de 2 dimensiones:
    cout<<"primeros de array:  int Arr_43[4][3]"<<endl;
    //int*  Arr_43;
    for(int(* i)[3] = Arr_43 ; i< Arr_43+(4) ; i++ ){
        cout<<"dir: "<<i<<";  x: "<<*i<<";  n: "<<**i<<endl;
    }cout<<endl;cout<<endl;

    
    //Escribir funciones que recorra todos los elementos de array de 2 dimensiones:
    cout<<"todos 2 array:  int Arr_43[4][3]"<<endl;
    //
    int(* q)[3]  = Arr_43 ;                              //       1      2      3      4
    int(* q2)[3] = Arr_43 ;
                                                    //   [[1 2 3][- - -][- - -][- - -]]
    for(int(* i)[3] = Arr_43 ; i< Arr_43+(4) ; i++ ){ // i, capa externa, se movera cada 3*4 bits / 2da dimension                         
        for(int* j = *i ; j < *i+3 ; j++ ){  // queremos movernos capa interna,para movernos cada 4 bits / 1ra dimension
            cout<<"dir: "<<j<<";  x: "<<*j<<endl;//  se logra indireccionando i, ya que i es la capa de 2da dimension    
        }                                        //  y para acceder a la primera se pasa de hace esto
    }cout<<endl;cout<<endl;                      // 
    for(int(* i)[3] = q ; i< q+(4) ; i++ ){ //   Arr_43  [][n]  [aqui[][][][]]                   
        for(int* j = *i ; j < *i+3 ; j++ ){  // i apunta al 1er elemento , move 4*3 bits
            cout<<"dir: "<<j<<";  x: "<<*j<<endl;//  i =  , *i = [[aqui][][][]]
        }      //     n = **i  // porque se dice que se tiene q crear un puntero a puntero
    }          //    *n =  *i
               //   **n =   i
    cout<<endl;cout<<endl;
    //En un solo for imprimir todos los elementos
    cout<<"todos 2 un solo for:  int Arr_43[4][3]"<<endl;
    for(int(* i) = *Arr_43 ; i < *Arr_43+(12) ; i++ ){
        cout<<"1 for dir : "<<*i<<endl;
    }cout<<endl;cout<<endl;
    //conclusiones:  
    //  Cuando se crea un puntero int* p= Arr_6; es cierto que Arr_6 es suficiente 
    //  para que p apunte al primer elemento con Arr_6, ya que Arr_6 tiene por defecto
    //  la direccion del primer elemento del mismo array;
    //  Pero...
    //  int(* q)[3]  = Arr_43 ;  porque?
    //  ((Esto es porque si se crea un puntero int* q= Arr_6; estariamos erroneamente creando
    //  un puntero q que apunta  ,,,esto sirve para otra))
    //  Esto es porque si se crea un puntero int* q= Arr_6; el compilador lo evitara ya que se 
    //  necesita enviar el rango de las dimensiones posteriores a la primera: osea si hay

    // capa externa ; tercera dimension 
    // Arr_343[3][4][3]   ***p = n  ;  **p=  ;  *p 
    
    for(int(* i)[4][3] = Arr_343 ; i < Arr_343+(3) ; i++ ){ //Arr_b+(4) / al trabajar en la tercera dimension, capa externa            
        for(int(* j)[3] = *i ; j < *i+4 ; j++ ){             //necesitamos el limte de esta, por eso [*4*][4][3]
            for(int* k = *j ; k < *j+3 ; k++ ){  
                cout<<*k<<",";
            }cout<<endl;
        }
        
    }cout<<endl;cout<<endl;    
    int(* r)[4][3]=Arr_343;    
    
    for(int(* i)[4][3] = r ; i < r+(3) ; i++ ){ //Arr_b+(4) / al trabajar en la tercera dimension, capa externa            
        for(int(* j)[3] = *i ; j < *i+4 ; j++ ){             //necesitamos el limte de esta, por eso [*4*][4][3]
            for(int* k = *j ; k < *j+3 ; k++ ){  
                cout<<*k<<",";
            }cout<<endl;
        }
        
    }   cout<<endl;cout<<endl;
    
    //  Arr_343[3][4][3]
    
    cout<<"imprimir array de enteros 3 correctamente:"<<endl;
    for(int(* i)[4][3] = Arr_343 ; i < Arr_343+3 ; i++ ){
        for(int(* j)[3] = *i ; j < *i+4 ; j++ ){
            cout<<"[ ";
            for(int(* k) = *j ; k < *j+3 ; k++ ){
                    cout<<"[ "<< *k <<"],";
            }
           cout<<"],";
        }
        cout<<endl;
    }
    cout<<"imprimir array de enteros 3 correctamente:"<<endl;
    for( int(* i)=**Arr_343; i<**Arr_343+ 36;i++){
        cout<<"Arr_343 un solo for:"<<*i<<endl;

    }       

    cout<<endl;cout<<endl;
    cout<<endl;cout<<endl;


// char Arr_a4[5] ={"hola"};
    char* o = Arr_a4;
    cout<<o<<",";
    cout<<endl;cout<<endl;
    cout<<endl;cout<<endl;
    for(char* k = Arr_a4 ; *k ; k++ ){  //en este caso k apunta a "hola"
        cout<<*k<<",";   // al desreferenciar ingresamos a la capa interna y se mueve como
    }cout<<endl;         // si fuera esto;   {{h},{o},{l},{a}}
    
    char* k = Arr_a4;
    
    for( ; *k ; k++ ){  // si no desreferenciamos a "hola"
        cout<<k<<",";  // seria como si fuera esto;   {{hola}}
    }cout<<endl;
    
    
// char Arr_a43[4][3] ={"ab","cd","ef","gh"};

    
    for( char(* j)[3] = Arr_a43; j<Arr_a43+4 ; j++ ){
        cout<<j<<","<<endl;
        for( char* k = *j ; *k ; k++ ){  
           cout<<j<<","<<endl;
        }
    }cout<<endl;
    
 char Arr_a432[2][2][3] ={{"ab","cd"},{"AB","CD"}};
 
     for( char(* j)[2][3] = Arr_a432; j<Arr_a432+2 ; j++ ){
        //cout<<j<<","<<endl;
        for( char(* k)[3] = *j ; k<*j+2; k++ ){  
            //cout<<k<<","<<endl;
            for( char* l = *k ; *l ; l++ ){  
                cout<<*l<<","<<endl;
            }
        }
    }

}