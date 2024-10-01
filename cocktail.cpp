#include <iostream>
using namespace std;    //     p = 10
                        //  (i-p) = 0  1  2  3  4  5    
                             //     i
bool palindromo(char* p) {     //  10 11 12 13 14 15    16    tam = 6
    int tam =0;
    for(char* i = p; *i; i++){
        tam++;
    }
    //cout<<tam<<"\n";           //   a  b  c  c  b  a    /0 
    for(char* i = p; *i; i++){
        //cout<<"analizando; "<<"i: "<<*i<<" , -i :"<<*(p+tam-(i-p)-1)<<"\n";
        if(*i==' '){
            tam++;   //""
            continue;
            //cout<<"tam++ ; "<<tam<<endl;
        }
        if(*(p+tam-(i-p)-1) ==' '){
            tam--;
            //cout<<"tam-- ;  "<<tam<<endl;
        }
        if ( *i >= 'a' &&  *i<='z'){
            *i-=32;
        }   
        if ( *(p+tam-(i-p)-1) >= 'a' &&  *(p+tam-(i-p)-1) <='z'){
            *(p+tam-(i-p)-1) -=32;
        }   //  " abccba"
        //cout<<"SALTOS completos;  "<<"i: "<<*i<<" , -i :"<<*(p+tam-(i-p)-1)<<"\n";
                                       //  p + tam- (i-p)-1
        if(*i!=*(p+tam-(i-p)-1)){ // 10 + {6-1, 6-2, 6-3, 6-4, 6-5, 6-6}
            return false;
        }
    }
    return true;
}

int main() {
    char palabra[] = "anitA lavA la tiNa"; 
    if (palindromo(palabra)) {
        cout << "Es un palíndromo." << endl;
    } else {
        cout << "NO es un palíndromo." << endl;
    }

    return 0;
}
