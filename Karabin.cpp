#include <iostream>
#include "Karabin.h"

using namespace std;

void Karabin_szturmowy::printinfoSzturmowy() {
    cout << "--------------------------" << endl;
    cout << "Rodzaj karabinu: " << rodzaj << endl;
    cout << "Nazwa: " << nazwa << endl;
    cout << "Kraj pochodzenia: " << kraj_pochodzenia << endl;
    cout << "--------------------------" << endl;
}

void Karabin_snajperski::printinfoSnajperski() {
    cout << "--------------------------" << endl;
    cout << "Rodzaj karabinu: " << rodzaj << endl;
    cout << "Nazwa: " << nazwa << endl;
    cout << "Kraj pochodzenia: " << kraj_pochodzenia << endl;
    cout << "Max przyblizenie lunety: " << przyblizenie << "x" << endl;
    cout << "--------------------------" << endl;
}

void Ciezki_karabin::printinfoCiezki() {
    cout << "--------------------------" << endl;
    cout << "Rodzaj karabinu: " << rodzaj << endl;
    cout << "Nazwa: " << nazwa << endl;
    cout << "Kraj pochodzenia: " << kraj_pochodzenia << endl;
    cout << "--------------------------" << endl;
}