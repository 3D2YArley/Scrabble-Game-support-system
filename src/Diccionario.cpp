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

bool Diccionario::palabras_is_empty(){
    return palabras.empty();
}