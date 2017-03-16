class Matrix{

	private:

	public:
		float** matrix;
		int rows, cols;

		int allocateSize(int rows,int cols); 
		int fillMatrix(float []);
		int printMatrix();

		int getrows();
		int getcols();

		float get(int x,int y);
		int set(int x,int y, float val);

		//matrix transposition 
		Matrix transpose();

		//matrix addition
		Matrix add(Matrix m);
		
		//matrix addition
		Matrix substract(Matrix m);

		//matrix multiplication with a scalar
		Matrix scalarMul(float val);
		
		//ordinary matrix multiplication
		Matrix matrixMul(Matrix m);
		
		//Hadamard multiplication (component-wise multiplication)
		Matrix hadamardMul(Matrix m);
		
		//Kronecker multiplication
		Matrix kroneckerMul(Matrix m);

		//horizontal matrix concatenation
		Matrix horizontalConc(Matrix m);


		Matrix();
		~Matrix(void);
};