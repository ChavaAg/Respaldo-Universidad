#include "Nodo.h"

Nodo::Nodo() : sig(nullptr), ant(nullptr) {}

Nodo::Nodo(const Cancion& e) : contenido(e), sig(nullptr), ant(nullptr) {}

Cancion Nodo::getContenido() {
	return contenido;
}

Nodo* Nodo::getSig() {
	return sig;
}

Nodo* Nodo::getAnt() {
	return ant;
}

void Nodo::setContenido(Cancion elemento) {
	contenido = elemento;
}

void Nodo::setSig(Nodo* p) {
	sig = p;
}

void Nodo::setAnt(Nodo* p) {
	ant = p;
}
