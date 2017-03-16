#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Matrix.h"
#include "ActivationFunction.h"

int main()
{
	

	// input matrix --> { {0,0}, {0,1}, {1,0}, {1,1} }
	// weight matrix1 --> { {w1,w2,w3,w4}, {w5,w6,w7,w8}}
	// weight matrix2 --> { {w9}, {w10}, {w11}, {w12}}
	
	Matrix	inputMatrix, weightMatrix1, weightMatrix2, hiddenLayerMatrix, transfhiddenMatrix, resultMatrix;
	
	// data for input matrix		
	float data1[8] = {0,0,0,1,1,0,1,1};
	// weight matrix1
	float data2[8];
	// weight matrix2
	float data3[4];

	inputMatrix.allocateSize(4,2);
	inputMatrix.fillMatrix(data1);

	/******* reading the weights ***************************************/

	std::string line;
	std::ifstream datafile ("weights");
	if (datafile.is_open())
	{
		while ( getline (datafile,line) )
		{
			//std::cout << line << '\n';
			std::istringstream in(line);
			std::string matrix;
		    in >> matrix;                  

		    int tmpindx = 0;
		    if(matrix == "matrix1:") {

		    	while (tmpindx < 8 )
		    	{
		    		float weight;
		    		in >> weight;
		    		data2[tmpindx] = weight;
		    		tmpindx++;
		    	}	

		    } else if(matrix == "matrix2:") {

		    	while (tmpindx < 4 )
		    	{
		    		float weight;
		    		in >> weight;
		    		data3[tmpindx%4] = weight;
		    		tmpindx++;
		    	}	

		    } 
		}
		datafile.close();
	}

	else std::cout << "Unable to load the data file";

	weightMatrix1.allocateSize(2,4);	
	weightMatrix2.allocateSize(4,1);	
	weightMatrix1.fillMatrix(data2);
	weightMatrix2.fillMatrix(data3);
	//weightMatrix2.printMatrix();
	

	std::cout<<"Input: \n";
	inputMatrix.printMatrix();

	//weightMatrix1.printMatrix();	
	//weightMatrix2.printMatrix();

	std::cout<<"Output: \n";

	hiddenLayerMatrix = inputMatrix.matrixMul(weightMatrix1);
	transfhiddenMatrix = ActivationFunction::sigmoid(hiddenLayerMatrix);
	resultMatrix = transfhiddenMatrix.matrixMul(weightMatrix2);

	//resultMatrix.printMatrix();

	/******* printing the results *******************************************/

	int rows = resultMatrix.getrows();
	int cols = resultMatrix.getcols();
	for (int i = 0; i < rows; i++)
    {	
        for (int j = 0; j < cols; j++)
	    {	
	        float weightedSum = resultMatrix.get(i,j);
	        if (weightedSum < 0) std::cout<<0<<"\n";
	        else std::cout<<1<<"\n";
	    }    
	}	

	return 0;

}	