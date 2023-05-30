#include <iostream>

using namespace std;

#ifndef PROJEKTPO_BRON_H
#define PROJEKTPO_BRON_H

class Proch{
public:
    virtual void reload() = 0;
    virtual void shoot() = 0;
    virtual void printinfoSzturmowy() = 0;
    virtual void printinfoSnajperski() = 0;
    virtual void printinfoCiezki() = 0;
};

class Naboj :public Proch{
protected:
    int naboje;
};

class Bron :public Naboj {
protected:
    string typ;
    int pojemnosc_mag;

public:
    virtual void reload();
    virtual void shoot();
};

class Karabin :public Bron {
public:
    friend class Strzelec;

    Karabin(string rodzaj = "unkown", string nazwa = "unknown", string kraj_pochodzenia = "unknown"){
        this->rodzaj = rodzaj;
        this->nazwa = nazwa;
        this->kraj_pochodzenia = kraj_pochodzenia;
    }

protected:
    string rodzaj;
    string nazwa;
    string kraj_pochodzenia;
    int zasieg_efekt;
};

class Pistolet :public Bron {
    string nazwa;
    string kraj_pochodzenia;
    int zasieg_efekt;

public:
    Pistolet(string nazwa, string kraj_pochodzenia, int zasieg_efekt, int pojemnosc_mag){
        this->nazwa = nazwa;
        this->kraj_pochodzenia = kraj_pochodzenia;
        this->zasieg_efekt = zasieg_efekt;
        this->pojemnosc_mag = pojemnosc_mag;
    }
    ~Pistolet(){
        cout << "Nie ma danego pistoletu w schowku";
    }
};

#endif