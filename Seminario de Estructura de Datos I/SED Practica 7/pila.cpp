#include "pila.h"
#include <iostream>

using namespace std;

CPilaEstatica::CPilaEstatica(): iIndiceInsercion (0){
	cout << "Se ha creado una pila" << endl << endl;
}

CPilaEstatica::~CPilaEstatica(){
	cout << "Se ha destruido una pila" << endl;
	iIndiceInsercion = 0;
}

void CPilaEstatica::push(float nd) {
	if (isFull()) {
		cout << "No se puede insertar mas elementos en la pila" << endl;
		return;
	}

	pila[iIndiceInsercion++] = nd;
}

float CPilaEstatica::pop() {
	float iCopy;
	if (isEmpty()) {
		cout << "La cola esta vacia" << endl;
		return -1;
	}

	iCopy= pila[--iIndiceInsercion];

	return iCopy;
}

float CPilaEstatica::tos() {
	if (isEmpty()) {
		cout << "La cola esta vacia" << endl;
		return -1;
	}

	return pila[iIndiceInsercion -1];
}

int CPilaEstatica::size() {
	return iIndiceInsercion;
}

bool CPilaEstatica::isEmpty() {
	bool validacion;

	if (iIndiceInsercion == 0) {
		validacion = true;
	}
	else {
		validacion = false;
	}

	return validacion;
}

bool CPilaEstatica::isFull() {
	bool validacion;

	if (iIndiceInsercion == 10) {
		validacion = true;
	}
	else {
		validacion = false;
	}

	return validacion;
}

void CPilaEstatica::imprimir() {
	int gps = iIndiceInsercion -1;

	while (gps >=0 ) {
		cout << " |" << pila[gps--] << "|" << endl;
	}
	cout << endl;
}