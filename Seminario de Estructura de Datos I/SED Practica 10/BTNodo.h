#ifndef BTNODO_H_INCLUDED
#define BTNODO_H_INCLUDED

class BTNodo {

	friend class CArbol;

private:
	float fdato;
	BTNodo* pIzda;
	BTNodo* pDcha;
public:

	BTNodo();

	void insertar(float nd);
	bool ToTheLeft(float nd);

	void inOrden();
	void preOrden();
	void posOrden();
};


#endif // !BTNODO_H_INCLUDED
