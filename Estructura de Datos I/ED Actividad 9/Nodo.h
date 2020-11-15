#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "Cancion.h"

class Nodo {
private:
	Cancion contenido;
	Nodo* sig;
public:

	Nodo();
	Nodo(const Cancion&);

	Cancion getContenido();
	Nodo* getSig();

	void setContenido(Cancion);
	void setSig(Nodo*);
};

#endif // !NODO_H_INCLUDED




