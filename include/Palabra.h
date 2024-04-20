#ifndef PALABRA_H_
#define PALABRA_H_

#include <iostream>
#include <string>

using namespace std;

class Palabra {
    private:
        string palabra;
        int puntos;

    public:
        string getPalabra();
        bool operator<(const Palabra& otra) const;
};

#endif