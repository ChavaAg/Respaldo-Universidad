#include <iostream>
using namespace std;

class CCadena{
private:
	char szBuffer[128];
public:
	void Leer();
	void Imprimir();
	
	void ImprimeVertical();
	int Tamanio();
	
	void ImprimeReves();
	int Cuenta(char);
	int PrimerAparicion(char);
	
	int Concatenar(char*);
	void Reves();
};
void CCadena::Leer(){
	gets(szBuffer);
}
void CCadena::Imprimir(){
	int iLongitud=Tamanio();
	
	for(int iX=0; iX<iLongitud; iX++){
		cout << szBuffer[iX];
	}
}
void CCadena::ImprimeVertical(){
	int iLongitud=Tamanio();
	for(int iX=0; iX < iLongitud; iX++){
		cout << szBuffer[iX] <<endl;
	}
}
int CCadena::Tamanio(){
	int iLongitud=0;
	
	for(int iX=0;iX<50;iX++){
		if(szBuffer[iX]=='\0'){
			return iLongitud;
		}
		iLongitud++;
	};
	return iLongitud;
}
void CCadena::ImprimeReves(){
	int iLongitud=Tamanio();
	
	for(int iX=iLongitud; iX >= 0; iX--){
		cout << szBuffer[iX];
	}
	cout<<endl;
}
int CCadena::Cuenta(char cContar){
	int iResult=0;
	int iLongitud=Tamanio();
	
	for(int iX=0;iX<iLongitud;iX++){
		
		if(szBuffer[iX]==cContar){
			
			iResult++;
		}
	}
	return iResult;
}
int CCadena::PrimerAparicion(char cContar){
	int iLongitud=Tamanio();
	
	for(int iX=0;iX<iLongitud;iX++){
		
		if(szBuffer[iX]== cContar){
			return iX+1;
		}
	}
	return -1;
}
int CCadena::Concatenar(char* pszIn){
	int iLongitud=Tamanio();
	int iLongitud2=0;
	
	do{
		szBuffer[iLongitud]=pszIn[iLongitud2];
		iLongitud2++;
		iLongitud++;
		
	} while(pszIn[iLongitud2-1]!='\0');
	
	return 0;
}
void CCadena::Reves(){
	int iLongitud=Tamanio();
	char cCopia[128];
	
	for(int iX=0, iY=iLongitud-1;iX<iLongitud;iX++){
		cCopia[iX]=szBuffer[iY];
		iY--;
	};
	for(int iX=0;iX<iLongitud;iX++){
		szBuffer[iX]=cCopia[iX];
	};
}
int main() {
	char cContar='e';
	char cBuscar='r';
	
	char cIn[]= "Daureth";
	char* pszIn;
	pszIn=cIn;
	
	CCadena cadena;
	
	cout<<"Ingrese la cadena: "; cadena.Leer();
	cout<<endl;
	cout<<"Cadena ingresada: "; cadena.Imprimir();
	cout<<endl;
	cout<< "||Impresion vertical||" << endl;
	cadena.ImprimeVertical();
	cout << "Cantidad de letra es: " << cadena.Tamanio();
	cout<<endl;
	cout<< "||Impresion al reves||" << endl;
	cadena.ImprimeReves();
	cout << "La cantidad de " << cContar << " es: " << cadena.Cuenta(cContar);
	cout<<endl;
	cout << "La primera aparicion de " << cBuscar << " es en la posicion: " << cadena.PrimerAparicion(cBuscar);
	cout<<endl;
	cadena.Reves();
	cout << "Funcion Reves: "; cadena.Imprimir();
	cout<<endl;
	cadena.Reves();
	cout << "Funcion Concatenar: "; cadena.Concatenar(pszIn);
	cadena.Imprimir();
	return 0;
}

