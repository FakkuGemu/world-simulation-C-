#include "Lis.h"

Lis::Lis(){
	
}

Lis::Lis(Swiat* swiat) : Zwierze(swiat)
{
	this->setSila(3);
	this->setInicjatywa(7);
	this->setNazwaGatunku('l');
	this->dodajDoKolejki(this);
}

Lis::Lis(Swiat* swiat, int polozenieX, int polozenieY) : Zwierze(swiat, polozenieX, polozenieY){
	this->setSila(3);
	this->setInicjatywa(7);
	this->setNazwaGatunku('l');
	this->dodajDoKolejki(this);
}

void Lis::akcja(){
	
	int ilosc_prob_ruchu = 0; //zapobiega nieskonczonym ruchom
	ruch(1, ilosc_prob_ruchu);
	
}

void Lis::kolicja(Organizm* atakujacy){
	if (!czyToSamoZwierze(atakujacy)) {
		cout << "Lis zostal zaatakowany przez " << atakujacy->getNazwaGatunku() << endl;
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
			cout << "Lis sie rozmnaza." << endl;
			Lis* nowylis = new Lis(this->getSwiat(), x, y);
		}
	}

}

bool Lis::czyToSamoZwierze(Organizm* organizm)
{
	if (dynamic_cast<Lis*>(organizm) != NULL)
		return true;
	else
		return false;
}

void Lis::zmienPolozenie(int x, int y, int& ilosc_prob_ruchu){
	int nx = getPolozenieX() + x;
	int ny = getPolozenieY() + y;
	if (czyWychodziPozaTablice(nx, ny)) {
		ilosc_prob_ruchu++;
		ruch(1, ilosc_prob_ruchu);
	}
	else {
		if (czyStoiZwierze(nx, ny)) {
			if (naCoWszedl(nx, ny)->getSila() > this->getSila()){
				ruch(1, ilosc_prob_ruchu);
			}	
			else naCoWszedl(nx, ny)->kolizja(this);
		}
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

Lis::~Lis(){
	cout << "Lis umar" << endl;
}
