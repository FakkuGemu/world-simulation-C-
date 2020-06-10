#include "Mlecz.h"

Mlecz::Mlecz() {

}

Mlecz::Mlecz(Swiat* swiat) : Roslina(swiat) {
	this->setSila(0);
	this->setNazwaGatunku('m');
	this->dodajDoKolejki(this);
}

Mlecz::Mlecz(Swiat* swiat, int polozenieX, int polozenieY) : Roslina(swiat, polozenieX, polozenieY){
	this->setSila(0);
	this->setNazwaGatunku('m');
	this->dodajDoKolejki(this);
}

void Mlecz::akcja(){
	for (int proby_rozsiania = 0; proby_rozsiania < 3; proby_rozsiania++) {
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
				cout << "Mlecz sie rozsiewa." << endl;
				Mlecz* nowymlecz = new Mlecz(this->getSwiat(), x, y);
			}
		}
	}
}

Mlecz::~Mlecz(){
	cout << "Mlecz zostal zjedzony" << endl;
}
