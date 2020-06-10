#include "Roslina.h"

Roslina::Roslina()
{
}

Roslina::Roslina(Swiat* swiat) : Organizm(swiat){
	this->setInicjatywa(0);
}

Roslina::Roslina(Swiat* swiat, int polozenieX, int polozenieY) : Organizm(swiat, polozenieX, polozenieY){
	this->setInicjatywa(0);
}

void Roslina::akcja(){
}

void Roslina::kolizja(Organizm* atakujacy){
	cout << atakujacy->getNazwaGatunku() << " wszedl na " << this->getNazwaGatunku() << endl;
	this->wojna(atakujacy);
}

bool Roslina::czySieRozsieje()
{
	int randomowa = rand() % 10;
	if (randomowa == 0)
		return true;
	return false;
}

Roslina::~Roslina(){
}
