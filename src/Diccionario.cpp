#include "Diccionario.h"

/* Creadores de instancias de Diccionario */
Diccionario::Diccionario(){
    this->list_words = list<Palabra>();
}
/* Obtenedores de atributos */
list<Palabra> Diccionario::getListWords(){
    return list_words;
}
/* Fijadores del valor de atributos*/
void Diccionario::setListWords(list<Palabra> works){
    list_words = works;
}
/* Agregar una palabra a la lista de palabras */
void Diccionario::addWord(Palabra work){
    list_words.push_back(work);
}
/* Función que busca una palabra en una lista utilizando punteros */
Palabra* Diccionario::searchWord(const string& word) {
    for (Palabra& palabra : list_words) {
        if (palabra.getWord() == word) {
            return &palabra; // Devuelve el puntero a la palabra si la encuentra
        }
    }
    return nullptr; // Devuelve nullptr si la palabra no está en la lista
}
/* Verificación de diccionario vacio */
bool Diccionario::palabras_is_empty(){
    return list_words.empty();
}