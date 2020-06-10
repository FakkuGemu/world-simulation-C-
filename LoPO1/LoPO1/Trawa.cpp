#include "Trawa.h"

Trawa::Trawa(){
}

Trawa::Trawa(Swiat* swiat) : Roslina(swiat) {
	this->setSila(0);
	this->setNazwaGatunku('t');
	this->dodajDoKolejki(this);
}

Trawa::Trawa(Swiat* swiat, int polozenieX, int polozenieY) : Roslina(swiat, polozenieX, polozenieY){
	this->setSila(0);
	this->setNazwaGatunku('t');
	this->dodajDoKolejki(this);
}

void Trawa::akcja(){
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
			cout << "Trawa sie rozsiewa." << endl;
			Trawa* nowatrawa = new Trawa(this->getSwiat(), x, y);
		}
	}
}

Trawa::~Trawa() {
	cout << "Trawa zostala zjedzona" << endl;
}

