#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {

public:
	Owca();
	Owca(Swiat* swiat);
	Owca(Swiat* swiat, int polozenieX, int polozenieY);
	bool czyToSamoZwierze(Organizm* organizm) override;
	void kolizja(Organizm* atakujacy);

	~Owca() override;
};