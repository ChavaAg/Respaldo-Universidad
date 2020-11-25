#ifndef CARBOL_H_INCLUDED
#define CARBOL_H_INCLUDED

#include "BTNodo.h"

class CArbol {
private:
	BTNodo* pRaiz;

	BTNodo* buscarMalPadre(int);
public:
	
	CArbol ();

	void insertar(float nd);
	void eliminar(int nd);

	void inOrden();
	void preOrden();
	void posOrden();
};


#endif // !CARBOL_H_INCLUDED

