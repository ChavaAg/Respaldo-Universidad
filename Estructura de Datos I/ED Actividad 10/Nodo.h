#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "Cancion.h"

class Nodo {
private:
	Cancion contenido;
	Nodo* sig;
	Nodo* ant;
public:

	Nodo();
	Nodo(const Cancion&);

	Cancion getContenido();
	Nodo* getSig();
	Nodo* getAnt();

	void setContenido(Cancion);
	void setSig(Nodo*);
	void setAnt(Nodo*);
};

#endif // !NODO_H_INCLUDED