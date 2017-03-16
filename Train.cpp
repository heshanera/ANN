#include <iostream>
#include <fstream>

#include "Matrix.h"
#include "ActivationFunction.h"

int main()
{
	
	// input matrix --> { {0,0}, {0,1}, {1,0}, {1,1} }
	// weight matrix1 --> { {w1,w2,w3,w4}, {w5,w6,w7,w8}}
	// weight matrix2 --> { {w9}, {w10}, {w11}, {w12}}
	
	Matrix	inputMatrix, weightMatrix1, weightMatrix2, tmpWeightMatrix, hiddenLayerMatrix, transfhiddenMatrix, resultMatrix, 
			transfresultMatrix, targetMatrix, errorMarginMatrix, deltaMatrix3, deltaWeightMatrix3, deltaMatrix2, deltaWeightMatrix2;

	// data for target matrix
	float data0[4] = {0,1,1,0};		
	// data for input matrix		
	float data1[8] = {0,0,0,1,1,0,1,1};
	// data for weight matrix1 (initial weights)
	float data2[8] = {0.1,0.4,0.2,0.3,0.8,0.7,0.1,0.5};
	// data for weight matrix2 (initial weights)
	float data3[4] = {0.2,0.7,0.4,0.1};

	targetMatrix.allocateSize(4,1);
	targetMatrix.fillMatrix(data0);	

	inputMatrix.allocateSize(4,2);
	inputMatrix.fillMatrix(data1);

	weightMatrix1.allocateSize(2,4);	
	weightMatrix1.fillMatrix(data2);

	weightMatrix2.allocateSize(4,1);	
	weightMatrix2.fillMatrix(data3);
	//weightMatrix2.printMatrix();

	int n = 0;

	while(n < 500)
	{	

		/******************* forward propogation ***********************************/ 

		hiddenLayerMatrix = inputMatrix.matrixMul(weightMatrix1);
		//hiddenLayerMatrix.printMatrix();

		transfhiddenMatrix = ActivationFunction::sigmoid(hiddenLayerMatrix);
		//transfhiddenMatrix.printMatrix();

		resultMatrix = transfhiddenMatrix.matrixMul(weightMatrix2);
		//resultMatrix.printMatrix();
		transfresultMatrix = ActivationFunction::sigmoid(resultMatrix);
		//transfresultMatrix.printMatrix();

		/****************** back propagation ***************************************/

		errorMarginMatrix = targetMatrix.substract(transfresultMatrix);
		//errorMarginMatrix.printMatrix();
		deltaMatrix3 = ActivationFunction::SigmoidDerivative(resultMatrix).hadamardMul(errorMarginMatrix);
		//deltaMatrix3.printMatrix();

		/** new values for weight matrix2 **/
		deltaWeightMatrix3 = transfhiddenMatrix.transpose().matrixMul(deltaMatrix3);
		tmpWeightMatrix = weightMatrix2;
		weightMatrix2 = weightMatrix2.add(deltaWeightMatrix3);
		//weightMatrix2.printMatrix();

		/** new values for weight matrix1 **/
		deltaMatrix2 = deltaMatrix3.kroneckerMul(weightMatrix2.transpose()).hadamardMul(ActivationFunction::SigmoidDerivative(hiddenLayerMatrix));
		deltaWeightMatrix2 = inputMatrix.transpose().matrixMul(deltaMatrix2);
		weightMatrix1 = weightMatrix1.add(deltaWeightMatrix2);
		//weightMatrix1.printMatrix();	

		n++;

	}	

	/************** Writing the weights to the file ******************************/

	std::ofstream dataFile;
  	dataFile.open ("weights");

  	dataFile <<"matrix1: ";

  	int rows = weightMatrix1.getrows();
	int cols = weightMatrix1.getcols();
	for (int i = 0; i < rows; i++)
    {	
        for (int j = 0; j < cols; j++)
	    {	
	        float weight = weightMatrix1.get(i,j);
	        dataFile <<weight<<" ";
	    }    
	}	
	dataFile <<"\n";
	dataFile <<"matrix2: ";
	rows = weightMatrix2.getrows();
	cols = weightMatrix2.getcols();
	for (int i = 0; i < rows; i++)
    {	
        for (int j = 0; j < cols; j++)
	    {	
	        float weight = weightMatrix2.get(i,j);
	        dataFile <<weight<<" ";
	    }    
	    //dataFile <<"\n";
	}	
	dataFile <<"\n";
  	dataFile.close();

	  	
	//weightMatrix1.printMatrix();	
	//weightMatrix2.printMatrix();
	
	/*
	hiddenLayerMatrix = inputMatrix.matrixMul(weightMatrix1);
	transfhiddenMatrix = ActivationFunction::sigmoid(hiddenLayerMatrix);
	resultMatrix = transfhiddenMatrix.matrixMul(weightMatrix2);

	targetMatrix.printMatrix();
	resultMatrix.printMatrix();
	*/

	return 0;
}	