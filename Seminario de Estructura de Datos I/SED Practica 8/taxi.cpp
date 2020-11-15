#include "taxi.h"
#include <iostream>

using namespace std;

CTaxi::CTaxi() {
	cout << "Se creo un taxi" << endl;
	motor.getCilindrada(40);
	motor.getCilindros(25);
}

CTaxi::~CTaxi() {
	cout << "Se destruyo un taxi" << endl;
}

void CTaxi::Acelerar() {
	velocidad += 5;
	cout << "Su velocidad actual es: " << velocidad << endl;
}

void CTaxi::ImprimirVirtual() {
	cout << "Es un taxi" << endl;
	cout << "Su velocidad actual es: " << velocidad << endl;
	motor.Imprimir();
	cout << endl;
}

void CTaxi::ImprimirNoVirtual() {
	cout << "Es un taxi" << endl;
	cout << "Su velocidad actual es: " << velocidad << endl;
	motor.Imprimir();
	cout << endl;
}