#include "cola.h"
#include"pila.h"
#include<iostream>
#include<string>

using namespace std;

int main() {
	CCola cola;
	CPila pila;
	cout << "Aqui se utiliza la cola" << endl << endl;

	if (cola.isEmpty()) 
		cout << "Esta vacio" << endl;
	else 
		cout << "No esta vacio" << endl;

	cola.push(10);
	cola.push(115);
	cola.push(15);
	cola.push(25.5);

	cout << "Datos dentro de la cola hay " << cola.size()<<" elementos" << endl;
	cola.imprimir();
	cout << "Dato eliminado de la cola: " << cola.pop() << endl << endl;
	cout << "Datos dentro de la cola hay " << cola.size() << " elementos" << endl;
	cola.imprimir();

	if (cola.isFull())
		cout << "Esta lleno" << endl;
	else
		cout << "No esta lleno" << endl;
	cout << "===============================================" << endl;
	cout << "Aqui se utiliza la pila" << endl << endl;

	if (pila.isEmpty())
		cout << "Esta vacio" << endl;
	else
		cout << "No esta vacio" << endl;
	
	pila.push(10);
	pila.push(20);
	pila.push(30);
	pila.push(40);

	cout << "Datos dentro de la cola hay " << pila.size() << " elementos" << endl;
	pila.imprimir();
	cout << "Dato eliminado de la pila: " << pila.pop() << endl;
	cout << "Dato eliminado de la pila: " << pila.pop() << endl << endl;
	cout << "El dato arriba de la pila es: " << pila.tos() << endl << endl;
	cout << "Datos dentro de la cola hay " << pila.size() << " elementos" << endl;
	pila.imprimir();

	if (pila.isFull())
		cout << "Esta lleno" << endl;
	else
		cout << "No esta lleno" << endl;
}