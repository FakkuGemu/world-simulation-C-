#include "Wilk.h"


Wilk::Wilk(){
}

Wilk::Wilk(Swiat* swiat) : Zwierze(swiat){
	this->setSila(9);
	this->setInicjatywa(5);
	this->setNazwaGatunku('w');
	this->dodajDoKolejki(this);
}

Wilk::Wilk(Swiat* swiat, int polozenieX, int polozenieY) : Zwierze(swiat, polozenieX, polozenieY){
	this->setSila(9);
	this->setInicjatywa(5);
	this->setNazwaGatunku('w');
	this->dodajDoKolejki(this);
}

bool Wilk::czyToSamoZwierze(Organizm* organizm)
{
	if (dynamic_cast<Wilk*>(organizm) != NULL)
		return true;
	else
		return false;
}

void Wilk::kolizja(Organizm* atakujacy){
	if (!czyToSamoZwierze(atakujacy)) {
		cout << "Wilk zostal zaatakowany przez " << atakujacy->getNazwaGatunku() << endl;
		this->wojna(atakujacy);
	}
	else {
		int x = this->getPolozenieX(),y = this->getPolozenieY(), ilos_prob = 0;
		while (czyStoiZwierze(x, y) && ilos_prob < 50) { //ilos_prob zapobiega nieskonczonemu szukaniu miejsca na urodzenie zwierzecia
			int i = rand() % 8;
			ilos_prob++;
			switch(i){
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
		if (ilos_prob < 50) {//stworzy wikla tylko jezeli znajdzie dobre miejsce
			cout << "Wilk sie rozmnaza." << endl;
			Wilk* nowywilk = new Wilk(this->getSwiat(), x, y);
		}
	}

}

Wilk::~Wilk(){
	cout << "Wilk umar" << endl;
}
