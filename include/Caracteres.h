#ifndef CARACTERES_H_INCLUDED
#define CARACTERES_H_INCLUDED

#include <string>
#include <cstring>

class caracter {
private:
    std::string c;
    int frecuencia;
    char binario[10];

public:

    void setCaracter (std::string C) {
        c=C;
    }
    void setFrecuencia (int f) {
        frecuencia=f;
    }
    void setBinario (char T[]) {
        strcpy(binario,T);
    }

    std::string getCaracter() {
        return c;
    }
    int getFrecuencia () {
        return frecuencia;
    }
    char* getBinario () {
        return binario;
    }
};

#endif // CARACTERES_H_INCLUDED
