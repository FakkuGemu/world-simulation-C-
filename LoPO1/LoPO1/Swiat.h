#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <initializer_list>
#include<fstream>
#include <conio.h>
#include "Organizm.h"
#include <algorithm>
#include "Zwierze.h"
#include <vector>
#include <cstdio>
#include "Czlowiek.h"
#include "Wilk.h"
#include "Mlecz.h"
#include "Owca.h"
#include "Trawa.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Guarana.h"
#include "BarszczSosnowskiego.h"
#include "WilczeJagody.h"



class Swiat {
	int tura;
	int szerokosc;
	int umiejetnoscAktywna = 0;
	int pozostaleTury = 0;
	int ilosc_zwierzat = 0;
	bool czySymulacjatrwa = true;
	vector<Organizm *> kolejkaOrganizmow;
	Organizm*** tablicaSwiata;
	Organizm*** stworzTabliceSwiata(int szerokosc);
	
	void setSzerokosc(int i);
	void setTura(int i);

public:
	Swiat();
	Swiat(int szerokosc);

	void rysujSwiat();
	void wykonajTure();
	void wczytajSwiat();

	void setUmiejetnoscAktywna(int i);
	void setpozostaleTury(int i);
	void setCzySymulacjaTrwa(bool i);
	int getSzerokosc() const;
	Organizm*** getTablicaSwiata() const;

	void wstawDoTablicy(Organizm* organizm);
	
	Organizm* getZwierzeZTablicy(int x, int y);
	
	void usunZKolejki(Organizm* organizm);
	void zaktualizujKolejke();
	void dodajDoKolejki(Organizm* organizm);
	
	bool czyZajete(int x, int y);
	bool czyWychodziPozaSwiat(int x, int y);
	bool czyZwierze(int x, int y);
	bool czyStoiZwierze(int x, int y);
	bool czySymulacjaTrwa();
	void zabijOba(Organizm* o1, Organizm* o2);
	void wypiszKolejke();
	void usunZeSwiata(Organizm* organizm);
	void WALKA(Organizm* organizm1, Organizm* organizm2);
	void ucieczka(Organizm* organizm1, Organizm* organizm2);
	void zabijZwierzetaDookola(Organizm* organizm);
	
	void wczytajWilka(FILE* plik);
	void wczytajOwce(FILE* plik);
	void wczytajLisa(FILE* plik);
	void wczytajAntylope(FILE* plik);
	void wczytajZolwia(FILE* plik);
	void wczytajCzlowieka(FILE* plik);
	void wczytajTrawe(FILE* plik);
	void wczytajGuarane(FILE* plik);
	void wczytajBarszcz(FILE* plik);
	void wczytajJagode(FILE* plik);
	void wczytajMlecz(FILE* plik);


	~Swiat();
protected:
	void zapiszStanGry();
};

