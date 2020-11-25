#include <string>
#include "Lista.h"
#include "Cancion.h"


class Menu {
public:
	Lista MyMenu;
	Cancion MyCopias;

	Lista::Position pos;

	bool inicio(int);
	void optencion();
	void impresionBusqueda(string, Nodo*);
	Nodo* busquedas(string, int);
};