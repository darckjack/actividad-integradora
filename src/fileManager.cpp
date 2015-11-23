#include "../include/fileManager.h"

using namespace std;

void FileManager::addPet(Pet pet, Customer customer) {
    string fileNamePet = pet.getName() + ".dat";
    string fileNameCustomer = customer.getName() + ".dat";

    ofstream outFilePet(fileNamePet, ios::out);
    ofstream outFileCustomer(fileNameCustomer, ios::app);

    if (!outFilePet.good() or !outFileCustomer.good())
    {
        throw "No se pudo generar el archivo";
    }
    else
    {
        outFilePet << BEGIN_PET         << endl;
        outFilePet << pet.getId()       << endl;
        outFilePet << pet.getName()     << endl;
        outFilePet << pet.getRace()     << endl;
        outFilePet << pet.getAge()      << endl;
        outFilePet << pet.getSize()     << endl;
        outFilePet << BEGIN_CUSTOMER    << endl;
        outFilePet << customer.getName() << endl;
        outFilePet << END_CUSTOMER      << endl;
        outFilePet << END_PET           << endl;

        outFileCustomer << BEGIN_PET   << endl;
        outFileCustomer << pet.getName() << endl;
        outFileCustomer << END_PET     << endl;
    }

    outFilePet.close();
    outFileCustomer.close();
}

void FileManager::addCustomer(Customer customer) {
    string fileName = customer.getName() + ".dat";

    ofstream outFile(fileName, ios::out);

    if (!outFile.good())
    {
        throw "El archivo no pudo ser creado";
    }
    else
    {

        outFile << BEGIN_CUSTOMER        << endl;
        outFile << customer.getId()      << endl;
        outFile << customer.getName()    << endl;
        outFile << customer.getEmail()   << endl;
        outFile << customer.getAddress() << endl;
        outFile << customer.getPhone()   << endl;
        outFile << END_CUSTOMER          << endl;
    }

    outFile.close();
}

void FileManager::addTreatment(Treatment treatment, Pet pet) {
    string fileName = pet.getName() + ".dat";

    ofstream outFile(fileName, ios::app);

    if (!outFile.good())
    {
        throw "El archivo no existe";
    }
    else
    {
        outFile << BEGIN_TREATMENT         << endl;
        outFile << treatment.getId()       << endl;
        outFile << treatment.getYear()     << endl;
        outFile << treatment.getMonth()    << endl;
        outFile << treatment.getDay()      << endl;
        outFile << treatment.getDuration() << endl;
        outFile << treatment.getMedicine() << endl;
        outFile << treatment.getDosis()    << endl;
        outFile << treatment.getVet()      << endl;
        outFile << END_TREATMENT           << endl;
    }

    outFile.close();
}

void FileManager::addVaccine(Vaccine vaccine, Pet pet) {
    string fileName = pet.getName() + ".dat";

    ofstream outFile(fileName, ios::app);

    if (!outFile.good())
    {
        throw "El archivo no existe";
    }
    else
    {
        outFile << BEGIN_VACCINE            << endl;
        outFile << vaccine.getId()          << endl;
        outFile << vaccine.getYear()        << endl;
        outFile << vaccine.getMonth()       << endl;
        outFile << vaccine.getDay()         << endl;
        outFile << vaccine.getDuration()    << endl;
        outFile << vaccine.getName()        << endl;
        outFile << vaccine.getExpireYear()  << endl;
        outFile << vaccine.getExpireMonth() << endl;
        outFile << vaccine.getExpireDay()   << endl;
        outFile << END_VACCINE              << endl;
    }

    outFile.close();
}

Pet FileManager::readPet(string petName) {
    string fileName = petName + ".dat";
    string auxS;
    int auxI;
    float auxF;

    Pet * aux = new Pet();

    ifstream inFile(fileName, ios::in);

    if (!inFile.good())
    {
        throw "El archivo no existe";
    }
    else
    {
        getline(inFile, auxS);
        inFile >> auxI;
        aux->setId(auxI);
        getline(inFile, auxS);
        aux->setName(auxS);
        getline(inFile, auxS);
        aux->setRace(auxS);
        inFile >> auxI;
        aux->setAge(auxI);
        inFile >> auxF;
        aux->setSize(auxF);
        getline(inFile, auxS);
        getline(inFile, auxS);
        aux->setOwner(readCustomer(auxS));
    }

    inFile.close();

    return *aux;
}

Customer FileManager::readCustomer(string customerName) {
    string fileName = customerName + ".dat";
    string auxS;
    int auxI;

    Customer * aux = new Customer();

    ifstream inFile(fileName, ios::in);

    if (!inFile.good())
    {
        throw "El archivo no existe";
    }
    else
    {
        getline(inFile, auxS);
        inFile >> auxI;
        aux->setId(auxI);
        getline(inFile, auxS);
        aux->setName(auxS);
        getline(inFile, auxS);
        aux->setEmail(auxS);
        getline(inFile, auxS);
        aux->setAddress(auxS);
        getline(inFile, auxS);
        aux->setPhone(auxS);
    }

    inFile.close();

    return *aux;
}

Treatment FileManager::readTreatment(string petName, int treatmentId) {
    string fileName = petName + ".dat";
    string auxS;
    int auxI;
    float auxF;
    
    Treatment * aux = new Treatment();
    
    ifstream inFile(fileName, ios::in);
    
    if (!inFile.good())
    {
        throw "No existe el archivo";
    }
    else
    {
        while(!inFile.eof())
        {
            getline(inFile, auxS);

            if (auxS == BEGIN_VACCINE)
            {
                inFile >> auxI;
                if (auxI == treatmentId)
                {
                    aux->setId(auxI);
                    inFile >> auxI;
                    aux->setYear(auxI);
                    inFile >> auxI;
                    aux->setMonth(auxI);
                    inFile >> auxI;
                    aux->setDay(auxI);
                    inFile >> auxI;
                    aux->setDuration(auxI);
                    getline(inFile, auxS);
                    aux->setMedicine(auxS);
                    inFile >> auxF;
                    aux->setDosis(auxF);
                    getline(inFile, auxS);
                    aux->setVet(auxS);
                }
            }
        }
    }
    
    inFile.close();
    
    return *aux;
}

Vaccine FileManager::readVaccine(string petName, int vaccineId) {
    string fileName = petName + ".dat";
    string auxS;
    int auxI;
    
    Vaccine * aux = new Vaccine();
    
    ifstream inFile(fileName, ios::in);
    
    if (!inFile.good())
    {
        throw "El archivo no existe";
    }
    else
    {
        while(!inFile.eof())
        {
            getline(inFile, auxS);

            if (auxS == BEGIN_VACCINE)
            {
                inFile >> auxI;
                if (auxI == vaccineId)
                {
                    aux->setId(auxI);
                    inFile >> auxI;
                    aux->setYear(auxI);
                    inFile >> auxI;
                    aux->setMonth(auxI);
                    inFile >> auxI;
                    aux->setDay(auxI);
                    inFile >> auxI;
                    aux->setDuration(auxI);
                    getline(inFile, auxS);
                    aux->setName(auxS);
                    inFile >> auxI;
                    aux->setExpireYear(auxI);
                    inFile >> auxI;
                    aux->setExpireMonth(auxI);
                    inFile >> auxI;
                    aux->setExpireDay(auxI);
                }
            }
        }
    }
    
    inFile.close();
    
    return *aux;
    
}

void FileManager::deletePet(Pet pet) {
    string fileName = pet.getName() + ".dat";
    const char * fileNamePet = fileName.c_str();
    string auxOwner, aux;

    ifstream inFilePet(fileNamePet, ios::in);

    if(!inFilePet.good())
    {
        return;
    }
    else
    {
        while (aux != pet.getOwner().getName() )
        {
            getline(inFilePet, auxOwner);
        }

        string fileNameC = auxOwner + ".dat";
        const char * fileNameCustomer = fileNameC.c_str();

        fstream inFileCustomer(fileNameCustomer, ios::out | ios::in);
        ofstream outFileCustomer("temp.dat", ios::out);

        if (!inFileCustomer.good())
        {
            throw "El archivo del cliente no existe";
        }
        else
        {
            while(!inFileCustomer.eof())
            {
                getline(inFileCustomer, aux);

                if (aux != pet.getName())
                {
                    outFileCustomer << aux << endl;
                }
            }

            remove(fileNameCustomer);
            rename("temp.dat", fileNameCustomer);
        }

        remove(fileNamePet);
    }

}

void FileManager::deleteCustomer(Customer customer) {
    string fileN = customer.getName() + ".dat";
    const char * fileName = fileN.c_str();
    string aux;

    ifstream inFile(fileName, ios::in);

    if (!inFile.good())
    {
        throw "No existe el archivo del cliente";
    }
    else
    {
        while(!inFile.eof())
        {
            getline(inFile, aux);
            if (aux == BEGIN_PET)
            {
                getline(inFile, aux);
                string file = aux + ".dat";
                const char * fileN = file.c_str();
                remove(fileN);
            }
        }
    }

    remove(fileName);
}

void FileManager::deleteTreatment(Pet pet, Treatment treatment) {
    string fileN = pet.getName(); + ".dat";
    const char * fileName = fileN.c_str();
    string aux1, aux2;
    bool found;

    ifstream inFile(fileName, ios::in);
    ofstream outFile("temp.dat", ios::out);

    if (!inFile.good() and !outFile.good())
    {
        throw "Error con los archivos";
    }
    else
    {
        while(!inFile.eof())
        {
            getline(inFile, aux1);

            if (aux1 == BEGIN_TREATMENT)
            {
                getline(inFile, aux2);
                if (aux2 == to_string(treatment.getId()))
                {
                    while(aux1 != END_TREATMENT)
                    {
                        getline(inFile, aux1);
                    }
                }
                else
                {
                    outFile << aux1 << endl;
                    outFile << aux2 << endl;
                }
            }
            else
            {
                outFile << aux1 << endl;
            }
        }
    }

    remove(fileName);
    rename("temp.dat", fileName);

}

void FileManager::deleteVaccine(Pet pet, Vaccine vaccine) {
    string fileN = pet.getName(); + ".dat";
    const char * fileName = fileN.c_str();
    string aux1, aux2;
    bool found;

    ifstream inFile(fileName, ios::in);
    ofstream outFile("temp.dat", ios::out);

    if (!inFile.good() or !outFile.good())
    {
        throw "Error con los archivos";
    }
    else
    {
        while(!inFile.eof())
        {
            getline(inFile, aux1);

            if (aux1 == BEGIN_VACCINE)
            {
                getline(inFile, aux2);
                if (aux2 == to_string(vaccine.getId()))
                {
                    while(aux1 != END_VACCINE)
                    {
                        getline(inFile, aux1);
                    }
                }
                else
                {
                    outFile << aux1 << endl;
                    outFile << aux2 << endl;
                }
            }
            else
            {
                outFile << aux1 << endl;
            }
        }
    }

    remove(fileName);
    rename("temp.dat", fileName);
}

void FileManager::updatePet(Pet prevPet, Pet pet) {
    string fileN = prevPet.getName() + ".dat";
    string fileN2 = pet.getName() + ".dat";
    const char * fileName = fileN.c_str();
    string aux;
    bool write = false;

    rename(fileName,"temp.dat");

    addPet(pet, pet.getOwner());

    ifstream inFile("temp.dat", ios::in);
    ofstream outFile(fileN2, ios::app);

    if (!inFile.good() or !outFile.good())
    {
        throw "Error con los archivos";
    }
    else
    {
        while(!inFile.eof())
        {
            getline(inFile, aux);

            if (aux == END_PET)
            {
                write = true;
            }

            if(write and aux != END_PET)
            {
                outFile << aux << endl;
            }
        }
    }

    string auxOwner, aux1;

    ifstream inFilePet("temp.dat", ios::in);

    if(!inFilePet.good())
    {
        return;
    }
    else
    {
        while (auxOwner != BEGIN_CUSTOMER )
        {
            getline(inFilePet, auxOwner);
        }

        getline(inFilePet, auxOwner);

        string fileNameC = auxOwner + ".dat";
        const char * fileNameCustomer = fileNameC.c_str();

        fstream inFileCustomer(fileNameCustomer, ios::out | ios::in);
        ofstream outFileCustomer("temp1.dat", ios::out);

        if (!inFileCustomer.good())
        {
            throw "El archivo del cliente no existe";
        }
        else
        {
            while(!inFileCustomer.eof())
            {
                getline(inFileCustomer, aux1);

                if (aux != pet.getName())
                {
                    outFileCustomer << aux1 << endl;
                }
            }

            remove(fileNameCustomer);
            rename("temp1.dat", fileNameCustomer);
        }

        remove("temp.dat");
    }

}

void FileManager::updateCustomer(Customer prevCustomer, Customer customer) {
    string fileN1 = prevCustomer.getName() + ".dat";
    string fileN2 = customer.getName() + ".dat";
    const char * fileName1 = fileN1.c_str();
    string aux;
    bool write = false;

    rename(fileName1, "temp.dat");

    addCustomer(customer);

    ifstream inFile("temp.dat", ios::in);
    ofstream outFile(fileN2, ios::app);

    if (!inFile.good() or !outFile.good())
    {
        throw "Error con los archivos";
    }
    else
    {
        while(!inFile.eof())
        {
            getline(inFile, aux);

            if (aux == END_CUSTOMER)
            {
                write = true;
            }

            if(write and aux != END_CUSTOMER)
            {
                outFile << aux << endl;
            }
        }
    }

    remove("temp.dat");
}

void FileManager::updateTreatment(Pet pet, Treatment prevTreatment, Treatment treatment) {
    deleteTreatment(pet, prevTreatment);
    addTreatment(treatment, pet);
}

void FileManager::updateVaccine(Pet pet, Vaccine prevVaccine, Vaccine vaccine) {
    deleteVaccine(pet, prevVaccine);
    addVaccine(vaccine, pet);
}
