#pragma once
#include "nodo.h"

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

