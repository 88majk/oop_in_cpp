#include <iostream>
#include "Bron.h"

using namespace std;

#ifndef PROJEKTPO_KARABIN_H
#define PROJEKTPO_KARABIN_H

class Karabin_szturmowy :public Karabin {
public:
    friend class Strzelec;

    Karabin_szturmowy(string rodzaj, string nazwa, string kraj_pochodzenia, int zasieg_efekt = 0, int pojemnosc_mag = 0) {
        this->rodzaj = rodzaj;
        this->nazwa = nazwa;
        this->kraj_pochodzenia = kraj_pochodzenia;
        this->zasieg_efekt = zasieg_efekt;
        this->pojemnosc_mag = pojemnosc_mag;
    }
    ~Karabin_szturmowy(){
        cout << "Nie ma danego karabinu w schowku." << endl;
    }
    virtual void printinfoSzturmowy();

protected:

};


class Karabin_snajperski :public Karabin_szturmowy {
public:
    friend class Strzelec;

    Karabin_snajperski(string rodzaj, string nazwa, string kraj_pochodzenia, int przyblizenie, int zasieg_efekt = 0, int pojemnosc_mag = 0)
    : Karabin_szturmowy(rodzaj, nazwa, kraj_pochodzenia, zasieg_efekt, pojemnosc_mag){
        this->przyblizenie = przyblizenie;
    }
    ~Karabin_snajperski(){
        cout << "Nie ma danego karabinu w schowku." << endl;
    }
    virtual void printinfoSnajperski();

protected:
    int przyblizenie;
};

class Ciezki_karabin :public Karabin_snajperski {
public:
    friend class Strzelec;
    friend void wrogNaHoryzoncie(Ciezki_karabin karabin);

    Ciezki_karabin(string rodzaj, string nazwa, string kraj_pochodzenia, int przyblizenie, int zasieg_efekt = 0, int pojemnosc_mag = 0, int szybkostrzelnosc = 0)
    : Karabin_snajperski(rodzaj, nazwa, kraj_pochodzenia, przyblizenie, zasieg_efekt, pojemnosc_mag){
        this->szybkostrzelnosc = szybkostrzelnosc;
    }
    ~Ciezki_karabin(){
        cout << "Nie ma danego karabinu w schowku." << endl;
    }

    virtual void printinfoCiezki();

protected:
    int szybkostrzelnosc;
};

#endif