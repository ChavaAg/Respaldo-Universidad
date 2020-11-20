#include "CArbol.h"
#include <iostream>

using namespace std;

CArbol::CArbol() {
	pRaiz = nullptr;
}

void CArbol::insertar(float nd) {
	if (pRaiz==nullptr) {
		pRaiz = new BTNodo;
		pRaiz->fdato = nd;
	} else {
		pRaiz->insertar(nd);
	}
}

void CArbol::inOrden() {
	if (pRaiz == nullptr) {
		cout << "No hay elementos en el arbol binario" << endl;
		return;
	}
	
	pRaiz->inOrden();
	
}

void CArbol::preOrden() {
	if (pRaiz==nullptr) {
		cout << "No hay elementos en el arbol binario" << endl;
		return;
	}
	pRaiz->preOrden();

}

void CArbol::posOrden() {
	if (pRaiz == nullptr) {
		cout << "No hay elementos en el arbol binario" << endl;
		return;
	}

	pRaiz->posOrden();
}
