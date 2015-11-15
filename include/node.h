#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <memory>

template <class T>
class Node {
private:
    Node* m_next;
    Node* m_prev;
    T* m_dataptr;

public:
    Node();
    Node(T&);
    Node(Node&);
    ~Node();

    T getData();
    T* getDataPtr();
    Node* getNext();
    Node* getPrev();

    void setData(T);
    void setDataPtr(T*);
    void setNext(Node*);
    void setPrev(Node*);

};

// Constructor por defecto
template <class T>
Node<T>::Node() {
    m_dataptr = nullptr;
    m_next = nullptr;
    m_prev = nullptr;
}

// Constructor por parámetro
template <class T>
Node<T>::Node(T& data) : Node() {
    m_dataptr = new T;
    *m_dataptr = data;
}

template <class T>
Node<T>::Node(Node<T> &aux) {
    m_dataptr = aux->getData();
    m_next = aux->getNext();
    m_prev = aux->getPrev();
}

template <class T>
T Node<T>::getData() {
    return *m_dataptr;
}

template <class T>
T* Node<T>::getDataPtr()
{
    return m_dataptr;
}


template <class T>
Node<T>* Node<T>::getNext() {
    return m_next;
}

template <class T>
Node<T>* Node<T>::getPrev() {
    return m_prev;
}

template <class T>
void Node<T>::setData(T data) {
    *m_dataptr = data;
}

template <class T>
void Node<T>::setDataPtr(T* data)
{
    m_dataptr = data;
}


template <class T>
void Node<T>::setNext(Node<T>* next) {
    m_next = next;
}

template <class T>
void Node<T>::setPrev(Node<T>* prev) {
    m_prev = prev;
}



template <class T>
Node<T>::~Node() {}

#endif // NODE_H