#include "Czlowiek.h"
#include <conio.h>

enum STRZALKI {
	STRZALKA_W_GORE = 72,
	STRZALKA_W_DOL = 80,
	STRZALKA_W_PRAWO = 77,
	STRZALKA_W_LEWO = 75
};

Czlowiek::Czlowiek() {

}
Czlowiek::Czlowiek(Swiat* swiat) : Zwierze(swiat) {
	this->setSila(5);
	this->setNazwaGatunku('C');
	this->setInicjatywa(4);
	this->dodajDoKolejki(this);
}

Czlowiek::Czlowiek(Swiat* swiat, int polozenieX, int polozenieY) : Zwierze(swiat, polozenieX, polozenieY){
	this->setSila(5);
	this->setNazwaGatunku('C');
	this->setInicjatywa(4);
	this->dodajDoKolejki(this);
}

void Czlowiek::setUmiejetnoscAktywna(int i){
	this->umiejetnoscAktywna = i;
}

void Czlowiek::setPozostaleTury(int i){
	this->pozostaleTury = i;
}


void Czlowiek::akcja(){
	int ilosc_prob_ruchu = 0; //zapobiega nieskonczonym ruchom
	cout << "Twoja kolej: " << endl;
	tarczaAlzura();
	ruch(1, ilosc_prob_ruchu);
	
}

void Czlowiek::kolizja(Organizm* atakujacy){
	if (!czyToSamoZwierze(atakujacy)) {
		cout << "Zostales zaatakowany przez " << atakujacy->getNazwaGatunku() << endl;
		if (czyUmiejetnoscAktywna()) {
			cout << "Tarcza Alzura ochronila ciebie przed " << atakujacy->getNazwaGatunku()<<endl;
			atakujacy->ucieczka(this);
		}
		else this->wojna(atakujacy);
	}
}

void Czlowiek::ruch(int ileKrokow, int ilosc_prob_ruchu){
	cout << "Porusz sie strzalkami " << endl;
	wypiszSwiat();
	char ruch = _getch();
	ruch = _getch();
		switch (ruch) {
		case STRZALKA_W_GORE:
			zmienPolozenie(-ileKrokow, 0, ilosc_prob_ruchu);
			break;
		case STRZALKA_W_DOL:
			zmienPolozenie(ileKrokow, 0, ilosc_prob_ruchu);
			break;
		case STRZALKA_W_PRAWO:
			zmienPolozenie(0, ileKrokow, ilosc_prob_ruchu);
			break;
		case STRZALKA_W_LEWO:
			zmienPolozenie(0, -ileKrokow, ilosc_prob_ruchu);
			break;
		}
	
	
}

void Czlowiek::tarczaAlzura(){

	if (czyUmiejetnoscAktywna()) {
		pozostaleTury--;

		if (pozostaleTury == 0) {
			umiejetnoscAktywna = 0;
		}
		else {
			cout << "Tarcza Alzura jest aktywna pozostaly " << pozostaleTury << " tury." << endl;
		}
	}

	if (!czyUmiejetnoscAktywna()) {
		cout << "Czy aktywowac tarcze Alzura? y/n" << endl;
		char zmienna = _getch();
		if (zmienna == 'y') {
			umiejetnoscAktywna = 1;
			pozostaleTury = 5;
		}
	}
	setPozostaleTurySwiata(pozostaleTury);
	setUmiejetnosc(umiejetnoscAktywna);
}

bool Czlowiek::czyUmiejetnoscAktywna()
{
	if (umiejetnoscAktywna == 0)
		return false;
	return true;
}

void Czlowiek::zmienPolozenie(int x, int y, int& ilosc_prob_ruchu) {
	int nx = getPolozenieX() + x;
	int ny = getPolozenieY() + y;
	if (czyWychodziPozaTablice(nx, ny)) {
		ilosc_prob_ruchu++;
		ruch(1, ilosc_prob_ruchu);
	}
	else {
		if (czyStoiZwierze(nx, ny))
			naCoWszedl(nx, ny)->kolizja(this);
		else {
			cout << this->getNazwaGatunku() << " porusza sie ";
			if (x == -1)
				cout << "w gore" << endl;
			if (x == 1)
				cout << "w dol" << endl;
			if (y == 1)
				cout << "w prawo" << endl;
			if (y == -1)
				cout << "w lewo" << endl;
			poruszenieSie(nx, ny);
		}
	}

}

bool Czlowiek::czyToSamoZwierze(Organizm* organizm)
{
	return false;
}

Czlowiek::~Czlowiek(){
	cout << "Umarles koniec gry!!!" << endl;
	cout << "Wcisnij enter by zakonczyc" << endl;
	_getch();
	zakonczSymulacje();
}
