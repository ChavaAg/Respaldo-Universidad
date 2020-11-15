#include <iostream>
#include <string>
#include "ColaAndPilaException.h"


template <class T, int TAM = 1024>
class Cola {
private:
	T data[TAM];
	int frontpos;
	int endpos;
	void copyAll(const Cola<T, TAM>&);
public:
	Cola();
	bool isVacio();
	bool isLleno();
	void enCola(const T&);
	T desColar();
	T getFront();
	Cola<T, TAM>& operator = (const Cola<T, TAM>&);
};
template<class T, int TAM>
void Cola<T, TAM>::copyAll(const Cola<T, TAM>& q) {
	for (int i = 0; i <= TAM; i++) {
		data[i] = q.data[i];
	}
	frontpos = q.frontpos;
	endpos = q.endpos;
}
template <class T, int TAM>
Cola<T, TAM>::Cola() : frontpos(0), endpos(TAM - 1) {}
template <class T, int TAM>
bool Cola<T, TAM>::isVacio() {
	return frontpos == endpos + 1
		or (frontpos == 0 and endpos == TAM - 1);
}
template <class T, int TAM>
bool Cola<T, TAM>::isLleno() {
	return frontpos == endpos + 2
		or (frontpos == 0 and endpos == TAM - 2)
		or (frontpos == 1 and endpos == TAM - 1);
}
template <class T, int TAM>
void Cola<T, TAM>::enCola(const T& e) {
	if (isLleno()) {
		throw ColaAndPilaExecption("Desbordamiento de datos enCola");
	}
	if (++endpos == TAM) {
		endpos = 0;
	}
	data[endpos] = e;
}
template <class T, int TAM>
T Cola<T, TAM>::desColar() {
	if (isVacio()) {
		throw ColaAndPilaExecption("Insuficiencia de datos enCola");
	}
	T result(data[frontpos]);
	if (++frontpos == TAM) {
		frontpos = 0;
	}
	return result;
}
template <class T, int TAM>
T Cola<T, TAM>::getFront() {
	if (isVacio()) {
		throw ColaAndPilaExecption("Insuficiencia de datos enCola");
	}
	return data[frontpos];
}
template <class T, int TAM>
Cola<T, TAM>& Cola<T, TAM>::operator = (const Cola<T, TAM>& q) {
	copyAll(q);
	return *this;
}