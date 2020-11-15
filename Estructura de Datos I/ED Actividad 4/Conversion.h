#include <iostream>
#include <string>
#include "Pila.h"
#include "Cola.h"

using namespace std;

class Convertidor {
private:
	Cola<char, 60> infijo;
	Pila<char, 60> pila;
	Cola<char, 60> posfijo;
public:
	void vaciarAResultado();
	void vaciarParentesis();
	void vaciarSumaYResta();
	void vaciarMultYDiv();
	void trasExpresion(std::string&);
	string toString();
};
