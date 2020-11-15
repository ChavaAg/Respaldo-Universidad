#ifndef PATRULLA_H_INCLUDED
#define PATRULLA_H_INCLUDED

#include "auto.h"

class CPatrulla : public CAuto {
public:
	CPatrulla();
	~CPatrulla();

	virtual void Acelerar();

	virtual void ImprimirVirtual();
	void ImprimirNoVirtual();
};
#endif // !PATRULLA_H_INCLUDED

