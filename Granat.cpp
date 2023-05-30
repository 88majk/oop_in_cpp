#include <iostream>
#include "Granat.h"

using namespace std;


void Bomba::printinfoBomba() {
    cout << "Rodzaj: " << rodzaj << endl;
    if(rodzaj == "atomowa") {
        cout << "Pierwiastek uzyty do produkcji: " << material_wybuch << endl;
        cout << "Masa bomby: " << masa << " kg" << endl;
    }
    else if(rodzaj == "kasetowa") {
        cout << "Rodzaj subamunicji: " << material_wybuch << endl;
        cout << "Ilosc ladunkow: " << masa << endl;
    }
    else {
        cout << "Material wybuchowy: " << material_wybuch << endl;
        cout << "Masa bomby: " << masa << " kg" << endl;
    }
}

void Bomba::makeBomb() {
    cout << "Program do tworzenia bomby" << endl;
    cout << "Wybierz rodzaj bomby: " << endl << "a) burzaca" << endl << "b) atomowa" << endl <<"c) kasetowa" << endl;
    char wybor, ladunek;
    cin >> wybor;
    switch (wybor) {
        case 'a':
            rodzaj = "burzaca";
            cout << "Jakiego materialu chcesz uzyc: " << "\na) Tritonal\nb) TNT\nc) COMP B" << endl;
            cin >> ladunek;
            if(ladunek == 'a')
                material_wybuch = "Tritonal";
            else if(ladunek == 'b')
                material_wybuch = "TNT";
            else if(ladunek == 'c')
                material_wybuch = "COMP B";
            else
                cout << "Bledny wybor";
            cout << "Podaj mase bomby (w kg): ";
            cin >> masa;
            break;
        case 'b':
            rodzaj = "atomowa";
            cout << "Z czego chcesz stworzyc bombe: " << endl << "a) wodor\nb) uran\nc) pluton" << endl;
            cin >> ladunek;
            if(ladunek == 'a')
                material_wybuch = "wodor";
            else if(ladunek == 'b')
                material_wybuch = "uran";
            else if(ladunek == 'c')
                material_wybuch = "pluton";
            else
                cout << "Bledny wybor";
            cout << "Podaj mase bomby (w kg): ";
            cin >> masa;
            break;
        case 'c':
            rodzaj = "kasetowa";
            cout << "Wybierz rodzaj subamunicji: " << endl << "a) odlamkowa\nb) przeciwpancerna\nc) chemiczna" << endl;
            cin >> ladunek;
            if(ladunek == 'a')
                material_wybuch = "odlamkowa";
            else if(ladunek == 'b')
                material_wybuch = "przeciwpancerna";
            else if(ladunek == 'c')
                material_wybuch = "chemiczna";
            else
                cout << "Bledny wybor";
            cout << "Podaj ilosc ladunkow: ";
            cin >> masa;
            break;
    }
}