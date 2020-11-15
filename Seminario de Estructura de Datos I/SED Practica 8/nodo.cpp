
#include <iostream>
#include "nodo.h"

void CNodo::InsertarAdelante(CAuto* dato) {

	CNodo* pNodo = new CNodo;
	pNodo->fContenido = dato;

	pNodo->pAnterior = this;

	pNodo->pSiguiente = this->pSiguiente;

	this->pSiguiente->pAnterior = pNodo;

	this->pSiguiente = pNodo;
}

CAuto* CNodo::EliminarSiguiente() {
	CNodo* pNodo = this->pSiguiente;
	CAuto* fDato = pNodo->fContenido;

	this->pSiguiente->pSiguiente->pAnterior = this;
	this->pSiguiente = this->pSiguiente->pSiguiente;

	delete(pNodo);

	return fDato;
}