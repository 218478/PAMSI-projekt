CXXFLAGS = -Iinc -Wall -pedantic -g -std=c++11
CC = g++
FILEPATH = ../dataset/letter.data

SOURCES = src/main.cpp src/Reader.cpp src/Letter.cpp src/NeuralNetwork.cpp

HEADERS = inc/Reader.h inc/Letter.h inc/NeuralNetwork.h

OBJECTS = $(subst src/,obj/,$(subst .cpp,.o,$(SOURCES)))
EXECUTABLE = program

__start__: $(EXECUTABLE)
				./$(EXECUTABLE) $(FILEPATH)

all: executable

obj:
				mkdir obj

executable: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
				$(CC) $(OBJECTS) -o $@

obj/%.o: src/%.cpp $(HEADERS) obj
				$(CC) $(CXXFLAGS) -c -o $@ $<

clean:
				rm -rf $(OBJECTS) $(EXECUTABLE) unit_test

test: unit_test
				./unit_test

unit_test: src/unit_test.cpp inc/catch.hpp $(HEADERS)
				$(CC) $(CXXFLAGS) -o unit_test src/unit_test.cpp

order:
				rm -f src/*~ inc/*~ *~ src/#* inc/#*

help:
				@echo
				@echo "\tmake\t\t- tworzenie i uruchomienie aplikacji"
				@echo "\tmake test\t- przeprowadza testy jednostkowe aplikacji"
				@echo "\tmake clean\t- usuniecie produktow kompilacji i konsolidacji"
				@echo "\tmake order\t- usuwa zbedne pliki tymczasowe z koncowka \"~\""
				@echo "\tmake help\t- wyswietla niniejsza informacje"
				@echo
