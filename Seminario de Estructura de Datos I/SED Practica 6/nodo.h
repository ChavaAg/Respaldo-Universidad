#pragma once

class CNodo {
	friend class CLista;

private:
	CNodo* pSiguiente;
	CNodo* pAnterior;
	float fContenido;
public:

	void InsertarAdelante(float);
	float EliminarSiguiente();
};
