#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "Nodo.h"
#include<string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

class Grafo {
private:
	Vertice* ancla;
public:
	Grafo();
	~Grafo();

	bool vacia();
	void insertarVertice(Aereopuerto);
	void insertarArista(string, string, int);
	void eliminarVertice(Vertice*);
	void eliminarArista(Vertice*, Arista*);

	void borrarAristas(Vertice*);
	void borrarVertices();

	Vertice* buscarVertice(string);
	Arista* buscarAristas(string, string);


	void guardar();
	void cargar();

	Vertice* getUltimoVertice();
	Arista* getUltimaArista(Vertice*);

	string toString();
	string toStringGuardar();

};

#endif // !GRAFO_H_INCLUDED
