#include "ConsoleIO.h"
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

ConsoleIO::ConsoleIO() {
    scrabble = Scrabble();
    ayuda = {
        {"1. Configuración del juego.",
        {
            {"inicializar diccionario.txt", "Inicializa el sistema a partir del archivo diccionario.txt"},
            {"iniciar_inverso diccionario.txt", "Inicializa el sistema a partir del archivo y almacena las palabras en sentido inverso"},
            {"puntaje palabra", "El comando permite conocer la puntuación que puede obtenerse con una palabra dada."},
            {"salir", "Termina la ejecución de la aplicación."}
        }},

        {"2. Búsqueda de palabras.",
        {
            {"inicializar_arbol diccionario.txt", "Inicializa el sistema desde un archivo diccionario.txt y almacena las palabras en árboles."},
            {"iniciar_arbol_inverso diccionario.txt", "Inicializa el sistema a partir del archivo y almacena las palabras en sentido inverso en árboles."},
            {"palabras_por_prefijo prefijo", "Dado un prefijo, el comando recorre el árbol de letras para ubicar todas las palabras posibles a construir."},
            {"palabras_por_sufijo sufijo", "Dado un sufijo, el comando recorre el árbol de letras para ubicar todas las palabras posibles a construir."}
        }},

        {"3. Combinaciones de palabras.",
        {
            {"grafo_de_palabras", "No implementado."},
            {"posibles_plabras letras", "No implementado."}
        }
        }
    };
};


void ConsoleIO::process_command(string command){
    if(command.substr(0, 5) == "ayuda"){
        list_commands(command);
    } else if(command == "salir"){
        exit(0);
    } else {
        process_components(command);
    }
} 

void ConsoleIO::list_commands(string command){
    cout << endl;
    for (auto& componente : ayuda){
        cout << componente.first << ":" << endl;

        for (auto& comando : componente.second){
            cout << "     " << left << setw(40) << comando.first << comando.second << endl;
        }
        cout << endl;
    }
}

void ConsoleIO::process_components(string command){
    if (command.substr(0, 11) == "inicializar"){
        cout << "Diccionario.txt" << endl;
    } else if (command.substr(0, 15) == "iniciar_inverso"){
        cout << "Diccionario.txt inverso" << endl;
    } else if (command.substr(0, 6) == "puntaje"){
        cout << "puntaje" << endl;

    } else if (command.substr(0, 13) == "iniciar_arbol"){
        cout << "iniciar_arbol" << endl;

    } else if (command.substr(0, 22) == "iniciar_arbol_inverso"){
        cout << "iniciar_arbol_inverso" << endl;

    } else if (command.substr(0, 20) == "palabras_por_prefijo"){
        cout << "palabras_por_prefijo" << endl;

    } else if (command.substr(0, 19) == "palabras_por_sufijo"){
        cout << "palabras_por_sufijo" << endl;

    } else if (command.substr(0, 17) == "grafo_de_palabras"){
        cout << "grafo_de_palabras" << endl;

    } else if (command.substr(0, 17) == "posibles_palabras"){
        cout << "posibles_palabras" << endl;

    } else {
        cout << "Comando no reconocido" << endl;
    }
}

/*
list<Letra> leerLetras(string nombreArch){
    list<Letra> letras;
    Letra l;
    int p;
    char c;

    // Se abre el archivo de texto con el nombre dado    
    ifstream myfile(nombreArch);
    if (myfile.is_open()) {
        string line;

        while (getline(myfile, line)) {
            istringstream iss(line);
            iss >> l.letra >> l.puntos;
            letras.push_back(l);
        }
        myfile.close();

        return letras;
    }
    else {
        cout << endl << "El archivo letras.txt no ha sido leído, se requiere revisión de archivo.\n" << endl;
        // retorna un lista vacia en caso de no poder leer el archivo
        return letras;
    }
}
*/