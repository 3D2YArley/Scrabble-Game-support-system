#include "ConsoleIO.h"
#include <iostream>
#include <iomanip>

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

void ConsoleIO::draw_interface(){
    string command;
    cout << endl << "ayuda                      Lista de comandos disponibles" << endl;
    cout << "ayuda nombre_comando       Descripción del comando" << endl;

    while (true) {
        // Entrada de comandos 
        cout << endl << " $  ";
        getline(cin, command);

        process_command(command);
    }
}

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
    cout << "Entra" << endl;
}

