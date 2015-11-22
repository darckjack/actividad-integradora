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
        outFilePet << custome.getName() << endl;
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

void FileManager::readCustomer(Customer customer) {
    // Creo que podemos cambiar esto para mejorar un poco el acceso a los achivos
    /*
    Customer aux;
    string fileName = customer + ".dat";
    
    ifstream inFile(fileName, ios::in);
    
    if (!inFile.good()) 
    {
        throw "El archivo no existe";
    }
    else
    {
        
    }
    */
}

void FileManager::readPet(Pet) {
    // lo mismo que el metodo anterior
}

void FileManager::deletePet(Pet pet) {
    string fileNamePet = pet.getName() + ".dat";
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
            getline(inFile, auxOwner);
        }
        
        string fileNameCustomer = auxOwner + ".dat";
        
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
    string fileName = customer.getName() + ".dat";
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
                
                remove(aux + ".dat");
            }
        }
    }
    
    remove(fileName);
}

void FileManager::deleteTreatment(Pet pet, Treatment treatment) {
    string fileName = pet.getName(); + ".dat";
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
                if (aux2 == treatment.getId())
                {
                    while(aux1 =! END_TREATMENT)
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
    rename("temp.dat");
    
}

void FileManager::deleteVaccine(Pet pet, Vaccine vaccine) {
    string fileName = pet.getName(); + ".dat";
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
                if (aux2 == vaccine.getId())
                {
                    while(aux1 =! END_VACCINE)
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
    string fileName = pet.getName() + ".dat";
    string aux;
    bool write = false;
    
    rename(fileName,"temp.dat");
    
    addPet(pet, pet.getOwner());
    
    ifstream inFile("temp.dat", ios::in);
    ofstream outFile(fileName, ios::app);
    
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

    string auxOwner, aux;
    
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
        
        string fileNameCustomer = auxOwner + ".dat";
        
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
                getline(inFileCustomer, aux);
                
                if (aux != pet.getName())
                {
                    outFileCustomer << aux << endl; 
                }
            }
            
            remove(fileNameCustomer);
            rename("temp1.dat", fileNameCustomer);
        }
        
        remove("temp.dat");
    }
    
}

void FileManager::updateCustomer(Customer customer) {
    string fileName1 = customer.getName() + ".dat";
    string aux;
    bool write = false;
    
    addCustomer(customer);
    
    ifstream inFile(fileName1, ios::in);
    ofstream outFile("temp.dat", ios::app);
    
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
    
    deletePet(prevPet);
    
    rename("temp.dat", fileName2);
}

void FileManager::updateTreatment(Pet pet, Treatment prevTreatment, Treatment treatment) {
    deleteTreatment(pet, prevTreatment);
    addTreatment(treatment, pet);
}

void FileManager::updateVaccine(Pet pet, Vaccine prevVaccine, Vaccine vaccine) {
    deleteVaccine(pet, vaccine);
    addVaccine(vaccine);
}