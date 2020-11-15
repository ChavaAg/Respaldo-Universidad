#include"cola.h"
#include <iostream>

void CCola::push(float nd) {
	lista.InsertarInicio(nd);
}

float CCola::pop() {
	return lista.EliminarFinal();
}

int CCola::size() {
	return lista.Size();
}

bool CCola::isEmpty() {
	return lista.IsEmpty();
}

bool CCola::isFull() {
	return lista.isFull();
}

void CCola::imprimir() {

	lista.Imprime();
}
