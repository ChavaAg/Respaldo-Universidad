#include "CPilaDinamica.h"
#include <iostream>

void CPilaDinamica::push(float nd) {
	lista.InsertarInicio(nd);
}

float CPilaDinamica::pop() {
	return lista.EliminarInicio();;
}

float CPilaDinamica::tos() {
	int iCopy;

	iCopy = lista.EliminarInicio();
	lista.InsertarInicio(iCopy);

	return iCopy;
}
int CPilaDinamica::size() {
	return lista.Size();
}
bool CPilaDinamica::isEmpty() {
	return lista.IsEmpty();
}
bool CPilaDinamica::isFull() {
	return lista.isFull();
}
void CPilaDinamica::imprimir() {
	lista.Imprime();
}