#include "Czolg.h"
#include <iostream>

using namespace std;

void Naped::printinfoSilnik() {
    cout << nazwa << endl;
    cout << "Pojemnosc silnika: " << pojemnosc_silnika << " l." << endl;
    cout << "Moc silnika: " << moc << " KM" << endl;
    cout << "Pojemnosc zbiornika paliwa: " << pojemnosc_zbiornika << " l." << endl;
    cout << "Predkosc maksymalna czolgu: " << vmax << " km/h" << endl;
}
void Naped::zwiekszMoc() {
    cout << "O ile chcesz zwiekszyc moc?";
    int km;
    cin >> km;
    moc += km;
}

void Dzialo::printinfoDzialo() {
    cout << nazwa << endl;
    cout << "Kaliber: " << kaliber << " mm" << endl;
    cout << "Dlugosc lufy: " << dlugosc_lufy << " kalibrow" << endl;
    cout << "Predkosc wylotowa: " << predkosc_wylotowa << " m/s" << endl;
    cout << "Masa naboju: " << masa_naboju << " kg" << endl;
}

void Dzialo::zwiekszMaseNaboju() {
    cout << "O ile chcesz zwiekszyc moc?";
    float km;
    cin >> km;
    masa_naboju += km;
}

void Czolg::printinfoCzolg() {
    cout << nazwa << endl;
    cout << "Rodzaj: " << rodzaj << endl;
    cout << "Rok produkcji: " << data_produkcji << endl;
    cout << "Naped: " << naped->nazwa << endl;
    cout << "Dzialo: " << dzialo->nazwa << endl;

}
