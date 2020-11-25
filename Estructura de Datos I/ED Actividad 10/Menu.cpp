#include "Menu.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

bool Menu::inicio(int op) {
	int insertar, insercion;
	bool finish = true;
	string busqueda;


	switch (op) {
	case 1:

	if (MyMenu.vacia()) {
		system("cls");
		getchar();
		optencion();
		MyMenu.inserta(MyMenu.getPrimero(), MyCopias);
		system("cls");
		cout << MyMenu.toString() << endl;
	} else {
		system("cls");
		cout << MyMenu.toString() << endl << endl;;
		cout << "Elige el el donde quieres insertar la nueva cancion\n 1. Al principio\n 2. En cualquier posicion\n 3. Al final\n Opcion: ";
		cin >> insertar;

		switch (insertar) {
		case 1:
		system("cls");
		getchar();
		optencion();
		MyMenu.inserta(MyMenu.getPrimero(), MyCopias);
		system("cls");
		cout << MyMenu.toString() << endl;
		break;
		case 2:
		getchar();
		optencion();
		getchar();
		system("cls");
		cout << "Que dato va elegir para poser insertar\n 1. Cancion\n 2. Interprete\n Opcion: ";
		cin >> insercion;
		getchar();
		system("cls");
		cout << MyMenu.toString() << endl;
		cout << "Ingresa el nombre donde deseas insertar" << endl;
		getline(cin, busqueda);
		pos = busquedas(busqueda, insercion);
		if (pos == nullptr) {
			system("cls");
			cout << "El dato que se uso como referencia no se encuentra en la lista" << endl << endl;;
		} else {
			MyMenu.inserta(pos, MyCopias);
			system("cls");
		}
		cout << MyMenu.toString() << endl;
		break;
		case 3:
		system("cls");
		getchar();
		optencion();
		MyMenu.inserta(MyMenu.getUltimo(), MyCopias);
		system("cls");
		cout << MyMenu.toString() << endl;
		break;
		default:
		cout << "La opcion elegida es invalida" << endl;
		break;
		}
	}
	break;
	case 2:
	system("cls");
	cout << MyMenu.toString() << endl;
	cout << "Que dato va elegir para poder eliminar\n 1. Cancion\n 2. Interprete" << endl;
	getchar();
	cin >> insercion;
	cout << endl << "Elige el elemento para a eliminar: ";
	getchar();
	getline(cin, busqueda);
	pos = busquedas(busqueda, insercion);
	if (pos == nullptr) {
		system("cls");
		cout << "El dato que se uso como referencia no se encuentra en la lista" << endl << endl;
	} else {
		MyMenu.elimina(pos);
		system("cls");
	}
	cout << MyMenu.toString() << endl;
	break;
	case 3:

	system("cls");
	cout << MyMenu.toString() << endl;
	cout << "Que dato va elegir para poder buscar\n 1. Cancion\n 2. Interprete" << endl;
	getchar();
	cin >> insercion;
	cout << "Ingresa el dato a buscar" << endl;
	getchar();
	getline(cin, busqueda);
	system("cls");
	impresionBusqueda(busqueda, busquedas(busqueda, insercion));
	break;
	case 4:
	system("cls");
	MyMenu.borradorHD();
	break;
	case 5:
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

	cout << "Ingresa el nombre del archivo mp3: ";
	getline(cin, oracion);
	oracion = oracion + ".mp3";
	MyCopias.setMp3(oracion);

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

void Menu::impresionBusqueda(string busqueda, Nodo* posicion) {
	if (posicion == nullptr) {
		cout << "La cancion " << busqueda << " no esta en la lista de la disquera" << endl;
	} else {
		cout << "La cancion " << busqueda << " se encontro en la posicion: " << posicion << endl << endl;

		cout << "Nombre del archivo mp3: " << MyMenu.recupera(posicion).getMp3() << endl;
		cout << "Nombre de la cancion: " << MyMenu.recupera(posicion).getCancion() << endl;
		cout << "Nombre del autor: " << MyMenu.recupera(posicion).getAutor() << endl;
		cout << "Nombre del interprete: " << MyMenu.recupera(posicion).getInterprete() << endl;
		cout << "Lugar en el ranking: " << MyMenu.recupera(posicion).getRank() << endl;
	}
}

Nodo* Menu::busquedas(string oracion, int op) {

	if (op == 1) {
		return MyMenu.busquedaCancion(oracion);
	} else if (op == 2) {
		return MyMenu.busquedaInterprete(oracion);
	}
}