#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Grafo.h"
#include <iostream>

class Menu {
public:
	Grafo grafo;
	Aereopuerto MyCopias;

	bool inicio(int);
	void optencion();
};

#endif // !MENU_H_INCLUDED
