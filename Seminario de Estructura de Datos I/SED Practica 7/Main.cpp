#include <iostream>
#include "pila.h"
#include "cola.h"

using namespace std;

int main() {
	CPilaEstatica pila;

	pila.push(30.5);
	pila.push(56.5);
	pila.push(37.5);
	pila.push(19.6);
	pila.push(12.6);
	cout << "Cantidad de elementos en la pila: " << pila.size() << endl << endl;
	pila.imprimir();
	cout <<"El valor que se elimino fue: " << pila.pop() << endl;
	cout << "El valor que se elimino fue: " << pila.pop() << endl << endl;
	cout << "El ultimo valor de la pila es: " << pila.tos() << endl << endl;
	cout << "Cantidad de elementos en la pila: " << pila.size() << endl << endl;
	pila.imprimir();

	cout << "=============================================" << endl;
	CColaEstatica cola;

	cola.push(54.5);
	cola.push(20);
	cola.push(35);
	cola.push(56.9);
	cola.push(122.9);
	cout << "Cantidad de elementos en la cola: " << cola.size() << endl << endl;
	cola.imprimir();
	cout << "El valor que se elimino fue: " << cola.pop() << endl;
	cout << "El valor que se elimino fue: " << cola.pop() << endl << endl;
	cout << "Cantidad de elementos en la cola: " << cola.size() << endl << endl;
	cola.push(27);
	cola.push(96);
	cola.push(96);
	cola.imprimir();
}