#ifndef LISTDESENCRIPTA_H_INCLUDED
#define LISTDESENCRIPTA_H_INCLUDED

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "Caracteres.h"

class NodoD {
    caracter Data;
    NodoD *siguiente;
    friend class ListaD;
};

typedef NodoD *ptro;

class ListaD {

private:

    NodoD *inicio,*fin;

public:
    void Inicializar ();
    void Insertar ();
    void Vizualizacion();
    std::string Leerascii ();
    std::string RegresaBinario (std::string c);
    std::string crea(int arr[],int conta);
    void desencriptar (std::string frasebin);


};




#endif // LISTDESENCRIPTA_H