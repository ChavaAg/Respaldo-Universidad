#include"pila.h"
#include <iostream>

void CPila::push(float nd) {
	lista.InsertarInicio(nd);
}

float CPila::pop() {
	return lista.EliminarInicio();;
}

float CPila::tos() {
	int iCopy;

	iCopy = lista.EliminarInicio();
	lista.InsertarInicio(iCopy);
	
	return iCopy;
}
int CPila::size() {
	return lista.Size();
}
bool CPila::isEmpty() {
	return lista.IsEmpty();
}
bool CPila::isFull() {
	return lista.isFull();
}
void CPila::imprimir() {
	lista.Imprime();
}