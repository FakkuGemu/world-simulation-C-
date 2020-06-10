#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
	int umiejetnoscAktywna = 0;
	int pozostaleTury = 0;
	void tarczaAlzura();
	bool czyUmiejetnoscAktywna();

public:
	Czlowiek();
	Czlowiek(Swiat* swiat);
	Czlowiek(Swiat* swiat, int polozenieX, int polozenieY);

	void setUmiejetnoscAktywna(int i);
	void setPozostaleTury(int i);

	void akcja() override;
	void kolizja(Organizm* atakujacy);
	void ruch(int ilosc_krokow, int ilosc_prob_ruchu);
	
	void zmienPolozenie(int x, int y, int& ilosc_prob_ruchu) override;
	bool czyToSamoZwierze(Organizm* organizm) override;
	
	

	~Czlowiek();
};