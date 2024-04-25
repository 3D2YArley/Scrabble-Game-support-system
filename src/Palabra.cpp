#include "Palabra.h"

/* Creadores de instancias de Palabra */
Palabra::Palabra(){ }

Palabra::Palabra(string word){
    this->word = word;
    this->points = 0;
    this->length = word.length();
}
/* Obtenedores de atributos */
string Palabra::getWord(){
    return word;
}
int Palabra::getPoints(){
    return points;
}
int Palabra::getLength(){
    return length;
}
/* Fijadores del valor de atributos*/
void Palabra::setWord(string word){
    word = word;
}
void Palabra::setPoints(int points){
    points = points;
}
void Palabra::setLength(int length){
    length = length;
}

/* Ordenador de elementos de TAD Palabra*/
bool Palabra::operator<(const Palabra& other) const {
    return word < other.word;
}

