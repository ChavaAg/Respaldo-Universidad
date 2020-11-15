#include <string>
#include <climits>
#include <iostream>
#include <cfloat>
#include "Tipo de dato.h"
#include "Matriz.h"
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;
int main() {

	int op, cant;

	TipoDato d1("Caracter con signo", sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
	TipoDato d2("Caracter sin signo", sizeof(unsigned char), 0, UCHAR_MAX);
	TipoDato d3("Entero corto con signo", sizeof(short), SHRT_MIN, SHRT_MAX);
	TipoDato d4("Entero corto sin signo", sizeof(unsigned short), 0, USHRT_MAX);
	TipoDato d5("Entero largo con signo", sizeof(long), LONG_MIN, LONG_MAX);
	TipoDato d6("Entero largo sin signo", sizeof(unsigned long), 0, ULONG_MAX);
	TipoDato d7("Real de precision simpleo", sizeof(float), FLT_MIN, FLT_MAX);
	TipoDato d8("Real de doble precision", sizeof(double), DBL_MAX, DBL_MAX);
	Matriz m1;


	do {
		cout << "Por favor elija una de las siguientes opciones" << endl << endl;
		cout << " 1. Tamano y rangos de los Tipos de Dato Primitivos" << endl;
		cout << " 2. Ejemplo de uso de Tipo de dato Estructurado" << endl;
		cout << " 3. Salir del programa" << endl;
		cout << "opcion: "; cin >> op;
		cout << endl;
		switch (op) {
		case 1:
		system("cls");
		cout << "Tipo de dato" << setw(15) << "||" << setw(5) << "Bits||";
		cout << " Valor minimo " << "||" << "Valor maximo" << endl;
		d1.tabla();
		d2.tabla();
		d3.tabla();
		d4.tabla();
		d5.tabla();
		d6.tabla();
		d7.tabla();
		d8.tabla();
		cout << endl;
		break;
		case 2:
		system("cls");

		cout << "Ingresa el tamano de la matriz (entre 3 y 10)" << endl;
		cout << "Cantidad: "; cin >> cant;
		if (cant < 11 && cant>2) {
			m1.setCantidad(cant);
		} else {
			system("cls");
			cout << "No es un numero valido" << endl;
		}
		cout << endl << endl;
		break;
		case 3:
		system("cls");
		cout << "Gracias por usar el programa hasta luego" << endl << endl;
		break;
		default:
		cout << "Opcion no valida" << endl << endl;
		break;
		}
	} while (op != 3);
}
