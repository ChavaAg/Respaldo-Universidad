
#include "nodo.h"

class CLista {
private:
	CNodo inicio;
	CNodo final;
public:
	CLista();
	~CLista();

	void InsertarInicio(CAuto*);
	void InsertarFinal(CAuto*);
	bool IsEmpty();
	bool isFull();
	int Size();
	void Vaciar();
	void ImprimeVirtual();
	void ImprimeNoVirtual();
	CAuto* EliminarInicio();
	CAuto* EliminarFinal();
};

