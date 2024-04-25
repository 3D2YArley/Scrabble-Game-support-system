#ifndef LETRA_H_
#define LETRA_H_

/* Definición del TAD Scrabble como una clase. */
class Letra {

    private:
        /* Datos mínimos */
        char letter;
        int point;

    public:
        /* Constructores */
        Letra();
        Letra(char c);


        /* getters */
        char getLetter();
        int getPoint();
        /* setters */
        void setLetter(char letter);
        void setPoint(int points);

        /* size() */
        /* empty() */

        /* operator< */
        bool operator<(const Letra &other) const;

};

#endif