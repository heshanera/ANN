Main: Matrix.o ActivationFunction.o Main.o Main.o
	g++ Matrix.o ActivationFunction.o Main.o -o Main

Matrix.o: Matrix.cpp
	g++ -c Matrix.cpp

ActivationFunction.o: ActivationFunction.cpp
	g++ -c ActivationFunction.cpp

Main.o: Main.cpp
	g++ -c Main.cpp	

clean: 
	rm *.o Main	
