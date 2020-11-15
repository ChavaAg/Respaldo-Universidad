#include <iostream>
#include <string>
#include "Lista.h"

class Menu {
public:
	Lista MyMenu;
	Cancion MyCopias;
	bool inicio(int);
	void optencion();
	void impresionBusqueda(string, int);
};