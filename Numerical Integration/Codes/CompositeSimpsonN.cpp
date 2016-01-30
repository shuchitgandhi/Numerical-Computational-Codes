#include <iostream>
#include <cmath>

using namespace std;

double f(double *, int);
double composite_simpson(double (*f)(double*, int), double *x0, double *xn, double *h, int n);
int increment(int *, int *, int);

int main()
{

	int n = 2;
	double x0[] = {0, 0}, xn[] = {0.5, 0.5}, h[] = {0.25, 0.25};	
	double ans = composite_simpson(f, x0, xn, h, n);
	cout<<ans<<"\n";
}

double f(double *x, int n)
{
	double z = 1.0;
	for(int i=0;i<n;i++)
	{
		z *= x[i];
	}
	return sin(z);
}

double composite_simpson(double (*f)(double *, int), double *x0, double *xn, double *h, int n)
{
	int i, *N = new int[n], *w = new int[n], *c = new int[n], C;
	double *x = new double[n], ans = 0;
	for(i=0;i<n;i++)
	{
		N[i] = (xn[i] - x0[i])/h[i];
		w[i] = 0;
	}
	do
	{
	
		C = 1;
		for(i=0;i<n;i++)
		{
			if(w[i]==0||w[i]==n)
				c[i] = 1;
			else if(w[i]%2==0)
				c[i] = 2;
			else
				c[i] = 4;
			C *= c[i];
			x[i] = x0[i] + w[i]*h[i];
		}	
		ans += C * f(x, n);
		
	} while(increment(w, N, n)>=0);
	for(i=0;i<n;i++)
		ans *= (h[i]/3);
	return ans;
}

int increment(int *w, int *N, int n)
{
	int carry = 0, i;
	w[n-1]++;
	if(w[n-1]>N[n-1])
	{
		w[n-1] = 0;
		carry = 1;
	}
	for(i=n-2;i>=0;i--)
	{
		w[i] += carry;
		if(w[i] > N[i])
		{
			w[i] = 0;
			carry = 1;
		}
		else
			carry = 0;
	}
	if(i==-1 && w[0]==0 && carry==1)
		return -1;
	else
		return 0;
}

