#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

int main() {

	Menu menu;
	
	bool finish;
	int op = 0;

	do{
		cout << "Elija una de las siguiente sopciones" << endl << endl;
		cout << " 1° Registrar producto" << endl << " 2° Mostrar productos" << endl << " 3° Retirar producto" << endl << " 4° Incrementar producto" << endl << " 5° Salir" << endl;
		cout << " Opcion: "; cin >> op;
		
		finish = menu.inicio(op);
	} while (finish);
	
	cout << endl << endl;
}