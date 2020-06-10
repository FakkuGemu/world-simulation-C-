#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {

public:
	Wilk();
	Wilk(Swiat* swiat);
	Wilk(Swiat* swiat, int polozenieX, int polozenieY);

	bool czyToSamoZwierze(Organizm* organizm) override;
	void kolizja(Organizm* atakujacy);

	~Wilk() override;
};