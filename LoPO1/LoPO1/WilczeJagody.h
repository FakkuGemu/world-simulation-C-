#pragma once
#include "Roslina.h"

class WilczeJagody : public Roslina {


public:
	WilczeJagody();
	WilczeJagody(Swiat* swiat);
	WilczeJagody(Swiat* swiat, int polozenieX, int polozenieY);

	void kolizja(Organizm* organizm) override;
	void akcja() override;

	~WilczeJagody() override;
};