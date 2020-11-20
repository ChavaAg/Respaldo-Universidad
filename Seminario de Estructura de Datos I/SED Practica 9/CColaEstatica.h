#ifndef CCOLAESTATICA_H_INCLUDED
#define CCOLAESTATICA_H_INCLUDED

#include "CPilaoCola.h"

class CColaEstatica :public CPilaoCola {
private:
	float cola[5];
	int iIndiceInsercion;
	int iIndiceDersecion;
	int iTamano;
public:
	CColaEstatica();
	~CColaEstatica();

	virtual void push(float nd);
	virtual float pop();
	virtual int size();
	bool isEmpty();
	bool isFull();
	virtual void imprimir();
};

#endif // !CCOLAESTATICA_H_INCLUDED
