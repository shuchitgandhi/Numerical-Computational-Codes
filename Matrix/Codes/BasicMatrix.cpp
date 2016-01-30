#include <iostream>
#include <fstream>

using namespace std;

void add(double **, int, int, double **, int, int, double **, int, int);
void subtract(double **, int, int, double **, int, int, double **, int, int);
void multiply(double **, int, int, double **, int, int, double **, int, int);
void display(double **, int, int);

int main(int argc, char const *argv[])
{
	double **A, **B, **C;
	int an, bn, cn, am, bm, cm;
	fstream fin;
	fin.open("BasicMatrix.dat", ios::in);

	/* Read dimensions */
	fin>>am>>an;
	/* Allocate memory */
	A = new double*[an];
	for(int i = 0;i<an;i++)
		A[i] = new double[am];
	/* Read values */
	for(int i=0;i<an;i++)
		for(int j = 0;j<am;j++)
			fin>>A[i][j];
	/* Read dimensions */	
	fin>>bn>>bm;
	/* Allocate memory */
	B = new double*[bn];
	for(int i = 0;i<bn;i++)
		B[i] = new double[bm];
	/* Read values */
	for(int i=0;i<an;i++)
		for(int j = 0;j<am;j++)
			fin>>B[i][j];
	/* Read dimensions */
	fin>>cn>>cm;
	/* Allocate memory */
	C = new double*[cn];
	for(int i = 0;i<cn;i++)
		C[i] = new double[cm];
	/* Perform functions*/
	add(C, cm, cn, A, am, an, B, bm, bn);
	cout<<"\nC = A + B\n";
	display(C, cm, cn);
	cout<<"\nC = A - B\n";
	subtract(C, cm, cn, A, am, an, B, bm, bn);
	display(C, cm, cn);
	cout<<"\nC = A * B\n";
	multiply(C, cm, cn, A, am, an, B, bm, bn);
	display(C, cm, cn);
	return 0;
}

void add(double **C, int cm, int cn, double **A, int am, int an, double **B, int bm, int bn)
{
	if(am!=bm || am!=cm || bm!=cm || an!=bn || an!=cn || bn!=cn)
	{
		cout<<"Matrix dimensions do not agree. Exiting.\n";
		return;
	}
	for(int i=0;i<am;i++)
	{
		for(int j=0;j<an;j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	return;
}

void subtract(double **C, int cm, int cn, double **A, int am, int an, double **B, int bm, int bn)
{
	if(am!=bm || am!=cm || bm!=cm || an!=bn || an!=cn || bn!=cn)
	{
		cout<<"Matrix dimensions do not agree. Exiting.\n";
		return;
	}
	for(int i=0;i<am;i++)
	{
		for(int j=0;j<an;j++)
		{
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	return;
}

void multiply(double **C, int cm, int cn, double **A, int am, int an, double **B, int bm, int bn)
{
	if(an != bm || am != cm || bn!=cn)
	{
		cout<<"Matrix dimensions do not agree. Exiting.\n";
		return;
	}
	for(int i=0;i<am;i++)
	{
		for(int j=0;j<bn;j++)
		{
			C[i][j] = 0;
			for(int k=0;k<an;k++)
				C[i][j] += (A[i][k] * B[k][j]);
		}
	}
	return;
}

void display(double **A, int am, int an)
{
	for(int i=0;i<am;i++)
	{
		for(int j=0;j<an;j++)
		{
			cout<<A[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
