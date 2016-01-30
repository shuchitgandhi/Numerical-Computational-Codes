#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void MatrixEquationSolver(double **, int, int);

int main()
{
	double **A, first;
	int i, j, k, rows, columns;
	fstream fin;
	fin.open("MatrixEquationSolver.dat", ios::in);
	/* Read matrix dimensions from file */
	fin>>rows>>columns;
	/* Allocate memory for matrix */
	A = new double*[rows];
	for(i = 0; i < rows; i++)
		A[i] = new double[columns];
	/* Read matrix from file */
	for(i=0;i<rows;i++)
			for(j=0;j<columns;j++)
				fin>>A[i][j];
	MatrixEquationSolver(A, rows, columns);
	/* Display all answers */
	for(i=0;i<rows;i++)
		cout<<"x"<<(i+1)<<" = "<<A[i][columns-1]<<"\n";
	return 0;				
}

void MatrixEquationSolver(double **A, int rows, int columns)
{
	int i, j, k;
	double first;
	for(i=0; i<rows;i++)
	{
		/* Set first to diagonal element of row */
		first = A[i][i];
		/* If first element is zero, exchange with row containing non-zero element in the same column */
		if(first==0)
	 	{
	 		bool success = false;
	 		/* Search for elements in rows below ith row */
	 		for(j=i+1;j<rows && !success;j++)
	 		{
	 			if(A[j][i]!=0)
	 			{
	 				double *temp = A[j];
	 				A[j] = A[i];
	 				A[i] = temp;
	 				success = true;
	 				break;
	 			}
	 		}
	 		/* If no non-zero element found in the column, exit */
	 		if(!success)
	 		{
	 			cout<<"Equations do not have consistent solution. Exiting.\n";
	 			return;
	 		}	
	 	}
	 	/* Reset first to diagonal element of row */
	 	first = A[i][i];
	 	/* Divide entire row with the first element making the diagonal element 1 */
		for(j=i;j<columns;j++)
			A[i][j] /= first;
		/* Make all elements below diagonal element to be 0 */
		for(j=i+1;j<rows;j++)
		{
			first = A[j][i];
			for(k=i;k<columns;k++)
				A[j][k] -= first*A[i][k];
		}
	}
	/* Perform back substitution */
	for(i=rows-2; i>=0;i--)
		for(j=columns-2;j>i;j--)
			A[i][columns-1] -= A[i][j]*A[j][columns-1];
	return;
}