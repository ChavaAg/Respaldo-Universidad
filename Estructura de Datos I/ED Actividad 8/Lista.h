#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


#include <iostream>
#include <string>
#include "Cancion.h"

using namespace std;

class Lista {
private:
	Cancion* MyData[3000];
	int cantidad;

	void OrdenarDatosMergeCancion(int, int);
	void OrdenarDatosQuickCancion(int, int);

	void OrdenarDatosMergeInterprete(int, int);
	void OrdenarDatosQuickInterprete(int, int);
public:
	Lista();
	~Lista();
	bool vacia();
	bool llena();
	void inserta(int, Cancion);
	void elimina(int);
	Cancion recupera(int);
	int primero();
	int ultimo();
	int anterior(int);
	int siguiente(int);
	void anula();
	void imprime();
	int getCantidad();
	bool isValidacion(int);

	int BusquedaLinealCancion(string);
	int BusquedaLinealInterprete(string);
	int BusquedaBinariaCancion(string);
	int BusquedaBinariaInterprete(string);
	void intercambioDeDatos(Cancion*&, Cancion*&);
	void OrdenarDatosBubbleCancion();
	void OrdenarDatosBubbleInterprete();
	void OrdenarDatosShellCancion();
	void OrdenarDatosShellInterprete();
	void OrdenarDatosInsertCancion();
	void OrdenarDatosInsertInterprete();
	void OrdenarDatosSelectCancion();
	void OrdenarDatosSelectInterprete();

	void OrdenarDatosMergeCancion();
	void OrdenarDatosQuickCancion();
	void OrdenarDatosMergeInterprete();
	void OrdenarDatosQuickInterprete();

	void ordenacionCancionIterativo(int);
	void ordenacionInterpreteIterativo(int);
	void ordenacionCancionRecursiva(int);
	void ordenacionInterpreteRecursiva(int);
};
#endif // !LISTA_H_INCLUDED