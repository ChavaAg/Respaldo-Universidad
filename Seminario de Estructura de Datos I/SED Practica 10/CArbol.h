#ifndef CARBOL_H_INCLUDED
#define CARBOL_H_INCLUDED

#include "BTNodo.h"

class CArbol {
private:
	BTNodo* pRaiz;
public:
	CArbol ();

	void insertar(float nd);

	void inOrden();
	void preOrden();
	void posOrden();
};


#endif // !CARBOL_H_INCLUDED

