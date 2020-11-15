#include <iostream>
#include <string>
#include "ColaAndPilaException.h"

template <class T, int TAM = 1204>
class Pila {
private:
	T dato[TAM];
	int tope;
	void copyAll(const Pila<T, TAM>&);
public:
	Pila();
	Pila(const Pila<T, TAM>&);
	bool isLleno();
	bool isVacio();
	void apilar(const T&);
	T desapilar();
	T ultPila();
	Pila<T, TAM>& operator = (const Pila<T, TAM>&);
};
template <class T, int TAM>
Pila <T, TAM>::Pila() : tope(-1) {}
template<class T, int TAM>
Pila<T, TAM>::Pila(const Pila<T, TAM>& p) {
	copyAll(p);
}
template <class T, int TAM>
void Pila <T, TAM>::copyAll(const Pila<T, TAM>& p) {
	for (int i = 0; i <= p.tope; i++) {
		this->dato[i] = p.dato[i];
	}
	this->tope = p.tope;
}
template <class T, int TAM>
bool Pila <T, TAM>::isVacio() {
	return tope == -1;
}
template <class T, int TAM>
bool Pila <T, TAM>::isLleno() {
	return tope == TAM - 1;
}
template <class T, int TAM>
void Pila<T, TAM>::apilar(const T& a) {
	if (isLleno()) {
		throw ColaAndPilaExecption("Esta lleno");
	}
	dato[++tope] = a;
}
template <class T, int TAM>
T Pila<T, TAM>::desapilar() {
	if (isVacio()) {
		throw ColaAndPilaExecption("Esta vacio");
	}
	return dato[tope--];
}
template <class T, int TAM>
T Pila<T, TAM>::ultPila() {
	if (isVacio()) {
		throw ColaAndPilaExecption("Esta vacio");
	}
	return dato[tope];
}
template <class T, int TAM>
Pila<T, TAM>& Pila<T, TAM>::operator=(const Pila <T, TAM>& o) {
	copyAll(o);
	return *this;
}
