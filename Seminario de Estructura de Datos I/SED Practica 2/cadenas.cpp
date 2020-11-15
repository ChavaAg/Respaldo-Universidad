#include <iostream>

using namespace std;

void ImprimeVertical(char* pszCadena);
int Tamanio(char* pszCadena);
void ImprimeReves(char* pszCadena);
int Cuenta(char* pszCadena, char cContar);
int PrimerAparicion(char* pszCadena, char cContar);
int Concatenar (char* pszInOut, char* pszIn);
void Reves(char* pszCadena);

int main() {
	
	char cCadena[]= "Nada es verdad";
	char cContar= 'e';
	
	char cInOut[]= "Somos";
	char cIn[]= "Mortales";
	
	char* pszCadena;
	char* pszInOut;
	char* pszIn;
	
	
	pszCadena=cCadena;
	pszInOut=cInOut;
	pszIn=cIn;
	
	cout<< "||Impresion vertical||" << endl;
	ImprimeVertical(pszCadena);
	cout << endl;
	cout<< "||Impresion al reves||" << endl;
	ImprimeReves(pszCadena);	
	cout << endl;
	cout << "Cantidad de letra es: " << Tamanio(pszCadena) << endl;
	cout << "La cantidad de " << cContar << " es: " << Cuenta(pszCadena,cContar) << endl;
	cout << "La primera aparicion de " << cContar << " es en la posicion: " << PrimerAparicion(pszCadena,cContar)<<endl;
	Reves(pszCadena);
	cout << "Funcion Reves: ";
	for(int iX=0;iX<50;iX++){
		if(pszCadena[iX]=='\0'){
			break;
		}else{
			cout << pszCadena[iX];
		}
	}
	cout << endl;
	Concatenar(pszInOut,pszIn);
	cout << "Funcion Concatenar: ";
	for(int iX=0;iX<50;iX++){
		if(pszInOut[iX]=='\0'){
			break;
		}else{
			cout << pszInOut[iX];
		}
	}
	return 0;
}

void ImprimeVertical(char* pszCadena){
	int iLongitud=Tamanio(pszCadena);
		for(int iX=0; iX < iLongitud; iX++){
		cout << *pszCadena++ <<endl;
	}
}
int Tamanio(char* pszCadena){
	int iLongitud=0;
	
	for(int iX=0;iX<50;iX++){
		if(pszCadena[iX]=='\0'){
			return iLongitud;
		}
		iLongitud++;
		
	};
	return iLongitud;
}
void ImprimeReves(char* pszCadena){
	int iLongitud=Tamanio(pszCadena);
	
	for(int iX=iLongitud; iX >= 0; iX--){
		cout << pszCadena[iX];
	}
	cout<<endl;
}
int Cuenta(char* pszCadena, char cContar){
	int iResult=0;
	int iLongitud=Tamanio(pszCadena);
	
	for(int iX=0;iX<iLongitud;iX++){
		
		if(pszCadena[iX]==cContar){
			
			iResult++;
		}
	}
	return iResult;
}
int PrimerAparicion(char* pszCadena, char cContar){
	int iLongitud=Tamanio(pszCadena);
	
	for(int iX=0;iX<iLongitud;iX++){
		
		if(pszCadena[iX]== cContar){
			return iX+1;
		}
		
	}
	return -1;
}
int Concatenar (char* pszInOut, char* pszIn){
	int iLongitud=Tamanio(pszInOut);
	int iLongitud2=0;
	
	do{
		pszInOut[iLongitud]=pszIn[iLongitud2];
		iLongitud2++;
		iLongitud++;
		
	} while(pszIn[iLongitud2-1]!='\0');
	
	return 0;
}
						
void Reves(char* pszCadena){
	int iLongitud=Tamanio(pszCadena);
	char cCopia[50];
	
	for(int iX=0, iY=iLongitud-1;iX<iLongitud;iX++){
		cCopia[iX]=pszCadena[iY];
		iY--;
	};
	
	for(int iX=0;iX<iLongitud;iX++){
		pszCadena[iX]=cCopia[iX];
	};
	
}
	
