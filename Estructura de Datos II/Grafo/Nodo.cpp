#include "Nodo.h"

using namespace std;

//!implementacion de arista

Arista::Arista(int weight) {
	destino = nullptr;
	peso = weight;

	sigArista = nullptr;
	antArista = nullptr;
}

void Arista::setDestino(Vertice* destination) {
	destino = destination;
}

void Arista::setPeso(int weight) {
	peso = weight;
}

void Arista::setSigArista(Arista* siguiente) {
	sigArista = siguiente;
}

void Arista::setAntArista(Arista* anterior) {
	antArista = anterior;
}

Vertice* Arista::getDestino() {
	return destino;
}

int Arista::getPeso() {
	return peso;
}

Arista* Arista::getSigArista() {
	return sigArista;
}

Arista* Arista::getAntArista() {
	return antArista;
}

string Arista::toString() {
	stringstream ss;

	ss << destino->getContenido().toString() << peso;

	return ss.str();
}

string Arista::toStringGuargar() {
	stringstream ss;

	ss << destino->getContenido().getNombre()<< "|" << peso << "*";

	return ss.str();
}

//!Implementacion de vertice

Vertice::Vertice() {
	sigVertice = nullptr;
	antVertice = nullptr;

	primerArista = nullptr;
}

Aereopuerto Vertice::getContenido() {
	return contenido;
}

Vertice* Vertice::getSigVertice() {
	return sigVertice;
}

Vertice* Vertice::getAntVertice() {
	return antVertice;
}

Arista* Vertice::getPrimerArista() {
	return primerArista;
}

void Vertice::setContenido(Aereopuerto data) {
	contenido = data;
}

void Vertice::setSigVertice(Vertice* siguiente) {
	sigVertice = siguiente;
}

void Vertice::setAntVertice(Vertice* anterior) {
	antVertice = anterior;
}

void Vertice::setPrimerArista(Arista* arista) {
	primerArista = arista;
}

string Vertice::toString() {
	stringstream ss;
	Arista* aux = primerArista;

	ss << "Aereopuerto: "<<getContenido().getNombre()<<endl;
	ss << "Destino  |  Ubicacion  |  Vuelos diarios  |  Distancia" << endl;

	while(aux != nullptr) {
		ss << aux->toString()<<endl;
		aux = aux->getSigArista();
	}

	return ss.str();
}

string Vertice::toStringGuargar() {
	stringstream ss;
	Arista* aux = primerArista;

	while(aux != nullptr) {
		ss << contenido.getNombre() << "|";
		ss << aux->toStringGuargar();		
		aux = aux->getSigArista();
	}

	return ss.str();
}
