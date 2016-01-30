#include <iostream>
#include <cmath>

using namespace std;

double f(double, double, double);
double composite_trapezoidal_triple(double (*f)(double, double, double), double, double, double, double, double, double, double, double, double);

int main()
{
	double x0 = 0, xn = 1, p = 0.25, y0 = 1, yn = 2, q = 0.25, z0 = 2, zn = 3, r = 0.25;
	double ans = composite_trapezoidal_triple(f, x0, xn, p, y0, yn, q, z0, zn, r);
	cout<<ans<<"\n";
}

double f(double x, double y, double z)
{
	return ((2*x*y*z)/((1+x*x)*(1+y*y)*(1+z*z)));
}

double composite_trapezoidal_triple(double (*f)(double, double, double), double x0, double xn, double p, double y0, double yn, double q, double z0, double zn, double r)
{
	int n = (xn-x0)/p;
	int m = (yn-y0)/q;
	int o = (zn-z0)/r;
	double ans = 0.0, cx, cy, cz;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=o;k++)
			{
				if(i==0||i==n)
					cx = 1;
				else
					cx = 2;
				if(j==0||j==m)
					cy = 1;
				else
					cy = 2;
				if(k==0||k==o)
					cz = 1;
				else
					cz = 2;
				ans += cx*cy*cz*f(x0+p*i, y0+q*j, z0+r*k);
			}
		}
	}
	ans *= (p*q*r)/8;
	return ans;
}

