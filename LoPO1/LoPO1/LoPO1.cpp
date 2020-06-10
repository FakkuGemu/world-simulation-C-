#include <iostream>
#include "Swiat.h"

int main(){
    char opcja = '0';
    srand(time(NULL));
    cout << "1. Zacznij nowa gre." << endl;
    cout << "2. Wczytaj zapisana gre." << endl;
    opcja = _getch();
    system("cls");
    if (opcja == '2') {
        Swiat* swiat = new Swiat();
        swiat->wczytajSwiat();
        while (swiat->czySymulacjaTrwa()) {
            swiat->wykonajTure();
        }
        cout << "A TERAZ WSZYSTKO UMRZE!!!" << endl;
        swiat->~Swiat();
    }
    else {
    int szerokosc;
    cout << "Podaj rozmiar swiata (zatwierdz enterem): ";
    cin >> szerokosc;
    system("cls");

    Swiat* swiat = new Swiat(szerokosc);
        while (swiat->czySymulacjaTrwa()) {
            swiat->wykonajTure();
        }
        cout << "A TERAZ WSZYSTKO UMRZE!!!" << endl;
        swiat->~Swiat();
    }

    
}

