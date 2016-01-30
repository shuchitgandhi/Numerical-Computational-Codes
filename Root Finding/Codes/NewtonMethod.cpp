#include <iostream>
#include <cmath>
#define MAXN 1000
using namespace std;

double f(double);
double fd(double);
double newton_method(double (*f)(double), double (*fd)(double), double, double);

int main(int argc, char const *argv[])
{
	cout<<"Cube root of 35 is : "<<newton_method(f, fd, 3, 0.00001)<<"\n";
	return 0;
}

double newton_method(double (*f)(double), double (*fd)(double), double x, double e)
{
	int i = 0;
	double xn = x, xn_1;
	do
	{
		xn_1 = xn;
		if(fd(xn)==0)
		{
			cout<<"Derivative reached zero.\n";
			break;
		}	
		xn = xn - f(xn)/fd(xn);
		i++;
	} while((fabs(xn-xn_1)>e || fabs(f(xn)) > e) && i<1000);
	cout<<"No. of iterations : "<<i<<"\n";
	return xn;
}

double f(double x)
{
	return x*x*x - 35;
}

double fd(double x)
{
	return 3*x*x;
}