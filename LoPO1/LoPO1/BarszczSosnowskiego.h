#pragma once
#include "Roslina.h"

class BarszczSosnowskiego : public Roslina {


public:
	BarszczSosnowskiego();
	BarszczSosnowskiego(Swiat* swiat);
	BarszczSosnowskiego(Swiat* swiat, int polozenieX, int polozenieY);

	void akcja() override;
	void kolizja(Organizm* organizm) override;


	~BarszczSosnowskiego();
};