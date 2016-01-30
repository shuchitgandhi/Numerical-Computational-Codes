#include <iostream>
#include <cmath>

using namespace std;

double f(double, double);
double composite_simpson(double (*f)(double, double), double x0, double xn, double h, double y0, double yn, double k);

int main()
{
	double x0 = 0, xn = 0.5, h = 0.25, y0 = 0, yn = 0.5, k = 0.25;
	double ans = composite_simpson(f, x0, xn, h, y0, yn, k);
	cout<<ans<<"\n";
}

double f(double x, double y)
{
	return (sin(x*y)/(1+x*y));
}

double composite_simpson(double (*f)(double, double), double x0, double xn, double h, double y0, double yn, double k)
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
			else if(i%2==0)
				cx = 2;
			else
				cx = 4;
			if(j==0||j==m)
				cy = 1;
			else if(j%2==0)
				cy = 2;
			else
				cy = 4;
			ans += cx * cy * f(x0+h*i, y0+j*k);
		}
	}
	ans *= (h*k)/9;
	return ans;
}

