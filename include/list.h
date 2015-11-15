#ifndef LIST_H
#define LIST_H

#include <exception>
#include <iostream>
#include <string>
#include "node.h"

using namespace std;

class ListException : public exception {

protected:
    std::string msg;

public:
    explicit ListException(const char* message) : msg(message) {}

    explicit ListException(const std::string& message ) : msg(message) {}

    virtual~ListException() throw () {}

    virtual const char* what() const throw() {
        return msg.c_str();
    }

};

template <class T>
class List {
public:
    List();
    ~List();

    bool isEmpty();

    void insertData(Node<T>*, T);
    void insertSorted(T);
    void deleteData(Node<T>*);

    Node<T>* firstPos();
    Node<T>* lastPos();

    Node<T>* previousPos(Node<T>*);
    Node<T>* nextPos(Node<T>*);

    Node<T>* findData(T);

    T retrive(Node<T>*);

    void printList();

    void quickSort(Node<T>*, Node<T>*);
    void quickSort();

    void deleteAll();

private:
    Node<T>* m_anchor;

    bool isAValidPos(Node<T>*);

    void swapData(Node<T>*, Node<T>*);

    Node<T>* partitionList(Node<T>*, Node<T>*);
};

template<class T>
bool List<T>::isAValidPos(Node<T>* p) {
    Node<T>* aux = m_anchor->getNext();

    if(p == nullptr) {
        return true;
    }

    while (aux != m_anchor) {
        if (aux == p) {
            return true;
        }
        aux = aux->getNext();
    }

    return false;
}

template <class T>
void List<T>::swapData(Node<T>* a, Node<T>* b)
{
    Node<T>* aux = new Node<T>();
    aux->setDataPtr(a->getDataPtr());
    a->setDataPtr(b->getDataPtr());
    b->setDataPtr(aux->getDataPtr());
}

template <class T>
Node<T>* List<T>::partitionList(Node<T>* left, Node<T>* right)
{
    T aux = right->getData();

    Node<T>* i = left->getPrev();

    for (Node<T>* j = left; j != right; j = j->getNext()) {
        if (j->getData() <= aux) {
            i = (i == nullptr)? left : i->getNext();

            swapData(i, j);
        }
    }

    i = (i == nullptr)? left : i->getNext();
    swapData(i, right);

    return i;
}

//-------------------------------------//


template <class T>
List<T>::List() {
    m_anchor = new Node<T>();
    m_anchor->setNext(m_anchor);
    m_anchor->setPrev(m_anchor);
}

template <class T>
bool List<T>::isEmpty() {
    return m_anchor->getNext() == m_anchor;
}

template <class T>
void List<T>::insertData(Node<T>* pos, T data) {
    Node<T>* aux = new Node<T>(data);
    if (aux == nullptr) {
        throw ListException("Memoria insuficiente al insertar");
    }

    if(pos == nullptr) {
        pos = m_anchor;
    } else if (!isAValidPos(pos)) {
        throw ListException("Posicion invalida al insertar");
    }

    aux->setPrev(pos);
    aux->setNext(pos->getNext());
    pos->getNext()->setPrev(aux);
    pos->setNext(aux);
}

template <class T>
void List<T>::insertSorted(T data)
{
    Node<T> *aux1, *aux2;
    Node<T> *current = new Node<T>(data);
    if (a == nullptr) {
        throw ListException("Memoria insuficiente al insertar");
    }

    if (isEmpty()) {
        
        current->setNext(m_anchor);
        current->setPrev(m_anchor);
        m_anchor->setNext(current);
        m_anchor->setPrev(current);
        
    } else if (firstPos()->getData() > data) {
        
        current->setNext(firstPos());
        current->setPrev(m_anchor);
        firstPos()->setPrev(current);
        m_anchor->setNext(current);
        
    } else if (firstPos()->getData() <= data and firstPos() == lastPos()) {
        
        current->setPrev(firstPos());
        current->setNext(firstPos()->getNext());
        firstPos()->getNext()->setPrev(current);
        firstPos()->setNext(current);
        
    } else {
        
        aux1 = firstPos()->getNext();
        aux2 = firstPos();

        while (aux1 != m_anchor) {
            
            if(aux1->getData() > data and aux2->getData() <= data) {
                
                aux2->setNext(current);
                current->setPrev(aux2);
                current->setNext(aux1);
                aux1->setPrev(current);
                break;
            }

            aux1 = aux1->getNext();
            aux2 = aux2->getNext();

            if (aux2->getData() <= data and aux1 == m_anchor) {
                
                aux2->setNext(current);
                current->setPrev(aux2);
                current->setNext(aux1);
                aux1->setPrev(current);
            }
        }
    }
}

template <class T>
void List<T>::deleteData(Node<T>* pos) {
    if (isEmpty() or !isAValidPos()) {
        throw ListException("Posicion invalida al eliminar");
    }

    pos->getPrev()->setNext(pos->getNext());
    pos->getNext()->setPrev(pos->getPrev());

    delete pos;
}

template <class T>
Node<T>* List<T>::firstPos() {
    if (isEmpty()) {
        return  nullptr;
    }

    return m_anchor->getNext();
}

template <class T>
Node<T>* List<T>::lastPos() {
    if (isEmpty()) {
        return  nullptr;
    }

    return m_anchor->getPrev();
}

template <class T>
Node<T>* List<T>::previousPos(Node<T>* pos) {
    if (isEmpty() or !isAValidPos()) {
        return nullptr;
    }

    if(pos->getPrev() == m_anchor) {
        return m_anchor.getPrev();
    }

    return pos->getPrev();
}

template <class T>
Node<T>* List<T>::nextPos(Node<T>* pos) {
    if (isEmpty() or !isAValidPos()) {
        return nullptr;
    }

    if(pos->getNext() == m_anchor) {
        return firstPos();
    }

    return pos->getNext();
}

template <class T>
Node<T>* List<T>::findData(T data) {
    Node<T>* aux = firstPos();
    if (aux == nullptr) {
        throw ListException("Memoria insuficiente al buscar");
    }

    while(aux != m_anchor) {
        if (aux->getData == data) {
            return aux;
        }

        aux = aux->getNext();
    }

    return nullptr;
}

template <class T>
T List<T>::retrive(Node<T>* pos) {
    if (isEmpty() or !isAValidPos()) {
        throw ListException("Insuficiensa de datos al recuperar");
    }

    pos->getData();
}

template <class T>
void List<T>::printList() {
    Node<T>* aux = firstPos();

    while (aux != m_anchor) {
        std::cout << aux->getData() << std::endl;

        aux = aux->getNext();
    }
}

template <class T>
void List<T>::quickSort()
{
    quickSort(firstPos(), lastPos());
}

template <class T>
void List<T>::quickSort(Node<T>* left, Node<T>* right)
{
    if ( right != nullptr and left != right  and left != right->getNext()) {
        Node<T>* aux = partitionList(left, right);
        quickSort(left, aux->getPrev());
        quickSort(aux->getNext(), right);
    }
}

template <class T>
void List<T>::deleteAll() {
    while (m_anchor->getNext() != m_anchor) {
        Node<T>* aux = m_anchor->getNext();

        m_anchor->setNext(aux->getNext());

        delete aux;
    }

    m_anchor->setPrev(m_anchor);
}

template <class T>
List<T>::~List()
{
    deleteAll();
    delete m_anchor;
}


#endif // LIST_H