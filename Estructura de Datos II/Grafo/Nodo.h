
#include <sstream>
#include <string>
#include <iostream>
#include "Aereopuerto.h"

using namespace std;

class Vertice;

class Arista {
private:
	Vertice* destino;
	int peso;
	Arista* sigArista;
	Arista* antArista;
public:
	Arista(int);

	void setDestino(Vertice*);
	void setPeso(int);
	void setSigArista(Arista*);
	void setAntArista(Arista*);

	Vertice* getDestino();
	int getPeso();
	Arista* getSigArista();
	Arista* getAntArista();

	string toString();
	string toStringGuargar();

};

class Vertice {
private:
	Aereopuerto contenido;
	Vertice* sigVertice;
	Vertice* antVertice;
	Arista* primerArista;
public:
	Vertice();

	Aereopuerto getContenido();
	Vertice* getSigVertice();
	Vertice* getAntVertice();
	Arista* getPrimerArista();

	void setContenido(Aereopuerto);
	void setSigVertice(Vertice*);
	void setAntVertice(Vertice*);
	void setPrimerArista(Arista*);

	string toString();
	string toStringGuargar();
};