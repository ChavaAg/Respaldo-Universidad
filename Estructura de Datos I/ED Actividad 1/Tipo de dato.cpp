#include <string>
#include <iostream>
#include "Tipo de dato.h"
#include <iomanip>

using namespace std;

TipoDato::TipoDato(string x, int y, double z, double n) {
	nombre = x;
	bits = y;
	valorMin = z;
	valorMax = n;
}
void TipoDato::tabla() {
	cout << left << setw(25) << nombre << setw(3) << "||" << setw(3) << bits << setw(3) << "||";
	cout << setw(13) << right << valorMin << "||" << setw(12) << right << valorMax << endl;
}