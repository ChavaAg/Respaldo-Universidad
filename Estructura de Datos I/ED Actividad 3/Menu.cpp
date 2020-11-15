#include <iostream>
#include <string>
#include <stdlib.h>
#include "listexception.h"
#include "Menu.h"

using namespace std;

bool Menu::inicio(int op) {
	bool finish = true;
	int posicion;


	switch (op)	{
	case 1:

		if (MyMenu.vacia()) {
			system("cls");
			getchar();
			optencion();
			posicion = MyMenu.getCantidad();
			MyMenu.inserta(posicion, MyCopias);
			system("cls");
			MyMenu.imprime();
		}
		else if (MyMenu.llena()) {
			throw ListException("No se puede agregar mas elementos a la lista");
		}
		else {
			system("cls");
			MyMenu.imprime();
			getchar();
			optencion();
			cout << "Elige la posicion: que desea colocarlo: ";
			cin >> posicion;
			if (MyMenu.isValidacion(posicion)) {
				throw ListException("La posicion que marcaste es invalida");
			}
			else {
				MyMenu.inserta(posicion - 1, MyCopias);
			}
			system("cls");
			MyMenu.imprime();
		}
		break;
	case 2:
		if (MyMenu.vacia()) {
			
			throw ListException("No hay ninguna cancion registrada");
		}
		else {
			system("cls");
			MyMenu.imprime();
			cout << "Elige la cancion a eliminar: "; cin >> posicion;
			if (MyMenu.isValidacion(posicion)) {
				throw ListException("La posicion que marcaste es invalida");
			}
			else {
				MyMenu.elimina(posicion - 1);
			}
			system("cls");
			MyMenu.imprime();
		}
		
		break;
	case 3:
		finish = false;
		return finish;
	default:
		cout << "Esta es una opcion invalida" << endl;
		break;
	}
	cout << endl;
	return finish;
}

void Menu::optencion() {
	string oracion;
	int num;

	cout << "Ingresa el nombre de la cancion: ";
	getline(cin, oracion);
	MyCopias.setCancion(oracion);

	cout << "Ingresa el nombre del interprete: ";
	getline(cin, oracion);
	MyCopias.setInteprete(oracion);

	cout << "Ingresa el nombre del autor: ";
	getline(cin, oracion);
	MyCopias.setAutor(oracion);

	cout << "Ingresa el numero del ranking de la cancion: ";
	cin >> num;
	MyCopias.setRank(num);
}