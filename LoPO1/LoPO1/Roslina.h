#pragma once
#include "Organizm.h"

class Roslina : public Organizm {

public:
	Roslina();

	Roslina(Swiat* swiat);
	Roslina(Swiat* swiat, int polozenieX, int polozenieY);

	virtual void akcja() override;
	virtual void kolizja(Organizm* atakujacy) override;
	bool czySieRozsieje();

	virtual ~Roslina() override;
};