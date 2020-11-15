#include <iostream>
#include <string>
#include <string.h>
#include "listexception.h"
#include "Lista.h"

using namespace std;


Lista::Lista() : cantidad(-1) {}

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
void Lista::inserta(int pos, Datos d) {

	for (int gps = cantidad; gps > pos; gps--) {
		MyData[gps + 1] = MyData[gps];
	}

	MyData[pos + 1] = d;
	cantidad++;
}
void Lista::elimina(int pos) {

	for (int gps = pos; gps < cantidad; gps++) {
		MyData[gps] = MyData[gps + 1];
	}
	cantidad--;
}
Datos Lista::recupera(int pos) {
	if (isValidacion(pos)) {
		throw ListException("La posicion que marcaste es invalida");
	}
	return MyData[pos];
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
	if (ultimo() == a || !isValidacion(a)) {
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
void Lista::anula() {
	cantidad = -1;
}
void Lista::imprime() {
	cout << "N de lista || Nombre de la Cancion || Nombre del Autor || Nombre del interprete || Ranking" << endl;

	for (int i = 0; i <= cantidad; i++) {
		cout << i + 1 << "° " << MyData[i].toString() << endl;
	}

}
int Lista::getCantidad() {
	return cantidad;
}
bool Lista::isValidacion(int v) {

	if (v >= 0 && v <= cantidad + 1) {
		return false;
	}

	return true;
}
int Lista::BusquedaLineal(string busquedaLineal) {

	for (int pos = 0; pos <= cantidad; pos++) {

		if (MyData[pos].getCancion() == busquedaLineal) {
			return pos;
		}
	}
	return -1;
}
int Lista::BusquedaBinaria(string busquedaBinaria) {
	int inicio = 0, final = cantidad, pos;

	while (inicio <= final) {
		pos = (inicio + final) / 2;

		if (MyData[pos] == busquedaBinaria) {
			return pos;
		}

		if (busquedaBinaria < MyData[pos].getCancion()) {
			final = pos - 1;
		} else {
			inicio = pos + 1;
		}
	}
	return -1;
}

void Lista::intercambioDeDatos(Datos& a, Datos& b) {
	Datos copia = a;
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
			if (MyData[gps] > MyData[gps + 1]) {
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
			if (MyData[gps].getInterprete() > MyData[gps + 1].getInterprete()) {
				intercambioDeDatos(MyData[gps], MyData[gps + 1]);
				bandera = true;
			}
			gps++;
		}
		contador--;
	} while (bandera);
}


void Lista::OrdenarDatosInsertCancion() {
	Datos copia;
	int gps;

	for (int contador = 1; contador <= cantidad; contador++) {
		copia = MyData[contador];

		gps = contador;

		for (; gps > 0 && copia < MyData[gps - 1]; gps--) {
			MyData[gps] = MyData[gps - 1];
		}
		if (contador != gps) {
			MyData[gps] = copia;

		}
	}
}

void Lista::OrdenarDatosInsertInterprete() {
	Datos copia;

	for (int contador = 1; contador <= cantidad; contador++) {
		copia = MyData[contador];

		int gps = contador;

		for (; gps > 0 && copia.getInterprete() < MyData[gps - 1].getInterprete(); gps--) {
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
			if (MyData[gps] < MyData[menor]) {
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
			if (MyData[gps].getInterprete() < MyData[menor].getInterprete()) {
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

			while (gps >= diferencia && MyData[gps - diferencia] > MyData[gps]) {
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

			while (gps >= diferencia && MyData[gps - diferencia].getInterprete() > MyData[gps].getInterprete()) {
				intercambioDeDatos(MyData[gps - diferencia], MyData[gps]);

				gps -= diferencia;
			}
		}
		diferencia *= factor;
	}
}
void Lista::ordenacionCancion(int op) {

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

void Lista::ordenacionInterprete(int op) {

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
