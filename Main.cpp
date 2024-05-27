/* Fecha: 12 marzo 2024
   Autor: Arley Bernal, Kevin Garay, Felipe Garrido 
   Materia: Estructura de Datos
   Proyecto: Sistema de apoyo para el juego Scrabble
   Profesor: Ing. John Corredor, PhD
*/
#include "ConsoleIO.h"
#include <iostream>

using namespace std;

int main(){
    ConsoleIO consola;

    consola.add_letters();

    std::cout << "********************************************" << std::endl;
    std::cout << "*            Bienvenido a Scrabble           *" << std::endl;
    std::cout << "*         Que empiece la diversión...        *" << std::endl;
    std::cout << "********************************************" << std::endl;

    
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
