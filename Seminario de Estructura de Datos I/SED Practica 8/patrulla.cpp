#include <iostream>>
#include "patrulla.h"

using namespace std;

CPatrulla::CPatrulla() {
	cout << "Se construyo un patrulla" << endl;
	motor.getCilindrada(50);
	motor.getCilindros(30);
}

CPatrulla::~CPatrulla() {
	cout << "Se destruyo una patrulla" << endl;
}

void CPatrulla::Acelerar() {
	velocidad += 2;
	cout << "Su velocidad actual es: " << velocidad << endl;
}

void CPatrulla::ImprimirVirtual() {
	cout << "Es una patrulla" << endl;
	cout << "Su velocidad actual es: " << velocidad << endl;
	motor.Imprimir();
	cout << endl;
}

void CPatrulla::ImprimirNoVirtual() {
	cout << "Es una patrulla" << endl;
	cout << "Su velocidad actual es: " << velocidad << endl;
	motor.Imprimir();
	cout << endl;
}