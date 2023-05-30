#include <iostream>
#include "Bron.h"
#include "Karabin.h"
#include "Czolg.h"
#include "Samolot.h"
#include "Granat.h"

using namespace std;

#ifndef PROJEKTPO_ZOLNIERZ_H
#define PROJEKTPO_ZOLNIERZ_H

class Czlowiek {
public:
    virtual void pobor() = 0;
    virtual void show_id() = 0;
};

class Zolnierz : public Czlowiek{
public:
    Zolnierz(string imie = "---", string nazwisko = "---", string kraj_pochodzenia = "unknown", int soldier_id = 0000, string stopien = "rekrut"){
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->kraj_pochodzenia = kraj_pochodzenia;
        this->soldier_id = soldier_id;
        this->stopien = stopien;
    }
    ~Zolnierz(){
        cout << endl << "Brak podanego zolnierza w oddziale." << endl;
    }
    virtual void pobor();
    virtual void show_id();

protected:
    string imie;
    string stopien;
    string kraj_pochodzenia;
    string nazwisko;
    int soldier_id;
};

class Strzelec :public Zolnierz {
public:
    Strzelec(string imie, string nazwisko, string kraj_pochodzenia, int soldier_id, string stopien, string kompania, Ciezki_karabin *karabin){
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->kraj_pochodzenia = kraj_pochodzenia;
        this->soldier_id = soldier_id;
        this->stopien = stopien;
        this->kompania = kompania;
        this->karabin = karabin;
    }
    ~Strzelec(){
        cout << endl << "Brak podanego strzelca w kompanii." << endl;
    }
    Ciezki_karabin *karabin;

    friend void skadJestes(Strzelec strzelec);
    void shooter_id();
    void przydzial_broni();
    void wybor_kompanii();

protected:
    string kompania;

};

class Czolgista :public Zolnierz {
public:
    Czolgista(string imie, string nazwisko, int soldier_id, string stopien, string druzyna, string pozycja, Czolg *czolg){
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->soldier_id = soldier_id;
        this->stopien = stopien;
        this->druzyna = druzyna;
        this->pozycja = pozycja;
        this->czolg = czolg;
    }
    ~Czolgista(){
        cout << endl << "Brak podanego czolgisty w druzynie." << endl;
    }
    Czolg *czolg;

    void tanker_id();
    void wybor_druzyny();
protected:
    string druzyna;
    string pozycja;
};

class Lotnik :public Zolnierz {
public:
    Lotnik(string imie, string nazwisko, int soldier_id, string stopien, string jednostka, Samolot *samolot){
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->soldier_id = soldier_id;
        this->stopien = stopien;
        this->jednostka = jednostka;
        this->samolot = samolot;
    }
    ~Lotnik(){
        cout << endl << "Brak podanego lotnika w jednostce." << endl;
    }
    Samolot *samolot;
    DronPasazerski *dron;
    void lotnik_id();
    void wybor_jednostki();

protected:
    string jednostka;

};

class Saper :public Zolnierz{
public:
    Saper(string imie, string nazwisko, int soldier_id, string stopien, string druzyna, Bomba *bomba){
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->soldier_id = soldier_id;
        this->stopien = stopien;
        this->druzyna = druzyna;
        this->bomba = bomba;
    }
    ~Saper(){
        cout << endl << "Brak podanego sapera w druzynie." << endl;
    }
    Bomba *bomba;

    void saper_id();
protected:
    string druzyna;
};
#endif