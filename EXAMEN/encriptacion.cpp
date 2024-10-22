
#include <iostream>
using namespace std;

char cipher(char Ent,int key){
    return Ent*key%256;
}

void Procesa(char(*MATCAD)[200], int MATTAM, char (*OPER)(char,int),int key  ){

    for(char(*i)[200]=MATCAD ; i<MATCAD+MATTAM ; i++){
        for(char(*j)=*i ; *j ; j++){
            *j=OPER(*j,key);
        }
    }

}

void imprimir(char(*MAT)[200],int TAM){
    for(char(*p)[200]=MAT;p<MAT+TAM;p++){
        cout<<*p<<endl;
    }
}


int main()
{
    char c[][200]  {"abcdefghijklmnopqrstuvwxyz","abcdefghijklmnopqrstuvwxyz","abcdefghijklmnopqrstuvwxyz"};
    imprimir(c,3);
    Procesa(c,3,cipher,21);
    imprimir(c,3);
    Procesa(c,3,cipher,61);
    imprimir(c,3);

    return 0;
}
