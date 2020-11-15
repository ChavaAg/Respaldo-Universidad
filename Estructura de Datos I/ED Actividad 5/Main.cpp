#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

int main() {
	Menu myMenu;

	bool finish;
	int op;

	do {
		cout << "Bienvenido a la radiodifusora As Elemental" << endl << endl;
		cout << "Elija una de las siguientes opciones:" << endl;
		cout << " 1. Ingresar nueva cancion" << endl << " 2. Eliminar cancion existente" << endl << " 3. Busqueda Binaria" << endl << " 4. Busqueda Lineal" << endl;
		cout << " 5. Salir del programa" << endl << "Opcion: "; cin >> op;

		finish = myMenu.inicio(op);
	} while (finish);
	return 0;
}