#include "Nodo.h"

#include <iostream>

Nodo::Nodo(): Izda(nullptr), Dcha(nullptr) {}


	//Getters
Superheroes Nodo::getContenido() {
	return contenido;
}

Nodo* Nodo::getIzda() {
	return Izda;
}

Nodo* Nodo::getDcha() {
	return Dcha;
}

	// Setter
void Nodo::setContenido(Superheroes elemento) {
	contenido = elemento;
}

void Nodo::setIzda(Nodo* puntero) {
	Izda = puntero;
}

void Nodo::setDcha(Nodo* puntero) {
	Dcha = puntero;
}

int Nodo::cuantosHijos() {
	int hijos = 0;

	if(this->Izda != nullptr) {
		hijos++;
	}
	if(this->Dcha != nullptr) {
		hijos++;
	}
	return hijos;
}

