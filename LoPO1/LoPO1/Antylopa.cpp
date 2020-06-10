#include "Antylopa.h"

Antylopa::Antylopa() {

}

Antylopa::Antylopa(Swiat* swiat) : Zwierze(swiat) {
	this->setSila(4);
	this->setInicjatywa(4);
	this->setNazwaGatunku('a');
	this->dodajDoKolejki(this);
}

Antylopa::Antylopa(Swiat* swiat, int polozenieX, int polozenieY) : Zwierze(swiat, polozenieX, polozenieY){
	this->setSila(4);
	this->setInicjatywa(4);
	this->setNazwaGatunku('a');
	this->dodajDoKolejki(this);
}

void Antylopa::akcja(){
	int ilosc_prob_ruchu = 0; //zapobiega nieskonczonym ruchom
	 
	ruch(2, ilosc_prob_ruchu);
	
}

void Antylopa::kolizja(Organizm* atakujacy){
	if (!czyToSamoZwierze(atakujacy)) {
		if (czyUciekla()) {
			cout << "Antylopa uciekla przed walka" << endl;
			this->ucieczka(atakujacy);
		}
		else
			cout << "Antylopa zostala zaatakowana przez " << atakujacy->getNazwaGatunku() << endl;
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
			cout << "Antylopa sie rozmnaza." << endl;
			Antylopa* nowaantylopa = new Antylopa(this->getSwiat(), x, y);
		}
	}

}

bool Antylopa::czyToSamoZwierze(Organizm* organizm)
{
	if (dynamic_cast<Antylopa*>(organizm) != NULL)
		return true;
	else
		return false;
}

bool Antylopa::czyUciekla()
{
	int zmienna = rand() % 2;
	if (zmienna == 1)
		return true;
	return false;
}

Antylopa::~Antylopa(){
	cout << "Antylopa umarla" << endl;
}
