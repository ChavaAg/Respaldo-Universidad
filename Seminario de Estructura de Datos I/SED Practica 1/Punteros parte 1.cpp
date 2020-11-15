#include <iostream>

using namespace std;

int main() {
	
	int iX, iY;
	
	iX = 5;
	iY = 10;
	
	int* pA;
	pA = &iX;
	
	cout << "iX" << endl;
	cout << "Impresion de iX: " << iX << endl;
	cout << "Impresion a lo que apunta pA: " << *pA << endl;
	cout << "Impresion de la dreccion de memoria de iX " << &iX << endl;
	cout << "Impresion de pA: " << pA << endl << endl;
	
	pA = &iY;
	
	cout << "iY" << endl;
	cout << "Impresion de iY: " << iY << endl;
	cout << "Impresion a lo que apunta pA: " << *pA << endl;
	cout << "Impresion de la dreccion de memoria de iY " << &iY << endl;
	cout << "Impresion de pA: " << pA << endl;
	
	return 0;
}
