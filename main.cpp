#include <iostream>
#include <string>
#include <math.h>
#include "Czolg.h"
#include "Karabin.h"
#include "Granat.h"
#include "Zolnierz.h"

using namespace std;

//Klasy generyczne
template <typename add>
class Dodaj{
public:
    add x, y;

    add dodaj(add x, add y){
        return x + y;
    }
};

template <typename sub>
class Odejmij{
public:
    sub x, y;

    sub odejmij(sub x, sub y){
        return x - y;
    }
};

template <typename mult>
class Pomnoz{
public:
    mult x, y;

    mult pomnoz(mult x, mult y){
        return x*y;
    }
};

template <typename div>
class Podziel{
public:
    div x, y;

    div podziel(div x, div y){
        return x/y;
    }
};

template <typename pow>
class Kwadrat{
public:
    pow x;

    pow doKwadratu(pow x){
        return x*x;
    }
};

template <typename sqrt>
class Pierwiastek{
public:
    sqrt x;

    sqrt podPierwiastek(sqrt x){
        return sqrtf(x);
    }
};

template <typename mod>
class Modulo{
public:
    mod x, y;

    mod modulo(mod x, mod y){
        return x % y;
    }
};
////////////////////////////////////

void skadJestes(Strzelec strzelec);
void sprawdzMoc(Czolg czolg);
void wyscigSamolotow(Samolot samolot);
void lotDronem(DronPasazerski pasazerski);
void wrogNaHoryzoncie(Ciezki_karabin karabin);

void lotnik();
void czolgista();
void strzelec();
void bomba();
void dron();
void generyczne();


int main()
{
    //generyczne();
    //bomba();
    //dron();
    //lotnik();
    strzelec();
    return 0;
}

void skadJestes(Strzelec strzelec){
    cout << endl << strzelec.imie << " pochodzi z " << strzelec.kraj_pochodzenia << endl;
}

void sprawdzMoc(Czolg czolg){
    cout << "Jak myslisz " << czolg.nazwa << " ile ma mocy?" << endl;
    int moc;
    do {
        cin >> moc;
        if (moc > czolg.naped->moc)
            cout << "Nie trafiles! " << czolg.nazwa << " ma mniej mocy" << endl;
        else if (moc < czolg.naped->moc)
            cout << "Nie trafiles! " << czolg.nazwa << " ma wiecej mocy" << endl;
        else {
            cout << "Brawo zgadles!" << endl;
            exit(0);
        }
    }while(moc != czolg.naped->moc);
}

void wyscigSamolotow(Samolot samolot){
    cout << endl << "Sprawdz czy twoj samolot wygralby wyscig z " << samolot.nazwa << endl;
    int vmax;
    cout << "Podaj maksymalna predkosc twojego samolotu: "; cin >> vmax;
    cout << endl;

    if(vmax >= samolot.vmax)
        cout << "Niestety, " << samolot.nazwa << " ma male szanse z Toba..." << endl;
    else if (vmax < samolot.vmax)
        cout << "Twoj samolot jest za wolny dla " << samolot.nazwa << endl;
}

void lotDronem(DronPasazerski pasazerski){
    cout << "Przed wylotem na akcje, sprawdz czy twoja druzyna wejdzie do drona." << endl;
    int ekipa;
    cout << "Podaj ilosc czlonkow twojej druzyny: "; cin >> ekipa;
    cout << endl;
    if(ekipa <= pasazerski.liczba_miejsc)
        cout << "Mozecie leciec nim na akcje" << endl;
    else
        cout << "Poszukajcie wiekszego drona." << endl;
}

void wrogNaHoryzoncie(Ciezki_karabin ciezkiKarabin){
    cout << endl << endl << "Zalozmy, ze na horyzoncie pojawil sie wrog, twoja bron to " << ciezkiKarabin.nazwa << endl;
    cout << "Ta bron posiada swoj okreslony zasieg efektywny." << endl;
    int metry;
    cout << "Sprawdz jak daleko jest twoj wrog, i zobacz czy uda ci sie latwo zneutralizowac cel, podaj odleglosc:" << endl;
    cin >> metry;

    if (metry <= ciezkiKarabin.zasieg_efekt)
        cout << "Cel zneutralizowany." << endl;
    else
        cout << "Moze byc ciezko... poczekaj az podejdzie blizej o " << metry - ciezkiKarabin.zasieg_efekt << " m." << endl;

}

void czolgista(){
    Naped *M305 = new Naped("M 305", 3.46, 57, 144, 37);
    Dzialo *M3 = new Dzialo("M3", 75, 31, 588, 6.32, 1);
    Czolg *PZK1 = new Czolg("Panzerkampfwagen I", "lekki", "Niemcy", 1934, M305, M3,2);

    Czolgista *c1 = new Czolgista("", "", 0, "","","", PZK1);

    c1->pobor();
    c1->wybor_druzyny();
    c1->tanker_id();

    cout << endl << "Czego chcesz sie dowiedziec o swoim czolgu?" << endl;
    char wybor;

    do {
        cout << "a) Ogolne dane techniczne\nb) Specyfikacja dziala\nc) Informacje o napedzie\ne - wyjscie";
        cin >> wybor;
        switch (wybor) {
            case 'a':
                cout << endl << "--------Czolg--------" << endl;
                PZK1->printinfoCzolg();
                cout << "-----------------" << endl;
                break;
            case 'b':
                cout << endl << "--------Dzialo--------" << endl;
                M3->printinfoDzialo();
                cout << "-----------------" << endl;
                break;
            case 'c':
                cout << endl << "--------Naped--------" << endl;
                M305->printinfoSilnik();
                cout << "-----------------" << endl;
                break;
            case 'e':
                break;
        }
    } while (wybor != 'e');

    cout << "Quiz o napedzie" << endl;
    sprawdzMoc(*PZK1);
}

void strzelec() {
    Strzelec *s1 = new Strzelec("", "","Polska", 0, "", " ", nullptr);
    s1->pobor();
    cout << endl;
    skadJestes(*s1);
    s1->wybor_kompanii();
    s1->przydzial_broni();
    s1->shooter_id();
    s1->karabin->shoot();

    wrogNaHoryzoncie(*s1->karabin);
}

void lotnik(){
    auto *F16 = new Samolot("F-16", "bojowy", "odrzutowy", 2124);
    Lotnik *l1 = new Lotnik("", "", 0, "", "", F16);

    l1->pobor();
    l1->wybor_jednostki();
    l1->lotnik_id();

    wyscigSamolotow(*F16);

}

void bomba() {
    Bomba *b1 = new Bomba;
    b1->makeBomb();
    cout << endl << "Bomba " << endl;
    b1->printinfoBomba();
    delete b1;
}

void dron(){
    DronPasazerski dron(2,"Jet 2","zwiadowczy","karbon", 4, 4, 0, 50);
    dron.printInfoPasazerski();
    cout << endl;
    dron.printSmiglo();
    cout << endl;
    lotDronem(dron);
}

void generyczne(){
    cout << "Dodawanie:" << endl;
    Dodaj<int> *dodawanie = new Dodaj<int>;
    cout << dodawanie->dodaj(10, 7) << endl;

    cout << "Odejmowanie:" << endl;
    Odejmij<int> *odejmowanie = new Odejmij<int>;
    cout << odejmowanie->odejmij(9, 6) << endl;

    cout << "Mnozenie:" << endl;
    Pomnoz<int> *mnozenie = new Pomnoz<int>;
    cout << mnozenie->pomnoz(3, 4) << endl;

    cout << "Dzielenie:" << endl;
    Podziel<float> *dzielenie = new Podziel<float>;
    cout << dzielenie->podziel(12, 9) << endl;

    cout << "Podnies do kwadratu:" << endl;
    Kwadrat<int> *podnies = new Kwadrat<int>;
    cout << podnies->doKwadratu(4) << endl;

    cout << "Pierwiastkowanie:" << endl;
    Pierwiastek<float> *pierwiastkowanie = new Pierwiastek<float>;
    cout << pierwiastkowanie->podPierwiastek(9) << endl;

    cout << "Dzialanie modulo:" << endl;
    Modulo<int> *modulo = new Modulo<int>;
    cout << modulo->modulo(27, 14) << endl;
}