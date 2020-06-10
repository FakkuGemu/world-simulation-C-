#pragma once
#include "Roslina.h"

class Mlecz : public Roslina {


public:
	Mlecz();
	Mlecz(Swiat* swiat);
	Mlecz(Swiat* swiat, int polozenieX, int polozenieY);

	void akcja() override;

	~Mlecz() override;
};