#ifndef TREATMENT_H
#define TREATMENT_H

#include <string>

class Treatment {
public:
    Treatment();
    ~Treatment();
    
    int getYear();
    int getMonth();
    int getDay();
    std::string getDate();
    int getDuration();
    float getDosis();
    std::string getMedicine();
    std::string getVet();
    
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    void setDuration(int);
    void setDosis(float);
    void setMedicine(std::string);
    void setVet(std::string);

private:
    int m_year;
    int m_month;
    int m_day;
    int m_duration;
    float m_dosis;
    std::string m_medicine;
    std::string m_vet;

};

#endif //TREATMENT_H