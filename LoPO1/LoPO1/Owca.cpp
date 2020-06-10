#include "Owca.h"

Owca::Owca(){

}

Owca::Owca(Swiat* swiat) : Zwierze(swiat) {
	this->setSila(4);
	this->setInicjatywa(4);
	this->setNazwaGatunku('o');
	this->dodajDoKolejki(this);
}

Owca::Owca(Swiat* swiat, int polozenieX, int polozenieY) : Zwierze(swiat, polozenieX, polozenieY){
	this->setSila(4);
	this->setInicjatywa(4);
	this->setNazwaGatunku('o');
	this->dodajDoKolejki(this);
}

bool Owca::czyToSamoZwierze(Organizm* organizm)
{
	if (dynamic_cast<Owca*>(organizm) != NULL)
		return true;
	else
		return false;
}

void Owca::kolizja(Organizm* atakujacy){
	if (!czyToSamoZwierze(atakujacy)) {
		cout << "Owca zostala zaatakowana przez " << atakujacy->getNazwaGatunku() <<endl;
		this->wojna(atakujacy);
	}
	else {
		int x = this->getPolozenieX(), y = this->getPolozenieY(), ilos_prob = 0;
		while (czyStoiZwierze(x, y) && ilos_prob < 50) {
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
		if (ilos_prob < 50) {
			cout << "Owca sie rozmnaza." << endl;
			Owca* nowaowca = new Owca(this->getSwiat(), x, y);
		}
	}

		
}



Owca::~Owca(){
	cout << "Owca umarla" << endl;
}
