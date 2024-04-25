#ifndef PALABRA_H_
#define PALABRA_H_

#include <iostream>
#include <string>

using namespace std;

/* Definición del TAD Palabra como una clase. */
class Palabra {
    private:
        /* Datos mínimos */
        string word;
        int points;
        int length;

    public:
        /* Constructores */
        Palabra();
        Palabra(string word);

        /* getters */
        string getWord();
        int getPoints();
        int getLength();
        /* setters */
        void setWord(string word);
        void setPoints(int points);
        void setLength(int length);

        /* operator< */
        bool operator<(const Palabra& other) const;
};

#endif