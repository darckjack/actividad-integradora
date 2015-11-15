#include "../include/customer.h"

Customer::Customer() {
    //ctor
}

Customer::~Customer() {
    //dtor
}

int getId() {
    return m_id;
}

string getName() {
    return m_name;
}

string getEmail() {
    return m_email;
}

string getAddress() {
    return m_address;
}

string getPhone() {
    return m_phone;
}

void setId(int id) {
    m_id = id;
}

void setName(string name) {
    m_name = name;
}

void setEmail(string email) {
    m_email = email;
}

void setAddress(string address) {
    m_address = address;
}

void setPhone(string phone) {
    m_phone = phone;
}
