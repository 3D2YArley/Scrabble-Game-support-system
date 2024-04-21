#ifndef CONSOLE_IO_H
#define CONSOLE_IO_H_

#include "Scrabble.h"
#include <string>
#include <map>

class ConsoleIO {
    private:
        map<string, map<string, string>> ayuda;
        Scrabble scrabble;

    public:
        ConsoleIO();

        void add_letters();
        void process_command(string command);
        void list_commands(string command);

        void process_components(string command);

};

#endif