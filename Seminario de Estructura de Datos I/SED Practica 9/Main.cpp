#include "CPilaoCola.h"
#include "CPilaEstatica.h"
#include "CColaEstatica.h"
#include "CColaDinamica.h"
#include "CPilaDinamica.h"
#include <iostream>

using namespace std;

int main() {
	CPilaoCola* pElemento = 0;
	int iEleccion;

	cout << "Los datos que puede escorger son los siguientes:" << endl;
	cout << " 1. Pila Estatica\n 2. Cola Estatica\n 3. Pila Dinamica" << endl;
	cout << " 4. Cola Dinamica" << endl;
	cout << "Opcion: "; cin >> iEleccion;

	if (iEleccion == 1) {
		pElemento = new CPilaEstatica;
	} else if (iEleccion == 2) {
		pElemento = new CColaEstatica;
	} else if (iEleccion == 3) {
		pElemento = new CPilaDinamica;
	} else if (iEleccion == 4) {
		pElemento = new CColaDinamica;
	}

	pElemento->push(1);
	pElemento->push(2);
	pElemento->push(3);
	pElemento->push(4);
	pElemento->imprimir();
	cout << "El pElemento eleminado es: " << pElemento->pop() << endl << endl;
	pElemento->push(5);
	pElemento->push(6);
	pElemento->push(7);
	pElemento->push(8);
	pElemento->imprimir();

	cout << "Total de datos ingresados: " << pElemento->size();

	return 0;
}