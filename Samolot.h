#include <iostream>
using namespace std;

#ifndef PROJEKTPO_SAMOLOT_H
#define PROJEKTPO_SAMOLOT_H

class Samolot{
    string nazwa;
    string typ;
    string silnik;
    int vmax;

public:
    friend class Lotnik;
    friend void wyscigSamolotow(Samolot samolot);

    Samolot(string nazwa, string typ, string silnik, int vmax){
        this->nazwa = nazwa;
        this->typ = typ;
        this->silnik = silnik;
        this->vmax = vmax;
    }

};

class Material {
public:
    virtual void printInfoSmiglo() = 0;
    virtual void printInfoSilnik() = 0;
    virtual void printInfoDron() = 0;
    virtual void printSmiglo() = 0;
    virtual void printInfoPasazerski() = 0;
};

class Smiglo :public Material{
protected:
    string material;
    int skrzydla;

public:
    Smiglo(string material, int skrzydla){
        this->material = material;
        this->skrzydla = skrzydla;
    }
    virtual void printSmiglo();
    virtual void printInfoSmiglo();
};

class Silnik :public Smiglo{
protected:
    int smigla;
    float pojemnosc;
    int moc;

public:
    Silnik(string material, int skrzydla, int smigla, float pojemnosc, int moc): Smiglo(material, skrzydla){
        this->smigla = smigla;
        this->pojemnosc = pojemnosc;
        this->moc = moc;
    }
    virtual void printInfoSilnik();
};

class Dron :public Silnik{
protected:
    string nazwa;
    string zastosowanie;

public:
    Dron(string nazwa, string zastosowanie, string material, int skrzydla, int smigla, float pojemnosc, int moc)
     :Silnik(material, skrzydla, smigla,pojemnosc,moc){
        this->nazwa = nazwa;
        this->zastosowanie = zastosowanie;
    }
    virtual void printInfoDron();
};

class  DronPasazerski :public Dron{
protected:
    int liczba_miejsc;
public:
    friend void lotDronem(DronPasazerski pasazerski);
    friend class Lotnik;
    DronPasazerski(int liczba_miejsc, string nazwa, string zastosowanie, string material, int skrzydla, int smigla, float pojemnosc, int moc)
    : Dron(nazwa, zastosowanie, material, skrzydla, smigla,pojemnosc,moc){
        this->liczba_miejsc = liczba_miejsc;
    }
    virtual void printInfoPasazerski();
};


#endif //PROJEKTPO_SAMOLOT_H