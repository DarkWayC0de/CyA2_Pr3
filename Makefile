CC=g++
CXXFLAGS=-g -std=c++17
ODIR=src
BUILD=build

_OBJ=$(BUILD)/Calculadora.o $(BUILD)/Lenguaje.o
OBJ=$(patsubst %,%,$(_OBJ))

all:Calculadora
$(BUILD)/Calculadora.o: $(ODIR)/Calculadora.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/Lenguaje.o: $(ODIR)/Lenguaje.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

Calculadora: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) -lm

.PHONY:clean

clean:
	rm -rf build/* Calculadora

