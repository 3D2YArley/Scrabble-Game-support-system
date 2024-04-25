#include "ConsoleIO.h"

ConsoleIO::ConsoleIO() {
    ayuda = {
        {"1. Configuración del juego",
        {
            {"inicializar diccionario.txt", "Inicializa el sistema a partir del archivo diccionario.txt"},
            {"iniciar_inverso diccionario.txt", "Inicializa el sistema a partir del archivo y almacena las palabras en sentido inverso"},
            {"puntaje palabra", "El comando permite conocer la puntuación que puede obtenerse con una palabra dada."},
            {"salir", "Termina la ejecución de la aplicación."}
        }},

        {"2. Búsqueda de palabras",
        {
            {"inicializar_arbol diccionario.txt", "Inicializa el sistema desde un archivo diccionario.txt y almacena las palabras en un árbol."},
            {"iniciar_arbol_inverso diccionario.txt", "Inicializa el sistema a partir del archivo y almacena las palabras en sentido inverso en un árbol."},
            {"palabras_por_prefijo prefijo", "Dado un prefijo, se recorre el árbol de letras para ubicar todas las palabras posibles a construir."},
            {"palabras_por_sufijo sufijo", "Dado un sufijo, se recorre el árbol de letras para ubicar todas las palabras posibles a construir."}
        }},

        {"3. Combinaciones de palabras",
        {
            {"grafo_de_palabras", "No implementado."},
            {"posibles_plabras letras", "No implementado."}
        }
        }
    };
}

void ConsoleIO::add_letters(){
    bool init = scrabble.fill_letter("letras.txt");
    if (!init){
        cout << endl << "El archivo letras.txt no existe." << endl;
        cout << "Es necesario revisar los archivos de texto en la carpeta 'files'.\n" << endl;
        exit(0);
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
    if (command.substr(0, 12) == "inicializar "){
        scrabble.inicializar_diccionario(command.substr(12), false);

    } else if (command.substr(0, 16) == "iniciar_inverso "){
        scrabble.inicializar_diccionario(command.substr(16), true);

    } else if (command.substr(0, 8) == "puntaje "){
        scrabble.word_score(command.substr(8));

    } else if (command.substr(0, 14) == "iniciar_arbol "){
        scrabble.inicializar_Arbol(command.substr(14), false);

    } else if (command.substr(0, 22) == "iniciar_arbol_inverso "){
        scrabble.inicializar_Arbol(command.substr(22), true);

    } else if (command.substr(0, 21) == "palabras_por_prefijo "){
        scrabble.search_words(command.substr(21), false);

    } else if (command.substr(0, 20) == "palabras_por_sufijo "){
        scrabble.search_words(command.substr(20), true);


        
    } else if (command.substr(0, 18) == "grafo_de_palabras "){
        cout << "grafo_de_palabras" << endl;

    } else {        
        cout << "Comando no reconocido" << endl;
    }
}
