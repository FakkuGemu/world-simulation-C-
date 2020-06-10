#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {

public:
	Zolw();
	Zolw(Swiat* swiat);
	Zolw(Swiat* swiat, int polozenieX, int polozenieY);

	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
	bool czyToSamoZwierze(Organizm* organizm) override;
	bool czySieRuszy();
	bool czySieObronil(Organizm* atakujacy);

	~Zolw() override;
};