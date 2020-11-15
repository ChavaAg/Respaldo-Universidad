#include "Lista.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "listexception.h"
using namespace std;
Lista::Lista() : cantidad(-1) {}
Lista::~Lista() {
	anula();
}
bool Lista::vacia() {
	bool validation;
	if (cantidad == -1) {
		validation = true;
		return validation;
	} else {
		validation = false;
		return validation;
	}
}
bool Lista::llena() {
	bool validation;
	if (cantidad < 2999) {
		validation = false;
		return validation;
	} else {
		validation = true;
		return validation;
	}
}
void Lista::inserta(int pos, Cancion d) {
	if (pos != -1 && isValidacion(pos)) {
		throw ListException("La posicion que marcaste es invalida");
		return;
	}
	if (llena()) {
		throw ListException("No se puede insertar mas elementos");
		return;
	}
	Cancion* puntero;
	puntero = new Cancion;
	for (int gps = cantidad; gps > pos; gps--) {
		MyData[gps + 1] = MyData[gps];
	}
	*puntero = d;
	MyData[pos + 1] = puntero;
	cantidad++;
}
void Lista::elimina(int pos) {
	if (isValidacion(pos)) {
		throw ListException("La posicion que marcaste es invalida");
		return;
	}
	if (vacia()) {
		throw ListException("La lista esta vacia");
		return;
	}
	delete MyData[pos];
	for (int gps = pos; gps < cantidad; gps++) {
		MyData[gps] = MyData[gps + 1];
	}
	cantidad--;
}
Cancion Lista::recupera(int pos) {
	if (isValidacion(pos)) {
		throw ListException("La posicion que marcaste es invalida");
	}
	return *MyData[pos];
}
int Lista::primero() {
	if (vacia()) {
		return -1;
	}
	return 0;
}
int Lista::ultimo() {
	return cantidad;
}
int Lista::anterior(int a) {
	if (ultimo() == a || isValidacion(a)) {
		return -1;
	}
	return a - 1;
}
int Lista::siguiente(int l) {
	if (llena() || !isValidacion(l)) {
		return -1;
	}
	return l + 1;
}
void Lista::imprime() {
	cout << "N de lista || Nombre de la Cancion || Nombre del Autor || Nombre del interprete || Ranking"
		<< endl;
	for (int i = 0; i <= cantidad; i++) {
		cout << i + 1 << "° " << MyData[i]->toString() << endl;
	}
}
int Lista::getCantidad() {
	return cantidad;
}
void Lista::anula() {
	for (int i = 0; i < cantidad; i++) {
		delete MyData[i];
		MyData[i] = nullptr;
	}
	cantidad = -1;
}
bool Lista::isValidacion(int v) {
	if (v >= 0 && v <= cantidad + 1) {
		return false;
	}
	return true;
}
int Lista::BusquedaLinealCancion(string busquedaLineal) {
	for (int pos = 0; pos <= cantidad; pos++) {
		if (MyData[pos]->getCancion() == busquedaLineal) {
			return pos;
		}
	}
	return -1;
}
int Lista::BusquedaLinealInterprete(string busquedaLineal) {
	for (int pos = 0; pos <= cantidad; pos++) {
		if (MyData[pos]->getInterprete() == busquedaLineal) {
			return pos;
		}
	}
	return -1;
}
int Lista::BusquedaBinariaCancion(string busquedaBinaria) {
	int inicio = 0, final = cantidad, pos;
	while (inicio <= final) {
		pos = (inicio + final) / 2;
		if (MyData[pos]->getCancion() == busquedaBinaria) {
			return pos;
		}
		if (busquedaBinaria < MyData[pos]->getCancion()) {
			final = pos - 1;
		} else {
			inicio = pos + 1;
		}
	}
	return -1;
}
int Lista::BusquedaBinariaInterprete(string busquedaBinaria) {
	int inicio = 0, final = cantidad, pos;
	while (inicio <= final) {
		pos = (inicio + final) / 2;
		if (MyData[pos]->getInterprete() == busquedaBinaria) {
			return pos;
		}
		if (busquedaBinaria < MyData[pos]->getInterprete()) {
			final = pos - 1;
		} else {
			inicio = pos + 1;
		}
	}
	return -1;
}
void Lista::intercambioDeDatos(Cancion*& a, Cancion*& b) {
	Cancion* copia = a;
	a = b;
	b = copia;
}
void Lista::OrdenarDatosBubbleCancion() {
	int contador = cantidad;
	int gps;
	bool bandera;
	do {
		bandera = false;
		gps = 0;
		while (gps < contador) {
			if (MyData[gps]->getCancion() > MyData[gps + 1]->getCancion()) {
				intercambioDeDatos(MyData[gps], MyData[gps + 1]);
				bandera = true;
			}
			gps++;
		}
		contador--;
	} while (bandera);
}
void Lista::OrdenarDatosBubbleInterprete() {
	int contador = cantidad;
	int gps;
	bool bandera;
	do {
		bandera = false;
		gps = 0;
		while (gps < contador) {
			if (MyData[gps]->getInterprete() > MyData[gps + 1]->getInterprete()) {
				intercambioDeDatos(MyData[gps], MyData[gps + 1]);
				bandera = true;
			}
			gps++;
		}
		contador--;
	} while (bandera);
}
void Lista::OrdenarDatosInsertCancion() {
	Cancion* copia;
	int gps;
	for (int contador = 1; contador <= cantidad; contador++) {
		copia = MyData[contador];
		gps = contador;
		for (; gps > 0 && copia->getCancion() < MyData[gps - 1]->getCancion(); gps--) {
			MyData[gps] = MyData[gps - 1];
		}
		if (contador != gps) {
			MyData[gps] = copia;
		}
	}
}
void Lista::OrdenarDatosInsertInterprete() {
	Cancion* copia;
	for (int contador = 1; contador <= cantidad; contador++) {
		copia = MyData[contador];
		int gps = contador;
		for (; gps > 0 && copia->getInterprete() < MyData[gps - 1]->getInterprete(); gps--) {
			MyData[gps] = MyData[gps - 1];
		}
		if (contador != gps) {
			MyData[gps] = copia;
		}
	}
}
void Lista::OrdenarDatosSelectCancion() {
	int menor;
	for (int contador = 0; contador < cantidad; contador++) {
		menor = contador;
		for (int gps = contador + 1; gps <= cantidad; gps++) {
			if (MyData[gps]->getCancion() < MyData[menor]->getCancion()) {
				menor = gps;
			}
		}
		if (contador != menor) {
			intercambioDeDatos(MyData[contador], MyData[menor]);
		}
	}
}
void Lista::OrdenarDatosSelectInterprete() {
	for (int contador = 0; contador < cantidad; contador++) {
		int menor = contador;
		for (int gps = contador + 1; gps <= cantidad; gps++) {
			if (MyData[gps]->getInterprete() < MyData[menor]->getInterprete()) {
				menor = gps;
			}
		}
		if (contador != menor) {
			intercambioDeDatos(MyData[contador], MyData[menor]);
		}
	}
}
void Lista::OrdenarDatosShellCancion() {
	float factor = 0.5;
	int diferencia = (cantidad + 1) * factor;
	int gps;
	while (diferencia > 0) {
		for (int contador = diferencia; contador <= cantidad; contador++) {
			gps = contador;
			while (gps >= diferencia && MyData[gps - diferencia]->getCancion() > MyData[gps] -> getCancion()) {
				intercambioDeDatos(MyData[gps - diferencia], MyData[gps]);
				gps -= diferencia;
			}
		}
		diferencia *= factor;
	}
}
void Lista::OrdenarDatosShellInterprete() {
	float factor = 0.5;
	int diferencia = (cantidad + 1) * factor;
	int gps;
	while (diferencia > 0) {
		for (int contador = diferencia; contador <= cantidad; contador++) {
			gps = contador;
			while (gps >= diferencia && MyData[gps - diferencia]->getInterprete() > MyData[gps]->getInterprete()) {
				intercambioDeDatos(MyData[gps - diferencia], MyData[gps]);
				gps -= diferencia;
			}
		}
		diferencia *= factor;
	}
}
void Lista::OrdenarDatosMergeCancion() {
	OrdenarDatosMergeCancion(0, cantidad);
}
void Lista::OrdenarDatosMergeCancion(int extIzquierdo, int extDerecho) {
	//Criterio de paro
	if (extIzquierdo >= extDerecho) {
		return;
	}

	//Se divide la cadena
	int mitad = (extIzquierdo + extDerecho) / 2;
	OrdenarDatosMergeCancion(extIzquierdo, mitad);
	OrdenarDatosMergeCancion(mitad + 1, extDerecho);

	//Copi donde se guardan los datos de la cadena
	static Cancion* copia[100000];
	for (int gps = extIzquierdo; gps <= extDerecho; gps++) {
		copia[gps] = MyData[gps];
	}
	int izdo = extIzquierdo, dcha = mitad + 1, ordIzdo = extIzquierdo;
	while (izdo <= mitad && dcha <= extDerecho) {
		while (izdo <= mitad && copia[izdo]->getCancion() <= copia[dcha]->getCancion()) {
			MyData[ordIzdo++] = copia[izdo++];
		}
		if (izdo <= mitad) {
			while (dcha <= extDerecho && copia[dcha]->getCancion() <= copia[izdo] -> getCancion()) {
				MyData[ordIzdo++] = copia[dcha++];
			}
		}
	}
	while (izdo <= mitad) {
		MyData[ordIzdo++] = copia[izdo++];
	}
	while (dcha <= extDerecho) {
		MyData[ordIzdo++] = copia[dcha++];
	}
}
void Lista::OrdenarDatosMergeInterprete() {
	OrdenarDatosMergeInterprete(0, cantidad);
}
void Lista::OrdenarDatosMergeInterprete(int extIzquierdo, int extDerecho) {
	//Criterio de paro
	if (extIzquierdo >= extDerecho) {
		return;
	}

	//Se divide la cadena
	int mitad = (extIzquierdo + extDerecho) / 2;
	OrdenarDatosMergeInterprete(extIzquierdo, mitad);
	OrdenarDatosMergeInterprete(mitad + 1, extDerecho);

	//Copi donde se guardan los datos de la cadena
	static Cancion* copia[100000];
	for (int gps = extIzquierdo; gps <= extDerecho; gps++) {
		copia[gps] = MyData[gps];
	}
	int izdo = extIzquierdo, dcha = mitad + 1, ordIzdo = extIzquierdo;
	while (izdo <= mitad && dcha <= extDerecho) {
		while (izdo <= mitad && copia[izdo]->getInterprete() <= copia[dcha]->getInterprete()) {
			MyData[ordIzdo++] = copia[izdo++];
		}
		if (izdo <= mitad) {
			while (dcha <= extDerecho && copia[dcha]->getInterprete() <= copia[izdo] -> getInterprete()) {
				MyData[ordIzdo++] = copia[dcha++];
			}
		}
	}
	while (izdo <= mitad) {
		MyData[ordIzdo++] = copia[izdo++];
	}
	while (dcha <= extDerecho) {
		MyData[ordIzdo++] = copia[dcha++];
	}
}
//Cancion
void Lista::OrdenarDatosQuickCancion() {
	OrdenarDatosQuickCancion(0, cantidad);
}
void Lista::OrdenarDatosQuickCancion(int extIzquierdo, int extDerecho) {
	//Criterio de paro
	if (extIzquierdo >= extDerecho) {
		return;
	}

	int izdo = extIzquierdo, dcha = extDerecho;

	while (izdo < dcha) {
		while (izdo < dcha && MyData[izdo]->getCancion() <= MyData[extDerecho]->getCancion()) {
			izdo++;
		}
		while (izdo < dcha && MyData[dcha]->getCancion() >= MyData[extDerecho]->getCancion()) {
			dcha--;
		}
		if (izdo != dcha) {
			intercambioDeDatos(MyData[izdo], MyData[dcha]);
		}
	}
	if (izdo != extDerecho) {
		intercambioDeDatos(MyData[izdo], MyData[extDerecho]);
	}
	OrdenarDatosQuickCancion(extIzquierdo, izdo - 1);
	OrdenarDatosQuickCancion(izdo + 1, extDerecho);
}
void Lista::OrdenarDatosQuickInterprete() {
	OrdenarDatosQuickInterprete(0, cantidad);
}
void Lista::OrdenarDatosQuickInterprete(int extIzquierdo, int extDerecho) {
	//Criterio de paro
	if (extIzquierdo >= extDerecho) {
		return;
	}
	int izdo = extIzquierdo, dcha = extDerecho;
	while (izdo < dcha) {
		while (izdo < dcha && MyData[izdo]->getInterprete() <= MyData[extDerecho]->getInterprete()) {
			izdo++;
		}
		while (izdo < dcha && MyData[dcha]->getInterprete() >= MyData[extDerecho] ->getInterprete()) {
			dcha--;
		}
		if (izdo != dcha) {
			intercambioDeDatos(MyData[izdo], MyData[dcha]);
		}
	}
	if (izdo != extDerecho) {
		intercambioDeDatos(MyData[izdo], MyData[extDerecho]);
	}
	OrdenarDatosQuickInterprete(extIzquierdo, izdo - 1);
	OrdenarDatosQuickInterprete(izdo + 1, extDerecho);
}
void Lista::ordenacionCancionIterativo(int op) {
	if (vacia()) {
		throw ListException("La lista esta vacia, no se puede buscar");
	}
	switch (op) {
	case 1:
	OrdenarDatosBubbleCancion();
	break;
	case 2:
	OrdenarDatosInsertCancion();
	break;
	case 3:
	OrdenarDatosSelectCancion();
	break;
	case 4:
	OrdenarDatosShellCancion();
	break;
	default:
	cout << "La opcion es invalida" << endl;
	break;
	}
}
void Lista::ordenacionInterpreteIterativo(int op) {
	if (vacia()) {
		throw ListException("La lista esta vacia, no se puede buscar");
	}
	switch (op) {
	case 1:
	OrdenarDatosBubbleInterprete();
	break;
	case 2:
	OrdenarDatosInsertInterprete();
	break;
	case 3:
	OrdenarDatosSelectInterprete();
	break;
	case 4:
	OrdenarDatosShellInterprete();
	break;
	default:
	cout << "La opcion es invalida" << endl;
	break;
	}
}
void Lista::ordenacionCancionRecursiva(int op) {
	if (vacia()) {
		throw ListException("La lista esta vacia, no se puede buscar");
	}
	switch (op) {
	case 1:
	OrdenarDatosMergeCancion();
	break;
	case 2:
	OrdenarDatosQuickCancion();
	break;
	default:
	cout << "La opcion es invalida" << endl;
	break;
	}
}
void Lista::ordenacionInterpreteRecursiva(int op) {
	if (vacia()) {
		throw ListException("La lista esta vacia, no se puede buscar");
	}
	switch (op) {
	case 1:
	OrdenarDatosMergeInterprete();
	break;
	case 2:
	OrdenarDatosQuickInterprete();
	break;
	default:
	cout << "La opcion es invalida" << endl;
	break;
	}
}