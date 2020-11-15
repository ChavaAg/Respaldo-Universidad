#include <iostream>
#include "Datos.h"


void Datos::setNumero(int num) {
	numero = num;
}


bool Datos::operator < (Datos& c) {
	return numero < c.numero;
}
bool Datos::operator>(Datos& c) {
	return numero > c.numero;
}
bool Datos::operator <= (Datos& c) {
	return numero <= c.numero;
}
bool Datos::operator>=(Datos& c) {
	return numero >= c.numero;
}