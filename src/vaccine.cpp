#include "../include/vaccine.h"

using namespace std;

Vaccine::Vaccine() {

}

Vaccine::~Vaccine() {

}

int Vaccine::getId() {
    return m_id;
}

int Vaccine::getYear() {
    return m_year;
}

int Vaccine::getMonth() {
    return m_month;
}

int Vaccine::getDay() {
    return m_day;
}

int Vaccine::getDuration() {
    return m_duration;
}

int Vaccine::getExpireYear() {
    return m_expireYear;
}

int Vaccine::getExpireMonth() {
    return m_expireMonth;
}

int Vaccine::getExpireDay() {
    return m_expireDay;
}

string Vaccine::getDate() {
    return to_string(m_day) + "/" + to_string(m_month) + "/" + to_string(m_year);
}

string Vaccine::getExpireDate() {
    return to_string(m_expireDay) + "/" + to_string(m_expireMonth) + 
            "/" + to_string(m_expireYear);
}

string Vaccine::getName() {
    return m_name;
}

void Vaccine::setId(int id) {
    m_id = id
}

void Vaccine::setYear(int year) {
    m_year = year;
}

void Vaccine::setMonth(int month) {
    m_month = month;
}

void Vaccine::setDay(int day) {
    m_day = day;
}

void Vaccine::setDuration(int duration) {
    m_duration = duration;
}

void Vaccine::setExpireYear(int expireYear) {
    m_expireYear = expireYear;
}

void Vaccine::setExpireMonth(int expireMonth) {
    m_expireMonth = expireMonth;
}

void Vaccine::setExpireDay(int expireDay) {
    m_expireDay = expireDay;
}

void Vaccine::setName(string name) {
    m_name = name;
}