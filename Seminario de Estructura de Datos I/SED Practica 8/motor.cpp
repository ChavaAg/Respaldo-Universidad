#include <iostream>
#include "motor.h"

using namespace std;

void CMotor::Imprimir() {
	cout << "Tiene " << cilindros << " cilindros" << endl;
	cout << "Tiene una cilindrada " << cilindrada << endl;
}

void CMotor::getCilindros(int i) {
	cilindros = i;
}

void CMotor::getCilindrada(int p) {
	cilindrada = p;
}