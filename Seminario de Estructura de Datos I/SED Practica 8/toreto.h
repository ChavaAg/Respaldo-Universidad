#include "auto.h"

class CToreto_Car :public CAuto {
public:

	CToreto_Car();
	~CToreto_Car();

	virtual void Acelerar();
	void Turbo();

	virtual void ImprimirVirtual();
	void ImprimirNoVirtual();
};