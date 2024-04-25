#ifndef PALABRA_H_
#define PALABRA_H_

#include <iostream>
#include <string>

using namespace std;

class Palabra {
    private:
        string palabra;
        int puntos;
        int longitud;

    public:
        Palabra();
        Palabra(string word);

        string getPalabra();
        void setPalabra(string word);

        int getPoints();
        void setPoints(int point);

        int getLength();
        void setLength(int length);
        
        bool operator<(const Palabra& other) const;
};

#endif