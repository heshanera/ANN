#include <iostream>
#include <cmath>

#include "Matrix.h"
#include "ActivationFunction.h"

const float EulerConstant = std::exp(1.0);

float ActivationFunction::unitStep(float x)
{
	if ( x < 0 ) return 0;
	else return 1;	
}

/************************ linear ****************************/

float ActivationFunction::linear(float m, float c, float x)
{
	return ((m*x)+c);
}

Matrix ActivationFunction::linear(float m, float c, Matrix m1)
{	
	int rows = m1.getrows();
	int cols = m1.getcols();
	
	int size = rows * cols;
	float* tmpdata;
	tmpdata = new float[size];

	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			tmpdata[k] = ((m*(m1.get(i,j)))+c); k++;
		}	
	}	

	Matrix m2;
	m2.allocateSize(rows,cols);
	m2.fillMatrix(tmpdata);
	return m2;
}

/******************** sigmoid function **********************/

float ActivationFunction::sigmoid(float x)
{	
	return 1/(1 + pow (EulerConstant, -x));
}

Matrix ActivationFunction::sigmoid(Matrix m)
{	
	int rows = m.getrows();
	int cols = m.getcols();
	
	int size = rows * cols;
	float* tmpdata;
	tmpdata = new float[size];

	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			tmpdata[k] = sigmoid(m.get(i,j)); 
			k++;
		}	
	}	

	Matrix m2;
	m2.allocateSize(rows,cols);
	m2.fillMatrix(tmpdata);
	return m2;
}

float ActivationFunction::SigmoidDerivative(float x)
{	
	return (sigmoid(x))*(1-sigmoid(x));
}

Matrix ActivationFunction::SigmoidDerivative(Matrix m)
{	
	int rows = m.getrows();
	int cols = m.getcols();
	
	int size = rows * cols;
	float* tmpdata;
	tmpdata = new float[size];

	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			float x = m.get(i,j);
			tmpdata[k] = (sigmoid(x))*(1-sigmoid(x)); 
			k++;
		}	
	}	

	Matrix m2;
	m2.allocateSize(rows,cols);
	m2.fillMatrix(tmpdata);
	return m2;
}

/***********************************************************/