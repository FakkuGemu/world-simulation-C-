#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {

public:
	Lis();
	Lis(Swiat* swiat);
	Lis(Swiat* swiat, int polozenieX, int polozenieY);

	void akcja() override;
	void kolicja(Organizm* organizm);
	bool czyToSamoZwierze(Organizm* organizm);
	void zmienPolozenie(int x, int y, int& ilosc_prob_ruchu) override;

	~Lis() override;
};
