#include "../include/listDesencripta.h"

using namespace std;


void ListaD::Inicializar() {
    inicio=nullptr;
    fin=nullptr;
}

void ListaD::Insertar() {
    string c;
    string binario;
    char* b;

    ifstream leer ("Tabla.txt");
    if(!leer.good()) {
    } else {

        while (!leer.eof()) {
            if (leer.eof()) {
                break;
            } else {
                ;
            }

            getline (leer,c,'|');
            getline (leer,binario,'|');
            b=new char[binario.size() + 1];
            strcpy ( b, binario.c_str() );

            if (leer.eof()) {
                break;
            } else {
                ;
            }

            if(inicio==nullptr) {
                NodoD *nuevo;
                nuevo=new NodoD();
                nuevo->Data.setCaracter(c);
                nuevo->Data.setFrecuencia(0);
                nuevo->Data.setBinario(b);
                inicio=nuevo;
                fin=nuevo;

            }    else {
                NodoD  *nuevo;

                nuevo=new NodoD();
                nuevo->Data.setCaracter(c);
                nuevo->Data.setFrecuencia(0);
                nuevo->Data.setBinario(b);
                fin->siguiente=nuevo;
                fin=nuevo;
            }
            if (leer.eof()) {
                break;
            } else {
                ;
            }
        }//while
        leer.close();
    }//Existe archivo
}


void ListaD::Vizualizacion() {
    if(inicio==nullptr) {
        cout << "NO HAY NADA QUE MOSTRAR" << endl;
    } else {
        NodoD *actual;
        actual=inicio;
        while(actual!=nullptr) {

            cout << "Letra:       " <<actual->Data.getCaracter()        <<  endl;
            cout << "Binario :    " <<actual->Data.getBinario ()        << endl;
            cout << endl;
            actual=actual->siguiente;
        }

    }
}


std::string ListaD::Leerascii() {
    string ascci;
    ifstream Lectura ("ascii.txt");
    if(!Lectura.good()) {
        cout<<endl<<"[ERROR].Archivo no existe! ";
    } else {
        while (!Lectura.eof()) {
            if (Lectura.eof()) {
                break;
            } else {
                ;
            }
            getline (Lectura,ascci,'l');
            if (Lectura.eof()) {
                break;
            } else {
                ;
            }
        }
        Lectura.close();
        return ascci;
    }


}

std::string ListaD::RegresaBinario(std::string c) {
    int t=c.length();
    int arr[t+1];
    int y=0,as;
    string aux;

    for (int i=0; i<c.length(); i++) {
        aux = c.at(i);
        char *cs;
        strcpy ( cs, aux.c_str() );
        as = *cs;
        if(as<0) {
            as=256+as;
        } else {
            ;
        }
        arr[y]=as;
        y++;
    }
    string temp;
    temp=crea(arr,t);
    return temp;



}

std::string ListaD::crea(int arr[],int conta) {
    int numero, dividendo, resto, divisor = 2;
    string binario[conta];
    string frase = "";
    for(int i=0; i<conta; i++) {
        dividendo = arr[i];
        binario[i] = "";
        while(dividendo >= divisor) { //Mientras el dividendo sea mayor o igual que el divisor, es decir, mayor o igual que 2.
            resto = dividendo % 2;
            if(resto == 1)
                binario[i] = "1" + binario[i]; //Si el resto es igual a 1 concatenamos 1 a la variable string llamada binario
            else
                binario[i] = "0" + binario[i]; // Sino concatemanos 0
            //Es importante este orden de concatenación (primero el bit y luego el valor de la variable) esto para que nuestro número
            //en sistema binario esté ordenado correctamente.
            dividendo = dividendo/divisor; // Actualizamos el valor del dividendo dividiendolo entre 2.
        }
        if(dividendo == 1)
            binario[i] = "1" + binario[i]; // Por último sí el valor final del dividendo es 1 concatenamos 1 sino concatenamos 0.
        else
            binario[i] = "0" + binario[i];

        string bandera = binario[i];
        for(int j=bandera.length(); j<8; j++) {
            binario[i] = "0" + binario[i];
        }
        frase = frase + binario[i];
    }

//          cout << frase << endl;
    string limite,aux;
    ifstream a ("longitud.txt");
    if(!a.good()) {
        cout << "error" << endl;
    } else {
        getline (a,aux,'|');
        int b=atoi(aux.c_str());
        aux="";
        for (int z=0; z<b; z++) {
            aux=frase.at(z);
            limite=limite+aux;
        }
        return limite;
    }

}

void ListaD::desencriptar (std::string frasebin) {
    if(inicio==nullptr) {
        cout << "NO HAY NADA QUE MOSTRAR" << endl;
    } else {
        string temp;
        string frasefin;
        NodoD *actual;
        actual=inicio;

        for(int i= 0; i<frasebin.length(); i++) {
            actual = inicio;
            temp=temp+frasebin.substr(i,1);
            while(actual!=nullptr) {


                if(temp == actual->Data.getBinario()) {
                    temp="";
                    frasefin=frasefin+actual->Data.getCaracter();
                    break;
                }
                actual=actual->siguiente;
            }
        }
        for(int i=0; i<frasefin.length(); i++) {
            if(frasefin.at(i)=='"') {
                frasefin.at(i)=' ';
            } else {
                ;
            }

        }
        cout << frasefin << endl;
    }
}