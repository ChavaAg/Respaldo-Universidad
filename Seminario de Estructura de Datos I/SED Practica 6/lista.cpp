#include <iostream>
#include "lista.h"

using namespace std;


CLista::CLista() {
	inicio.pSiguiente = &final;
	final.pAnterior = &inicio;
}

CLista::~CLista() {
	Vaciar();

	cout << "Se ha eliminado el objeto lista" << endl;
}

void CLista::InsertarInicio(float fData) {
	inicio.InsertarAdelante(fData);
}
void CLista::InsertarFinal(float fData) {
	final.pAnterior->pAnterior->InsertarAdelante(fData);
}

int CLista::Size() {
	int nodos = 0;
	CNodo* pNodo = inicio.pSiguiente;

	while (pNodo != &final) {
		nodos++;
		pNodo = pNodo->pSiguiente;
	}

	return nodos;
}

void CLista::Vaciar() {

	while (inicio.pSiguiente != &final) {
		inicio.EliminarSiguiente();
	}
}
bool CLista::IsEmpty() {
	if (inicio.pSiguiente == &final) {
		return true;
	}

	return false;
}

bool CLista::isFull() {
	if (final.pAnterior==&final) {
		return true;
	}

	return false;
}

void CLista::Imprime() {
	CNodo* pNodo = inicio.pSiguiente;

	while (pNodo != &final) {
		cout << pNodo->fContenido << endl;
		pNodo = pNodo->pSiguiente;
	}
	cout << endl;
}

float CLista::EliminarInicio() {

	if (IsEmpty()) {
		cout << "No hay nodos en la lista" << endl << endl;
		return 0;
	}

	return inicio.EliminarSiguiente();
}

float CLista::EliminarFinal() {

	if (IsEmpty()) {
		cout << "No hay nodos en la lista" << endl << endl;
		return 0;
	}

	return final.pAnterior->pAnterior->EliminarSiguiente();
}