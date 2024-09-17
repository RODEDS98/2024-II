#include  <iostream>
#include <math.h>
using namespace std;

//variables globales

string cero = "cero";
string unidades[10] = {"", "uno", "dos", "tres", "cuatro",
                       "cinco", "seis", "siete", "ocho", "nueve" };

string diezal19[10] = {"diez", "once", "doce", "trece", "catorce", "quince", "diecisC)is",
                       "diecisiete", "dieciocho", "diecinueve"};

string decenas[8] = {"veinte", "treinta", "cuarenta", "cincuenta", "sesenta",
                     "setenta", "ochenta", "noventa"};

string centenas[9] = {"cien", "doscientos", "trescientos", "cuatrocientos",
                      "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

int extraer(int,int);
string identificar(int );


// identificar grado
string identificar(int n)     // extraer
{
	if(extraer(n,3)>=1 && (extraer(n,6))<1 ) {
		return "millar";

	}
	else if (extraer(n,6)>=1 ) {
		return "millon";
	}
	else {
		return "centena";
	}
}

int extraer(int n, int d)     // extraer
{
	int pot = pow(10,d); //
	int primer =n/pot;   // extrae el primer digito
	//int residuo = n - primer*pow(10,d);       // resto de  el numero total dxxx - d000  == xxx
	//std::cout<<primer<<std::endl;             // d
	//std::cout<<residuo<<std::endl;            // xxx
	return primer;
}



void imprimir_uno_to_99(int numero, string grado) {

	if(numero==0 && grado=="centena" ) {
		cout	<< cero;
	}
	else if(numero<=10) {
		cout	<<	unidades[numero];
	}
	else if(numero<=19) {
		cout	<<	diezal19[numero-10];
	}
	else if(numero%10==0 && numero>=10 && numero<=90) {
		cout	<<	decenas[(numero/10)-2];
	}
	else if(numero/20==1 && numero<30) {
		cout  <<"veinti"<<	unidades[numero%20];
	}
	else if(numero%10>0 && numero>=29 && numero<100) {
		cout	<<	decenas[(numero/10)-2]  <<" y "<<	unidades[numero%10];
	}
}

void imprimir_0_to_999(int numero, string grado) {

	if(numero<100) {
		imprimir_uno_to_99(numero, grado);
	}
	if(numero%100==0 && numero>=100 && numero<=900) {
		cout	<<	centenas[(numero/100)-1];
	}

	else if(numero%100>0 && numero>=100 && numero<=199) {
		cout  <<"ciento ";
		imprimir_uno_to_99(numero%100,grado);
	}

	else if(numero>=200) {
		cout	<<	centenas[(numero/100)-1] <<" ";
		imprimir_uno_to_99(numero%100,grado);
	}
}


void imprimir_mil_to_999999(int numero,string grado) {

	if (numero/1000==1) {
		cout  <<"mil ";
		if((numero%10)>=0) {
			imprimir_0_to_999(numero%1000, grado);
		}
	}
	else {
        // ANALIZANDO MILLARES CON UNIDAD 1
		if (((numero/1000)%10)==1)  {    
		    
            // LOS DE MENOR A 100K
			if((numero/1000)<92 ) {
			    
			    if((numero/1000)!=11){
			        if((numero/1000)==21){
			            cout  << "veintiun mil ";
			        }
			        else{
			            cout  << decenas[(numero/10000)-2];
				        cout  << " y un mil ";
			        }

			    }
			    else{
                    cout  <<"once mil ";
			    }

			}
            // LOS mayor igual a 100K
			else {
			    //cuya decena es cero (A01 AAA)
			    if((numero/10000)%10==0){
			        
			        // Los pertenecientes a ciento
			        if(numero/100000==1){
    			        cout  <<"ciento ";
    			        cout  <<"un mil ";
			        } 
			        // los mayores a ciento 
			        else if(numero/100000>1 && (numero/10000)%10==0){
    			        cout  <<centenas[(numero/100000)-1];
    			        cout  <<" un mil ";
    			    }
			    }
			    
			    //cuya decena no es cero (Ax1 AAA)    x>0
			    else{
			        //pertenecientes a ciento
			         if(numero/100000==1){
    			        cout  <<"ciento ";
    			        
        			     if(((numero/1000)%100)==21){
    			            cout  << "veintiun mil ";
    			         }
    			         else if(((numero/1000)%100)==11){
    			            cout  << "once mil ";
    			         }
    			         else{
    			            cout  <<decenas[((numero/10000)%10)-2];
    			            cout  <<" y un mil ";
    			         }
			        }
			        else if(numero/100000>1) {
			            
                         cout  <<centenas[(numero/100000)-1]<<" ";
        			     if(((numero/1000)%100)==21){
    			            cout  << "veintiun mil ";
    			         }
    			         else if(((numero/1000)%100)==11){
    			            cout  << "once mil ";
    			         }
    			         else{
    			            cout  <<decenas[((numero/10000)%10)-2];
    			            cout  <<" y un mil ";
    			         }
    			    }
    	        }
			}
			
			
			
			imprimir_0_to_999(numero%1000, grado);
		}
		else {
			imprimir_0_to_999(numero/1000, grado);
			cout  <<" mil ";
			imprimir_0_to_999(numero%1000, grado);
		}

	}





}

int main() {


	int a=999;
	int numero;
	int i{0};
	// extraer(1151180, 3);
	//cout<<" pruebas"<<endl;
	//cout<<" identificar"<<identificar(a);
	//cout<<" extra"<<extraer(a,3);
	//cout<<" extr"<<extraer(a,10);
    cout<<"Ingrese distintos numeros positivos hasta el 999 999: "<<endl;
	while (i<100 && numero<=999999 && numero>=0) {
		cin>>numero;
		i++;
		
		if(identificar(numero)=="centena") {
			//cout<<"centena\n";
			imprimir_0_to_999(numero,"centena");
		}

		if(identificar(numero)=="millar") {
			//cout<<"millar\n";
			imprimir_mil_to_999999(numero,"millar");
		}
		cout<<endl;
	}
	return 0;

}

