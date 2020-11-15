#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#include "motor.h"

class CAuto {
protected:
	CMotor motor;
	float velocidad;
public:
	CAuto();
	~CAuto();

	void setMotor(CMotor);

	virtual void ImprimirVirtual();
	void ImprimirNoVirtual();
	virtual void Acelerar();
};

#endif // !AUTO_H_INCLUDED

