#ifndef LETRA_H_
#define LETRA_H_

class Letra {
    private:
        char letra;
        int puntos;

    public:
        /* Constructores */
        Letra();
        Letra(char c);


        /* getters */
        char getLetra();
        int getPuntos();
        /* setters */
        void setLetra(char letter);
        void setPuntos(int points);

        /* size() */
        /* empty() */

        /* operator< */
        bool operator<(const Letra &otra) const;
};

#endif