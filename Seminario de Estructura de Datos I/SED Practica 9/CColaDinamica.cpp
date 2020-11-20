#include "CColaDinamica.h"
#include <iostream>

void CColaDinamica::push(float nd) {
	lista.InsertarInicio(nd);
}

float CColaDinamica::pop() {
	return lista.EliminarFinal();
}

int CColaDinamica::size() {
	return lista.Size();
}

bool CColaDinamica::isEmpty() {
	return lista.IsEmpty();
}

bool CColaDinamica::isFull() {
	return lista.isFull();
}

void CColaDinamica::imprimir() {

	lista.Imprime();
}

