#include <iostream>
#include "Menu.h"

using namespace std;

int main() {
	Menu myMenu;

	bool finish;
	int op;

	do {
		cout << "Bienvenido a la logistica de vuelos UdG\n\n";
		cout << "Elija una de las siguientes opciones:\n";
		cout << " 1. Ingresar aereopuerto\n 2. Ingresar trayecto\n 3. Eliminar areopuerto\n 4. Eliminar trayecto\n";
		cout << " 5. Mostar grafo\n 6. Guardar logistica\n 7. Cargar logistica\n 8. Salir del programa" << endl;
		cout << "Opcion: ";
		cin >> op;

		finish = myMenu.inicio(op);
	} while(finish);

	return 0;
}