#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Superheroes {
private:
	string nombre;
	string poder;
	string debilidad;
public:
	string getNombre();
	string getPoder();
	string getDebilidad();

	void setNombre(string);
	void setPoder(string);
	void setDebilidad(string);

	string toString();  

	bool operator !=(string&);
};

string Superheroes::getNombre() {
	return nombre;
}

string Superheroes::getPoder() {
	return poder;
}

string Superheroes::getDebilidad() {
	return debilidad;
}

void Superheroes::setNombre(string a) {
	nombre = a;
}

void Superheroes::setPoder(string a) {
	poder = a;
}

void Superheroes::setDebilidad(string a) {
	debilidad = a;
}

string Superheroes::toString() {
	string MyString;

	MyString = nombre;
	MyString += "|";
	MyString += poder;
	MyString += "|";
	MyString += debilidad;
	
	return MyString;
}

bool Superheroes::operator!=(string& c) {
	return nombre != c;
}

class Nodo {
private:
	Superheroes contenido;
	Nodo* sig;
	Nodo* ant;

public:

	Nodo();
	Nodo(const Superheroes&);

	Superheroes getContenido();
	Nodo* getSig();
	Nodo* getAnt();

	void setContenido(Superheroes);
	void setSig(Nodo*);
	void setAnt(Nodo*);

	
};

Nodo::Nodo() : sig(nullptr), ant(nullptr) {}

Nodo::Nodo(const Superheroes& e) : contenido(e), sig(nullptr), ant(nullptr){}

Superheroes Nodo::getContenido() {
	return contenido;
}

Nodo* Nodo::getSig() {
	return sig;
}

Nodo* Nodo::getAnt() {
	return ant;
}


void Nodo::setContenido(Superheroes elemento) {
	contenido = elemento;
}

void Nodo::setSig(Nodo* p) {
	sig = p;
}

void Nodo::setAnt(Nodo* p) {
	ant = p;
}


class Lista {
private:
	Nodo* inicio;
	bool isValidPos(Nodo*);
public:

	typedef Nodo* Position;

	Lista();
	~Lista();

	bool vacia();
	void inserta(Nodo*, Superheroes& j);
	void elimina(Nodo*);

	Nodo* getPrimero();
	Nodo* getUltimo();
	Nodo* getAntes(Nodo*);
	Nodo* getDespues(Nodo*);

	void guardarLista();
	void cargarLista();

	Nodo* busquedaHeroe(string);

	Superheroes recupera(Nodo*);

	void borradorHD();
	string toString();
};

Lista::Lista() : inicio(nullptr) {}

Lista::~Lista() {
	borradorHD();
}

bool Lista::vacia() {
	return inicio == nullptr;
}

void Lista::inserta(Nodo* p, Superheroes& j) {
	if(p != nullptr && !isValidPos(p)) {
		exit(1);
	}

	Nodo* aux = new Nodo(j);


	if(p == nullptr) {
		aux->setSig(inicio);
		if(inicio != nullptr) {
			inicio->setAnt(aux);
		}
		inicio = aux;
	}
	else {
		aux->setAnt(p);
		aux->setSig(p->getSig());

		if(p->getSig() != nullptr) {
			p->getSig()->setAnt(aux);
		}
		p->setSig(aux);
	}
}

void Lista::elimina(Nodo* p) {
	if(!isValidPos(p)) {
		exit(1);
	}

	if(p->getAnt() != nullptr) {
		p->getAnt()->setSig(p->getSig());
	}

	if(p->getSig() != nullptr) {
		p->getSig()->setAnt(p->getAnt());
	}

	if(p == inicio) {
		inicio = inicio->getSig();
	}

	delete p;
}

Nodo* Lista::getPrimero() {
	return inicio;
}

Nodo* Lista::getUltimo() {
	if(vacia()) {
		return nullptr;
	}

	Nodo* aux = inicio;

	while(aux->getSig() != nullptr) {
		aux = aux->getSig();
	}

	return aux;
}

Nodo* Lista::getAntes(Nodo* p) {
	if(!isValidPos(p)) {
		return nullptr;
	}

	return p->getAnt();
}

Nodo* Lista::getDespues(Nodo* p) {
	if(!isValidPos(p)) {
		return nullptr;
	}
	return p->getSig();
}

void Lista::guardarLista() {
	ofstream salida;
	string texto;

	salida.open("file01.txt", ios::out);

	Nodo* aux = inicio;

	while(aux != nullptr) {
		texto = aux->getContenido().toString();
		texto += "*";

		salida << texto;
		
		aux = aux->getSig();
	}
	salida.close();
}

void Lista::cargarLista() {

	ifstream entrada;
	string ingresar;
	Superheroes copia;

	borradorHD();

	entrada.open("file01.txt", ios::in);
	while(true) {
		getline(entrada,ingresar,'|');
		copia.setNombre(ingresar);
		getline(entrada, ingresar, '|');
		copia.setPoder(ingresar);
		getline(entrada, ingresar, '*');
		copia.setDebilidad(ingresar);

		if(entrada.eof()) {
			break;
		}
		
		inserta(getUltimo(), copia);
	}
	entrada.close();
}


Nodo* Lista::busquedaHeroe(string e) {
	Nodo* aux = inicio;

	while(aux != nullptr && aux->getContenido() != e) {
		aux = aux->getSig();
	}

	return aux;
}

Superheroes Lista::recupera(Nodo* e) {
	if(!isValidPos(e)) {
		
	}
	return e->getContenido();
}

void Lista::borradorHD() {
	Nodo* aux;

	while(inicio != nullptr) {
		aux = inicio;
		inicio = inicio->getSig();

		delete aux;
	}

}

string Lista::toString() {
	Nodo* aux = inicio;
	string cadena;

	cout << "Lista de heroes" << endl << endl;
	cout << "|Nombre del heroe|Poder|Debilidad|" << endl;

	while(aux != nullptr) {
		cadena += aux->getContenido().toString() + "\n";
		aux = aux->getSig();
	}

	return cadena;
}

bool Lista::isValidPos(Nodo* p) {
	Nodo* aux(inicio);

	while(aux != nullptr) {
		if(aux == p) {
			return true;
		}
		aux = aux->getSig();
	}
	return false;
}

class Menu {
public:
	Lista MyMenu;
	Superheroes MyCopias;

	Lista::Position pos;

	bool inicio(int);
	void optencion();
	void impresionBusqueda(string, Nodo*);
};

bool Menu::inicio(int op) {
	int insertar;
	bool finish = true;
	string busqueda;


	switch(op) {
	case 1:

		if(MyMenu.vacia()) {
			system("cls");
			getchar();
			optencion();
			MyMenu.inserta(MyMenu.getPrimero(), MyCopias);
			system("cls");
			cout << MyMenu.toString() << endl;
		}
		else {
			system("cls");
			cout << MyMenu.toString() << endl << endl;;
			cout << "Elige el el donde quieres insertar el nuevo heroe\n 1. Al principio\n 2. En cualquier posicion\n 3. Al final\n Opcion: ";
			cin >> insertar;

			switch(insertar) {
			case 1:
				system("cls");
				getchar();
				optencion();
				MyMenu.inserta(MyMenu.getPrimero(), MyCopias);
				system("cls");
				cout << MyMenu.toString() << endl;
				break;
			case 2:
				getchar();
				optencion();
				system("cls");
				cout << MyMenu.toString() << endl;
				cout << "Ingresa el nombre donde deseas insertar" << endl;
				getline(cin, busqueda);
				pos = MyMenu.busquedaHeroe(busqueda);
				if(pos == nullptr) {
					system("cls");
					cout << "El dato que se uso como referencia no se encuentra en la lista" << endl << endl;;
				}
				else {
					MyMenu.inserta(pos, MyCopias);
					system("cls");
				}
				cout << MyMenu.toString() << endl;
				break;
			case 3:
				system("cls");
				getchar();
				optencion();
				MyMenu.inserta(MyMenu.getUltimo(), MyCopias);
				system("cls");
				cout << MyMenu.toString() << endl;
				break;
			default:
				cout << "La opcion elegida es invalida" << endl;
				break;
			}
		}
		break;
	case 2:
		system("cls");
		cout << MyMenu.toString() << endl;
		cout << endl << "Elige el elemento para a eliminar: ";
		getchar();
		getline(cin, busqueda);
		pos = MyMenu.busquedaHeroe(busqueda);
		if(pos == nullptr) {
			system("cls");
			cout << "El dato que se uso como referencia no se encuentra en la lista" << endl << endl;
		}
		else {
			MyMenu.elimina(pos);
			system("cls");
		}
		cout << MyMenu.toString() << endl;
		break;
	case 3:

		system("cls");
		cout << MyMenu.toString() << endl;
		cout << "Ingresa el dato a buscar" << endl;
		getchar();
		getline(cin, busqueda);
		system("cls");
		impresionBusqueda(busqueda, MyMenu.busquedaHeroe(busqueda));
		break;
	case 4:
		system("cls");
		MyMenu.guardarLista();
		cout << "La lista se ha guardado con exito";
		break;
	case 5:
		system("cls");
		MyMenu.cargarLista();
		cout << "La lista se ha cargado con exito"<<endl;

		cout << MyMenu.toString() << endl;
		break;
	case 6:
		system("cls");
		MyMenu.borradorHD();
		break;
	case 7:
		finish = false;
		return finish;
	default:
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

void Menu::impresionBusqueda(string busqueda, Nodo* posicion) {
	if(posicion == nullptr) {
		cout << "El heroe " << busqueda << " no esta en la lista de heroes" << endl;
	}
	else {
		cout << "El heroe " << busqueda << " se encontro en la posicion: " << posicion << endl << endl;

		cout << "Nombre del superheroe: " << MyMenu.recupera(posicion).getNombre() << endl;
		cout << "Poder: " << MyMenu.recupera(posicion).getPoder() << endl;
		cout << "Debilidad: " << MyMenu.recupera(posicion).getDebilidad() << endl;
	}
}


int main() {
	Menu myMenu;

	bool finish;
	int op;

	do {
		cout << "Bienvenido a la wiki del heroe" << endl << endl;
		cout << "Elija una de las siguientes opciones:" << endl;
		cout << " 1. Ingresar nueva heroe" << endl << " 2. Eliminar heroe existente" << endl << " 3. Busqueda Lineal" << endl;
		cout << " 4. Guardar lista" << endl << " 5. Cargar lista" << endl << " 6. Borrar toda la lista";
		cout << endl << " 7. Salir del programa" << endl << "Opcion: ";
		cin >> op;

		finish = myMenu.inicio(op);
	} while(finish);
	return 0;
}


//fflush(stdin)