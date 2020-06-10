#pragma once
#include "Roslina.h"

class Guarana : public Roslina {


public:
	Guarana();
	Guarana(Swiat* swiat);
	Guarana(Swiat* swiat, int polozenieX, int polozenieY);

	void kolizja(Organizm* organizm) override;
	void akcja() override;

	~Guarana() override;
};