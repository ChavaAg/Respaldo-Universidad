#include "Lista.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

void main() {

	int num;
	Lista Principal;
	Lista Copia;
	clock_t t;
		
	default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> distribution(0, 1000000);
	auto dice = bind(distribution, generator);

	for (int i = 0; i < 100000; i++) {

		Principal.inserta(Principal.getCantidad(),dice()); 
	}

	cout << "Aqui se demuestra el timepo que se tardo un metodo en ordenar un arreglo de 100000 elementos" << endl << endl;
	//Copia  los numeros de la primera cadena y los analiza con el metodo bubble
	Copia = Principal;
	t = clock();
	Copia.OrdenarDatosBubble();
	t = clock()-t;
	cout << "El metodo Bubble tardo " << double(t) / CLOCKS_PER_SEC << " segundos."<<endl;
	
	//Copia  los numeros de la primera cadena y los analiza con el metodo bubble
	Copia = Principal;
	t = clock();
	Copia.OrdenarDatosInsert();
	t = clock() - t;
	cout << "El metodo Insert tardo  " << double(t) / CLOCKS_PER_SEC << " segundos." << endl;

	//Copia  los numeros de la primera cadena y los analiza con el metodo bubble
	Copia = Principal;
	t = clock();
	Copia.OrdenarDatosSelect();
	t = clock() - t;
	cout << "El metodo Select tardo  " << double(t) / CLOCKS_PER_SEC << " segundos." << endl;


	//Copia  los numeros de la primera cadena y los analiza con el metodo bubble
	Copia = Principal;
	t = clock();
	Copia.OrdenarDatosShell();
	t = clock() - t;
	cout << "El metodo Shell tardo  " << double(t) / CLOCKS_PER_SEC << " segundos." << endl;


	//Copia  los numeros de la primera cadena y los analiza con el metodo bubble
	Copia = Principal;
	t = clock();
	Copia.OrdenarDatosMerge();
	t = clock() - t;
	cout << "El metodo Merge tardo  " << double(t) / CLOCKS_PER_SEC << " segundos." << endl;
	
	//Copia  los numeros de la primera cadena y los analiza con el metodo bubble
	Copia = Principal;
	t = clock();
	Copia.OrdenarDatosQuick();
	t = clock() - t;
	cout << "El metodo Quick tardo  " << double(t) / CLOCKS_PER_SEC << " segundos." << endl;
}