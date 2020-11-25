#include "CArbol.h"
#include <iostream>

using namespace std;

BTNodo* CArbol::buscarMalPadre(int dato) {
	BTNodo* aux = pRaiz;


	while (aux) {

		if (aux->fdato<dato) {
		
			if (aux->pIzda==nullptr) {
				return nullptr;
			}


			if (aux->pIzda->fdato==dato) {
				return aux;
			} else {
				aux = aux->pIzda;
			}
		} else {
			if (aux->pDcha == nullptr) {
				return nullptr;
			}
			if (aux->pDcha->fdato == dato) {
				return aux;
			} else {
				aux = aux->pDcha;
			}
		}

	}
	

	return nullptr;
}

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

void CArbol::eliminar(int nd) {
	BTNodo* unicoHijo;
	BTNodo* hijoIzda;
	BTNodo* hijoDcha;
	BTNodo* ExtremaDerecha;
	int cuantosHijos;


	if (pRaiz == nullptr) {
		cout << "No se puede eliminar ya que el arbol esta vacio" << endl;
		return;
	}

	if (pRaiz->fdato == nd) {
		cuantosHijos = pRaiz->cuantosHijos();
		switch (cuantosHijos) {
		case 0:
		delete pRaiz;
		break;
		case 1:
		unicoHijo = pRaiz->unicoHijo();
		delete pRaiz;
		pRaiz = unicoHijo;
		break;
		case 2:
		hijoDcha = pRaiz->pDcha;
		hijoIzda = pRaiz->pIzda;

		delete pRaiz;

		pRaiz = hijoIzda;

		ExtremaDerecha = hijoIzda->extremaDerecha();
		ExtremaDerecha->pDcha = hijoDcha;
		break;
		default:
		break;
		}
	}

	BTNodo* malpadre = buscarMalPadre(nd);
	

	if (malpadre==nullptr) {
		return;
	}

	if (malpadre->ToTheLeft(nd)) {
		cuantosHijos = malpadre->pIzda->cuantosHijos();
		switch (cuantosHijos) {
		case 0:
		delete malpadre->pIzda;
		malpadre->pIzda = nullptr;
		break;
		case 1:
		unicoHijo = malpadre->pIzda->unicoHijo();
		delete malpadre->pIzda;
		malpadre->pIzda = unicoHijo;
		break;
		case 2:
		hijoDcha = malpadre->pIzda->pDcha;
		hijoIzda = malpadre->pIzda->pIzda;

		delete malpadre->pIzda;

		malpadre->pIzda = hijoIzda;

		ExtremaDerecha = hijoIzda->extremaDerecha();
		ExtremaDerecha->pDcha = hijoDcha;
		break;
		default:
		break;
		}
	} else {
		cuantosHijos = malpadre->pDcha->cuantosHijos();
		switch (cuantosHijos) {
		case 0:
		delete malpadre->pDcha;
		malpadre->pDcha = nullptr;
		break;
		case 1:
		unicoHijo = malpadre->pDcha->unicoHijo();
		delete malpadre->pDcha;
		malpadre->pDcha = unicoHijo;
		break;
		case 2:
		hijoDcha = malpadre->pDcha->pDcha;
		hijoIzda = malpadre->pDcha->pIzda;

		delete malpadre->pDcha;

		malpadre->pDcha = hijoIzda;

		ExtremaDerecha = hijoIzda->extremaDerecha();
		ExtremaDerecha->pDcha = hijoDcha;
		break;
		default:
		break;
		}
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
