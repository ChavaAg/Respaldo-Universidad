#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <exception>
#include <string>

using namespace std;

template <class T>
class Pila {
private:
	class Nodo {
	private:
		T contenido;
		Nodo* sig;
	public:

		Nodo();
		Nodo(const T&);

		T getContenido();
		Nodo* getSig();

		void setContenido(T);
		void setSig(Nodo*);
	};

	Nodo* inicio;
	void borradorHD();
public:
	class Exception :public std::exception {
	private:
		std::string msg;
	public:
		explicit Exception(const char* message) : msg(message) {}
		explicit Exception(const std::string& message) : msg(message) {}
		virtual ~Exception() throw() {}
		virtual const char* what() const throw() {
			return msg.c_str();
		}
	};

	Pila();
	~Pila();

	bool vacio();

	void push(T&);

	T pop();
	T getTop();

};


//Implementacion de la clse nodo

template <class T>
Pila<T>::Nodo::Nodo() : sig(nullptr) {}

template <class T>
Pila<T>::Nodo::Nodo(const T& e) : contenido(e), sig(nullptr) {}

template <class T>
T Pila<T>::Nodo::getContenido() {
	return contenido;
}

template <class T>
typename Pila<T>::Nodo* Pila<T>::Nodo::getSig() {
	return sig;
}

template <class T>
void Pila<T>::Nodo::setContenido(T elemento) {
	contenido = elemento;
}

template <class T>
void Pila<T>::Nodo::setSig(Nodo* p) {
	sig = p;
}

//Implementacion de la clase lista

template<class T>
void Pila<T>::borradorHD() {
	Nodo* aux;

	while (inicio!=nullptr) {
		aux = inicio;
		inicio = inicio->getSig();

		delete aux;
	}
}

template<class T>
 Pila<T>::Pila():inicio(nullptr) {}

 template<class T>
 Pila<T>::~Pila() {
	 borradorHD();
 }
 template<class T>
 bool Pila<T>::vacio() {
	 return inicio==nullptr;
 }
 template<class T>
 void Pila<T>::push(T& e) {
	 Nodo* aux = new Nodo(e);

	 if (aux==nullptr) {
		 throw Exception("Memoria no disponible");
	 }

	 aux->setSig(inicio);

	 inicio = aux;
 }
 template<class T>
 T Pila<T>::pop() {
	 if (inicio==nullptr) {
		 throw Exception("No hay elementos");
	 }

	 T resultado = inicio->getContenido();

	 Nodo* aux = inicio;

	 inicio = inicio->getSig();

	 delete aux;

	 return resultado;
 }
 template<class T>
 T Pila<T>::getTop() {
	 if (inicio==nullptr) {
		 throw Exception("No hay elementos");
	 }

	 return inicio->getContenido();
 }
#endif // !PILA_H_INCLUDED

