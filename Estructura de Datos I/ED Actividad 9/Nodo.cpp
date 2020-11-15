#include "Nodo.h"

Nodo::Nodo(): sig(nullptr) {}

Nodo::Nodo(const Cancion& e) : contenido(e), sig(nullptr){}

Cancion Nodo::getContenido() {
	return contenido;
}

Nodo* Nodo::getSig() {
	return sig;
}

void Nodo::setContenido(Cancion elemento) {
	contenido = elemento;
}

void Nodo::setSig(Nodo* p) {
	sig = p;
}