#pragma once
#include "Organizm.h"


class Zwierze : public Organizm {

public:
	Zwierze();
	Zwierze(Swiat* swiat);
	Zwierze(Swiat* swiat, int polozenieX, int polozenieY);

	virtual void ruch(int ileKrokow, int& ilosc_prob_ruchu);
	virtual void akcja() override;
	virtual void kolizja(Organizm* organizm) override;

	virtual void zmienPolozenie(int x, int y, int& ilosc_prob_ruchu);
	virtual bool czyToSamoZwierze(Organizm* orgaznim1) = 0;

	virtual ~Zwierze() override;
};