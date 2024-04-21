#include "Letra.h"

Letra::Letra(){}

char Letra::getLetra(){
    return letra;
}

void Letra::setLetra(char letter){
    letra = letter;
}

int Letra::getPuntos(){
    return puntos;
}

void Letra::setPuntos(int points){
    puntos = points;
}


bool Letra::operator<(const Letra& otra) const {
    return letra < otra.letra;
}