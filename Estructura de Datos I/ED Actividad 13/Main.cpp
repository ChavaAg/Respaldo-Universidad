#include "BArbol.h"
#include <iostream>
#include <random>
#include <chrono>
#include <functional>

using namespace std;

int main() {
	default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> distribution(0,1000);
	auto dice = bind(distribution,generator);

	BArbol <int> arbol;
	int cantidad;
	int valores;

	cout << "Cuantos numeros desea generar\nCantidad: ";
	cin >> cantidad;

	cout << "\nDatos insertados: " << endl;

	for (int i = 0; i < cantidad; i++) {

		valores = dice();
		cout << valores << ",";
		arbol.insertar(valores);
	}

	cout << "\n\nRecorrido en PreOrder: \n";
	arbol.preOrder();
	cout << endl << endl;

	cout << "Recorrido en IneOrder: \n";
	arbol.inOrder();
	cout << endl << endl;

	cout << "Recorrido en PosOrder: \n";
	arbol.posOrder();
	cout << endl << endl;;

	cout << "La altura del arbol a la izquierda: \n";
	cout << arbol.getAlturaIzda();
	cout << endl << endl;;

	cout << "La altura del arbol a la derecha: \n";
	cout << arbol.getAlturaDcha();
	cout << endl << endl;

	return 0;
}