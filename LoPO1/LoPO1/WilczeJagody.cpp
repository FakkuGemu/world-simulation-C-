#include "WilczeJagody.h"

WilczeJagody::WilczeJagody() {

}
WilczeJagody::WilczeJagody(Swiat* swiat) : Roslina(swiat) {
	this->setSila(99);
	this->setNazwaGatunku('j');
	this->dodajDoKolejki(this);
}
WilczeJagody::WilczeJagody(Swiat* swiat, int polozenieX, int polozenieY) : Roslina(swiat, polozenieX, polozenieY) {
	this->setSila(99);
	this->setNazwaGatunku('j');
	this->dodajDoKolejki(this);
}

void WilczeJagody::kolizja(Organizm* atakujacy){
	cout << atakujacy->getNazwaGatunku() << " wszedl na " << this->getNazwaGatunku() << endl;
	zabijObydwa(atakujacy);
}

void WilczeJagody::akcja(){
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
			cout << "Wilcze jagody sie rozsiewaja." << endl;
			WilczeJagody* nowy = new WilczeJagody(this->getSwiat(), x, y);
		}
	}
}

WilczeJagody::~WilczeJagody(){
	cout << "Wilcze jagody zostaly zjedzone" << endl;
}
