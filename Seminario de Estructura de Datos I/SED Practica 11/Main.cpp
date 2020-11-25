#include <iostream>
#include "CArbol.h"

using namespace std;


void impresion(CArbol arbol) {
	cout << endl << "Funcion inOrden: ";
	arbol.inOrden();
	cout << endl << endl;
	cout << "Funcion preOrden: ";
	arbol.preOrden();
	cout << endl << endl;
	cout << "Funcion posOrden: ";
	arbol.posOrden();
	cout << endl << "==========================================================================================="<< endl;
}

int main() {
	CArbol arbol;

	arbol.insertar(50);
	arbol.insertar(65);
	arbol.insertar(99);
	arbol.insertar(100);
	arbol.insertar(80);
	arbol.insertar(98);
	arbol.insertar(75);
	arbol.insertar(51);
	arbol.insertar(64);
	arbol.insertar(63);
	arbol.insertar(65);
	arbol.insertar(51);
	arbol.insertar(35);
	arbol.insertar(1);
	arbol.insertar(0);
	arbol.insertar(45);
	arbol.insertar(48);
	arbol.insertar(46);
	arbol.insertar(43);
	arbol.insertar(44);
	arbol.insertar(41);
	arbol.insertar(10);
	arbol.insertar(8);
	arbol.insertar(30);
	arbol.insertar(34);

	cout << "Se elimina el numero 65" << endl;
	arbol.eliminar(65);
	impresion(arbol);

	cout << "Se elimina el numero 50" << endl;
	arbol.eliminar(50);
	impresion(arbol);

	cout << "Se elimina el numero 30" << endl;
	arbol.eliminar(30);
	impresion(arbol);

	return 0;
}