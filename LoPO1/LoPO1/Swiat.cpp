#include "Swiat.h"

Swiat::Swiat(){
	this->tura = 1;
	this->szerokosc = 0;
	this->tablicaSwiata = NULL;
}

Swiat::Swiat(int szerokosc){
	this->tura = 1;
	this->szerokosc = szerokosc;
	this->tablicaSwiata = stworzTabliceSwiata(szerokosc);
	vector<Organizm*> kolejkaOrganizmow;
	Czlowiek* gracz = new Czlowiek(this);
	Lis* lis1 = new Lis(this);
	Lis* lis2 = new Lis(this);
	Guarana* g1 = new Guarana(this);
	Guarana* g2 = new Guarana(this);
	Wilk* wilk1 = new Wilk(this);
	Wilk* wilk2 = new Wilk(this);
	Mlecz* mlecz1 = new Mlecz(this);
	Mlecz* mlecz2 = new Mlecz(this);
	Owca* owca1 = new Owca(this);
	Owca* owca2 = new Owca(this);
	Antylopa* a2 = new Antylopa(this);
	Antylopa* a1 = new Antylopa(this);
	Zolw* z1 = new Zolw(this);
	Zolw* z2 = new Zolw(this);
	Trawa* trawa1 = new Trawa(this);
	Trawa* trawa2 = new Trawa(this);
	WilczeJagody* wj1 = new WilczeJagody(this);
	WilczeJagody* wj2 = new WilczeJagody(this);
	BarszczSosnowskiego* bs1 = new BarszczSosnowskiego(this);
	BarszczSosnowskiego* bs2 = new BarszczSosnowskiego(this);
	

}




void Swiat::rysujSwiat(){
	for (int i = 0; i < szerokosc; i++) {
		for (int j = 0; j < szerokosc; j++)
			if (tablicaSwiata[i][j] == NULL) {
				cout << "-"<< " ";
			}
			else {
				cout << tablicaSwiata[i][j]->getNazwaGatunku()<<" ";
			}
		cout << endl;
	}
}

void Swiat::wykonajTure(){
	zaktualizujKolejke();
	//wypiszKolejke();
	cout << "Autor: Jan Jetke"<< endl;
	cout << "Indeks: 180278 (Umiejetnosc - Tarcza Alzura)" << endl << endl;
	cout << "Poczatek tury: " << this->tura << endl;
	

	for (int i = 0; i < kolejkaOrganizmow.size(); i++) {
		if (kolejkaOrganizmow[i] != NULL) {
			int wiek = kolejkaOrganizmow[i]->getWiek();
			wiek++;
			kolejkaOrganizmow[i]->setWiek(wiek);

			if (kolejkaOrganizmow[i]->getWiek() > 1) {
				

				//wypiszKolejke();
				kolejkaOrganizmow[i]->akcja();
			}
			
		}
	}
	zaktualizujKolejke();
	this->tura++;
	cout << "Czy zapisac stan gry i wyjsc? y/n" << endl;
	int opcja = _getch();
	if (opcja == 'y') {
		zapiszStanGry();
		cout << "Pomyslnie zapisano stan gry wcisnij ENTER, by zakonczyc." << endl;
		_getch();
		exit(1);
	}
	system("cls");
}

void Swiat::wczytajSwiat(){
	FILE* plik;
	if ((plik = fopen("zapisSwiata.txt", "r")) == NULL) {
		printf("Nie mogê otworzyæ pliku zapisSwiata.txt do zapisu!\n");
		exit(1);
	}
	
	int zmiennaint;
	int ilosc_zwierzat;
	int i = 0;

	int nazwa;
	fscanf(plik, "%i", &ilosc_zwierzat);
	fscanf(plik, "%i", &zmiennaint); // wczytuje szerokosc
	this->szerokosc = zmiennaint;
	this->tablicaSwiata = stworzTabliceSwiata(zmiennaint);
	fscanf(plik, "%i", &zmiennaint); //  wczytuje ture
	this->tura = zmiennaint;

	while (i < ilosc_zwierzat) {
		fscanf(plik, "%i", &nazwa);
		i++;
		switch (nazwa) {
		case 'w':
			wczytajWilka(plik);
			break;
		case 'o':
			wczytajOwce(plik);
			break;
		case 'l':
			wczytajLisa(plik);
			break;
		case 'a':
			wczytajAntylope(plik);
			break;
		case 'z':
			wczytajZolwia(plik);
			break;
		case 'C':
			wczytajCzlowieka(plik);
			break;
		case 'g':
			wczytajGuarane(plik);
			break;
		case 'm':
			wczytajMlecz(plik);
			break;
		case 't':
			wczytajTrawe(plik);
			break;
		case 'j':
			wczytajJagode(plik);
			break;
		case 'b':
			wczytajBarszcz(plik);
			break;
		}
	}

	fclose(plik);
}

void Swiat::setUmiejetnoscAktywna(int i){
	this->umiejetnoscAktywna = i;
}

void Swiat::setpozostaleTury(int i){
	this->pozostaleTury = i;
}

void Swiat::setCzySymulacjaTrwa(bool i){
	this->czySymulacjatrwa = i;
}

int Swiat::getSzerokosc() const{
	return this->szerokosc;
}
Organizm*** Swiat::getTablicaSwiata() const
{
	return this->tablicaSwiata;
}
Organizm*** Swiat::stworzTabliceSwiata(int szerokosc) {
	Organizm*** tablicaSwiata = new Organizm ** [szerokosc];
	for (int i = 0; i < szerokosc; i++) {
		tablicaSwiata[i] = new Organizm*[szerokosc];
	}
	for (int i = 0; i < szerokosc; i++) {
		for (int j = 0; j < szerokosc; j++)
			tablicaSwiata[i][j] = NULL;
	}

	return tablicaSwiata;
}

void Swiat::setSzerokosc(int i){
	this->szerokosc = i;
}

void Swiat::setTura(int i){
	this->tura = i;
}

void Swiat::wstawDoTablicy(Organizm* organizm) {
	this->tablicaSwiata[organizm->getPolozenieX()][organizm->getPolozenieY()] = organizm;
}

struct porownajOrganizmy {
	bool operator()(Organizm* organizm1, Organizm* organizm2) {
		if (organizm1 == NULL || organizm2 == NULL)
			return false;

		if (organizm1->getInicjatywa() > organizm2->getInicjatywa())
			return true;
		else if (organizm1->getInicjatywa() < organizm2->getInicjatywa())
			return false;
		else {
			if (organizm1->getWiek() > organizm2->getWiek())
				return true;
			else
				return false;
		}
		
	}
};

Organizm* Swiat::getZwierzeZTablicy(int x, int y)
{
	return this->tablicaSwiata[x][y];
}


void Swiat::usunZKolejki(Organizm* organizm){
	int i = 0;
	while (kolejkaOrganizmow[i] != organizm && i < kolejkaOrganizmow.size()) {
		i++;
	}
	kolejkaOrganizmow[i] = NULL;
}

void Swiat::zaktualizujKolejke() {
	for (int i = 0; i < kolejkaOrganizmow.size(); i++) {
		if (kolejkaOrganizmow[i] == NULL) {
			kolejkaOrganizmow.erase(kolejkaOrganizmow.begin() + i);
		}
	}
	sort(kolejkaOrganizmow.begin(), kolejkaOrganizmow.end(), porownajOrganizmy());
	ilosc_zwierzat = kolejkaOrganizmow.size();
}


void Swiat::dodajDoKolejki(Organizm* organizm) {
	kolejkaOrganizmow.push_back(organizm);
}



bool Swiat::czyZajete(int x, int y)
{
	if (!czyWychodziPozaSwiat(x, y)) {
		if (tablicaSwiata[x][y] != NULL)
			return true;
		return false;
	}
	return true;
}

bool Swiat::czyWychodziPozaSwiat(int x, int y)
{
	if (x >= szerokosc || x < 0 || y < 0 || y >= szerokosc)
		return true;
	return false;
}

bool Swiat::czyZwierze(int x, int y)
{
	if (dynamic_cast<Zwierze*>(getZwierzeZTablicy(x, y)) != NULL)
		return true;
	else
		return false;
}
bool Swiat::czyStoiZwierze(int x, int y)
{
	if (!czyWychodziPozaSwiat(x, y)) {
		if (czyZwierze(x, y))
			return true;
		return false;
	}
	return false;
}

bool Swiat::czySymulacjaTrwa()
{
	return czySymulacjatrwa;
}

void Swiat::zabijOba(Organizm* o1, Organizm* o2){
	usunZeSwiata(o1);
	usunZeSwiata(o2);
}

void Swiat::wypiszKolejke(){

	for (int i = 0; i < kolejkaOrganizmow.size(); i++) {
		if (kolejkaOrganizmow[i] != NULL) {
			cout << "Inicjatywa " << kolejkaOrganizmow[i]->getNazwaGatunku() << " wynosi: " << kolejkaOrganizmow[i]->getInicjatywa() << ", wiek: " << kolejkaOrganizmow[i]->getWiek() << ", x: " << kolejkaOrganizmow[i]->getPolozenieX() << ", y: " << kolejkaOrganizmow[i]->getPolozenieY() << endl;
		}
		else
			cout << "zostanie usunieta" << endl;
	}
	cout << endl;
}



void Swiat::usunZeSwiata(Organizm* organizm){
	tablicaSwiata[organizm->getPolozenieX()][organizm->getPolozenieY()] = NULL;
	organizm->~Organizm();
}

void Swiat::WALKA(Organizm* broniacy, Organizm* atakujacy){
	if (atakujacy->getSila() >= broniacy->getSila()) {
		int x = broniacy->getPolozenieX();
		int y = broniacy->getPolozenieY();
		usunZeSwiata(broniacy);
		atakujacy->poruszenieSie(x, y);
	}

	else if (atakujacy->getSila() < broniacy->getSila()) {
		usunZeSwiata(atakujacy);
	}
	
}

void Swiat::ucieczka(Organizm* uciekajacy, Organizm* atakujacy){
	int x = uciekajacy->getPolozenieX();
	int y = uciekajacy->getPolozenieY();
	int nx = x;
	int ny = y;
	int ilos_prob = 0;
	while (uciekajacy->czyStoiZwierze(x, y) && ilos_prob < 50) { //ilos_prob zapobiega nieskonczonemu szukaniu miejsca na urodzenie zwierzecia
		int i = rand() % 4;
		ilos_prob++;
		switch (i) {
		case 0:
			x = uciekajacy->getPolozenieX() + 1;
			y = uciekajacy->getPolozenieY();
			break;
		case 1:
			x = uciekajacy->getPolozenieX() - 1;
			y = uciekajacy->getPolozenieY();
			break;
		case 2:
			x = uciekajacy->getPolozenieX();
			y = uciekajacy->getPolozenieY() + 1;
			break;
		case 3:
			x = uciekajacy->getPolozenieX();
			y = uciekajacy->getPolozenieY() - 1;
			break;
		}
	}
	uciekajacy->poruszenieSie(x, y);
	atakujacy->poruszenieSie(nx, ny);

}

void Swiat::zabijZwierzetaDookola(Organizm* organizm){
	int x = organizm->getPolozenieX();
	int y = organizm->getPolozenieY();
	if (czyStoiZwierze(x + 1, y)) {
		cout << "Barszcz Sosnowskiego rozsiewa trojaca chmure " << endl;
		usunZeSwiata(getZwierzeZTablicy(x + 1, y));
	}
	if (czyStoiZwierze(x - 1, y)) {
		cout << "Barszcz Sosnowskiego rozsiewa trojaca chmure " << endl;
		usunZeSwiata(getZwierzeZTablicy(x - 1, y));
	}
	if (czyStoiZwierze(x, y + 1)) {
		cout << "Barszcz Sosnowskiego rozsiewa trojaca chmure " << endl;
		usunZeSwiata(getZwierzeZTablicy(x, y + 1));
	}
	if (czyStoiZwierze(x, y - 1)) {
		cout << "Barszcz Sosnowskiego rozsiewa trojaca chmure " << endl;
		usunZeSwiata(getZwierzeZTablicy(x, y - 1));
	}
}

void Swiat::wczytajWilka(FILE* plik) {
	int polozenieX;
	int polozenieY;
	int sila;
	int inicjatywa;
	int wiek;
	fscanf(plik, "%i", &polozenieX);
	fscanf(plik, "%i", &polozenieY);
	Wilk* nowy = new Wilk(this, polozenieX, polozenieY);
	fscanf(plik, "%i", &sila);
	nowy->setSila(sila);
	fscanf(plik, "%i", &inicjatywa);
	nowy->setInicjatywa(inicjatywa);
	fscanf(plik, "%i", &wiek);
	nowy->setWiek(wiek);
}
void Swiat::wczytajOwce(FILE* plik) {
	int polozenieX;
	int polozenieY;
	int sila;
	int inicjatywa;
	int wiek;
	fscanf(plik, "%i", &polozenieX);
	fscanf(plik, "%i", &polozenieY);
	Owca* nowy = new Owca(this, polozenieX, polozenieY);
	fscanf(plik, "%i", &sila);
	nowy->setSila(sila);
	fscanf(plik, "%i", &inicjatywa);
	nowy->setInicjatywa(inicjatywa);
	fscanf(plik, "%i", &wiek);
	nowy->setWiek(wiek);
}
void Swiat::wczytajLisa(FILE* plik) {
	int polozenieX;
	int polozenieY;
	int sila;
	int inicjatywa;
	int wiek;
	fscanf(plik, "%i", &polozenieX);
	fscanf(plik, "%i", &polozenieY);
	Lis* nowy = new Lis(this, polozenieX, polozenieY);
	fscanf(plik, "%i", &sila);
	nowy->setSila(sila);
	fscanf(plik, "%i", &inicjatywa);
	nowy->setInicjatywa(inicjatywa);
	fscanf(plik, "%i", &wiek);
	nowy->setWiek(wiek);
}
void Swiat::wczytajAntylope(FILE* plik) {
	int polozenieX;
	int polozenieY;
	int sila;
	int inicjatywa;
	int wiek;
	fscanf(plik, "%i", &polozenieX);
	fscanf(plik, "%i", &polozenieY);
	Antylopa* nowy = new Antylopa(this, polozenieX, polozenieY);
	fscanf(plik, "%i", &sila);
	nowy->setSila(sila);
	fscanf(plik, "%i", &inicjatywa);
	nowy->setInicjatywa(inicjatywa);
	fscanf(plik, "%i", &wiek);
	nowy->setWiek(wiek);
}
void Swiat::wczytajZolwia(FILE* plik) {
	int polozenieX;
	int polozenieY;
	int sila;
	int inicjatywa;
	int wiek;
	fscanf(plik, "%i", &polozenieX);
	fscanf(plik, "%i", &polozenieY);
	Zolw* nowy = new Zolw(this, polozenieX, polozenieY);
	fscanf(plik, "%i", &sila);
	nowy->setSila(sila);
	fscanf(plik, "%i", &inicjatywa);
	nowy->setInicjatywa(inicjatywa);
	fscanf(plik, "%i", &wiek);
	nowy->setWiek(wiek);
}
void Swiat::wczytajCzlowieka(FILE* plik) {
	int polozenieX;
	int polozenieY;
	int sila;
	int inicjatywa;
	int wiek;
	int umiejetnosc;
	int pozostaletury;

	fscanf(plik, "%i", &polozenieX);
	fscanf(plik, "%i", &polozenieY);
	Czlowiek* nowyczlowiek = new Czlowiek(this, polozenieX, polozenieY);
	fscanf(plik, "%i", &sila);
	nowyczlowiek->setSila(sila);
	fscanf(plik, "%i", &inicjatywa);
	nowyczlowiek->setInicjatywa(inicjatywa);
	fscanf(plik, "%i", &wiek);
	nowyczlowiek->setWiek(wiek);
	fscanf(plik, "%i", &umiejetnosc);
	nowyczlowiek->setUmiejetnoscAktywna(umiejetnosc);
	fscanf(plik, "%i", &pozostaletury);
	nowyczlowiek->setPozostaleTury(pozostaletury);
}

void Swiat::wczytajTrawe(FILE* plik){
	int polozenieX;
	int polozenieY;
	int sila;
	int inicjatywa;
	int wiek;
	fscanf(plik, "%i", &polozenieX);
	fscanf(plik, "%i", &polozenieY);
	Trawa* nowy = new Trawa(this, polozenieX, polozenieY);
	fscanf(plik, "%i", &sila);
	nowy->setSila(sila);
	fscanf(plik, "%i", &inicjatywa);
	nowy->setInicjatywa(inicjatywa);
	fscanf(plik, "%i", &wiek);
	nowy->setWiek(wiek);
}

void Swiat::wczytajGuarane(FILE* plik){
	int polozenieX;
	int polozenieY;
	int sila;
	int inicjatywa;
	int wiek;
	fscanf(plik, "%i", &polozenieX);
	fscanf(plik, "%i", &polozenieY);
	Guarana* nowy = new Guarana(this, polozenieX, polozenieY);
	fscanf(plik, "%i", &sila);
	nowy->setSila(sila);
	fscanf(plik, "%i", &inicjatywa);
	nowy->setInicjatywa(inicjatywa);
	fscanf(plik, "%i", &wiek);
	nowy->setWiek(wiek);
}
void Swiat::wczytajJagode(FILE* plik) {
	int polozenieX;
	int polozenieY;
	int sila;
	int inicjatywa;
	int wiek;
	fscanf(plik, "%i", &polozenieX);
	fscanf(plik, "%i", &polozenieY);
	WilczeJagody* nowy = new WilczeJagody(this, polozenieX, polozenieY);
	fscanf(plik, "%i", &sila);
	nowy->setSila(sila);
	fscanf(plik, "%i", &inicjatywa);
	nowy->setInicjatywa(inicjatywa);
	fscanf(plik, "%i", &wiek);
	nowy->setWiek(wiek);
}
void Swiat::wczytajBarszcz(FILE* plik) {
	int polozenieX;
	int polozenieY;
	int sila;
	int inicjatywa;
	int wiek;
	fscanf(plik, "%i", &polozenieX);
	fscanf(plik, "%i", &polozenieY);
	BarszczSosnowskiego* nowy = new BarszczSosnowskiego(this, polozenieX, polozenieY);
	fscanf(plik, "%i", &sila);
	nowy->setSila(sila);
	fscanf(plik, "%i", &inicjatywa);
	nowy->setInicjatywa(inicjatywa);
	fscanf(plik, "%i", &wiek);
	nowy->setWiek(wiek);
}
void Swiat::wczytajMlecz(FILE* plik) {
	int polozenieX;
	int polozenieY;
	int sila;
	int inicjatywa;
	int wiek;
	fscanf(plik, "%i", &polozenieX);
	fscanf(plik, "%i", &polozenieY);
	Mlecz* nowy = new Mlecz(this, polozenieX, polozenieY);
	fscanf(plik, "%i", &sila);
	nowy->setSila(sila);
	fscanf(plik, "%i", &inicjatywa);
	nowy->setInicjatywa(inicjatywa);
	fscanf(plik, "%i", &wiek);
	nowy->setWiek(wiek);
}

void Swiat::zapiszStanGry() {
	ofstream zapis("zapisSwiata.txt");

	zapis<< ilosc_zwierzat<< " " << szerokosc << " " << tura << " ";

	for (int i = 0; i < kolejkaOrganizmow.size(); i++) {
		if (kolejkaOrganizmow[i]->getNazwaGatunku() != 'C') {
			zapis << (int)kolejkaOrganizmow[i]->getNazwaGatunku()<< " " << kolejkaOrganizmow[i]->getPolozenieX() << " " << kolejkaOrganizmow[i]->getPolozenieY() << " " << kolejkaOrganizmow[i]->getSila() << " " << kolejkaOrganizmow[i]->getInicjatywa() << " " << kolejkaOrganizmow[i]->getWiek() << " ";
		}
		else {
			zapis << (int)kolejkaOrganizmow[i]->getNazwaGatunku() << " " << kolejkaOrganizmow[i]->getPolozenieX() << " " << kolejkaOrganizmow[i]->getPolozenieY() << " " << kolejkaOrganizmow[i]->getSila() << " " << kolejkaOrganizmow[i]->getInicjatywa() << " " << kolejkaOrganizmow[i]->getWiek() << " " << umiejetnoscAktywna << " " << pozostaleTury << " ";
		}
	}


	zapis.close();
}

Swiat::~Swiat(){
	zaktualizujKolejke();
	for (int i = 0; i < kolejkaOrganizmow.size(); i++) {
		kolejkaOrganizmow[i]->~Organizm();
	}
}


