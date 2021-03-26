#ifndef BTNODO_H_INCLUDED
#define BTNODO_H_INCLUDED


#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class BTNodo {

	friend class CArbol;

private:
	string szOracion;
	BTNodo* pIzda;
	BTNodo* pDcha;

public:

	BTNodo();
	
	void insertar(string, string);
	
	BTNodo* getIzda();
	BTNodo* getDcha();

	string preOrdenGuardar(BTNodo*);
	string* ingresarArbol(string*);

};

#endif // !BTNODO_H_INCLUDED