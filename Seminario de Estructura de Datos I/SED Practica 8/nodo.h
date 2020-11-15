#include "PatrullaBlindada.h"
#include "taxi.h"
#include "toreto.h"


class CNodo {
	friend class CLista;
private:
	CNodo* pSiguiente;
	CNodo* pAnterior;
	CAuto* fContenido;
public:

	void InsertarAdelante(CAuto*);
	CAuto* EliminarSiguiente();
};
