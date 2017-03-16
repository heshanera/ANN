class Matrix;

class ActivationFunction
{
	private:

	public:

		/****** activation functions *************************/

		// Unit step
		static float unitStep(float x);

		// Linear
		static float linear(float m, float c, float x);
		static Matrix linear(float m, float c, Matrix x);

		// Sigmoid
		static float sigmoid(float x);
		static Matrix sigmoid(Matrix m);

		// Piecewise Linear 

		// Gaussian

		/****** activation functions derivatives *************/

		// Sigmoid
		static float SigmoidDerivative(float x);
		static Matrix SigmoidDerivative(Matrix m);
};