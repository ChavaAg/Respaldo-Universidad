#include "Menu.h"

bool Menu::inicio(int op) {
	string etiqueta;
	bool finish = true;
	string origen;
	string destino;
	int peso;

	switch(op) {
	case 1:
		system("cls");
		getchar();
		optencion();

		grafo.insertarVertice(MyCopias);
		system("cls");
		break;
	case 2:
		system("cls");
		getchar();
		cout << "Introdusca el origen de la arista: ";
		getline(cin,origen);
		cout << "Introdusca el destino de la arista: ";
		getline(cin, destino);
		cout << "Introdusca el peso: ";
		cin >> peso;

		grafo.insertarArista(origen, destino, peso);
		system("cls");
		break;
	case 3:
		system("cls");
		cout << grafo.toString() << endl;
		cout << "Introdusca el nombre del vertice: ";
		getchar();
		getline(cin, etiqueta);

		grafo.eliminarVertice(grafo.buscarVertice(etiqueta));
		system("cls");
		break;
	case 4:
		system("cls");
		getchar();
		cout << grafo.toString() << endl;
		cout << "Introdusca el origen de la arista a eliminar: ";
		getline(cin, origen);
		cout << "Introdusca el destino de la arista a eliminar: ";
		getline(cin, destino);

		grafo.eliminarArista(grafo.buscarVertice(origen), grafo.buscarAristas(origen, destino));
		system("cls");
		break;
	case 5:
		system("cls");

		cout<<grafo.toString();
		break;
	case 6:
		system("cls");
		if(grafo.vacia()) {
			cout << "No Se puede guardar ya que no hay datos dentro del arbol\n\n";
			break;
		}

		grafo.guardar();
		cout << "El grafo se ha guardado con exito" << endl;
		break;
	case 7:
		system("cls");

		if(!grafo.vacia()) {
			grafo.borrarVertices();
		}

		grafo.cargar();
		cout << "El grafo se ha cargado con exito" << endl;

		break;

	case 8:
		finish = false;
		break;
	default:
		system("cls");
		cout<<"No es una opcion valida"<<endl;
		break;
	}

    return finish;
}

void Menu::optencion() {
	string oracion;
	int numero;

	cout << "Ingresa el nombre del aerepuerto: ";
	getline(cin, oracion);
	MyCopias.setNombre(oracion);

	cout << "Ingresa donde se ubica el aereopuerto: ";
	getline(cin, oracion);
	MyCopias.setLugar(oracion);

	cout << "Ingresa el numero de vuelos diarios: ";
	cin >> numero;
	MyCopias.setVuelos(numero);
}
