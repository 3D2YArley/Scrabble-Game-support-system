#include "Letra.h"

/* Creadores de instancias de Letra */
Letra::Letra(){}

Letra::Letra(char c){
    this->letra = c;
    this->puntos = 0;
}
/* Obtenedores de atributos */
char Letra::getLetra(){
    return letra;
}
int Letra::getPuntos(){
    return puntos;
}

/* Fijadores del valor de atributos*/
void Letra::setLetra(char letter){
    letra = letter;
}
void Letra::setPuntos(int points){
    puntos = points;
}

/* Ordenador de elementos de TAD Letra*/
bool Letra::operator<(const Letra& otra) const {
    return letra < otra.letra;
}