all: Main Train

Main: Matrix.o ActivationFunction.o Main.o
	g++ Matrix.o ActivationFunction.o Main.o -o Main

Train: Matrix.o ActivationFunction.o Train.o
	g++ Matrix.o ActivationFunction.o Train.o -o Train	

Matrix.o: Matrix.cpp
	g++ -c Matrix.cpp

ActivationFunction.o: ActivationFunction.cpp
	g++ -c ActivationFunction.cpp

Main.o: Train.cpp
	g++ -c Train.cpp	

Main.o: Main.cpp
	g++ -c Main.cpp	

clean: 
	rm *.o	
