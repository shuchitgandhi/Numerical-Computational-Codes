#include <iostream>
#include <cmath>
#define MAXN 1000
using namespace std;

double f(double);
double fd(double);
double newton_method(double (*f)(double), double (*fd)(double), double, double);

int main(int argc, char const *argv[])
{
    double ans = newton_method(f, fd, 0, 0.00001);
	cout<<"Root of (1 - exp(-x*x)) : "<<ans<<"\n";
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
//			cout<<"Derivative reached zero.\n";
			break;
		}	
		xn = xn - f(xn)/fd(xn);
		i++;
        cout<<"Rn at iteration "<<i<<" : "<<(0-xn)/((0-xn_1)*(0-xn_1))<<"\n";
	} while((fabs(xn-xn_1)>e || fabs(f(xn)) > e) && i<1000);
	return xn;
}

double f(double x)
{
	return (1 - exp(-x*x));
}

double fd(double x)
{
	return 2*x*exp(-x*x);
}