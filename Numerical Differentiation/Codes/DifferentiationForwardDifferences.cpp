#include <iostream>
#include <fstream>

using namespace std;

double **forward_difference_table(double *, double *, int);
double forward_difference_differentiator(double *, double **, int, double);

int main(int argc, char const *argv[])
{
	int i, n;
	double *x, *f, **FD, input, ans, h;
	fstream	fin;
	fin.open("DifferentiationForwardDifferences.dat", ios::in);
	fin>>n;
	x = new double[n];
	f = new double[n];
	for(i=0;i<n;i++)
		fin>>x[i];
	for(i=0;i<n;i++)
		fin>>f[i];
	FD = forward_difference_table(x, f, n);
	h = x[1] - x[0];	// Assuming uniform 'h'
	ans = forward_difference_differentiator(x, FD, n, h);
	cout<<"Value of f'("<<x[0]<<") = "<<ans<<"\n";
	return 0;
}

double **forward_difference_table(double *x, double *f, int n)
{
	double **FD;
	int i, j;
	/* Allocate memory for forward differences table */
	FD = new double*[n];
	for(i=0;i<n;i++)
		FD[i] = new double[n];
	/* Insert first column as values of f(x) */
	for(i=0;i<n;i++)
		FD[i][0] = f[i];
	/* Create forward differences table */
	for(j=1;j<n;j++)
	{
		for(i=0;i<n-j;i++)
			FD[i][j] = FD[i+1][j-1] - FD[i][j-1];
	}
	return FD;
}

double forward_difference_differentiator(double *x, double **FD, int n, double h)
{
	int j;
	double ans = 0, sign = 1;
	for(j=1;j<n;j++, sign*=-1)
		ans += (sign*FD[0][j]/double(j));
	ans /= h;
	return ans;
}