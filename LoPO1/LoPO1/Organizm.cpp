#pragma once
#include "Organizm.h"
#include "Swiat.h"


class Swiat;

Organizm::Organizm(){
	this->inicjatywa = 0;
	this->sila = 0;
	this->wiek = 1;
}

Organizm::Organizm(Swiat* swiat) {
	this->swiat = swiat;
	this->polozenieX = rand() % getSzerokoscSwiata();
	this->polozenieY = rand() % getSzerokoscSwiata();
	while (czyStoiZwierze(polozenieX, polozenieY)) {
		this->polozenieX = rand() % getSzerokoscSwiata();
		this->polozenieY = rand() % getSzerokoscSwiata();
	}
	this->wiek = 1;
	swiat->wstawDoTablicy(this);
}

Organizm::Organizm(Swiat* swiat, int polozenieX, int polozenieY){
	this->swiat = swiat;
	this->polozenieX = polozenieX;
	this->polozenieY = polozenieY;
	this->wiek = 0;
	swiat->wstawDoTablicy(this);
}

char Organizm::rysowanie(){
	return getNazwaGatunku();
}

int Organizm::getSila() const{
	return this->sila;
}
int Organizm::getInicjatywa() const {
	return this->inicjatywa;
}
int Organizm::getWiek() const {
	return this->wiek;
}
int Organizm::getPolozenieX() const {
	return this->polozenieX;
}
int Organizm::getPolozenieY() const {
	return this->polozenieY;
}
char Organizm::getNazwaGatunku() const {
	return this->nazwaGatunku;
}

Swiat* Organizm::getSwiat() const{
	return this->swiat;
}


int Organizm::getSzerokoscSwiata() const {
	return this->swiat->getSzerokosc();
}

void Organizm::setUmiejetnosc(int i){
	swiat->setUmiejetnoscAktywna(i);
}

void Organizm::setPozostaleTurySwiata(int i){
	swiat->setpozostaleTury(i);
}


void Organizm::setSila(int sila) {
	this->sila = sila;
}

void Organizm::setInicjatywa(int inicjatywa){
	this->inicjatywa = inicjatywa;
}

void Organizm::setWiek(int wiek){
	this->wiek = wiek;
}
void Organizm::setPolozenieX(int polozenieX){
	this->polozenieX = polozenieX;
}
void Organizm::setPolozenieY(int polozenieY) {
	this->polozenieY = polozenieY;
}

void Organizm::setNazwaGatunku(char nazwaGatunku){
	this->nazwaGatunku = nazwaGatunku;
}

void Organizm::setSwiat(Swiat* swiat){
	this->swiat = swiat;
}

void Organizm::zakonczSymulacje(){
	swiat->setCzySymulacjaTrwa(false);
}

void Organizm::dodajDoKolejki(Organizm* organizm){
	this->swiat->dodajDoKolejki(organizm);
}

void Organizm::wypiszSwiat(){
	swiat->rysujSwiat();
}


bool Organizm::czyWychodziPozaTablice(int x, int y)
{
	return swiat->czyWychodziPozaSwiat(x, y);
}

bool Organizm::czyStoiZwierze(int x, int y)
{
	return swiat->czyZajete(x, y);
}

void Organizm::poruszenieSie(int x, int y){
	swiat->getTablicaSwiata()[x][y] = swiat->getTablicaSwiata()[polozenieX][polozenieY];
	swiat->getTablicaSwiata()[polozenieX][polozenieY] = NULL;
	this->setPolozenieX(x);
	this->setPolozenieY(y);
}

Organizm* Organizm::naCoWszedl(int x, int y)
{
	return swiat->getZwierzeZTablicy(x, y);
}

void Organizm::zabijZwierzetaDookola(){
	swiat->zabijZwierzetaDookola(this);
}

void Organizm::zabijObydwa(Organizm* organizm){
	swiat->zabijOba(this, organizm);
}


void Organizm::wojna(Organizm* atakujacy){
	swiat->WALKA(this, atakujacy);
}

void Organizm::ucieczka(Organizm* organizm){
	swiat->ucieczka(this, organizm);
}


Organizm::~Organizm(){
	swiat->usunZKolejki(this);
}


