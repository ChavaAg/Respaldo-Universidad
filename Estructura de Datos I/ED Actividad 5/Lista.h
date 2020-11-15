#pragma once
#include <iostream>
#include <string>
#include "Datos.h"

using namespace std;

class Lista {
private:
	Datos MyData[50];
	int cantidad;
public:
	
	Lista();

	bool vacia();
	bool llena();
	void inserta(int, Datos);
	void elimina(int);
	Datos recupera(int);
	int primero();
	int ultimo();
	int anterior(int);
	int siguiente(int);
	void anula();
	void imprime();
	int getCantidad();
	bool isValidacion(int);

	int BusquedaLineal(string);
	int BusquedaBinaria(string);
};

