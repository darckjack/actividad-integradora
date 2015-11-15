#ifndef VACCINE_H
#define VACCINE_H

#include <string>

class Vaccine {
public:
    Vaccine();
    ~Vaccine();
    
    int getYear();
    int getMonth();
    int getDay();
    int getDuration();
    int getExpireYear();
    int getExpireMonth();
    int getExpireDay();
    std::string getDate();
    std::string getExpireDate();
    std::string getName();
    
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    void setDuration(int);
    void setExpireYear(int);
    void setExpireMonth(int);
    void setExpireDay(int);
    void setName(std::string);
    
private:
    int m_year;
    int m_month;
    int m_day;
    int m_duration;
    int m_expireYear;
    int m_expireMonth;
    int m_expireDay;
    std::string m_name;
    
};

#endif //VACCINE_H