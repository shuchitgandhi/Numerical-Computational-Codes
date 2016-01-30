#include <iostream>
#include <cmath>
#define MAXN 1000
using namespace std;

double f(double);
double fd(double);
double newton_method(double (*f)(double), double (*fd)(double), double, double);

int main(int argc, char const *argv[])
{
    double ans = newton_method(f, fd, 1.5, 0.00001);
	cout<<"Depth of the tank must be : "<<ans<<" m\n";
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
        cout<<"Relative Error at iteration "<<i<<" : "<<(fabs(xn-1.5677))/1.5677<<"\n";
	} while((fabs(xn-xn_1)>e || fabs(f(xn)) > e) && i<1000);
	return xn;
}

double f(double x)
{
	return (((22/7)*x*x*x*x) - (3*3*(22/7)*x*x*x) + (3*30));
}

double fd(double x)
{
	return ((4*(22/7)*x*x*x) - (9*3*(22/7)*x*x));
}