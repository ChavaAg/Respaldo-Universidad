#include <iostream>
#include <string>
#include <stdlib.h>
#include "listexception.h"
#include "Menu.h"

using namespace std;

bool Menu::inicio(int op) {
	bool finish = true;
	int posicion, ordenar, comparar, buscar;
	string busqueda;
	switch (op) {
	case 1:
	if (MyMenu.vacia()) {
		system("cls");
		getchar();
		optencion();
		posicion = MyMenu.getCantidad();
		MyMenu.inserta(posicion, MyCopias);
		system("cls");
		MyMenu.imprime();
	} else {
		system("cls");
		MyMenu.imprime();
		getchar();
		optencion();
		cout << "Elige la posicion: que desea colocarlo: ";
		cin >> posicion;
		MyMenu.inserta(posicion - 1, MyCopias);
		system("cls");
		MyMenu.imprime();
	}
	break;
	case 2:
	system("cls");
	MyMenu.imprime();
	cout << "Elige la cancion a eliminar: "; cin >> posicion;
	MyMenu.elimina(posicion - 1);
	system("cls");
	MyMenu.imprime();
	break;
	case 3:
	system("cls");
	cout << "Con que dato desea buscar" << endl;
	cout << " 1. Cancion" << endl;
	cout << " 2. Interprete" << endl;
	cout << " Opcion: ";
	getchar();
	cin >> buscar;
	system("cls");
	MyMenu.imprime();
	if (buscar == 1) {
		getchar();
		cout << endl << "Ingrese el nombre de la cancion a buscar en binario: ";
		getline(cin, busqueda);
		system("cls");
		posicion = MyMenu.BusquedaBinariaCancion(busqueda);
		impresionBusqueda(busqueda, posicion);
	} else if (buscar == 2) {
		getchar();
		cout << endl << "Ingrese el nombre de la cancion a buscar en binario: ";
		getline(cin, busqueda);
		system("cls");
		posicion = MyMenu.BusquedaBinariaInterprete(busqueda);
		impresionBusqueda(busqueda, posicion);
	} else {
		cout << "La opcion es invalida" << endl;
	}
	break;
	case 4:
	system("cls");
	cout << "Con que dato desea buscar" << endl;
	cout << " 1. Cancion" << endl;
	cout << " 2. Interprete" << endl;
	cout << " Opcion: ";
	getchar();
	cin >> buscar;
	system("cls");
	MyMenu.imprime();
	if (buscar == 1) {
		getchar();
		cout << endl << "Ingrese el nombre de la cancion a buscar linelmente: ";
		getline(cin, busqueda);
		system("cls");
		posicion = MyMenu.BusquedaLinealCancion(busqueda);
		impresionBusqueda(busqueda, posicion);
	} else if (buscar == 2) {
		getchar();
		cout << endl << "Ingrese el nombre de la cancion a buscar linelmente: ";
		getline(cin, busqueda);
		system("cls");
		posicion = MyMenu.BusquedaLinealInterprete(busqueda);
		impresionBusqueda(busqueda, posicion);
	} else {
		cout << "La opcion es invalida" << endl;
	}
	break;
	case 5:
	system("cls");
	cout << "Como quiere ordenar los datos" << endl;
	cout << " 1. Cancion" << endl;
	cout << " 2. Interprete" << endl;
	cout << " Opcion: ";
	getchar();
	cin >> ordenar;
	system("cls");
	if (ordenar == 1) {
		cout << "Elige el metodo a ordenar" << endl;
		cout << " 1. Bubble" << endl << " 2. Insert" << endl << " 3. Select" << endl << " 4. Shell" << endl;
			cout << " Opcion: "; cin >> comparar;
		MyMenu.ordenacionCancionIterativo(comparar);
	} else if (ordenar == 2) {
		cout << "Elige el metodo a ordenar" << endl;
		cout << " 1. Bubble" << endl << " 2. Insert" << endl << " 3. Select" << endl << " 4. Shell" << endl;
			cout << " Opcion: "; cin >> comparar;
		MyMenu.ordenacionInterpreteIterativo(comparar);
	} else {
		cout << "La opcion es invalida" << endl;
	}
	system("cls");
	MyMenu.imprime();
	break;
	case 6:
	system("cls");
	cout << "Como quiere ordenar los datos" << endl;
	cout << " 1. Cancion" << endl;
	cout << " 2. Interprete" << endl;
	cout << " Opcion: ";
	getchar();
	cin >> ordenar;
	system("cls");
	if (ordenar == 1) {
		cout << "Elige el metodo a ordenar" << endl;
		cout << " 1. Mezcla" << endl << " 2. Quick" << endl;
		cout << " Opcion: "; cin >> comparar;
		MyMenu.ordenacionCancionRecursiva(comparar);
	} else if (ordenar == 2) {
		cout << "Elige el metodo a ordenar" << endl;
		cout << " 1. Mezcla" << endl << " 2. Quick" << endl;
		cout << " Opcion: "; cin >> comparar;
		MyMenu.ordenacionInterpreteRecursiva(comparar);
	} else {
		cout << "La opcion es invalida" << endl;
	}
	system("cls");
	MyMenu.imprime();
	break;
	case 7:
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
void Menu::impresionBusqueda(string busqueda, int posicion) {
	if (posicion == -1) {
		cout << "La cancion " << busqueda << " no esta en la lista de la disquera" << endl;
	} else {
		cout << "La cancion " << busqueda << " se encontro en la posicion: " << posicion << endl <<
			endl;
		cout << "Nombre del archivo mp3: " << MyMenu.recupera(posicion).getMp3() << endl;
		cout << "Nombre de la cancion: " << MyMenu.recupera(posicion).getCancion() << endl;
		cout << "Nombre del autor: " << MyMenu.recupera(posicion).getAutor() << endl;
		cout << "Nombre del interprete: " << MyMenu.recupera(posicion).getInterprete() << endl;
		cout << "Lugar en el ranking: " << MyMenu.recupera(posicion).getRank() << endl;
	}
}
