ifeq ($(OS),Windows_NT)
	EXECUTABLE=bin/ActividadIntegradora.exe
else
	EXECUTABLE=bin/ActividadIntegradora.out
endif

CC=g++
CFLAGS=-c -Wall -std=c++11
SOURCES=main.cpp src/customer.cpp src/pet.cpp src/treatment.cpp src/vaccine.cpp src/fileManager.cpp src/Arbolista.cpp src/listDesencripta.cpp
OBJECTS=$(SOURCES:.cpp=.o)


all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean: 
	$(RM) $(EXECUTABLE)
	$(RM) $(OBJECTS)
	$(RM) *.dat