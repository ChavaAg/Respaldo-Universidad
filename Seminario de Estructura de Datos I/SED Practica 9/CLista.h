#ifndef CLISTA_H_INCLUDED
#define CLISTA_H_INCLUDED

#include "CNodo.h"

class CLista {
private:
	CNodo inicio;
	CNodo final;
public:
	CLista();
	~CLista();

	void InsertarInicio(float);
	void InsertarFinal(float);
	bool IsEmpty();
	bool isFull();
	int Size();
	void Vaciar();
	void Imprime();
	float EliminarInicio();
	float EliminarFinal();
};

#endif // !CLISTA_H_INCLUDED


