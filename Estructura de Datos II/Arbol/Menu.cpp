#include "Menu.h"


bool Menu::inicio(int op) {
	int orden;
	bool finish = true;
	string busqueda;


	switch(op) {
	case 1:

		system("cls");
		getchar();
		optencion();
		arbol.inserta(arbol.root, MyCopias);
		system("cls");
		cout << "Se ha insertado exitosamente\n";

		break;
	case 2:
		system("cls");
		if(arbol.vacia()) {
			cout << "No se puede eliminar ya que no hay datos dentro del arbol\n\n";
			break;
		}
		cout << "El arbol se ha mostrado en preorder\n\n";
		arbol.preOrder(arbol.root);
		cout << endl << "Elige el elemento para a eliminar: ";
		getchar();
		getline(cin, busqueda);
		arbol.elimina(busqueda);
		system("cls");
		cout << "El arbol se ha mostrado en preorder\n\n";
		arbol.preOrder(arbol.root);
		break;
	case 3:
		system("cls");
		if(arbol.vacia()) {
			cout << "No se puede mostrar ya que no hay datos dentro del arbol\n\n";
			break;
		}
		cout << "Como desea que sea el recorrido?\n 1. Preornden\n 2. Inorden\n 3. Postornden\n";
		cout << "Opcion: ";
		getchar();
		cin >> orden;
		system("cls");
		switch(orden) {
		case 1:
			cout << "Se ha mostrado en preOrder\n\n";
			arbol.preOrder(arbol.root);
			break;
		case 2:
			cout << "Se ha mostrado en inOrder\n\n";
			arbol.inOrder(arbol.root);
			break;
		case 3:
			cout << "Se ha mostrado en postOrder\n\n";
			arbol.posOrder(arbol.root);
			break;
		default:
			break;
		}
		break;
	case 4:
		system("cls");
		if(arbol.vacia()) {
			cout << "No Se puede guardar ya que no hay datos dentro del arbol\n\n";
			break;
		}

		arbol.guardar();
		cout << "La lista se ha guardado con exito" << endl;
		break;
	case 5:
		system("cls");
		arbol.cargar();
		cout << "La lista se ha cargado con exito" << endl;
		break;
	case 6:
		system("cls");
		if(arbol.vacia()) {
			cout << "No se puede borrar el arbol ya que no hay datos dentro del arbol\n\n";
			break;
		}
		arbol.anular();
		cout << "El arbol se ha eliminado \n\n";
		break;
	case 7:
		finish = false;
		return finish;
		break;
	default:
		system("cls");
		cout << "Esta es una opcion invalida" << endl;
		break;
	}
	cout << endl;
	return finish;
}

void Menu::optencion() {
	string oracion;

	cout << "Ingresa el nombre del heroe: ";
	getline(cin, oracion);;
	MyCopias.setNombre(oracion);

	cout << "Ingresa el poder del heroe: ";
	getline(cin, oracion);
	MyCopias.setPoder(oracion);

	cout << "Ingresa la debilidad del heroe: ";
	getline(cin, oracion);
	MyCopias.setDebilidad(oracion);
}