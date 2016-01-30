#include <iostream>
#include <cmath>
#define MAXN 1000
using namespace std;

double f(double);
double secant_method(double (*f)(double), double, double, double);

int main(int argc, char const *argv[])
{
	cout<<"Root of xlog(x)-1.5 is : "<<secant_method(f, 1.0, 3.0, 0.00001)<<"\n";
	return 0;
}

double secant_method(double (*f)(double), double x_1, double x0, double e)
{
	int i = 0;
	double xn, xn_1;
	xn = x0; xn_1 = x_1;
	while(fabs(xn-xn_1)>e && i<1000)
	{
		double temp = xn;
		xn = xn - f(xn)*((xn-xn_1)/(f(xn)-f(xn_1)));
		xn_1 = temp;
		i++;
	}
//	cout<<"No. of iterations : "<<i<<"\n";
	return xn;
}

double f(double x)
{
	return (x*log(x)) - 1.5;
}