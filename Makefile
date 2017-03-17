CC = g++

SRC = sources/
HDR = headers/
OBJ = objets/

all: matrice

matrice : $(OBJ)rotation.o
	$(CC) -o $@ $^
	
$(OBJ)rotation.o : $(SRC)rotation.cpp $(HDR)Matrice.hpp $(HDR)Vecteur.hpp
	$(CC) -o $@ -c $< -std=c++11 -I$(HDR)