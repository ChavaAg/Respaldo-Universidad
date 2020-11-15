#include "Matriz.h"
#include <iostream>
#include <iomanip>

using namespace std;


int convertidor;
float entero, decimales, respuesta;
int matrizA[10][10];
int matrizB[10][10];
int matrizC[10][10];
void Matriz::setCantidad(int cant) {
	cantidad = cant;
	impresion();
}
void Matriz::llenarMatriz() {

	for (int filas = 0; filas < cantidad; filas++) {
		for (int columnas = 0; columnas < cantidad; columnas++) {
			entero = rand() % 101;
			decimales = rand() % 100;
			respuesta = entero + (decimales / 100);

			matrizA[filas][columnas] = respuesta;
		}
	}
	for (int filas = 0; filas < cantidad; filas++) {
		for (int columnas = 0; columnas < cantidad; columnas++) {
			entero = rand() % 101;
			decimales = rand() % 100;
			respuesta = entero + (decimales / 100);

			matrizB[filas][columnas] = respuesta;
		}
	}
}
void Matriz::convercion() {
	for (int filas = 0; filas < cantidad; filas++) {
		for (int columnas = 0; columnas < cantidad; columnas++) {
			convertidor = rand() % 2;
			if (convertidor == 0) {
				matrizA[filas][columnas] = -matrizA[filas][columnas];
			}
		}
	}
	for (int filas = 0; filas < cantidad; filas++) {
		for (int columnas = 0; columnas < cantidad; columnas++) {
			convertidor = rand() % 2;
			if (convertidor == 0) {
				matrizB[filas][columnas] = -matrizB[filas][columnas];
			}
		}
	}
}
void Matriz::sumaMatriz() {
	for (int filas = 0; filas < cantidad; filas++) {
		for (int columnas = 0; columnas < cantidad; columnas++) {
			matrizC[filas][columnas] = matrizA[filas][columnas] + matrizB[filas][columnas];
		}
	}
	for (int filas = 0; filas < cantidad; filas++) {
		for (int columnas = 0; columnas < cantidad; columnas++) {
			cout << setw(7) << matrizC[filas][columnas] << setw(7);
		}
		cout << endl;
	}
}
void Matriz::multiplicacion() {
	for (int filas = 0; filas < cantidad; filas++) {
		for (int columnas = 0; columnas < cantidad; columnas++) {
			matrizC[filas][columnas] = matrizA[filas][columnas] * matrizB[filas][columnas];
		}
	}
	for (int filas = 0; filas < cantidad; filas++) {
		for (int columnas = 0; columnas < cantidad; columnas++) {
			cout << setw(7) << matrizC[filas][columnas] << setw(7);
		}
		cout << endl;
	}
}
void Matriz::impresion() {

	llenarMatriz();
	convercion();
	cout << "Matriz A" << endl;
	for (int filas = 0; filas < cantidad; filas++) {
		for (int columnas = 0; columnas < cantidad; columnas++) {
			cout << setw(7) << matrizA[filas][columnas] << setw(7);
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "Matriz B" << endl;
	for (int filas = 0; filas < cantidad; filas++) {
		for (int columnas = 0; columnas < cantidad; columnas++) {
			cout << setw(7) << matrizB[filas][columnas] << setw(7);
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "Suma de matriz" << endl;
	sumaMatriz();
	cout << endl << endl;
	cout << "Multiplicacion de matriz" << endl;
	multiplicacion();
}