
#include <iostream>  //556.60
using namespace std;

int main(){

	float A[11]={200,100,50,20,10,5,2,1,0.5,0.2,0.1};

	float dinero;
	float copia;
	int cociente;

	cout << "Ingrese una cantidad en soles\n";
	cin >> dinero;
	copia = dinero;
	//cout<<"copia "<<copia<<endl; 
	
	for(float* p = A ; p < A + 11 ; p++ ){
    
		cociente = copia/(*p);               // 200/200  = 1 
		//cout<<"cociente "<<cociente<<endl;
		
		if(copia>0) {                        // 200 
		    copia -= cociente*(*p);          // 200 - 200*1  = 0
		    //cout<<"copia "<<copia<<endl; 
		}
		cout<<"unidades de - "<< *p<<" - :"<< cociente<<endl;
	}

}
