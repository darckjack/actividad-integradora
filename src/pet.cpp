#include "../include/pet.h"

using namespace std;

Pet::Pet() {
    
}

Pet::~Pet() {
    
}

int Pet::getId() {
    return m_id;
}

int Pet::getAge() {
    return m_age;
}

string Pet::getName() {
    return m_name;
}

string Pet::getRace() {
    return m_race;
}

float Pet::getSize() {
    return m_size;
}

Customer Pet::getOwner() {
    return m_owner;
}

void Pet::setId(int id) {
    m_id = id;
}

void Pet::setAge(int age) {
    m_age = age;
}

void Pet::setName(string name) {
    m_name = name;
}

void Pet::setRace(string race) {
    m_race = race;
}

void Pet::setSize(float size) {
    m_size = size;
}

void Pet::setOwner(Customer owner) {
    m_owner = owner;
}