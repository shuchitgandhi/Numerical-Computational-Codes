#include <iostream>
#include <fstream>

using namespace std;

double **divided_difference_table(double *, double *, int);
double divided_difference_interpolator(double *, double **, int, double);

int main(int argc, char const *argv[])
{
	int i, n;
	double *x, *f, **DD, input, ans;
	fstream	fin;
	fin.open("q2_a.dat", ios::in);
	fin>>n;
	x = new double[n];
	f = new double[n];
	for(i=0;i<n;i++)
		fin>>x[i];
	for(i=0;i<n;i++)
		fin>>f[i];
	DD = divided_difference_table(x, f, n);
	cout<<"Enter any value between ["<<x[0]<<", "<<x[n-1]<<"] : ";
	cin>>input;
	ans = divided_difference_interpolator(x, DD, n, input);
	cout<<"The interpolated value for x="<<input<<" is "<<ans<<"\n";
	return 0;
}

double **divided_difference_table(double *x, double *f, int n)
{
	double **DD;
	int i, j;
	/* Allocate memory for forward differences table */
	DD = new double*[n];
	for(i=0;i<n;i++)
		DD[i] = new double[n];
	/* Insert first column as values of f(x) */
	for(i=0;i<n;i++)
		DD[i][0] = f[i];
	/* Create forward differences table */
	for(j=1;j<n;j++)
	{
		for(i=0;i<n-j;i++)
			DD[i][j] = (DD[i+1][j-1] - DD[i][j-1])/(x[i+j] - x[i]);
	}
	return DD;
}

double divided_difference_interpolator(double *x, double **DD, int n, double input)
{
	int i, j;
	double ans = 0, term;
	for(i=0;i<n;i++)
	{
		term = DD[0][i];
		for(j=0;j<i;j++)
			term *= (input - x[j]);
		ans += term;
	}
	return ans;
}