#include "Lista.h"
#include"listexception.h"
#include <iostream>

using namespace std;

Lista::Lista() : cantidad(-1) {}

	//Getters
int Lista::getCantidad() {
	return cantidad;
}


void Lista::inserta(int pos, int d) {

	if (pos != -1 && isValidacion(pos)) {
		throw ListException("La posicion que marcaste es invalida");
		return;
	}

	int gps = cantidad;
	for (; gps > pos; gps--) {
		numeros[gps + 1] = numeros[gps];
	}
	numeros[pos + 1] = d;
	cantidad++;
}

void Lista::elimina(int pos) {

	if (isValidacion(pos)) {
		throw ListException("La posicion que marcaste es invalida");
		return;
	}

	for (int gps = pos; gps < cantidad; gps++) {
		numeros[gps] = numeros[gps + 1];
	}
	cantidad--;
}

bool Lista::vacia() {
	bool validation;

	if (cantidad == -1) {
		validation = true;
		return validation;
	}
	else {
		validation = false;
		return validation;
	}
}
bool Lista::llena() {
	bool validation;

	if (cantidad < 99999) {
		validation = false;
		return validation;
	}
	else {
		validation = true;
		return validation;
	}
}

int Lista::recupera(int pos) {
	if (isValidacion(pos)) {
		throw ListException("La posicion que marcaste es invalida");
	}
	return numeros[pos];
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

bool Lista::isValidacion(int v) {

	if (v >= 0 && v <= cantidad+1 ) {
		return false;
	}

	return true;
}

std::string Lista::toString() {
	string resultado;

	int i = 0;
	while (i <= cantidad) {
		resultado += to_string(numeros[i]) + ",";
		i++;
	}
	resultado += "\n";
	return resultado;
}


	//Busquedas
int Lista::BusquedaLineal(int busquedaLineal) {

	for (int pos = 0; pos <= cantidad; pos++) {

		if (numeros[pos] == busquedaLineal) {
			return pos;
		}
	}
	return -1;
}
int Lista::BusquedaBinaria(int busquedaBinaria) {
	int inicio = 0, final = cantidad, pos;

	while (inicio <= final) {
		pos = (inicio + final) / 2;

		if (numeros[pos] == busquedaBinaria) {
			return pos;
		}

		if (busquedaBinaria < numeros[pos]) {
			final = pos - 1;
		}
		else {
			inicio = pos + 1;
		}
	}
	return -1;
}


	//Metodos de odenamiento
void Lista::intercambioDeDatos(int& a, int& b) {
	int copia = a;
	a = b;
	b = copia;
}

void Lista::OrdenarDatosBubble() {
	int contador = cantidad;
	int gps;
	bool bandera;

	do {
		bandera = false;
		gps = 0;
		while (gps < contador) {
			if (numeros[gps] > numeros[gps + 1]) {
				intercambioDeDatos(numeros[gps], numeros[gps + 1]);
				bandera = true;
			}
			gps++;
		}
		contador--;
	} while (bandera);
}

void Lista::OrdenarDatosInsert() {
	int copia;
	int gps;

	for (int contador = 1; contador <= cantidad; contador++) {
		copia = numeros[contador];

		gps = contador;

		for (; gps > 0 && copia < numeros[gps - 1]; gps--) {
			numeros[gps] = numeros[gps - 1];
		}
		if (contador != gps) {
			numeros[gps] = copia;

		}
	}
}

void Lista::OrdenarDatosSelect() {
	int menor;

	for (int contador = 0; contador < cantidad; contador++) {
		menor = contador;

		for (int gps = contador + 1; gps <= cantidad; gps++) {
			if (numeros[gps] < numeros[menor]) {
				menor = gps;
			}
		}

		if (contador != menor) {
			intercambioDeDatos(numeros[contador], numeros[menor]);
		}
	}
}

void Lista::OrdenarDatosShell() {
	float factor = 0.5;
	int diferencia = (cantidad + 1) * factor;
	int gps;

	while (diferencia > 0) {

		for (int contador = diferencia; contador <= cantidad; contador++) {

			gps = contador;

			while (gps >= diferencia && numeros[gps - diferencia] > numeros[gps]) {
				intercambioDeDatos(numeros[gps - diferencia], numeros[gps]);

				gps -= diferencia;
			}
		}
		diferencia *= factor;
	}
}

void Lista::OrdenarDatosMerge() {
	OrdenarDatosMerge(0, cantidad);
}

void Lista::OrdenarDatosMerge(int extIzquierdo, int extDerecho) {
	//Criterio de paro
	if (extIzquierdo >= extDerecho) {
		return;
	}
	//Se divide la cadena
	int mitad = (extIzquierdo + extDerecho) / 2;

	OrdenarDatosMerge(extIzquierdo, mitad);
	OrdenarDatosMerge(mitad + 1, extDerecho);

	//Copi donde se guardan los datos de la cadena
	static int copia[100000];
	for (int gps = extIzquierdo; gps <= extDerecho; gps++) {
		copia[gps] = numeros[gps];
	}

	int izdo = extIzquierdo, dcha = mitad + 1, ordIzdo = extIzquierdo;

	while (izdo <= mitad && dcha <= extDerecho) {
		while (izdo <= mitad && copia[izdo] <= copia[dcha]) {
			numeros[ordIzdo++] = copia[izdo++];
		}

		if (izdo <= mitad)	{
			while (dcha <= extDerecho && copia[dcha] <= copia[izdo]) {
				numeros[ordIzdo++] = copia[dcha++];
			}
		}
	}

	while (izdo <= mitad) {
		numeros[ordIzdo++] = copia[izdo++];
	}
	while (dcha <= extDerecho) {
		numeros[ordIzdo++] = copia[dcha++];
	}
}

void Lista::OrdenarDatosQuick() {
	OrdenarDatosQuick(0, cantidad);
}

void Lista::OrdenarDatosQuick(int extIzquierdo, int extDerecho) {
	//Criterio de paro
	if (extIzquierdo >= extDerecho) {
		return;
	}

	int izdo = extIzquierdo, dcha = extDerecho;

	while (izdo < dcha) {
		while (izdo < dcha && numeros[izdo] <= numeros[extDerecho]) {
			izdo++;
		}
		while (izdo < dcha && numeros[dcha] >= numeros[extDerecho]) {
			dcha--;
		}

		if (izdo != dcha) {
			intercambioDeDatos(numeros[izdo], numeros[dcha]);
		}
	}

	if (izdo != extDerecho) {
		intercambioDeDatos(numeros[izdo], numeros[extDerecho]);
	}

	OrdenarDatosQuick(extIzquierdo, izdo-1);
	OrdenarDatosQuick(izdo +1, extDerecho);
}