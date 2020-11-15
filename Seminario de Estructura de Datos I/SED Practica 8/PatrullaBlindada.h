#ifndef PATRULLABLINDADA_H_INCUDED
#define PATRULLABLINDADA_H_INCUDED

#include "patrulla.h"

class CPatullaArtillada : public CPatrulla {
private:
	int blindaje;
public:

	CPatullaArtillada();
	~CPatullaArtillada();


	virtual void Acelerar();
	virtual void ImprimirVirtual();
	void ImprimirNoVirtual();
};

#endif // !PATRULLABLINDADA_H_INCUDED