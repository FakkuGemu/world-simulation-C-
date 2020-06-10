#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {

public:
	Antylopa();
	Antylopa(Swiat* swiat);
	Antylopa(Swiat* swiat, int polozenieX, int polozenieY);

	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
	bool czyToSamoZwierze(Organizm* organizm) override;
	bool czyUciekla();

	~Antylopa() override;
};