#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <cstdio>
#include <fstream>
#include <string>
#include "treatment.h"
#include "vaccine.h"
#include "pet.h"
#include "customer.h"

#define BEGIN_PET "<Pet>"
#define END_PET "</Pet>"
#define BEGIN_CUSTOMER "<Customer>"
#define END_CUSTOMER "</Customer>"
#define BEGIN_TREATMENT "<Treatment>"
#define END_TREATMENT "</Treatment>"
#define BEGIN_VACCINE "<Vaccine>"
#define END_VACCINE "</Vaccine>"

class FileManager {
public:
    void addPet(Pet, Customer);
    void addCustomer(Customer);
    void addTreatment(Treatment, Pet);
    void addVaccine(Vaccine, Pet);
    
    void readCustomer(Customer);
    void readPet(Pet);
    
    void deletePet(Pet);
    void deleteCustomer(Customer);
    void deleteTreatment(Pet, Treatment);
    void deleteVaccine(Pet, Vaccine);
    
    void updatePet(Pet);
    void updateCustomer(Customer);
    void updateTreatment(Pet, Treatment);
    void updateVaccine(Pet, Vaccine);
};