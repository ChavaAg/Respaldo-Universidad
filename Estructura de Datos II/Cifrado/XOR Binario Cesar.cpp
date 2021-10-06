#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string toBinary(int n);
string XOR(string frase, string clave, bool bandera);
string CesarCifrado(string frase, int desplaz, char alfabeto[]);
string CesarDescifrado(string frase, int desplaz, char alfabeto[]);
string cargarCifrado(string archivo);
void guardarCifrado(string frase, string archivo);
string cargarArchivo(string archivo);


int main() {
	char alfabeto[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string frase, clave, cifradoCesar, cifradoXOR, decifradoCesar, decifradoXOR, archivo, cargado, cifrado;
	int desplaz, opcion, opcion2;
	bool finish = true;


	do {
		system("cls");
		cout << "-------Bienvenidos al cifrado AG-------" << endl;
		cout << " Este cifrado es un hibrido de Cesar y XOR" << endl;
		cout << " 1. Cifrar\n 2. Decifrar\n 3. Salir\n Opcion: ";
		cin >> opcion;

		system("cls");
		switch(opcion) {
		case 1:
			cout << "El cifrado se hara en un archivo existente?\n";
			cout << " 1. Si\n 2. No\n Opcion: ";
			cin >> opcion;

			system("cls");
			if(opcion == 1) {
				getchar();
				cout << "Ingresa el nombre del archivo existente: ";
				getline(cin, archivo);
				archivo += ".txt";

				frase = cargarArchivo(archivo);

				cout << "Ingresa el dezplazamiento: ";
				cin >> desplaz;
				cout << "Ingresa la clave: ";
				cin >> clave;
				cout << "Ingresa el nombre del archivo cifrado: ";
				getchar();
				getline(cin, archivo);
				archivo += ".txt";

				cifradoCesar = CesarCifrado(frase, desplaz, alfabeto);
				cifradoXOR = XOR(cifradoCesar, clave, true);

				guardarCifrado(cifradoXOR, archivo);
			}
			else if(opcion == 2) {
				getchar();
				cout << "Ingresa el nombre del archivo cifrado: ";
				getline(cin, archivo);
				archivo += ".txt";
				cout << "Ingresa la frase a encriptar: ";

				getline(cin, frase);
				cout << "Ingresa el dezplazamiento: ";
				cin >> desplaz;
				cout << "Ingresa el dezplazamiento la clave: ";
				cin >> clave;


				cifradoCesar = CesarCifrado(frase, desplaz, alfabeto);
				cifradoXOR = XOR(cifradoCesar, clave, true);

				guardarCifrado(cifradoXOR, archivo);
			}
			break;
		case 2:
			getchar();
			cout << "Ingresa el nombre del archivo existente: ";
			getline(cin, archivo);
			archivo += ".txt";
			cout << "Ingresa el dezplazamiento: ";
			cin >> desplaz;
			cout << "Ingresa la clave: ";
			cin >> clave;


			cifrado = cargarCifrado(archivo);


			decifradoXOR = XOR(cifrado, clave, false);
			decifradoCesar = CesarDescifrado(decifradoXOR, desplaz, alfabeto);

			guardarCifrado(decifradoCesar, archivo);

			break;
		case 3:
			finish = false;
			cout << "\nGracias por usar el programa\n";
			break;
		default:
			cout << "\nEsta opcion no es valida\n";
			break;
		}
	} while(finish);

	return 0;
}

int toInt(int binario[]) {
	int total = 0;
	int indice = 0;

	//! Aqui se multiplica los 0's y 1's dentro del arreglo con
	//! el resultado de elecvar el 2 a la potencia designada
	//! Se empieza a elevar desde 0 y se ira incrementado cada vez
	//! ademas que se comienza desde el ultimo dijito del arreglo
	for(int i = 7; i >= 0; i--) {
		total += binario[i] * (pow(2, indice++));
	}

	return total;
}

string toBinary(int numero) {
	int bits[] = { 0,0,0,0,0,0,0,0 };
	string binario = "";
	int indice = 7;

	//!Aqui con la operacion modulo revisaremos si al dividir entre
	//!dos nos da como residuo 0, si lo es agrega un 0 si no un 1
	//!Despues se divide entre dos, esto se repetira hasta que el numero a
	//!comvertir a binario sea igual a cero
	while(numero != 0) {
		bits[indice--] += (numero % 2 == 0 ? 0 : 1);
		numero /= 2;
	}

	//!Aqui solamente se ingresa el binario en una cadena para poder
	//! retornarla
	for(int i = 0; i < 8; i++) {
		binario += to_string(bits[i]);
	}

	return binario;
}

string XOR(string frase, string clave, bool bandera) {
	int chFrase, chIndice, chCifrado, indice;
	string cifrado = "";
	string descifrado = frase;

	//!Se recorre la cadena para obtener la cadena encriptada/desencriptada
	for(int i = 0; i < frase.length(); i++) {
		chFrase = int(frase[i]);

		//!Aqui se calcula el indice de la clave usando el operador modulo
		indice = i % clave.length();
		chIndice = int(clave[indice]);
		//!Aqui se utiliza el operador para encriptar/ desencriptar el 
		//!caracter
		chCifrado = chFrase ^ chIndice;

		//!Ya que se puede usar esta funcion de diferente manera se utiliza
		//!una bandera para saber si se esta encriptando o desencriptando
		if(bandera) {
			cifrado += toBinary(chCifrado);
		}
		else {
			descifrado[i] = char(chCifrado);
		}

	}
	//!Al igual que antes se utiliza la bandera para retornar el valor 
	//! correto
	if(bandera) {
		return cifrado;
	}
	else {
		return descifrado;
	}

}

string CesarCifrado(string frase, int desplaz, char alfabeto[]) {
	string textoCifrado = "";
	bool bandera;

	int j;
	//!Se recorre la cadena para obtener la cadena encriptada
	for(int i = 0; i < frase.length(); i++) {
		bandera = true;
		j = 0;
		//! Ya que el alfabeto tiene 52 letras contando mayusculas y minusculas
		//! con esta iteracion pasara por cada una dentro del arreglo.
		while(j < 52) {
			//! Aqui va verificando letra por letra buscando una coincidencia
			//! dentro del alfabeto
			if(frase[i] == alfabeto[j] and j < 26) {  //! Si entra aqui esta en la parte de las minusculas

				//! Se le suma el desplazamiento y verifica que no arrebase el rango de
				//! las minusculas dentro del arreglo
				j += desplaz;
				if(j > 25) {
					j -= 26;
				}
				//! Con el desplazamiento hecho lo agregamos a una cadena y paramos la iteracion
				textoCifrado += alfabeto[j];
				bandera = false;
				break;
			}
			//!Aqui se repide lo de arriba pero ahora en el rango de las mayusculas
			else if(frase[i] == alfabeto[j]) {
				j += desplaz;
				if(j > 51) {
					j -= 26;
				}
				textoCifrado += alfabeto[j];
				bandera = false;
				break;
			}
			j++;
		}
		//! Esta validacion se encarga de verificar si el caracter esta dentro del alfabeto
		//! si no lo esta solamente lo ingresa sin modificacion
		if(bandera) {
			textoCifrado += frase[i];
		}
	}

	return textoCifrado;
}

string CesarDescifrado(string frase, int desplaz, char alfabeto[]) {
	string textoCifrado = "";
	bool bandera;

	int j;
	//!Se recorre la cadena para obtener la cadena desencriptada
	for(int i = 0; i < frase.length(); i++) {
		bandera = true;
		j = 0;
		//! Ya que el alfabeto tiene 52 letras contando mayusculas y minusculas
		//! con esta iteracion pasara por cada una dentro del arreglo.
		while(j < 52) {
			//! Aqui va verificando letra por letra buscando una coincidencia
			//! dentro del alfabeto
			if(frase[i] == alfabeto[j] and j < 26) { //! Si entra aqui esta en la parte de las minusculas

				//! Se le suma el desplazamiento y verifica que no arrebase el rango de
				//! las minusculas dentro del arreglo
				j -= desplaz;
				if(j < 0) {
					j += 26;
				}

				//! Con el desplazamiento hecho lo agregamos a una cadena y paramos la iteracion
				textoCifrado += alfabeto[j];
				bandera = false;
				break;
			}
			//!Aqui se repide lo de arriba pero ahora en el rango de las mayusculas
			else if(frase[i] == alfabeto[j]) {
				j -= desplaz;
				if(j < 26) {
					j += 26;
				}
				textoCifrado += alfabeto[j];
				bandera = false;
				break;
			}
			j++;
		}
		//! Esta validacion se encarga de verificar si el caracter esta dentro del alfabeto
		//! si no lo esta solamente lo ingresa sin modificacion
		if(bandera) {
			textoCifrado += frase[i];
		}
	}

	return textoCifrado;
}


void guardarCifrado(string frase, string archivo) {
	ofstream salida;

	salida.open(archivo, ios::out);

	if(salida.fail()) {
		cout << "El archivo no se pudo abrir";
		exit(1);
	}

	salida << frase;

	salida.close();
}

string cargarCifrado(string archivo) {
	ifstream entrada;
	int binario[8];
	char bit;
	string frase = "";

	entrada.open(archivo, ios::in);

	if(entrada.fail()) {
		cout << "El archivo no se pudo abrir";
		exit(1);
	}

	while(true) {
		for(int i = 0; i < 8; i++) {
			entrada.get(bit);

			//!Una forma para convertir de caracter a entero
			binario[i] = bit - '0';

		}
		if(entrada.eof()) {
			break;
		}
		frase += char(toInt(binario));
	}

	entrada.close();

	return frase;
}

string cargarArchivo(string archivo) {
	ifstream entrada;
	string linea;
	string texto = "";

	entrada.open(archivo, ios::in);

	if(entrada.fail()) {
		cout << "El archivo no se pudo abrir";
		exit(1);
	}

	while(!entrada.eof()) {
		getline(entrada, linea);
		texto += linea;
		texto += "\n";
	}

	return texto;
}