#include "Bron.h"
#include <iostream>

using namespace std;

void Bron::reload() {
    naboje = pojemnosc_mag;
    cout << endl << "Bron zostala przeladowana" << endl;
}

void Bron::shoot() {
    naboje = pojemnosc_mag;
    cin.sync();
    cout << endl << "Symulator strzelania" << endl << "s - strzal\nr - przeladowanie\nelse - schowanie broni" << endl;
    char mag[40];
    do {
        gets(mag);
        if (*mag == 's') {
            cout << "Puf! -> " << naboje - 1;
            naboje -= 1;
        } else if (*mag == 'r')
            reload();
        else {
            cout << "*bron zostala schowana*";
            break;
        }
        if (naboje == 0)
            reload();
    } while (*mag);
}
