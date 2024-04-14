/* Fecha: 12 marzo 2024
   Autor: Kevin Garay, Felipe Garrido , Arley Bernal
   Materia: Estructura de Datos
   Proyecto: Sistema de apoyo para el juego Scrabble
   Profesor: Ing. John Corredor, PhD
*/

// Definición de la biblioteca scrabble con sus funciones y estructuras.
#ifndef __SCRABBLE_H__
#define __SCRABBLE_H__

#include <string>
#include <map>

using namespace std;

extern map<string, map<string, string>> ayuda;

/* El TAD letra es usado para almacenar la información de una letra y su puntuación */
struct Letra {
    char letra;
    int punto;
};

/* El TAD palabra es usado para almacenar la información de una palabra y el total de puntos */
struct Palabra {
    string palabra;
    int puntos;
};

/* El TAD diccionario es usado para almacenar una lista de palabras.*/
struct Diccionario {
    set<Palabra> palabras;

    public:
        bool palabras_is_empty(){
            if(palabras.empty()){
                return true;
            } else {
                return false;
            }
        }
};

/* Cabezaras de funciónes a usar */
list<Letra> leerletras(string nombreArch);
void executeCommand(string command);
bool inicializarDiccionario(const string& archivo, Diccionario& diccionario, bool invetir);
list<Palabra>::iterator buscarEnDiccionario(list<Palabra> &listaDePalabras, const string &word);
string puntaje_palabra(string word, list<Letra> letras, Diccionario &diccionario);


#endif