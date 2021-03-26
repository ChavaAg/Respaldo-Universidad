#include <iostream>
#include "CArbol.h"
#include <stdlib.h>

using namespace std;

int main() {
	int iOpcion;
	CArbol arbol;

	do {
		cout << "Elija la opcion a escorger" << endl;
		cout << " 1. Jugar\n 2. Guardar el arbol\n 3. Cargar el arbol\n 4. Salir" << endl;
		cout << " Opcion: "; cin >> iOpcion;
		switch (iOpcion) {
		case 1:
			if (arbol.vacio()) {
				arbol.primeraInsercion("Elzio");
			}
			arbol.Akinator();
			break;
		case 2:
			system("cls");
			cout << "\nSe ha guardado su arbol, puede estar en calma\n\n";
			arbol.GuardarArbol();
			break;
		case 3:
			system("cls");
			cout << "\nEl juego anteriormente guardado se ha cargado exitosamente\n\n";
			arbol.CargarArbol();
			break;
		case 4:
			system("cls");
			cout << "\nEspero que hayas guardado, Hasta la proxima" << endl;
			break;
		default:
			break;
		}
	} while (iOpcion != 4);
}