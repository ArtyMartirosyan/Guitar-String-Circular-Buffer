CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic  
OBJ = CircularBuffer.o StringSound.o KSGuitarSim.o
DEPS = CircularBuffer.cpp CircularBuffer.h StringSound.cpp KSGuitarSim.cpp
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lboost_unit_test_framework -lsfml-audio
EXE = KSGuitarSim

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS)  -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)
