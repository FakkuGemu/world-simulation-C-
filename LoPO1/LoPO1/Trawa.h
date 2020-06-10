#pragma once
#include "Roslina.h"

class Trawa : public Roslina {


public:
	Trawa();
	Trawa(Swiat* swiat);
	Trawa(Swiat* swiat, int polozenieX, int polozenieY);

	void akcja() override;
	~Trawa() override;
};