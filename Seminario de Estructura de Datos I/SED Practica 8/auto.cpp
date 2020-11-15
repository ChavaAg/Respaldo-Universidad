#include "auto.h"
#include <iostream>

using namespace std;

CAuto::CAuto() : velocidad(0) {
	cout << "Se construyo un auto" << endl;
	motor.getCilindrada(14);
	motor.getCilindros(20);
}

CAuto::~CAuto() {
	cout << "Se destruyo un auto" << endl;
}

void CAuto::ImprimirVirtual() {
	cout << "Es un auto" << endl;
	cout << "Su velocidad actual es: " << velocidad << endl;
	motor.Imprimir();
	cout << endl;
}

void CAuto::ImprimirNoVirtual() {
	cout << "Es un auto" << endl;
	cout << "Su velocidad actual es: " << velocidad << endl;
	motor.Imprimir();
	cout << endl;
}

void CAuto::Acelerar() {
	velocidad += 1;
	cout << "Su velocidad actual es: " << velocidad << endl;
}

void CAuto::setMotor(CMotor e) {
	motor = e;
}