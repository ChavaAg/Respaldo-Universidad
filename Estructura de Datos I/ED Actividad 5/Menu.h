#pragma once

#include <iostream>
#include <string>
#include "Lista.h"

class Menu {
public:
	Lista MyMenu;
	Datos MyCopias;


	bool inicio(int);
	void optencion();
	void impresionBusqueda(string,int);
};


