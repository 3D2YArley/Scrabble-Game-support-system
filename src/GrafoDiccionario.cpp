#include "GrafoDiccionario.h"

GrafoDiccionario::GrafoDiccionario() {}

void GrafoDiccionario::addNodo(Palabra& palabra) {
    string palabraStr = palabra.getWord();
    if (nodos.find(palabraStr) == nodos.end()) {
        nodos[palabraStr] = new NodoGrafo(palabra);
    }
}

void GrafoDiccionario::deleteNodo(const string& palabra) {
    auto it = nodos.find(palabra);
    if (it != nodos.end()) {
        // Eliminar aristas que apuntan al nodo a eliminar
        for (auto& pair : nodos) {
            pair.second->deleteAdyacente(it->second);
        }
        // Eliminar el nodo del grafo
        delete it->second;
        nodos.erase(it);
    }
}

void GrafoDiccionario::addAristas() {
    // Conectar nodos
    for (auto it1 = nodos.begin(); it1 != nodos.end(); ++it1) {
        for (auto it2 = next(it1); it2 != nodos.end(); ++it2) {
            if (diferenciaUnaLetra(it1->first, it2->first)) {
                it1->second->addAdyacente(it2->second);
                it2->second->addAdyacente(it1->second);
            }
        }
    }
}

void GrafoDiccionario::eliminarArista(const string& palabra1, const string& palabra2) {
    auto nodo1 = getNodo(palabra1);
    auto nodo2 = getNodo(palabra2);
    if (nodo1 && nodo2) {
        nodo1->deleteAdyacente(nodo2);
        nodo2->deleteAdyacente(nodo1);
    }
}

NodoGrafo* GrafoDiccionario::getNodo(const string& palabra) {
    auto it = nodos.find(palabra);
    if (it != nodos.end()) {
        return it->second;
    }
    return nullptr;
}
 
void GrafoDiccionario::modificarNodo(const string& palabra, const Palabra& nuevaPalabra) {
    auto it = nodos.find(palabra);
    if (it != nodos.end()) {
        // Modificar la palabra del nodo
        it->second->setPalabra(nuevaPalabra);
        // Actualizar la palabra en las aristas
        for (auto& pair : nodos) {
            if (pair.second != it->second) {
                pair.second->modificarAdyacente(it->second, nuevaPalabra);
            }
        }
    }
}

void GrafoDiccionario::imprimirVecinos(const string& palabra) {
    auto it = nodos.find(palabra);
    if (it != nodos.end()) {
        cout << "Vecinos de la palabra \"" << palabra << "\": " << endl;
        for (const auto& vecino : it->second->getAdyacentes()) {
            cout << vecino->getPalabra().getWord() << "\n";
        }
        cout << endl;
    } else {
        cout << "La palabra \"" << palabra << "\" no existe en el grafo." << endl;
    }
}

bool GrafoDiccionario::diferenciaUnaLetra(const string& palabra1, const string& palabra2) {
    if (palabra1.length() != palabra2.length()) {
        return false;
    }

    int diferencias = 0;
    for (size_t i = 0; i < palabra1.length(); ++i) {
        if (palabra1[i] != palabra2[i]) {
            ++diferencias;
            if (diferencias > 1) {
                return false;
            }
        }
    }
    return diferencias == 1;
}