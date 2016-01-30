#include <iostream>
#include <cmath>

using namespace std;

double f(double, double);
double composite_trapezoidal(double (*f)(double, double), double x0, double xn, double h, double y0, double yn, double k);

int main()
{
	double x0 = 0, xn = 1, h = 0.25, y0 = 1, yn = 2, k = 0.25;
	double ans = composite_trapezoidal(f, x0, xn, h, y0, yn, k);
	cout<<ans<<"\n";
}

double f(double x, double y)
{
	return ((2*x*y)/((1+x*x)*(1+y*y)));
}

double composite_trapezoidal(double (*f)(double, double), double x0, double xn, double h, double y0, double yn, double k)
{
	int n = (xn-x0)/h;
	int m = (yn-y0)/k;
	double ans = 0.0, cx, cy;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0||i==n)
				cx = 1;
			else
				cx = 2;
			if(j==0||j==m)
				cy = 1;
			else
				cy = 2;
			ans += cx*cy*f(x0+h*i, y0+j*k);
		}
	}
	ans *= (h*k)/4;
	return ans;
}

