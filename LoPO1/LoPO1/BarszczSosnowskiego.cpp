#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego() {

}

BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiat) : Roslina(swiat) {
	this->setSila(10);
	this->setNazwaGatunku('b');
	this->dodajDoKolejki(this);
}

BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiat, int polozenieX, int polozenieY) : Roslina(swiat, polozenieX, polozenieY){
	this->setSila(10);
	this->setNazwaGatunku('b');
	this->dodajDoKolejki(this);
}

void BarszczSosnowskiego::akcja(){
	
	this->zabijZwierzetaDookola();
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
			cout << "Barszcz sosnowskiego sie rozsiewa." << endl;
			BarszczSosnowskiego* nowy = new BarszczSosnowskiego(this->getSwiat(), x, y);
		}
	}
}

void BarszczSosnowskiego::kolizja(Organizm* atakujacy){
	cout << atakujacy->getNazwaGatunku() << " wszedl na " << this->getNazwaGatunku() << endl;
	zabijObydwa(atakujacy);
}

BarszczSosnowskiego::~BarszczSosnowskiego(){
	cout << "Braszcz Sosnowskiego zostal zjedzony" << endl;
}
