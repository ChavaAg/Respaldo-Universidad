#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

template <class T>
class Cola {
private:
	class Nodo {
	private:
		T* contenidoPtr;
		Nodo* ant;
		Nodo* sig;
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

		Nodo();
		Nodo(const T&);
		~Nodo();

		T* getContenidoPtr();
		T getContenido();
		Nodo* getSig();
		Nodo* getAnt();

		void serContenidoPtr(T*);
		void setContenido(T);
		void setSig(Nodo*);
		void setAnt(Nodo*);
	};

	Nodo* encabezado;
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
	Cola();
	~Cola();

	bool vacio();

	void enColar(T);

	T desColar();

	T getFront();

};

//implementacion del nodo

template<class T>
Cola<T>::Nodo::Nodo() : contenidoPtr(nullptr), ant(nullptr), sig(nullptr) {}

template<class T>
Cola<T>::Nodo::Nodo(const T& e) : contenidoPtr(new T(e)), ant(nullptr), sig(nullptr) {
	if (contenidoPtr==nullptr) {
		throw Exception("Memoria insuficiente");
	}
}

template<class T>
Cola<T>::Nodo::~Nodo() {
	delete contenidoPtr;
}

template<class T>
T* Cola<T>::Nodo::getContenidoPtr() {
	return contenidoPtr;
}

template<class T>
T Cola<T>::Nodo::getContenido() {
	if (contenidoPtr==nullptr) {
		throw Exception("Dato inexistente");
	}
	return *contenidoPtr;
}

template<class T>
typename Cola<T>::Nodo* Cola<T>::Nodo::getAnt() {
	return ant;
}

template<class T>
typename Cola<T>::Nodo* Cola<T>::Nodo::getSig() {
	return sig;
}

template<class T>
void Cola<T>::Nodo::serContenidoPtr(T* p) {
	contenidoPtr = p;
}

template<class T>
void Cola<T>::Nodo::setContenido(T e) {
	if (contenidoPtr==nullptr) {
		if ((contenidoPtr=new T(e))== nullptr) {
			throw Exception("Memoria no disponible");
		}
	} else {
		*contenidoPtr = e;
	}
}

template<class T>
void Cola<T>::Nodo::setAnt(Nodo* p) {
	ant = p;
}

template<class T>
void Cola<T>::Nodo::setSig(Nodo* p) {
	sig = p;
}


//Implementacion de la cola

template<class T>
void Cola<T>::borradorHD() {
	Nodo* aux;

	while (encabezado->getSig() != encabezado) {
		aux = encabezado->getSig();

		encabezado->setSig(aux->getSig());

		delete aux;
	}
	encabezado->setAnt(encabezado);
}

template<class T>
Cola<T>::Cola() : encabezado(new Nodo){
	if (encabezado==nullptr) {
		throw Exception("Memoria insuficiente");
	}

	encabezado->setAnt(encabezado);
	encabezado->setSig(encabezado);
}

template<class T>
 Cola<T>::~Cola() {
	 borradorHD();

	 delete encabezado;
}

 template<class T>
 bool Cola<T>::vacio() {
	 return encabezado->getSig() == encabezado;
 }

 template<class T>
 void Cola<T>::enColar(T e) {
	 Nodo* aux;

	 try {
		 if ((aux=new Nodo(e))==nullptr) {
			 throw Exception("Memoria disponible");
		 }
	 }
	 catch (typename Nodo::Exception ex) {
		 throw Exception(ex.what());
	 }

	 aux->setAnt(encabezado->getAnt());
	 aux->setSig(encabezado);

	 encabezado->getAnt()->setSig(aux);
	 encabezado->setAnt(aux);
 }

 template<class T>
 T Cola<T>::desColar() {

	 if (vacio()) {
		 throw Exception("Insuficencia de datos");
	 }

	 T result(encabezado->getSig()->getContenido());

	 Nodo* aux(encabezado->getSig());

	 aux->getAnt()->setSig(aux->getSig());
	 aux->getSig()->setAnt(aux->getAnt());

	 delete aux;
	 return result;
 }

 template<class T>
 T Cola<T>::getFront() {

	 if (vacio()) {
		 throw Exception("Insuficencia de datos");
	 }

	 return encabezado->getSig()->getContenido();
 }
#endif // !COLA_H_INCLUDED
