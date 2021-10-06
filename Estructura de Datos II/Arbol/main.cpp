#include <iostream>
#include "Menu.h"

using namespace std;

int main() {
    Menu myMenu;

	bool finish;
	int op;

	do {
		cout << "Bienvenido a la wiki del heroe" << endl << endl;
		cout << "Elija una de las siguientes opciones:" << endl;
		cout << " 1. Ingresar nueva heroe" << endl << " 2. Eliminar heroe existente" << endl << " 3. Mostrar arbol" << endl;
		cout << " 4. Guardar arbol" << endl << " 5. Cargar arbol" << endl << " 6. Borrar arbol"<<endl<<" 7. Salir del programa" << endl;
		cout << "Opcion: ";
		cin >> op;

		finish = myMenu.inicio(op);
	} while(finish);

    return 0;
}
