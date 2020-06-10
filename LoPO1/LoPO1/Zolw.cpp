#include "Zolw.h"

Zolw::Zolw()
{
}

Zolw::Zolw(Swiat* swiat) : Zwierze(swiat) {
	this->setSila(2);
	this->setNazwaGatunku('z');
	this->setInicjatywa(1);
	this->dodajDoKolejki(this);
}

Zolw::Zolw(Swiat* swiat, int polozenieX, int polozenieY) : Zwierze(swiat, polozenieX, polozenieY){
	this->setSila(2);
	this->setNazwaGatunku('z');
	this->setInicjatywa(1);
	this->dodajDoKolejki(this);
}

void Zolw::akcja(){
	
	int ilosc_prob_ruchu = 0; //zapobiega nieskonczonym ruchom

	if (czySieRuszy()) {
		cout << "Zolw sie rusza." << endl;
		ruch(1, ilosc_prob_ruchu);
	}
	else cout << "Zolw sie nie rusza." << endl;
	
}

void Zolw::kolizja(Organizm* atakujacy){
	if (!czyToSamoZwierze(atakujacy)) {
		if(!czySieObronil(atakujacy))
			this->wojna(atakujacy);
	}
	else {
		int x = this->getPolozenieX(), y = this->getPolozenieY(), ilos_prob = 0;
		while (czyStoiZwierze(x, y) && ilos_prob < 50) { //ilos_prob zapobiega nieskonczonemu szukaniu miejsca na urodzenie zwierzecia
			int i = rand() % 8;
			ilos_prob++;
			switch (i) {
			case 0:
				x = this->getPolozenieX() + 1;
				y = this->getPolozenieY();
				break;
			case 1:
				x = this->getPolozenieX() - 1;
				y = this->getPolozenieY();
				break;
			case 2:
				x = this->getPolozenieX();
				y = this->getPolozenieY() + 1;
				break;
			case 3:
				x = this->getPolozenieX();
				y = this->getPolozenieY() - 1;
				break;
			case 4:
				x = atakujacy->getPolozenieX() + 1;
				y = atakujacy->getPolozenieY();
				break;
			case 5:
				x = atakujacy->getPolozenieX() - 1;
				y = atakujacy->getPolozenieY();
				break;
			case 6:
				x = atakujacy->getPolozenieX();
				y = atakujacy->getPolozenieY() + 1;
				break;
			case 7:
				x = atakujacy->getPolozenieX();
				y = atakujacy->getPolozenieY() - 1;
				break;
			default:
				break;
			}
		}
		if (ilos_prob < 50) {  //stworzy wikla tylko jezeli znajdzie dobre miejsce
			cout << "Zolw sie rozmnaza." << endl;
			Zolw* nowyzolw = new Zolw(this->getSwiat(), x, y);
		}
	}

}

bool Zolw::czyToSamoZwierze(Organizm* organizm)
{
	if (dynamic_cast<Zolw*>(organizm) != NULL) 
		return true;
	else
		return false;
}

bool Zolw::czySieRuszy()
{
	int zmienna = rand() % 4;
	if (zmienna == 0)
		return true;
	return false;
}

bool Zolw::czySieObronil(Organizm* atakujacy)
{
	if (atakujacy->getSila() < 5) {
		cout << "Zolw obroil sie przed " << atakujacy->getNazwaGatunku() << endl;
		return true;
	}
	cout << "Zolw nie zdolal sie obronic przed " << atakujacy->getNazwaGatunku() << endl;
	return false;
}

Zolw::~Zolw(){
	cout << "Zolw umar" << endl;
}
