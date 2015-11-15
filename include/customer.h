#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    Customer();
    ~Customer();
    int getId();
    std::string getName();
    std::string getEmail();
    std::string getAddress();
    std::string getPhone();
    
    void setId(int);
    void setName(std::string);
    void setEmail(std::string);
    void setAddress(std::string);
    void setPhone(std::string);

private:
    int m_id;
    std::string m_name;
    std::string m_email;
    std::string m_address;
    std::string m_phone;
};

#endif // CUSTOMER_H