#ifndef CNODO_H_INCLUDED
#define CNODO_H_INCLUDED

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

#endif // !CNODO_H_INCLUDED