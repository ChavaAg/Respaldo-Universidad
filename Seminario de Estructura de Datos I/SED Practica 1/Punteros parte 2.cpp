#include <iostream>

using namespace std;

int Potencia(int iBase, int iExp) {
	int iResult = 1;
	
	for (int iX = 0; iX < iExp; iX++){
		iResult = iResult * iBase;
	}
	return iResult;
}
void Potencia2(int *pBase, int iExp) {	
	int iResult = 1;
	
	for (int iX = 0; iX < iExp; iX++){
		iResult = iResult * (*pBase);
	}
	*pBase = iResult;
}
int main() {
	
	int iBase, iExp;
	iBase = 7;
	iExp = 5;
	
	int* pBase;
	pBase = &iBase;
	
	cout << "Base: " << iBase << endl;
	cout << "Exponente: " << iExp << endl << endl;
	
	cout << "Usando la Funcion Potencia el resultado es: " << Potencia(iBase, iExp) << endl;
	Potencia2(pBase,iExp);
	cout << "Usando la Funcion Potencia2 el resultado es: " << *pBase;
	
	
	return 0;
}
