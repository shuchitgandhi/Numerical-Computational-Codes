#include <iostream>
#include <fstream>

using namespace std;

double **backward_difference_table(double *, double *, int);
double backward_difference_differentiator(double *, double **, int, double);

int main(int argc, char const *argv[])
{
	int i, n;
	double *x, *f, **BD, input, ans, h;
	fstream	fin;
	fin.open("DifferentiationBackwardDifferences.dat", ios::in);
	fin>>n;
	x = new double[n];
	f = new double[n];
	for(i=0;i<n;i++)
		fin>>x[i];
	for(i=0;i<n;i++)
		fin>>f[i];
	BD = backward_difference_table(x, f, n);
	h = x[1] - x[0];	// Assuming uniform 'h'
	ans = backward_difference_differentiator(x, BD, n, h);
	cout<<"Value of f'("<<x[n-1]<<") = "<<ans<<"\n";
	return 0;
}

double **backward_difference_table(double *x, double *f, int n)
{
	double **BD;
	int i, j;
	/* Allocate memory for backward differences table */
	BD = new double*[n];
	for(i=0;i<n;i++)
		BD[i] = new double[n];
	/* Insert first column as values of f(x) */
	for(i=0;i<n;i++)
		BD[i][0] = f[i];
	/* Create backward differences table */
	for(j=1;j<n;j++)
	{
		for(i=n-1;i>=j;i--)
			BD[i][j] = BD[i][j-1] - BD[i-1][j-1];
	}
	return BD;
}

double backward_difference_differentiator(double *x, double **BD, int n, double h)
{
	int j;
	double ans = 0;
	for(j=1;j<n;j++)
		ans += (BD[n-1][j]/double(j));
	ans /= h;
	return ans;
}