#include "Zwierze.h"



Zwierze::Zwierze()
{
}

Zwierze::Zwierze(Swiat* swiat) : Organizm(swiat){
}

Zwierze::Zwierze(Swiat* swiat, int polozenieX, int polozenieY) : Organizm(swiat, polozenieX, polozenieY){
}

enum kierunki {
	GORA,
	DOL,
	PRAWO,
	LEWO
};

void Zwierze::zmienPolozenie(int x, int y, int& ilosc_prob_ruchu) {
	int nx = getPolozenieX() + x;
	int ny = getPolozenieY() + y;
	if (czyWychodziPozaTablice(nx, ny)) {
		ilosc_prob_ruchu++;
		ruch(1, ilosc_prob_ruchu);
	}
	else {
		if (czyStoiZwierze(nx, ny))
			naCoWszedl(nx, ny)->kolizja(this);
		else {
			cout << this->getNazwaGatunku() << " porusza sie ";
			if (x < 0)
				cout << "w gore" << endl;
			if (x > 0)
				cout << "w dol" << endl;
			if (y > 0)
				cout << "w prawo" << endl;
			if (y < 0)
				cout << "w lewo" << endl;
			poruszenieSie(nx, ny);
		}
	}

}


void Zwierze::ruch(int ileKrokow, int& ilosc_prob_ruchu){
	int ruch = rand() % 4;
	if (ilosc_prob_ruchu < 50) {
		switch (ruch) {
		case GORA:
			zmienPolozenie(-ileKrokow, 0, ilosc_prob_ruchu);
			break;
		case DOL:
			zmienPolozenie(ileKrokow, 0, ilosc_prob_ruchu);
			break;
		case PRAWO:
			zmienPolozenie(0, ileKrokow, ilosc_prob_ruchu);
			break;
		case LEWO:
			zmienPolozenie(0, -ileKrokow, ilosc_prob_ruchu);
			break;
		}
	}
}



void Zwierze::akcja(){

	int ilosc_prob_ruchu = 0; //zapobiega nieskonczonym ruchom
	
	ruch(1, ilosc_prob_ruchu);
	
}

void Zwierze::kolizja(Organizm* atakujacy){

}

Zwierze::~Zwierze(){
}
