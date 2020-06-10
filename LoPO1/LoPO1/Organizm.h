#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

class Swiat;

class Organizm abstract{
	int sila;
	int inicjatywa;
	int wiek;
	int polozenieX;
	int polozenieY;
	char nazwaGatunku;
	Swiat* swiat;

public:
	Organizm();
	Organizm(Swiat* swiat);
	Organizm(Swiat* swiat, int polozenieX, int polozenieY);

	virtual void akcja() = 0;
	virtual void kolizja(Organizm* organizm) = 0;
	char rysowanie();

	int getSila() const;
	int getInicjatywa() const;
	int getWiek() const;
	int getPolozenieX() const;
	int getPolozenieY() const;
	char getNazwaGatunku() const;
	int getSzerokoscSwiata() const;
	void setUmiejetnosc(int i);
	void setPozostaleTurySwiata(int i);
	Swiat* getSwiat() const;
	
	

	void setSila(int sila);
	void setInicjatywa(int inicjatywa);
	void setWiek(int wiek);
	void setPolozenieX(int PolozenieX);
	void setPolozenieY(int polozenieY);
	void setNazwaGatunku(char nazwaGatunku);
	void setSwiat(Swiat* swiat);
	void zakonczSymulacje();
	
	void dodajDoKolejki(Organizm* organizm);
	void wypiszSwiat();
	bool czyWychodziPozaTablice(int x, int y);
	bool czyStoiZwierze(int x, int y);
	void poruszenieSie(int x, int y);
	void wojna(Organizm* atakujacy);
	void ucieczka(Organizm* organizm);
	Organizm* naCoWszedl(int x, int y);
	void zabijZwierzetaDookola();
	void zabijObydwa(Organizm* organizm);


	virtual ~Organizm();
};


