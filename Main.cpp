/* Fecha: 12 marzo 2024
   Autor: Kevin Garay, Felipe Garrido , Arley Bernal
   Materia: Estructura de Datos
   Proyecto: Sistema de apoyo para el juego Scrabble
   Profesor: Ing. John Corredor, PhD
*/
#include "include/ConsoleIO.h"
#include <iostream>

using namespace std;

int main(){
    ConsoleIO consola;

    string command;
    cout << endl << "ayuda                      Lista de comandos disponibles" << endl;
    cout << "ayuda nombre_comando       Descripción del comando" << endl;

    while (true) {
        // Entrada de comandos 
        cout << endl << " $  ";
        getline(cin, command);

        consola.process_command(command);
    }
    
    
    return 0;
}

