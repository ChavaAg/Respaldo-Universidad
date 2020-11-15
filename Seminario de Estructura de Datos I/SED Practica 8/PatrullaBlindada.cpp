#include "PatrullaBlindada.h"
#include <iostream>

using namespace std;

CPatullaArtillada::CPatullaArtillada() :blindaje(20) {
	cout << "Se construyo un patrulla artillada" << endl << endl;
	motor.getCilindrada(90);
	motor.getCilindros(45);
}

CPatullaArtillada::~CPatullaArtillada() {
	cout << "Se destruyo una patrulla artillada" << endl;
}

void CPatullaArtillada::Acelerar() {
	velocidad += 1.5;
	cout << "Su velocidad actual es: " << velocidad << endl;
}

void CPatullaArtillada::ImprimirVirtual() {
	cout << "Es una patrulla blindada" << endl;
	cout << "Tienes un blindaje de " << blindaje << endl;
	cout << "Su velocidad actual es: " << velocidad << endl;
	motor.Imprimir();
	cout << endl;
}

void CPatullaArtillada::ImprimirNoVirtual() {
	cout << "Es una patrulla blindada" << endl;
	cout << "Tienes un blindaje de " << blindaje << endl;
	cout << "Su velocidad actual es: " << velocidad << endl;
	motor.Imprimir();
	cout << endl;
}
