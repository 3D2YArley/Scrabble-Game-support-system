#include "Scrabble.h"

using namespace std;

Scrabble::Scrabble() {
    letras = list<Letra>();
    diccionario = Diccionario();
    dicc_inverso = Diccionario();
    arbol = ArbolTrie();
    arbol_inverso = ArbolTrie();
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
    // Verificar si el diccionario ya ha sido inicializado
    if (!diccionario.palabras_is_empty() && !invertir){
        cout << "El diccionario ya ha sido inicializado." << endl;
        return false;
    } else if (!dicc_inverso.palabras_is_empty() && invertir){
        cout << "El diccionario inverso ya ha sido inicializado." << endl;
        return false;
    } 
    
    ifstream fin("files/" + nom_archivo);
    string palabra;

    if (!fin.is_open()) {
        cout << "El archivo " << nom_archivo << " no existe o no puede ser leído.\n" << endl;
        return false;
    }

    while (fin >> palabra) {
        if (check_words(palabra)) {
            Palabra p;
            if (invertir) {
                reverse(palabra.begin(), palabra.end());
                p.setPalabra(palabra);
                dicc_inverso.add_palabra(p);
            } else {
                p.setPalabra(palabra);
                diccionario.add_palabra(p);
            }
        } else {
            cout << "El archivo " << nom_archivo << " contiene palabras con carácteres inválidos." << endl;
            return false;
        }
    }
    fin.close();
    string str = (!invertir) ? "diccionario" : "diccionario inverso";
    cout << "El " << str << " se ha inicializado correctamente." << endl;
    return true;
}

/* Calcula el puntaje de una palabra dada segun el puntaje de sus letras */
bool Scrabble::word_score(string word) {
    if (diccionario.palabras_is_empty()) {
        cout << "El Diccionario no ha sido inicializado." << endl;
        return false;
    } else if (dicc_inverso.palabras_is_empty()){
        cout << "El Diccionario Inverso no ha sido inicializado." << endl;
        return false;
    } else if (!check_words(word)){
        cout << "La palabra " + word + "  contiene símbolos inválidos." << endl;
        return false;
    }

    int puntaje = 0;
    string word_inv = word;
    reverse(word_inv.begin(), word_inv.end());

    // Verificar que la palabra esté en los diccionarios
    Palabra* pal = diccionario.search_word(word);
    Palabra* pal2 = dicc_inverso.search_word(word_inv);

    // sino existe retorna error
    if (pal == nullptr || pal2 == nullptr){
       cout << "La palabra " + word + " no existe en los diccionarios." << endl;
    } else {
        // Si la palabra existe en el diccionario, se calcula su puntaje
        puntaje = calculate_score(word);
        // insertamos puntajes al diccionario
        pal->setPoints(puntaje);
        pal2->setPoints(puntaje);
    }
    cout << "La palabra " + word + " tiene un puntaje de: " + to_string(puntaje) << endl;
    return true;
}

bool Scrabble::inicializar_Arbol(string nom_archivo, bool invertir){
    if (!arbol.isEmpty() && !invertir){
        cout << "El árbol del diccionario ya ha sido inicializado.";
        return false;
    } else if (!arbol_inverso.isEmpty() && invertir){
        cout << "El árbol del diccionario inverso ya ha sido inicializado.";
        return false;
    }

    ifstream fin("files/" + nom_archivo);
    string palabra;

    if (!fin.is_open()) {
        cout << "El archivo " << nom_archivo << " no existe o no puede ser leído.\n" << endl;
        return false;
    }
    
    while (fin >> palabra) {
        if (check_words(palabra)) {
            if (invertir) {
                reverse(palabra.begin(), palabra.end());
                arbol_inverso.insert_word(palabra);
            } else
                arbol.insert_word(palabra);
        } else {
            cout << "El archivo " << nom_archivo << " contiene palabras con carácteres inválidos." << endl;
            return false;
        }
    }
    fin.close();
    string str = (!invertir) ? "" : "inverso ";
    cout << "El árbol del diccionario " << str << "se ha inicializado correctamente." << endl;
    return true;
}


void Scrabble::search_words(string word, bool isPrefix) {
    set<string> listaAuxiliar;
    set<Palabra> lista_palabras;
    string preSuf = isPrefix ? "sufijo " : "prefijo ";

    if (!isPrefix){
        listaAuxiliar = arbol.search_words(word, isPrefix);
    } else if (isPrefix) {
        reverse(word.begin(), word.end());
        listaAuxiliar = arbol_inverso.search_words(word, isPrefix);
    }

    if (!listaAuxiliar.empty()){
        for (string c : listaAuxiliar){
            Palabra palabra = Palabra(c); 

            int puntaje = calculate_score(c);
            palabra.setPoints(puntaje);

            lista_palabras.insert(palabra);
        }
        cout << endl << "Las palabras que inician con este " << preSuf << " son: " << endl;
        cout << left << setw(20) << "Palabra" << setw(10) << "Puntaje" << setw(10) << "Longitud" << endl;
        for(auto p : lista_palabras){
            cout << left << setw(20) << p.getPalabra() << setw(10) << to_string(p.getPoints()) << setw(10) << to_string(p.getLength()) << endl;
        }
    } else {
        cout << "Prefijo " << word << " no pudo encontrarse en el diccionario." << endl;
    }
}


/* Es posible sacar estas funciones en una clase Utils.*/
bool Scrabble::check_words(string &word){
    // Verificar que la palabra contenga solo letras
    if (!all_of(word.begin(), word.end(), ::isalpha)){
        cout << endl << word << endl;
        return false;
    } else {
        for (char &c : word)
            c = tolower(c);
    }
    return true;
}

int Scrabble::calculate_score(string& word){
    int puntaje = 0;
    deque<char> fila(word.begin(), word.end());

    for (auto& letra : letras){
        for(auto it = fila.begin(); it != fila.end(); ){
            if (letra.getLetra() == *it){
                puntaje += letra.getPuntos();
                it = fila.erase(it);
            } else 
                it++;
        }   
    }
    return puntaje;
}