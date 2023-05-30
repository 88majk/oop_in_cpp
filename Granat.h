#include <iostream>

using namespace std;

#ifndef PROJEKTPO_GRANAT_H
#define PROJEKTPO_GRANAT_H

class Wybuch{
public:
    virtual void printinfoBomba() = 0;
    virtual void makeBomb() = 0;
};

class MaterialWybuchowy :public Wybuch{
protected:
    string material_wybuch;
};

class Bomba :public MaterialWybuchowy{
protected:
    string rodzaj;
    int masa;

public:
    friend class Saper;
    virtual void printinfoBomba();
    virtual void makeBomb();
};

#endif