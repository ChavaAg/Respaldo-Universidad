#include "toreto.h"
#include <iostream>

using namespace std;

CToreto_Car::CToreto_Car() {
	cout << "Se construyo un carro al estilo Toreto" << endl;
	motor.getCilindrada(20);
	motor.getCilindros(5);
}

CToreto_Car::~CToreto_Car() {
	cout << "Se destruyo un carro al estilo Toreto" << endl;
}

void CToreto_Car::Acelerar() {
	velocidad += 3;
	cout << "Su velocidad actual es: " << velocidad << endl;
}

void CToreto_Car::Turbo() {
	velocidad += 10;
	cout << "Su velocidad actual es: " << velocidad << endl;
}

void CToreto_Car::ImprimirVirtual() {
	cout << "Es un carro de toreto" << endl;
	cout << "Su velocidad actual es: " << velocidad << endl;
	motor.Imprimir();
	cout << endl;
}

void CToreto_Car::ImprimirNoVirtual() {
	cout << "Es un carro de toreto" << endl;
	cout << "Su velocidad actual es: " << velocidad << endl;
	motor.Imprimir();
	cout << endl;
}