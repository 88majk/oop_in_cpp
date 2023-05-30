#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include "Zolnierz.h"

using namespace std;

void Zolnierz::pobor() {
    srand(time(NULL));
    soldier_id = rand() % (9000) + 1000;
    cout << "-----------Formularz-------------";
    cout << endl << "Imie:"; cin >> imie;
    cout << "Nazwisko:"; cin >> nazwisko;
    cout << "A oto twoje ID: " << soldier_id;
    stopien = "rekrut";
    cout << endl << "Od teraz jestes w naszych szeregach!";
}

void Zolnierz::show_id() {
    cout << "Zolnierz: " << this->imie << " " << this->nazwisko << endl;
    cout << "Stopien: " << this->stopien << endl;
    cout << "ID: " << this->soldier_id << endl;
}

void Strzelec::przydzial_broni() {
    auto *AK47 = new Ciezki_karabin("szturmowy", "AK-47", "Arabia Saudyjska", 450, 300, 30);
    auto *AWP = new Ciezki_karabin("snajperski", "AWP", "USA", 8, 1000, 10);
    auto *M249 = new Ciezki_karabin("ciezki", "M249", "Argentyna", 300, 800, 60);

    cout << "Wybierz bron: \na) " << AK47->nazwa << endl;
    cout << "b) " << AWP->nazwa << endl;
    cout << "c) " << M249->nazwa << endl;

    char wybor;
    cin >> wybor;
    switch (wybor) {
        case 'a':
            karabin = AK47;
            AK47->printinfoSzturmowy();
            break;
        case 'b':
            karabin = AWP;
            AWP->printinfoSnajperski();
            break;
        case 'c':
            karabin = M249;
            M249->printinfoCiezki();
            break;
        default:
            cout << "Zly wybor";
            break;
    }
}

void Strzelec::wybor_kompanii() {
    cout << "Wpisz kompanie do ktorej chcesz nalezec: ";
    cin.sync();
    getline(cin,kompania);
    cout << endl;
}

void Strzelec::shooter_id() {
    Zolnierz::show_id();
    cout << "Kompania: " << kompania << endl;
    cout << "Posiadana bron: " << karabin->nazwa << endl;
}

void Czolgista::tanker_id() {
    Zolnierz::show_id();
    cout << "Druzyna: " << druzyna << endl;
    cout << "Czolg druzyny: " << czolg->nazwa << endl;
    cout << "Specjalizacja: " << pozycja << endl;
}

void Czolgista::wybor_druzyny() {
    cout << endl << "Wpisz druzyne do ktorej chcesz nalezec: ";
    cin.sync();
    getline(cin,druzyna);
    cout << endl << "Wybierz swoja specjalizacje: " << endl;
    cout << "a) kierowca" << endl << "b) strzelec" << endl << "c) obsluga dziala" << endl;
    char wybor;
    cin >> wybor;
    switch (wybor) {
        case 'a':
            pozycja = "kierowca";
            break;
        case 'b':
            pozycja = "strzelec";
            break;
        case 'c':
            pozycja = "obsluga dziala";
            break;
        default:
            cout << "Blad wyboru." << endl;
            break;
    }
}

void Lotnik::wybor_jednostki() {
    cout << endl << endl << "Wpisz jednostke do ktorej chcesz nalezec: ";
    cin.sync();
    getline(cin, jednostka);
}

void Lotnik::lotnik_id() {
    Zolnierz::show_id();
    cout << "Jednostka: " << jednostka << endl;
    cout << "-------Samolot-------" << endl;
    cout << "nazwa: " << samolot->nazwa << endl;
    cout << "przeznaczenie: " << samolot->typ << endl;
    cout << "silnik: " << samolot->silnik << endl;
    cout << "---------------------" << endl;
}

void Saper::saper_id(){
    Zolnierz::show_id();
    cout << "Druzyna: " << druzyna << endl;
}