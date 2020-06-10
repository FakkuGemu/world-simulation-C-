#include "Guarana.h"

Guarana::Guarana() {

}

Guarana::Guarana(Swiat* swiat) : Roslina(swiat) {
	this->setSila(0);
	this->setNazwaGatunku('g');
	this->dodajDoKolejki(this);
}

Guarana::Guarana(Swiat* swiat, int polozenieX, int polozenieY) : Roslina(swiat, polozenieX, polozenieY) {
	this->setSila(0);
	this->setNazwaGatunku('g');
	this->dodajDoKolejki(this);
}

void Guarana::kolizja(Organizm* atakujacy){
	cout << atakujacy->getNazwaGatunku() << " wszedl na " << this->getNazwaGatunku() << endl;
	this->wojna(atakujacy);
	int nowasila = atakujacy->getSila();
	nowasila += 3;
	atakujacy->setSila(nowasila);
}

void Guarana::akcja(){
	if (czySieRozsieje()) {
		int x = this->getPolozenieX(), y = this->getPolozenieY(), ilos_prob = 0;
		while (czyStoiZwierze(x, y) && ilos_prob < 50) { //ilos_prob zapobiega nieskonczonemu szukaniu miejsca na urodzenie zwierzecia
			int i = rand() % 4;
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
			}
		}
		if (ilos_prob < 50) {//stworzy trawe tylko jezeli znajdzie dobre miejsce
			cout << "Guarana sie rozsiewa." << endl;
			Guarana* guarana = new Guarana(this->getSwiat(), x, y);
		}
	}
}

Guarana::~Guarana(){
	cout << "Guarana zostala zjedzona" << endl;
}
