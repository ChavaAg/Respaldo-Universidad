#include <iostream>
#include <string>
#include "Datos.h"

using namespace std;

class Lista {
private:
	Datos MyData[3000];
	int cantidad;
public:

	Lista();

	bool vacia();
	bool llena();
	void inserta(int, Datos);
	void elimina(int);
	Datos recupera(int);
	int primero();
	int ultimo();
	int anterior(int);
	int siguiente(int);
	void anula();
	void imprime();
	int getCantidad();
	bool isValidacion(int);

	int BusquedaLineal(string);
	int BusquedaBinaria(string);

	void intercambioDeDatos(Datos&, Datos&);
	void OrdenarDatosBubbleCancion();
	void OrdenarDatosBubbleInterprete();
	void OrdenarDatosShellCancion();
	void OrdenarDatosShellInterprete();
	void OrdenarDatosInsertCancion();
	void OrdenarDatosInsertInterprete();
	void OrdenarDatosSelectCancion();
	void OrdenarDatosSelectInterprete();

	void ordenacionCancion(int);
	void ordenacionInterprete(int);
};
