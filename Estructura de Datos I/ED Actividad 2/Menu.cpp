#include "Menu.h"
#include <iostream>
#include <string>

#include <stdlib.h>

using namespace std;

bool Menu::inicio(int op) {
	bool finish= true;

	switch (op){
	case 1:
		system("cls");
		getchar();
		inventario.registro(); 
		break;
	case 2:
		system("cls");
		getchar();


		inventario.invActual();
		break;
	case 3:
		system("cls");
		getchar();
		inventario.decrementar();
		break;
	case 4:
		system("cls");
		getchar();
		inventario.incrementar();
		break;
	case 5:
		system("cls");
		cout << "Gracias por usar este programa" << endl;
		finish = false;
		break;
	default:
		system("cls");
		cout << "No es una opcion valida" << endl;
		break;
	}
	cout << endl;

	return finish;
}



