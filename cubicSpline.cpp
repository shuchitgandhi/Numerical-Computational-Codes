/*
*LAB-6
* Constructing cubic spline using the alternative method. Calculating M0, M1, ... M5 only.
* Construct f(x) using these Ms and find f(2.5).
*/
#include <iostream>
#include <cmath>
using namespace std;
int x[6]={1,2,3,5,7,8};
double A[5][6];
double M[6];
double B[5];
double f(int x)
{
	double result;
	switch(x)
	{
		case 1: result=3.0;
			break;
		case 2: result=6.0;
			break;
		case 3: result=19.0;
			break;
		case 5: result=99.0;
			break;
		case 7: result=291.0;
			break;
		case 8: result=444.0;
			break;
	}
	return result;
}
double h(int i)
{
	return (double)(x[i]-x[i-1]);
}
void findA()
{
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(j==i)
				A[i][j]=(h(i)/2)+(h(i+1)/3);
			else if(j==(i+1))
				A[i][j]=h(i+1)/6;
			else
				A[i][j]=0;			
		}
	}
}

void findB()
{
	for(int i=0;i<5;i++)
		B[i]=  ((f(x[i+1])-f(x[i]) )/h(i+1)) - ((f(x[i])-f(x[i-1]) )/h(i)); 
}

int main()
{
	findA(); 
	findB();
	M[0]=M[5]=0;

	M[1]=B[0]/A[0][1];
	M[4]=B[4]/A[4][4];

	M[2]=(B[1]-A[1][1]*M[1])/A[1][2];
	M[3]=(B[2]-A[2][2]*M[2])/A[2][3];

	for(int i=0;i<6;i++)
		cout<<"M"<<i<<": "<<M[i]<<"\n";
		
	return 0;
}
