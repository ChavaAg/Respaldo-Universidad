#include "lista.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

CAuto* fnOptencion(CAuto* pAuto, CLista lista) {
	int iOpcion;

	do {
		cout << endl << "Ahora entramos en el campo de prebas" << endl << endl;
		cout << "Seleccion unaopcion" << endl;
		cout << " 1. Acelerar" << endl << " 2. Finalizar" << endl;
		cout << " Opcion: "; cin >> iOpcion;
		switch(iOpcion) {
		case 1:
			system("cls");
			cout << "Ha acelerado el vehiculo" << endl;
			pAuto->Acelerar();
			break;
		case 2:
			system("cls");
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while(iOpcion != 2);

	return pAuto;
}

CToreto_Car* fnOptencionToreto(CToreto_Car* pToreto, CLista lista) {
	int iOpcion;

	do {
		cout << endl << "Ahora entramos en el campo de prebas" << endl << endl;
		cout << "Seleccion unaopcion" << endl;
		cout << " 1. Acelerar" << endl << " 2. Turbo" << endl << " 3. Finalizar" << endl;
		cout << " Opcion: "; cin >> iOpcion;

		switch(iOpcion) {
		case 1:
			system("cls");
			cout << "Ha acelerado el vehiculo" << endl;
			pToreto->Acelerar();
			break;
		case 2:
			system("cls");
			cout << "Ha acelerado el vehiculo" << endl;
			pToreto->Turbo();
			break;
		case 3:
			system("cls");
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while(iOpcion != 3);

	return pToreto;
}

int main() {
	CLista lista;
	CAuto* pAuto;
	CToreto_Car* pToreto;
	int iVehiculo, iOpcion, iOp;

	do {
		cout << "Bienvenido a la autotaller As Elemental" << endl << endl << "Por favor ingrese el la opcion a escoger" << endl;
		cout << " 1. Contruir vehiculo" << endl << " 2. Mostrar vehiculos registrados No virtual" << endl << " 3. Mostrar vehiculos registrados Virtual" << endl;
		cout << " 4. Eliminar el primero vehiculo registrado en la lista" << endl << " 5. Eliminar el ultimo vehiculo registrado en la lista" << endl << " 6. Salir" << endl;
		cout << " Opcion: "; cin >> iOp;
		switch(iOp) {
		case 1:
			system("cls");
			cout << "Que vehiculo desea crear" << endl;
			cout << " 1. Auto" << endl << " 2. Patrulla" << endl << " 3. Patrulla Artillada" << endl << " 4. Taxi" << endl << " 5. Carro de toreto" << endl << " 6. Salir" << endl;
			cout << " Opcion: "; cin >> iVehiculo;

			switch(iVehiculo) {
			case 1:
				system("cls");
				pAuto = new CAuto;
				lista.InsertarFinal(fnOptencion(pAuto, lista));
				break;
			case 2:
				system("cls");
				pAuto = new CPatrulla;
				lista.InsertarFinal(fnOptencion(pAuto, lista));
				break;
			case 3:
				system("cls");
				pAuto = new CPatullaArtillada;
				lista.InsertarFinal(fnOptencion(pAuto, lista));
				break;
			case 4:
				system("cls");
				pAuto = new CTaxi;
				lista.InsertarFinal(fnOptencion(pAuto, lista));
				break;
			case 5:
				system("cls");
				pToreto = new CToreto_Car;
				lista.InsertarFinal(fnOptencionToreto(pToreto, lista));
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
			}
			break;
		case 2:
			system("cls");
			lista.ImprimeNoVirtual();
			break;
		case 3:
			system("cls");
			lista.ImprimeVirtual();
			break;
		case 4:
			system("cls");
			cout << lista.EliminarInicio() << endl;
			break;
		case 5:
			system("cls");
			cout << lista.EliminarFinal() << endl;
			break;
		case 6:
			system("cls");
			cout << "Gracias por su preferencia, hasta luego" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while(iOp != 6);
}
