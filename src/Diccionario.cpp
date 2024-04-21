#include "Diccionario.h"

list<Palabra> Diccionario::getListaPalabras(){
    return palabras;
}

void Diccionario::setListaPalabras(list<Palabra> works){
    palabras = works;
}

void Diccionario::add_palabra(Palabra work){
    palabras.push_back(work);
}

// Función que busca una palabra en una lista utilizando punteros
Palabra* Diccionario::search_word(const string& word) {
    for (Palabra& palabra : palabras) {
        if (palabra.getPalabra() == word) {
            return &palabra; // Devuelve el puntero a la palabra si la encuentra
        }
    }
    return nullptr; // Devuelve nullptr si la palabra no está en la lista
}

/* Busca la posicion de la palabra en la lista de palbras del diccionario, si no se encuentra retorna un apuntador al final de la lista */
/*
list<Palabra>::iterator Diccionario::search_word(const string &word) {
    for (auto it = palabras.begin(); it != palabras.end(); ++it) {
        if (it->getPalabra() == word) {
            return it;
        }
    }
    return palabras.end();
}*/

bool Diccionario::palabras_is_empty(){
    return palabras.empty();
}