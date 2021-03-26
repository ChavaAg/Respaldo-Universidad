#ifndef CARBOL_H_INCLUDED
#define CARBOL_H_INCLUDED

#include "BTNodo.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class CArbol {
private:
	BTNodo* pRaiz;
public:

	CArbol();

	void Akinator();
	void primeraInsercion(string);

	bool vacio();

	void GuardarArbol();
	void CargarArbol();
};

#endif // !CARBOL_H_INCLUDED