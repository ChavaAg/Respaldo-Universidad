#include "CColaEstatica.h"
#include <iostream>

using namespace std;

CColaEstatica::CColaEstatica() : iIndiceInsercion(0), iIndiceDersecion(0), iTamano(0) {
	cout << "Se ha creado una cola" << endl << endl;
}

CColaEstatica::~CColaEstatica() {
	cout << "Se ha destrudo una cola" << endl;
	iIndiceInsercion = 0;
	iIndiceDersecion = 0;
}

void CColaEstatica::push(float nd) {
	if (isFull()) {
		cout << "No se puede insertar mas elementos en la cola" << endl;
		return;
	}

	iIndiceInsercion = iIndiceInsercion % 5;
	cola[iIndiceInsercion++] = nd;
	iTamano++;

}

float CColaEstatica::pop() {
	float iCopia;

	if (isEmpty()) {
		cout << "La cola esta vacia" << endl;
		return -1;
	}

	iIndiceDersecion = iIndiceDersecion % 5;
	iCopia = cola[iIndiceDersecion++];
	iTamano--;
	return iCopia;
}

int CColaEstatica::size() {
	return iTamano;
}

bool CColaEstatica::isEmpty() {
	bool validacion;

	if (iTamano == 0) {
		validacion = true;
	} else {
		validacion = false;
	}


	return validacion;
}

bool CColaEstatica::isFull() {
	bool validacion;

	if (iTamano == 5) {
		validacion = true;
	} else {
		validacion = false;
	}

	return validacion;
}

void CColaEstatica::imprimir() {
	int iGps = iIndiceDersecion;
	int iContador = 0;
	cout << " |";

	while (iContador < iTamano) {
		cout << cola[iGps] << "|";
		iGps = ++iGps % 5;
		iContador++;
	}
	cout << endl << endl;
}