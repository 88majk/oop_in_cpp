#include <iostream>
#include "Samolot.h"

using namespace std;

void Smiglo::printInfoSmiglo() {
    cout << endl << "To smiglo jest zrobione z " << material << " i sklada sie z " << skrzydla << " skrzydel." << endl;
}

void Smiglo::printSmiglo() {
    cout << "Szkic smigla: " << endl;
    cout << "\t|" << endl;
    cout << "\t|" << endl;
    cout << "  ------+------" << endl;
    cout << "\t|" << endl;
    cout << "\t|" << endl;
}

void Silnik::printInfoSilnik() {

    if(pojemnosc != 0) {
        cout << endl << "W tym silniku smiglo jest zrobione z " << material << " i sklada sie z " << skrzydla << " skrzydel." << endl;
        cout << "W silniku znajduja sie " << smigla << " smigla. Pojemnosc tego silnika wynosi "
             << pojemnosc << " l., a moc jest rowna " << moc << " KM." << endl;
    }else{
        cout << endl << "W tym silniku smiglo jest zrobione z " << material << " i sklada sie z " << skrzydla << " skrzydel." << endl;
        cout << "W silniku znajduja sie " << smigla << " smigla. Jest to silnik elektryczny, o mocy rownej " << moc << " KM." << endl;
    }
}

void Dron::printInfoDron() {
    if(pojemnosc != 0) {
        cout << endl << "Dron " << nazwa << " to dron o zastosowaniu " << zastosowanie << ".";
        cout << endl << "W jego silniku smiglo jest zrobione z " << material << " i sklada sie z " << skrzydla
             << " skrzydel." << endl;
        cout << "W silniku znajduja sie " << smigla << " smigla. Pojemnosc tego silnika wynosi "
             << pojemnosc << " l., a moc jest rowna " << moc << " KM." << endl;
    }else{
        cout << endl << "Dron " << nazwa << " to dron o zastosowaniu " << zastosowanie << ".";
        cout << endl << "W jego silniku smiglo jest zrobione z " << material << " i sklada sie z " << skrzydla
             << " skrzydel." << endl;
        cout << "W silniku znajduja sie " << smigla << " smigla. Dron ten posiada silnik elektryczny, ktorego moc jest rowna " << moc << " KM." << endl;
    }
}

void DronPasazerski::printInfoPasazerski() {
    if(pojemnosc != 0) {
        cout << endl << "Dron " << nazwa << " to dron pasazerski z iloscia miejsc rowna " << liczba_miejsc << ", o zastosowaniu " << zastosowanie << ".";
        cout << endl << "W jego silniku smiglo jest zrobione z " << material << " i sklada sie z " << skrzydla
             << " skrzydel." << endl;
        cout << "W silniku znajduja sie " << smigla << " smigla. Pojemnosc tego silnika wynosi "
             << pojemnosc << " l., a moc jest rowna " << moc << " KM." << endl;
    }else{
        cout << endl << "Dron " << nazwa << " to dron pasazerski z iloscia miejsc rowna " << liczba_miejsc << ", o zastosowaniu " << zastosowanie << ".";
        cout << endl << "W jego silniku smiglo jest zrobione z " << material << " i sklada sie z " << skrzydla
             << " skrzydel." << endl;
        cout << "W silniku znajduja sie " << smigla << " smigla. Dron ten posiada silnik elektryczny, ktorego moc jest rowna " << moc << " KM." << endl;
    }
}