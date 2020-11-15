#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include "Producto.h"

using namespace std;

class Coleccion {
private:
	Producto inv[500];
	Fecha date;
	int gps = 0;
public:
	
	void incrementar();
	void decrementar();

	void registro();
	void invActual();
};

