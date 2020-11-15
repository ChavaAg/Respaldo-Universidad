#include <iostream>
#include "lista.h"

using namespace std;

CLista::CLista() {
	cout << "Se creo una lista" << endl;

	inicio.pSiguiente = &final;
	final.pAnterior = &inicio;
}

CLista::~CLista() {
	//Vaciar();
}

void CLista::InsertarInicio(CAuto* fData) {
	inicio.InsertarAdelante(fData);
}

void CLista::InsertarFinal(CAuto* fData) {
	final.pAnterior->InsertarAdelante(fData);
}

int CLista::Size() {
	int nodos = 0;
	CNodo* pNodo = inicio.pSiguiente;

	while(pNodo != &final) {
		nodos++;
		pNodo = pNodo->pSiguiente;
	}

	return nodos;
}

void CLista::Vaciar() {

	while(inicio.pSiguiente != &final) {
		inicio.EliminarSiguiente();
	}
}
bool CLista::IsEmpty() {
	if(inicio.pSiguiente == &final) {
		return true;
	}

	return false;
}

bool CLista::isFull() {
	if(final.pAnterior == &final) {
		return true;
	}

	return false;
}

void CLista::ImprimeVirtual() {
	CNodo* pNodo = inicio.pSiguiente;

	while(pNodo != &final) {
		pNodo->fContenido->ImprimirVirtual();
		pNodo = pNodo->pSiguiente;
	}
}

void CLista::ImprimeNoVirtual() {
	CNodo* pNodo = inicio.pSiguiente;

	while(pNodo != &final) {
		pNodo->fContenido->ImprimirNoVirtual();
		pNodo = pNodo->pSiguiente;
	}
}

CAuto* CLista::EliminarInicio() {

	if(IsEmpty()) {
		cout << "No hay nodos en la lista" << endl << endl;
		return 0;
	}

	return inicio.EliminarSiguiente();
}

CAuto* CLista::EliminarFinal() {

	if(IsEmpty()) {
		cout << "No hay nodos en la lista" << endl << endl;
		return 0;
	}

	return final.pAnterior->pAnterior->EliminarSiguiente();
}