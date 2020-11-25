#include "BTNodo.h"
#include <iostream>

using namespace std;


BTNodo::BTNodo() {
	pIzda = nullptr;
	pDcha = nullptr;
}

void BTNodo::insertar(float nd) {
	if (ToTheLeft(nd)) {
		if (pIzda == nullptr) {
			pIzda = new BTNodo;
			pIzda->fdato = nd;
		} else {
			pIzda->insertar(nd);
		}
	} else {
		if (pDcha == nullptr) {
			pDcha = new BTNodo;
			pDcha->fdato = nd;
		} else {
			pDcha->insertar(nd);
		}
	}
}

bool BTNodo::ToTheLeft(float nd) {
	if (nd > fdato) {
		return true;
	} else {
		return false;
	}
}

int BTNodo::cuantosHijos() {
	int hijos = 0;

	if (this->pIzda != nullptr) {
		hijos++;
	}
	if (this->pDcha != nullptr) {
		hijos++;
	}
	return hijos;
}

BTNodo* BTNodo::unicoHijo() {

	if (cuantosHijos()==1) {

		if (this->pIzda != nullptr) {
			return this->pIzda;
		} else if (this->pDcha != nullptr) {
			return this->pDcha;
		}

	}

	return nullptr;
}

BTNodo* BTNodo::extremaDerecha() {
	BTNodo* aux = this;


	while (true) {
		if (aux->pDcha == nullptr) {
			return aux;
		} else {
			aux = aux->pDcha;
		}
	}
	
	return nullptr;
}

void BTNodo::inOrden() {
	//criterio de paro
	if (this == nullptr) {
		return;
	}
	//Se salva el izquierdo
	pIzda->inOrden();
	//Se salva el padre
	cout << this->fdato << ",";
	//Por ultimo el hijo derecho
	pDcha->inOrden();
}

void BTNodo::preOrden() {
	//criterio de paro
	if (this == nullptr) {
		return;
	}
	//Se salva el padre
	cout << this->fdato << ",";
	//Se salva el izquierdo
	pIzda->preOrden();
	//Por ultimo el hijo derecho	
	pDcha->preOrden();
}

void BTNodo::posOrden() {
	//criterio de paro
	if (this == nullptr) {
		return;
	}

	//Se salva el izquierdo
	pIzda->posOrden();
	//Se el hijo derecho	
	pDcha->posOrden();
	//Por ultimo salva el padre
	cout << this->fdato << ",";
}
