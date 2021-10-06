#include "Grafo.h"
#include <stdlib.h>

using namespace std;

Grafo::Grafo() {
	ancla = nullptr;
}

Grafo::~Grafo() {
	borrarVertices();
}

bool Grafo::vacia() {
	return ancla == nullptr;
}

void Grafo::insertarVertice(Aereopuerto ver) {
	Vertice* aux = new Vertice();
	Vertice* ultimo = getUltimoVertice();

	if(vacia()) {
		ancla = aux;
		aux->setContenido(ver);
	}
	else {
		aux->setContenido(ver);
		ultimo->setSigVertice(aux);
		aux->setAntVertice(ultimo);
	}
	
}

void Grafo::insertarArista(string origin, string destination, int peso) {
	
	Arista* nueva = new Arista(peso);

	Vertice* origen = buscarVertice(origin);
	Vertice* destino = buscarVertice(destination);

	if(origen and destino) {
		Arista* aux = origen->getPrimerArista();

		if(aux == nullptr) {
			origen->setPrimerArista(nueva);
			nueva->setDestino(destino);
		}
		else {
			while(aux->getSigArista() != nullptr)
				aux = aux->getSigArista();

			aux->setSigArista(nueva);
			nueva->setAntArista(aux);
			nueva->setDestino(destino);
		}
	}
	else {
		cout << "No existen esos vertices";
	}
}

void Grafo::eliminarVertice(Vertice* eliminar) {

	if(eliminar == ancla)
		ancla = ancla->getSigVertice();

	if(eliminar->getAntVertice() != nullptr)
		eliminar->getAntVertice()->setSigVertice(eliminar->getSigVertice());

	if(eliminar->getSigVertice() != nullptr)
		eliminar->getSigVertice()->setAntVertice(eliminar->getAntVertice());

	borrarAristas(eliminar);

	Vertice* aux = ancla;
	Arista* temp;

	while(aux != nullptr) {
		temp = buscarAristas(aux->getContenido().getNombre(), eliminar->getContenido().getNombre());
		if(temp != nullptr) {
			eliminarArista(aux, temp);
		}
		aux = aux->getSigVertice();
	}
	delete eliminar;
}

void Grafo::eliminarArista(Vertice* origen, Arista* destino) {
	
	if(destino == origen->getPrimerArista())
		origen->setPrimerArista(origen->getPrimerArista()->getSigArista());

	if(destino->getAntArista() != nullptr)
		destino->getAntArista()->setSigArista(destino->getSigArista());

	if(destino->getSigArista() != nullptr)
		destino->getSigArista()->setAntArista(destino->getAntArista());

	delete destino;
}

void Grafo::borrarAristas(Vertice* dato) {
	
	Arista* aux;

	while(dato->getPrimerArista() != nullptr) {
		aux = dato->getPrimerArista();
		dato->setPrimerArista(dato->getPrimerArista()->getSigArista());
		delete aux;
	}
}

void Grafo::borrarVertices() {
	Vertice* aux = ancla;

	while(ancla != nullptr) {
		aux = ancla;
		ancla = ancla->getSigVertice();
		borrarAristas(aux);
		delete aux;
	}
}

Vertice* Grafo::buscarVertice(string data) {

	Vertice* aux = ancla;
	while(aux) {
		if(aux->getContenido().getNombre() == data) {
			return aux;
		}
		aux = aux->getSigVertice();
	}

	return nullptr;
}

Arista* Grafo::buscarAristas(string origen, string destino) {
	Vertice* temp = buscarVertice(origen);
	Arista* aux = temp->getPrimerArista();

	while(aux) {
		if(aux->getDestino()->getContenido().getNombre() == destino) {
			return aux;
		}
		aux = aux->getSigArista();
	}

	return nullptr;
}


void Grafo::guardar() {
	ofstream salida;

	salida.open("file01.txt", ios::out);

	if(salida.fail()) {
		cout << "El archivo no se pudo abrir";
		exit(1);
	}

	salida << toStringGuardar();

	salida.close();
}

void Grafo::cargar() {
	ifstream entrada;
	string vertice, arista, peso;
	Aereopuerto copia;
	char delimitador;

	entrada.open("file01.txt", ios::in);

	if(entrada.fail()) {
		cout << "El archivo no se pudo abrir";
		exit(1);
	}


	while(true) {
		getline(entrada,vertice,'|');
		copia.setNombre(vertice);

		getline(entrada, vertice, '|');
		copia.setLugar(vertice);

		getline(entrada, vertice, '|');
		copia.setVuelos(atoi(vertice.c_str()));

		insertarVertice(copia);

		entrada.get(delimitador);

		if(delimitador == '*') {
			break;
		}
	}

	if(entrada.eof()) {
		return;
	}

	while(true) {

		getline(entrada, vertice,'|');
		getline(entrada, arista,'|');
		getline(entrada, peso,'*');

		if(entrada.eof()) {
			break;
		}

		insertarArista(vertice, arista, atoi(peso.c_str()));
	}
	entrada.close();
}

Vertice* Grafo::getUltimoVertice() {
	if(vacia()) {
		return nullptr;
	}

	Vertice* aux = ancla;

	while(aux->getSigVertice() != nullptr) {
		aux = aux->getSigVertice();
	}

	return aux;
}

Arista* Grafo::getUltimaArista(Vertice* vertice) {
	if(vacia()) {
		return nullptr;
	}

	Arista* aux = vertice->getPrimerArista();

	while(aux->getSigArista() != nullptr) {
		aux = aux->getSigArista();
	}

	return aux;
}

string Grafo::toString() {

	stringstream ss;
	Vertice* aux = ancla;

	ss << "Lo que ve son las conexiones de cada aeropuerto"<<endl<<endl;

	while(aux != nullptr) {
		ss << aux->toString() << endl;
		aux = aux->getSigVertice();
	}
	return ss.str();
}

string Grafo::toStringGuardar() {

	stringstream ss;
	Vertice* aux = ancla;

	while(aux != nullptr) {
		ss << aux->getContenido().toString();
		if(aux->getSigVertice() != nullptr) {
			ss << "/";
		}
		else {
			ss << "*";
		}
		aux = aux->getSigVertice();
	}
	aux = ancla;
	while(aux != nullptr) {
		ss << aux->toStringGuargar();
		aux = aux->getSigVertice();
	}

	return ss.str();
}
