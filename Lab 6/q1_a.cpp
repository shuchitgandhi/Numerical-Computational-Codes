#include <iostream>
#include <fstream>

using namespace std;

double **forward_difference_table(double *, double *, int);
double forward_difference_interpolator(double *, double **, int, double, double);

int main(int argc, char const *argv[])
{
	int i, n;
	double *x, *f, **FD, input, ans, h;
	fstream	fin;
	fin.open("q1_a.dat", ios::in);
	fin>>n;
	x = new double[n];
	f = new double[n];
	for(i=0;i<n;i++)
		fin>>x[i];
	for(i=0;i<n;i++)
		fin>>f[i];
	FD = forward_difference_table(x, f, n);
	h = x[1] - x[0];	// Assuming uniform 'h'
	cout<<"Enter any value between ["<<x[0]<<", "<<x[n-1]<<"] : ";
	cin>>input;
	ans = forward_difference_interpolator(x, FD, n, h, input);
	cout<<"The interpolated value for x="<<input<<" is "<<ans<<"\n";
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

double forward_difference_interpolator(double *x, double **FD, int n, double h, double input)
{
	int i, j;
	double ans = 0, term;
	for(i=0;i<n;i++)
	{
		term = FD[0][i];
		for(j=0;j<i;j++)
			term *= ((input - x[j])/(h*(j+1)));
		ans += term;
	}
	return ans;
}