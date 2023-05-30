#include <iostream>

using namespace std;

#ifndef PROJEKTPO_CZOLG_H
#define PROJEKTPO_CZOLG_H

class Czolg;

class Naped {
    friend class Czolg;
    string nazwa;
    float pojemnosc_silnika;
    int moc;
    int pojemnosc_zbiornika;
    int vmax;
public:
    Naped(string nazwa, float pojemnosc_silnika, int moc, int pojemnosc_zbiornika, int vmax) {
        this->nazwa = nazwa;
        this->pojemnosc_silnika = pojemnosc_silnika;
        this->moc = moc;
        this->pojemnosc_zbiornika = pojemnosc_zbiornika;
        this->vmax = vmax;
    }
    ~Naped(){
        cout << "Brak danego napedu w warsztacie";
    }
    void printinfoSilnik();
    void zwiekszMoc();
    friend void sprawdzMoc(Czolg czolg);
};

class Dzialo {
    friend class Czolg;
    string nazwa;
    float kaliber;
    int dlugosc_lufy;
    int predkosc_wylotowa;
    int pojemnosc;
    float masa_naboju;
public:
    Dzialo(string nazwa, float kaliber, int dlugosc_lufy, int predkosc_wylotowa, float masa_naboju, int pojemnosc) {
        this->nazwa = nazwa;
        this->kaliber = kaliber;
        this->dlugosc_lufy = dlugosc_lufy;
        this->predkosc_wylotowa = predkosc_wylotowa;
        this->masa_naboju = masa_naboju;
        this->pojemnosc = pojemnosc;
    }
    ~Dzialo(){
        cout << "Brak danego dziala w warsztacie";
    }
    void printinfoDzialo();
    void zwiekszMaseNaboju();
};

class Czolg {
    friend class Czolgista;
    string rodzaj;
    string nazwa;
    string kraj_pochodzenia;
    int data_produkcji;
    Naped *naped;
    Dzialo *dzialo;
    int zaloga;
public:
    Czolg(string nazwa, string rodzaj, string kraj_pochodzenia, int data_produkcji, Naped *naped, Dzialo *dzialo, int zaloga){
        this->nazwa = nazwa;
        this->rodzaj = rodzaj;
        this->kraj_pochodzenia = kraj_pochodzenia;
        this->data_produkcji = data_produkcji;
        this->naped = naped;
        this->zaloga = zaloga;
        this->dzialo = dzialo;
    }
    ~Czolg(){
        cout << "Brak danego czolgu w garazu";
    }
    void printinfoCzolg();
    friend void sprawdzMoc(Czolg czolg);
};

#endif