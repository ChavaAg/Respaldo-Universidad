#include "CArbol.h"
#include <stdlib.h>


CArbol::CArbol() {
	pRaiz = nullptr;
}

void CArbol::Akinator() {
	BTNodo* pActual = pRaiz;
	bool bValidacion = true;
	int iX;
	string szNuevoDato;
	string szNuevoPregunta;

	do {
		system("cls");
		if ((pActual->pIzda == nullptr) && (pActual->pDcha == nullptr)) {
			cout << "Lo que estas pensando es: " << pActual->szOracion;
			cout << ",  Acerte?(1 = Si, 2 = No): "; cin >> iX;

			switch (iX) {
			case 1:
				cout << "\nUn punto mas para mi!!\n\nGracias por jugar!!\n\n";
				bValidacion = false;
				break;
			case 2:
				getchar();
				cout << "Repampanos, he perdido\n\nPodrias ingresar lo que estabas pensando: ";
				getline(cin,szNuevoDato);
				cout << "Ahora por favor ingrese una diferenicia entre esos dos: ";
				getline(cin,szNuevoPregunta);

				pActual->insertar(szNuevoDato,szNuevoPregunta);
				bValidacion = false;
				break;
			default:
				break;
			}
		} else {
			cout << pActual->szOracion << "?" << endl;
			cout << "(1 = Si, 2 = No) Opcion: "; cin >> iX;

			if (iX==1) {
				pActual = pActual->pIzda;
			} else if (iX==2) {
				pActual = pActual->pDcha;
			}
		}
	} while (bValidacion);
}

void CArbol::primeraInsercion(string nd) {
	
	if (pRaiz==nullptr) {
		pRaiz = new BTNodo;
		pRaiz->szOracion = nd;
	}
}

bool CArbol::vacio() {
	return pRaiz==nullptr;
}

void CArbol::GuardarArbol() {
	ofstream Salida;

	Salida.open("ArbolGuardado.txt",ios::out);

	Salida << pRaiz->preOrdenGuardar(pRaiz);

	Salida.close();
}

void CArbol::CargarArbol() {
	ifstream Entrada;
	string datos[200];
	string* pIndice = datos;
	string ingresar;

	Entrada.open("ArbolGuardado.txt",ios::in);
	while (!Entrada.eof()) {

		getline(Entrada,ingresar);
		*pIndice++ = ingresar;
	}
	Entrada.close();

	pIndice = datos;

	if (pRaiz==nullptr) {
		pRaiz = new BTNodo;
	
		pRaiz->ingresarArbol(pIndice);

	} else {
		pRaiz->ingresarArbol(pIndice);
	}
}
