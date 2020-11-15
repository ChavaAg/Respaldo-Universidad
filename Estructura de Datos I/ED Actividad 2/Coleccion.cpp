#include "Coleccion.h"
#include <iostream>
#include <string>

using namespace std;

void Coleccion::registro() {
	bool validacion;
	string oracion;
	float flotante;
	int entero;

	cout << "Codigo: ";
	getline(cin, oracion);

	if (oracion.length() == 13) {

		for (int i = 0; i < gps; i++) {

			if (inv[i].getCodigo() == oracion) {

				cout << "Este codigo ya ha sido actualizado" << endl;
				break;
			}
		}

		inv[gps].setCodigo(oracion);


		cout << "Nombre del producto: ";
		getline(cin, oracion);
		inv[gps].setNombre(oracion);

		cout << "Peso del producto: ";
		cin >> flotante;
		inv[gps].setPeso(flotante);

		cout << "Precio al Mayoreo: ";
		cin >> flotante;
		inv[gps].setMayoreo(flotante);

		cout << "Precio al Menudeo: ";
		cin >> flotante;
		inv[gps].setMenudeo(flotante);

		cout << "Existencias a agregar: (Max 500) ";
		validacion = true;
		do {
			cin >> entero;
			if (entero <=500) {
				inv[gps].setExistencia(entero);
				validacion = false;
			}
			else {
				cout << "Sobrepasa la capasidad permitida!!" << endl << endl << "Existencias a agregar (Max 500): ";
			}

		} while (validacion);


		

		cout << "Fecha de entrega" << endl;

		cout << "Dia: "; 
		validacion = true;
		do {
			cin >> entero;
			if ((entero > 0) && (entero < 32)) {
				date.setDia(entero);
				validacion = false;
			}
			else {
				cout << "Numero invalido!!" << endl << endl << "Dia: ";
			}

		} while (validacion);

		cout << "Mes: "; 
		validacion = true;
		do {
			cin >> entero;
			if ((entero > 0) && (entero <13)) {
				date.setMes(entero);
				validacion = false;
			}
			else {
				cout << "Numero invalido!!" << endl << endl << "Mes: ";
			}

		} while (validacion);

		cout << "Ano: ";
		validacion = true;
		do {
			cin >> entero;
			if (entero != 0) {
				date.setAno(entero);
				validacion = false;
			}
			else {
				cout << "Numero invalido!!" << endl << endl << "Ano: ";
			}

		} while (validacion);

		inv[gps].setEntrada(date);

		gps++;
	}
	else {
		cout << "El codigo es no es de 13 dijitos" << endl;
	}	
}

void Coleccion::incrementar() {
	int incremento;
	string codigo;

	cout << "Ingrese el codigo del producto registrado" << endl;
	getline(cin, codigo);

	if (codigo.length() == 13) {

		for (int i = 0; i < gps; i++) {

			if (inv[i].getCodigo() == codigo) {

				cout << "Producto encontrado, ahora por favor ingrese cuantos va ingresar" << endl;
				cin >> incremento;

				inv[i].incremento(incremento);
				break;
			}
		}
	}else {
		cout << "El codigo es no es de 13 dijitos" << endl;
	}

}
void Coleccion::decrementar() {
	int decremento;
	string codigo;

	cout << "Ingrese el codigo del producto registrado" << endl;
	getline(cin, codigo);

	if (codigo.length() == 13) {

		for (int i = 0; i < gps; i++) {

			if (inv[i].getCodigo() == codigo) {

				cout << "Producto encontrado, ahora por favor ingrese cuantos vas a retirar" << endl;
				cin >> decremento;

				inv[i].decremento(decremento);
				break;
			}
		}
	}
	else {
		cout << "El codigo es no es de 13 dijitos" << endl;
	}
}





void Coleccion::invActual() {
	
	cout << "Nombre del producto || Codigo de barras || Fecha de entrada || Precio al mayoreo || Precio al menudeo || Existencias" << endl<<endl;

	for (int i = 0; i < gps; i++) {
		cout << inv[i].convertidor() << endl;
	}
}

