#ifndef LETRA_H_
#define LETRA_H_

class Letra {
    private:
        char letra;
        int puntos;

    public:
        Letra();
        Letra(char c);

        bool operator<(const Letra &otra) const;
        char getLetra();
        void setLetra(char letter);
        int getPuntos();
        void setPuntos(int points);

};

#endif