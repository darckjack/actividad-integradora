#include "../include/Arbolista.h"

using namespace std;

void Lista::Inicializar() {
    inicio=nullptr;
    fin=nullptr;
    tam=0;
}

void Lista::Insertar (string c) {
    if(tam==0) {
        NodoL *nuevo;
        nuevo=new NodoL();
        nuevo->Data.setCaracter(c);
        nuevo->Data.setFrecuencia(1);
        inicio=nuevo;
        fin=nuevo;
        tam++;
    }    else {
        NodoL *actual, *nuevo;
        actual=inicio;
        while(actual!=nullptr and actual->Data.getCaracter() != c) {

            actual = actual->siguiente;
        }
        if(actual!=nullptr and actual->Data.getCaracter() == c) actual->Data.setFrecuencia(actual->Data.getFrecuencia()+1);
        else {
            nuevo=new NodoL();
            nuevo->Data.setCaracter(c);
            nuevo->Data.setFrecuencia(1);
            actual=fin;
            actual->siguiente=nuevo;
            nuevo->siguiente=nullptr;
            fin=nuevo;
            tam++;
        }
    }
}

void Lista::Vizualizacion () {
    if(inicio==nullptr) {
        cout << "NO HAY NADA QUE MOSTRAR" << endl;
    } else {
        NodoL *actual;
        actual=inicio;
        while(actual!=nullptr) {

            cout << "Letra:       " <<actual->Data.getCaracter()        <<  endl;
            cout << "Frecuencia:  " <<actual->Data.getFrecuencia()      <<  endl;
            cout << "Binario :    " <<actual->Data.getBinario ()        << endl;
            cout << endl;
            actual=actual->siguiente;
        }

    }
}

void Lista::Seleccion() {
    ptr menor,aux1,j;
    ptr ayuda=new NodoL();
    aux1=inicio;
    while(aux1!=nullptr) {
        menor=aux1;
        j=aux1->siguiente;
        while(j!=nullptr) {
            if(j->Data.getFrecuencia()<menor->Data.getFrecuencia()) {
                menor=j;
            }
            j=j->siguiente;
        }

        if(menor!=aux1) {
            ayuda->Data=aux1->Data;
            aux1->Data=menor->Data;
            menor->Data=ayuda->Data;


        }
        aux1=aux1->siguiente;
    }
}

void Lista::Seleccion1() {
    ptr menor,aux1,j;
    ptr ayuda=new NodoL();
    aux1=inicio;
    while(aux1!=nullptr) {
        menor=aux1;
        j=aux1->siguiente;
        while(j!=nullptr) {
            char *a,*b;
            a = new char[j->Data.getCaracter().size() + 1];
            strcpy ( a, j->Data.getCaracter().c_str() );
            b= new char [menor->Data.getCaracter().size()+1];
            strcpy (b,menor->Data.getCaracter().c_str());

            if(a<b) {
                menor=j;
            }
            j=j->siguiente;
        }

        if(menor!=aux1) {
            ayuda->Data=aux1->Data;
            aux1->Data=menor->Data;
            menor->Data=ayuda->Data;


        }
        aux1=aux1->siguiente;
    }
}


void Lista::Arbol () {
    if(inicio==nullptr) {
        cout << "NO HAY NADA QUE MOSTRAR" << endl;
    } else {
        ptr Nuevo,root;
        root=inicio;
        while(root!=nullptr and root->siguiente!=nullptr) {
            Nuevo=new NodoL ();
            Nuevo->Data.setCaracter("");
            Nuevo->der = root;
            root = root->siguiente;
            Nuevo->izq = root;
            root =root->siguiente;
            Nuevo->Data.setFrecuencia(Nuevo->der->Data.getFrecuencia() +
                                      Nuevo->izq->Data.getFrecuencia());
            InsertarOrden(root,Nuevo);
        }

        preorder(root);
        inorder(root);

    }
}

void Lista::InsertarOrden(ptr &Cabeza, ptr e) {
    ptr p, a;

    if(Cabeza==nullptr) {
        Cabeza = e;
        Cabeza->siguiente = nullptr;
    } else {
        /* Buscar el caracter en la lista (ordenada por frecuencia) */
        p = Cabeza;
        a = nullptr;
        while(p!=nullptr and p->Data.getFrecuencia() < e->Data.getFrecuencia()) {
            a = p;
            p = p->siguiente;
        }
        e->siguiente = p;
        if(a!=nullptr) a->siguiente = e;
        else Cabeza = e;
    }
}

void Lista::inorder(NodoL *&n) {
    ofstream salida ("Tabla.txt",ios::app);
    if (n != nullptr) {
        inorder(n->der);
        if(n->Data.getCaracter() !="") {
            cout << "Letra:       " <<n->Data.getCaracter()        <<  endl;
            cout << "Frecuencia:  " <<n->Data.getFrecuencia()      <<  endl;
            cout << "Binario :    " <<n->Data.getBinario ()        << endl;
            cout << endl;
            salida  << n->Data.getCaracter() <<'|'
                    << n->Data.getBinario () <<'|';
        }
        inorder(n->izq);


    }
    salida.close();
}

void Lista::preorder(NodoL *&n) {
    char binario[10];
    int i;


    if (n->der!= nullptr) {
        strcpy(binario,n->Data.getBinario());
        i=strlen(binario);
        binario[i]='0';
        binario[i+1]='\0';
        n->der->Data.setBinario(binario);
        preorder(n->der);
    }


    if (n->izq!= nullptr) {
        strcpy(binario,n->Data.getBinario());
        i=strlen(binario);
        binario[i]='1';
        binario[i+1]='\0';
        n->izq->Data.setBinario(binario);

        preorder(n->izq);
    }
}
std::string Lista::crearFraseBinario(std::string palabra) {
    string binario;
    string comodin;
    int multiplo= 0;
    if(inicio==nullptr) {
        cout << "NO HAY NADA QUE MOSTRAR" << endl;
    } else {
        NodoL *actual;
        actual=inicio;

        for(int i= 0; i<palabra.length(); i++) {
            actual = inicio;
            while(actual!=nullptr) {
                if(palabra.substr(i,1) == actual->Data.getCaracter()) {
                    comodin = actual->Data.getBinario();
                    binario = binario + comodin;
                    break;
                }
                actual=actual->siguiente;
            }
        }

        ofstream a ("longitud.txt",ios::trunc);
        int b=binario.length();
        a << b << '|';

        int multi = binario.length()%8;

        while(multi > 0 and multi < 8) {
            binario = binario + "0";
            multi++;
        }


    }
    return binario;
}

int Lista::crearFraseDecimal(std::string palabra) {
    if(inicio==nullptr) {
        cout << "NO HAY NADA QUE MOSTRAR" << endl;
    } else {

        int contador = 0;

        for(int i=0; i<palabra.length(); i=i+8) {
            contador++;
        }
        int arreglo[contador];
        int c=0,d=0,e=0;
        contador = 0;

        cout<<endl<<"binario: " <<endl;

        for(int i=0; i<palabra.length(); i=i+8) {
            arreglo[contador]=atoi(palabra.substr(i,8).c_str());
            cout<<arreglo[contador]<<endl;
            contador++;
        }
        cout<<endl<<"decimal: "<<endl;

        for(int i=0; i<contador; i++) {
            while(arreglo[i]>=10) {
                c=0;
                while(arreglo[i]>=10) {
                    arreglo[i]=arreglo[i]-10;
                    c++;
                }
                d=d+arreglo[i]*pow(2,e);
                e++;
                arreglo[i]=c;
            }
            d=d+c*pow(2,e);
            arreglo[i] = d;
            cout<<arreglo[i]<<endl;
            c=0;
            d=0;
            e=0;
        }
//     cout<<endl<<"Ascii: "<<endl;
        cout<<endl<<"Frase encriptada: "<<endl;
        char a;
        string ascci;
        for(int i=0; i<contador; i++) {
//      printf("%c \n",arreglo[i]);
            a=arreglo[i];
            cout << a ;
            ascci=ascci+a;
        }

        ofstream escribe ("ascii.txt",ios::trunc);
        escribe << ascci << '|';

        return 0;
    }
}
