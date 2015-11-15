#include "../include/customer.h"

using namespace std;

Customer::Customer() {
    //ctor
}

Customer::~Customer() {
    //dtor
}

int Customer::getId() {
    return m_id;
}

string Customer::getName() {
    return m_name;
}

string Customer::getEmail() {
    return m_email;
}

string Customer::getAddress() {
    return m_address;
}

string Customer::getPhone() {
    return m_phone;
}

void Customer::setId(int id) {
    m_id = id;
}

void Customer::setName(string name) {
    m_name = name;
}

void Customer::setEmail(string email) {
    m_email = email;
}

void Customer::setAddress(string address) {
    m_address = address;
}

void Customer::setPhone(string phone) {
    m_phone = phone;
}
