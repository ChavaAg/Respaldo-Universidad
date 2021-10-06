#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Arbol.h"

class Menu {
public:
	Arbol arbol;
	Superheroes MyCopias;

	bool inicio(int);
	void optencion();
};

#endif // !MENU_H_INCLUDED
