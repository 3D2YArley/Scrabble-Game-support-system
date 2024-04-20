#include "Letra.h"

Letra::Letra(){}

bool Letra::operator<(const Letra& otra) const {
    return letra < otra.letra;
}