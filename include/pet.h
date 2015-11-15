#ifndef PET_H
#define PET_H

#include <string>
#include "customer.h"

class Pet {
public:
    Pet();
    ~Pet();
    
    int getId();
    int getAge();
    std::string getName();
    std::string getRace();
    float getSize();
    Customer getOwner();
    
    void setId(int);
    void setAge(int);
    void setName(std::string);
    void setRace(std::string);
    void setSize(float);
    void setOwner(Customer);
    
private:
    int m_id;
    int m_age;
    std::string m_name;
    std::string m_race;
    float m_size;
    Customer m_owner;
    
};

#endif //PET_H