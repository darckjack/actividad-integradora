#ifndef ARBOLISTA_H
#define ARBOLISTA_H

#include "Caracteres.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <fstream>
using namespace std;

class NodoL {
    caracter Data;
    NodoL *siguiente;
    NodoL *izq;
    NodoL *der;
    friend class Lista;
};

typedef NodoL *ptr;

class Lista {

private:

    NodoL *inicio,*fin;
    int tam;

public:
    void Inicializar ();
    void Insertar (std::string c);
    void Vizualizacion();
    void Destruir_lista();
    void Seleccion();
    void Seleccion1();
    void Arbol ();
    void inorder(NodoL *&n);
    void InsertarOrden(ptr &Cabeza, ptr e);
    void preorder (NodoL*&n);
    std::string crearFraseBinario(std::string palabra);
    int crearFraseDecimal(std::string palabra);
    ptr getInicio() {
        return inicio;
    }
};


#endif // ARBOLISTA_H
