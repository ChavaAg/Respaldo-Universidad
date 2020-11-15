#include "auto.h"

class CTaxi :public CAuto {
public:
	CTaxi();
	~CTaxi();

	virtual void Acelerar();

	virtual void ImprimirVirtual();
	void ImprimirNoVirtual();
};
