/* Fecha: 12 marzo 2024
   Autor: Kevin Garay, Felipe Garrido , Arley Bernal
   Materia: Estructura de Datos
   Proyecto: Sistema de apoyo para el juego Scrabble
   Profesor: Ing. John Corredor, PhD
*/

#include <iostream>

using namespace std;

// main del programa
int main(){
    string command;
    Diccionario diccionario;

    // leer letras, esto deberia estar en un ciclo por si no se puede leer.
    list<Letra> letras = leerletras("letras.txt");
    if (letras.empty()) {
        return 0;
    }
    // Información sobre el uso de la terminal
    cout << endl << "ayuda                      Lista de comandos disponibles" << endl;
    cout << "ayuda nombre_comando       Descripción del comando" << endl;

    while (true) {
        // Entrada de comandos 
        cout << " $  ";
        getline(cin, command);

        // Bloque de condicionales para cada comando
        if (command.substr(0, 5) == "ayuda") {
            executeCommand(command);
        }
        else if (command.substr(0, 11) == "inicializar") {
            if (!diccionario.palabras_is_empty()){
                cout << "El diccionario ya ha sido inicializado.\n" << endl;
            } else {
                inicializarDiccionario(command.substr(12), diccionario, false);
            }
        } else if (command.substr(0, 15) == "iniciar_inverso") {
            if (!diccionario.palabras_inversas_is_empty()){
                cout << "El diccionario inverso ya ha sido inicializado.\n" << endl;
            } else {
                inicializarDiccionario(command.substr(16), diccionario, true);
            }        
        } else if (command == "puntaje palabra") {
            if (diccionario.palabras_is_empty() || diccionario.palabras_inversas_is_empty()){
              cout << "El diccionario y diccionario inverso no han sido inicializados.\n" << endl;
            } else {
              cout << "\nFuncion de puntaje de palabra ingresada\n";
              cout << "Ingrese la palabra: ";
              string word;
              cin >> word;
              cin.ignore();
              cout << puntaje_palabra(word, letras, diccionario) << endl;
            }
        } else if (command == "salir") {
            exit(0);
        } else {
            cout << "Comando no reconocido" << endl;
        }
    }
}