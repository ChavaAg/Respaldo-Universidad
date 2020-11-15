#pragma once
#include <iostream>
#include <string>
#include <string.h>

class Lista {
private:
	int numeros[100000];
	int cantidad;

	void OrdenarDatosMerge(int, int);
	void OrdenarDatosQuick(int, int);
	
public:
	Lista();

	int getCantidad();
	
	void inserta(int, int);
	void elimina(int);
	bool vacia();
	bool llena();
	int recupera(int);
	int primero();
	int ultimo();
	int anterior(int);
	int siguiente(int);
	void anula();
	bool isValidacion(int);

	std::string toString();

	int BusquedaLineal(int);
	int BusquedaBinaria(int);

	void intercambioDeDatos(int&, int&);
	void OrdenarDatosBubble();
	void OrdenarDatosInsert();
	void OrdenarDatosSelect();
	void OrdenarDatosShell();

	void OrdenarDatosMerge();
	void OrdenarDatosQuick();
};

