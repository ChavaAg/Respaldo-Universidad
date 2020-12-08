#include <iostream>
#include <string>
#include "Pila.h"
#include "Cola.h"

using namespace std;

class Convertidor {
private:
	Cola<char> infijo;
	Pila<char> pila;
	Cola<char> posfijo;
public:
	void vaciarAResultado();
	void vaciarParentesis();
	void vaciarSumaYResta();
	void vaciarMultYDiv();
	void trasExpresion(std::string&);
	string toString();
};