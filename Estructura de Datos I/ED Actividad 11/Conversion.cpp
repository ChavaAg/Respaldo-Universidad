#include <string>
#include <iostream>
#include "Conversion.h"
using namespace std;
void Convertidor::vaciarAResultado() {

	if (pila.vacio()) {
		return;
	}
	do {
		char character = pila.pop();
		posfijo.enColar(character);
	} while (!pila.vacio());
}
void Convertidor::vaciarParentesis() {
	do {
		char character = pila.getTop();
		if (character=='(') {
			return;
		}
		posfijo.enColar(character);
		pila.pop();
	} while (!pila.vacio());
}
void Convertidor::vaciarSumaYResta() {
	do {
		char character = pila.getTop();
		if (character=='+'||character=='-'||character=='(') {
			break;
		}
		posfijo.enColar(character);
		pila.pop();
	} while (!pila.vacio());
}
void Convertidor::vaciarMultYDiv() {
	do {
		char character = pila.getTop();
		if (character=='+'||character=='-'||character=='*'||character==
			'/'||character=='(') {
			break;
		}
		posfijo.enColar(character);
		pila.pop();
	} while (!pila.vacio());
}
void Convertidor::trasExpresion(string& f) {
	for (int i = 0; i<=f.length()-1; i++) {
		infijo.enColar(f[i]);
	}
	do {
		char character = infijo.desColar();
		switch (character) {
		case '*':
			if (pila.vacio()) {
				pila.push(character);
			} else {
				vaciarSumaYResta();
				pila.push(character);
			}
			break;
		case '/':
			if (pila.vacio()) {
				pila.push(character);
			} else {
				vaciarSumaYResta();
				pila.push(character);
			}
			break;
		case '+':
			if (pila.vacio()) {
				pila.push(character);
			} else {
				vaciarParentesis();
				pila.push(character);
			}
			break;
		case '-':
			if (pila.vacio()) {
				pila.push(character);
			} else {
				vaciarParentesis();
				pila.push(character);
			}
			break;
		case '^':
			if (pila.vacio()) {
				pila.push(character);
			} else {
				vaciarMultYDiv();
				pila.push(character);
			}
			break;
		case '(':
			pila.push(character);
			break;
		case ')':
			vaciarParentesis();
			pila.pop();
			break;
		default:
			posfijo.enColar(character);
			break;
		}
	} while (!infijo.vacio());
	vaciarAResultado();
}
string Convertidor::toString() {
	string resultado = "";
	do {
		resultado += posfijo.desColar();
	} while (!posfijo.vacio());
	return resultado;
}
