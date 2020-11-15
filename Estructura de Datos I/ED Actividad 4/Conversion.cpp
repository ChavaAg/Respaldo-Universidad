#include <string>
#include <iostream>
#include "Conversion.h"
using namespace std;
void Convertidor::vaciarAResultado() {

	if (pila.isVacio()) {
		return;
	}
	do {
		char character = pila.desapilar();
		posfijo.enCola(character);
	} while (!pila.isVacio());
}
void Convertidor::vaciarParentesis() {
	do {
		char character = pila.ultPila();
		if (character == '(') {
			return;
		}
		posfijo.enCola(character);
		pila.desapilar();
	} while (!pila.isVacio());
}
void Convertidor::vaciarSumaYResta() {
	do {
		char character = pila.ultPila();
		if (character == '+' || character == '-' || character == '(') {
			break;
		}
		posfijo.enCola(character);
		pila.desapilar();
	} while (!pila.isVacio());
}
void Convertidor::vaciarMultYDiv() {
	do {
		char character = pila.ultPila();
		if (character == '+' || character == '-' || character == '*' || character ==
			'/' || character == '(') {
			break;
		}
		posfijo.enCola(character);
		pila.desapilar();
	} while (!pila.isVacio());
}
void Convertidor::trasExpresion(string& f) {
	for (int i = 0; i <= f.length() - 1; i++) {
		infijo.enCola(f[i]);
	}
	do {
		char character = infijo.desColar();
		switch (character) {
		case '*':
		if (pila.isVacio()) {
			pila.apilar(character);
		} else {
			vaciarSumaYResta();
			pila.apilar(character);
		}
		break;
		case '/':
		if (pila.isVacio()) {
			pila.apilar(character);
		} else {
			vaciarSumaYResta();
			pila.apilar(character);
		}
		break;
		case '+':
		if (pila.isVacio()) {
			pila.apilar(character);
		} else {
			vaciarParentesis();
			pila.apilar(character);
		}
		break;
		case '-':
		if (pila.isVacio()) {
			pila.apilar(character);
		} else {
			vaciarParentesis();
			pila.apilar(character);
		}
		break;
		case '^':
		if (pila.isVacio()) {
			pila.apilar(character);
		} else {
			vaciarMultYDiv();
			pila.apilar(character);
		}
		break;
		case '(':
		pila.apilar(character);
		break;
		case ')':
		vaciarParentesis();
		pila.desapilar();
		break;
		default:
		posfijo.enCola(character);
		break;
		}
	} while (!infijo.isVacio());
	vaciarAResultado();
}
string Convertidor::toString() {
	string resultado = "";
	do {
		resultado += posfijo.desColar();
	} while (!posfijo.isVacio());
	return resultado;
}