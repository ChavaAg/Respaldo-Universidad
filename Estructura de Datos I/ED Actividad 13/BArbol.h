#ifndef BARBOL_H_INCLUDED
#define BARBOL_H_INCLUDED

#include <iostream>
#include <string>
#include <exception>

template <class T>
class BArbol {
private:
	class Nodo {
	private:
		int* contenidoPtr;
		Nodo* izdo;
		Nodo* dcho;
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
		Nodo*& getIzdo();
		Nodo*& getDcho();

		void setContenidoPtr(T*);
		void setContenido(T&);
		void setIzdo(Nodo*&);
		void setDcho(Nodo*&);
	};

	Nodo* raiz;
	Nodo* auxB=nullptr;

	void insertar(Nodo*&,T&);

	Nodo*& encontrar(Nodo*&,T&);

	int getAltura(Nodo*&);
	int getAlturaIzda(Nodo*&);
	int getAlturaDcha(Nodo*&);

	Nodo*& getMenor(Nodo*&);
	Nodo*& getMayor(Nodo*&);

	void preOrder(Nodo*&);
	void inOrder(Nodo*&);
	void posOrder(Nodo*&);

	int getBalanceo(Nodo*&);

	void simpleIzdoRotacion(Nodo*&);
	void simpleDchoRotacion(Nodo*&);
	void dobleIzdoRotacion(Nodo*&);
	void dobleDchoRotacion(Nodo*&);

	void doBalanceador(Nodo*&);

	void copiado(BArbol<T>&);
	void copiado(Nodo*&);

	void borradorHD(Nodo*&);

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

	BArbol();
	BArbol(BArbol&);

	~BArbol();

	bool vacio();

	void insertar(T&);

	void eliminar(Nodo*&);

	T recuperar(Nodo*&);

	Nodo*& encontrar(T&);

	Nodo*& getMenor();
	Nodo*& getMayor();

	bool isHoja(Nodo*&);

	int getAltura();
	int getAlturaIzda();
	int getAlturaDcha();

	void preOrder();
	void inOrder();
	void posOrder();

	void borradorHD();
};


//!Implementacion del nodo

template<class T>
BArbol<T>::Nodo::Nodo() : contenidoPtr(nullptr),izdo(nullptr),dcho(nullptr) {}

template<class T>
BArbol<T>::Nodo::Nodo(const T& e) : contenidoPtr(new int(e)),izdo(nullptr),dcho(nullptr) {
	if (contenidoPtr == nullptr) {
		throw Exception("Memoria insuficioente, creando nodo");
	}
}

template<class T>
BArbol<T>::Nodo::~Nodo() {
	delete contenidoPtr;
}

template<class T>
inline T* BArbol<T>::Nodo::getContenidoPtr() {
	return contenidoPtr;
}

template <class T>
T BArbol<T>::Nodo::getContenido() {
	if (contenidoPtr == nullptr) {
		throw Exception("Memoria insuficioente, getContenido");
	}
	return *contenidoPtr;
}

template <class T>
typename BArbol<T>::Nodo*& BArbol<T>::Nodo::getIzdo() {
	return  izdo;
}

template<class T>
typename BArbol<T>::Nodo*& BArbol<T>::Nodo::getDcho() {
	return dcho;
}

template<class T>
inline void BArbol<T>::Nodo::setContenidoPtr(T* p) {
	contenidoPtr = p;
}

template<class T>
void BArbol<T>::Nodo::setContenido(T& e) {
	if (contenidoPtr == nullptr) {
		if ((contenidoPtr = new T(e)) == nullptr) {
			throw Exception("Memoria no disponible, setData");
		}
	} else {
		*contenidoPtr = e;
	}
}

template<class T>
void BArbol<T>::Nodo::setIzdo(Nodo*& p) {
	izdo = p;
}

template<class T>
inline void BArbol<T>::Nodo::setDcho(Nodo*& p) {
	dcho = p;
}


//!implementacion del arbol

template<class T>
inline BArbol<T>::BArbol() :raiz(nullptr) {}

template<class T>
inline BArbol<T>::BArbol(BArbol& a): raiz(nullptr) {
	raiz = nullptr;
	copiado(a);
}

template<class T>
inline BArbol<T>::~BArbol() {
	borradorHD();
}

template<class T>
inline bool BArbol<T>::vacio() {
	return raiz == nullptr;
}

template<class T>
void BArbol<T>::copiado(BArbol<T>& a) {
	copiado(a->raiz);
}

template<class T>
void BArbol<T>::copiado(Nodo*& r) {
	if (r == nullptr) {
		return;
	}

	insertar(r->getContenido());
	copiado(r->getIzdo);
	copiado(r->getDcho);
}

template<class T>
 void BArbol<T>::insertar(T& e) {
	insertar(raiz,e);
}

template<class T>
void BArbol<T>::insertar(Nodo*& r,T& e) {
	if (r == nullptr) {
		try {
			if ((r = new Nodo(e)) == nullptr) {
				throw Exception("Memoria no disponible, insertarData");
			}
		}
		catch (typename Nodo::Exception ex) {
			throw Exception(ex.what());
		}
	} else {
		if (e < r->getContenido()) {
			insertar(r->getIzdo(),e);
		} else {
			insertar(r->getDcho(),e);
		}
		doBalanceador(r);
	}
}

template<class T>
inline void BArbol<T>::eliminar(Nodo*& m) {
	Nodo* replazo;

	if (raiz == nullptr || m == nullptr) {
		throw Exception("eliminar");
	}

	if (isHoja(m)) {
		delete m;
		m = nullptr;
		return;
	} else if (m->getIzdo() != nullptr) {

		replazo = getMayor(m->getIzdo());

	} else {
		replazo = getMenor(m->getDcho());
	}

	m->setContenidoPtr(replazo->getContenidoPtr());
	eliminar(replazo);

	return;
}

template<class T>
inline T BArbol<T>::recuperar(Nodo*& r) {
	return r->getContenido();
}

template<class T>
typename BArbol<T>::Nodo*& BArbol<T>::encontrar(T& e) {
	return encontrar(raiz,e);
}

template<class T>
typename BArbol<T>::Nodo*& BArbol<T>::encontrar(Nodo*& r,T& e) {
	if (r == nullptr || r->getContenido() == e) {
		return r;
	}

	if (e < r->getContenido()) {
		return encontrar(r->getIzdo(),e);
	}

	return encontrar(r->getDcho(),e);
}

template<class T>
typename BArbol<T>::Nodo*& BArbol<T>::getMenor() {
	return getMenor(raiz);
}

template<class T>
typename BArbol<T>::Nodo*& BArbol<T>::getMenor(Nodo*& r) {
	if (r == nullptr || r->getIzdo() == nullptr) {
		return r;
	}

	return getMenor(r->getIzdo());
}

template<class T>
typename BArbol<T>::Nodo*& BArbol<T>::getMayor() {
	return getMayor(raiz);
}

template<class T>
typename BArbol<T>::Nodo*& BArbol<T>::getMayor(Nodo*& r) {
	if (r == nullptr || r->getDcho() == nullptr) {
		return r;
	}

	return getMenor(r->getDcho());
}

template<class T>
inline bool BArbol<T>::isHoja(Nodo*& r) {
	return r != nullptr and r->getIzdo() == r->getDcho();
}

template<class T>
inline int BArbol<T>::getAltura() {
	return getAltura(raiz);
}

template<class T>
inline int BArbol<T>::getAltura(Nodo*& r) {
	if (r == nullptr) {
		return 0;
	}

	int lH(getAltura(r->getIzdo()));
	int rH(getAltura(r->getDcho()));

	return (lH > rH ? lH : rH) + 1;
}

template<class T>
inline int BArbol<T>::getAlturaIzda() {
	return getAlturaIzda(raiz->getIzdo());
}

template<class T>
inline int BArbol<T>::getAlturaIzda(Nodo*& r) {
	if (r == nullptr) {
		return 0;
	}

	int lH(getAlturaIzda(r->getIzdo()));
	int rH(getAlturaIzda(r->getDcho()));

	return (lH > rH ? lH : rH) + 1;
}

template<class T>
inline int BArbol<T>::getAlturaDcha() {
	return getAlturaDcha(raiz->getDcho());
}

template<class T>
inline int BArbol<T>::getAlturaDcha(Nodo*& r) {
	if (r == nullptr) {
		return 0;
	}

	int lH(getAlturaDcha(r->getIzdo()));
	int rH(getAlturaDcha(r->getDcho()));

	return (lH > rH ? lH : rH) + 1;
}

template<class T>
inline void BArbol<T>::preOrder() {
	preOrder(raiz);
}

template<class T>
inline void BArbol<T>::preOrder(Nodo*& r) {
	if (r == nullptr) {
		return;
	}

	std::cout << r->getContenido() << ",";
	preOrder(r->getIzdo());
	preOrder(r->getDcho());
}

template<class T>
inline void BArbol<T>::inOrder() {
	inOrder(raiz);
}

template<class T>
inline void BArbol<T>::inOrder(Nodo*& r) {
	if (r == nullptr) {
		return;
	}

	inOrder(r->getIzdo());
	std::cout << r->getContenido() << ",";
	inOrder(r->getDcho());
}

template<class T>
inline void BArbol<T>::posOrder() {
	posOrder(raiz);
}

template<class T>
inline void BArbol<T>::posOrder(Nodo*& r) {
	if (r == nullptr) {
		return;
	}

	posOrder(r->getIzdo());
	posOrder(r->getDcho());
	std::cout << r->getContenido() << ",";
}

template<class T>
inline void BArbol<T>::borradorHD() {
	borradorHD(raiz);
}

template<class T>
inline void BArbol<T>::borradorHD(Nodo*& r) {
	if (r == nullptr) {
		return;
	}

	borradorHD(r->getIzdo());
	borradorHD(r->getDcho());
	r->setIzdo(auxB);
	r->setDcho(auxB);
	delete r;
}

template<class T>
int BArbol<T>::getBalanceo(Nodo*& r) {
	return getAltura(r->getDcho()) - getAltura(r->getIzdo());
}

template<class T>
void BArbol<T>::simpleIzdoRotacion(Nodo*& r) {
	Nodo* aux1(r->getDcho());
	Nodo* aux2(aux1->getIzdo());

	r->setDcho(aux2);
	aux1->setIzdo(r);
	r = aux1;
}

template<class T>
void BArbol<T>::simpleDchoRotacion(Nodo*& r) {
	Nodo* aux1(r->getIzdo());
	Nodo* aux2(aux1->getDcho());

	r->setIzdo(aux2);
	aux1->setDcho(r);
	r = aux1;
}

template<class T>
void BArbol<T>::dobleIzdoRotacion(Nodo*& r) {
	simpleDchoRotacion(r->getDcho());
	simpleIzdoRotacion(r);
}

template<class T>
void BArbol<T>::dobleDchoRotacion(Nodo*& r) {
	simpleIzdoRotacion(r->getIzdo());
	simpleDchoRotacion(r);
}

template<class T>
void BArbol<T>::doBalanceador(Nodo*& r) {
	switch (getBalanceo(r)) {
	case -2:
		if (getBalanceo(r->getIzdo())== -1) {
			simpleDchoRotacion(r);
		} else {
			dobleDchoRotacion(r);
		}
		break;
	case 2:
		if (getBalanceo(r->getDcho()) == 1) {
			simpleIzdoRotacion(r);
		} else {
			dobleIzdoRotacion(r);
		}
		break;
	default:
		break;
	}
}

#endif // !BARBOL_H_INCLUDED