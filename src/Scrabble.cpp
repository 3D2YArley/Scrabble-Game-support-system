#include "Scrabble.h"
#include <fstream>
#include <iostream>
#include <set>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include "Letra.h"

using namespace std;

Scrabble::Scrabble() {
    letras = list<Letra>();
    diccionario = Diccionario();
    dicc_inverso = Diccionario();
}

bool Scrabble::fill_letter(string nom_archivo){
    Letra letra;
    string line;

    // Se abre el archivo de texto con el nombre dado
    ifstream myfile("files/" + nom_archivo);
    if (myfile.is_open()) {
        int p;
        char a;
        // Se lee el archivo linea por linea
        while (getline(myfile, line)) {
            istringstream iss(line);
            // Se lee la letra y el puntaje de la linea
            iss >> a >> p;
            letra.setLetra(a);
            letra.setPuntos(p);
            // Se agrega la letra  a la lista de letras
            letras.push_back(letra);
        }
        myfile.close();
        return true;
    }
    else {
        return false;
    }
}


/* Función encargada de inicializar el diccionario */    
bool Scrabble::inicializar_diccionario(string nom_archivo, bool invertir){
    ifstream fin("files/" + nom_archivo);
    string palabra;

    if (!fin.is_open()) {
        cout << "El archivo " << nom_archivo << " no existe o no puede ser leído.\n" << endl;
        return false;
    }

    while (fin >> palabra) {
        if (all_of(palabra.begin(), palabra.end(), ::isalpha)) {
            Palabra p;
            if (invertir) {
                reverse(palabra.begin(), palabra.end());
                p.setPalabra(palabra);
                dicc_inverso.add_palabra(p);
            } else {
                p.setPalabra(palabra);
                diccionario.add_palabra(p);
            }
        }
    }
    fin.close();
    string str = (!invertir) ? "diccionario" : "diccionario inverso";
    cout << "El " << str << " se ha inicializado correctamente." << endl;
    return true;

}

/* Calcula el puntaje de una palabra dada segun el puntaje de sus letras */
string Scrabble::word_score(string word) {
    int puntaje = 0;
    for (char &c : word) {
      c = tolower(c);
    }
    // Verificar que la palabra contenga solo letras
    if (!all_of(word.begin(), word.end(), ::isalpha)){
        return "La palabra " + word + "  contiene símbolos inválidos.";
    } else {
        for (char &c : word)
            c = tolower(c);
    }

    string word_inv = word;
    reverse(word_inv.begin(), word_inv.end());

    // Verificar que la palabra esté en los diccionarios
    Palabra* pal = diccionario.search_word(word);
    Palabra* pal2 = dicc_inverso.search_word(word_inv);

    // sino existe retorna error
    if (pal == nullptr || pal2 == nullptr){
        return "\nLa palabra " + word + " no existe en los diccionarios.\n";
    } else {
        // Si la palabra existe en el diccionario, se calcula su puntaje
        for (char caracter : word){
            for (auto& letra : letras){                
                if (letra.getLetra() == caracter)
                    puntaje += letra.getPuntos();
            }
        }
        // insertamos puntajes al diccionario
        pal->setPoints(puntaje);
        pal2->setPoints(puntaje);
    }
    return "La palabra " + word + " tiene un puntaje de: " + to_string(puntaje);
}