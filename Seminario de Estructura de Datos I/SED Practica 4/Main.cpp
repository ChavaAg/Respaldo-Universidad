#include <iostream>
#include <string>
#include "lista.h"

using namespace std;



int main() {

	CLista lista;
	lista.EliminarInicio();
	
	lista.InsertarInicio(20);
	lista.InsertarInicio(10);
	lista.InsertarInicio(2020);

	cout << "Nodos en la lista: " << lista.Size() << endl;
	lista.Imprime();

	cout << "Valor del nodo eliminado: " <<lista.EliminarInicio() << endl;
	cout << "Valor del nodo eliminado: " << lista.EliminarInicio() << endl;
	cout << endl;

	cout << "Nodos en la lista: " << lista.Size() << endl;
	lista.Imprime();

	lista.InsertarFinal(70.5);
	lista.InsertarFinal(30.5);

	cout << "Nodos en la lista: " << lista.Size() << endl;
	lista.Imprime();

	cout << "Valor del nodo eliminado: " << lista.EliminarFinal() << endl;
	cout << "Valor del nodo eliminado: " << lista.EliminarFinal() << endl;
	cout << endl;

	cout << "Nodos en la lista: " << lista.Size() << endl;
	lista.Imprime();

	cout << "Vaciando lista" << endl;
	lista.Vaciar();
	cout << "Nodos en la lista: " << lista.Size() << endl << endl;

}