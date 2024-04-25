#ifndef CONSOLE_IO_H
#define CONSOLE_IO_H_

#include "Scrabble.h"
#include <string>
#include <map>
#include <iostream>
#include <iomanip>
#include <list>

class ConsoleIO {
    private:
        map<string, map<string, string>> ayuda;
        Scrabble scrabble;

    public:
        ConsoleIO();

        void add_letters();
        void list_commands(string command);
        void process_command(string command);
        void process_components(string command);
};

#endif