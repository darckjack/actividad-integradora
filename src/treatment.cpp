#include "../include/treatment.h"

using namespace std;

Treatment::Treatment() {

}

Treatment::~Treatment() {

}

int Treatment::getYear() {
    return m_year;
}

int Treatment::getMonth() {
    return m_month;
}

int Treatment::getDay() {
    return m_day;
}

string Treatment::getDate() {
    return to_string(m_day) + "/" + to_string(m_month) + "/" + to_string(m_year);
}

int Treatment::getDuration() {
    return m_duration;
}

float Treatment::getDosis() {
    return m_dosis;
}

string Treatment::getMedicine() {
    return m_medicine;
}

string Treatment::getVet() {
    return m_vet;
}

void Treatment::setYear(int year) {
    m_year = year;
}

void Treatment::setMonth(int month) {
    m_month = month;
}

void Treatment::setDay(int day) {
    m_day = day;
}

void Treatment::setDuration(int duration) {
    m_duration = duration;
}

void Treatment::setDosis(float dosis) {
    m_dosis = dosis;
}

void Treatment::setMedicine(string medicine) {
    m_medicine = medicine;
}

void Treatment::setVet(string vet) {
    m_vet = vet;
}