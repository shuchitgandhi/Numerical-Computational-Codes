#include <iostream>
#include <cmath>

using namespace std;

double f(double);
double bisection_method(double (*f)(double), double, double, double);

int main(int argc, char const *argv[])
{
	cout<<"Cube root of 35 is : "<<bisection_method(f, 0.0, 4.0, 0.00001)<<"\n";
	return 0;
}

double bisection_method(double (*f)(double), double a, double b, double e)
{
	int i = 0;
	if(f(a)==0)
		return a;
	if(f(b)==0)
		return b;
	if(f(a)*f(b) > 0)
		return INFINITY;
	double an = a, bn = b, mn = (a+b)/2.0, mn_1;
	while(fabs(f(mn))>e || fabs(mn-mn_1)>e)
	{
		if(f(an)*f(mn)<0)
			bn = mn;
		else if(f(bn)*f(mn)<0)
			an = mn;
		mn_1 = mn;
		mn = (an+bn)/2.0;
		i++;
	}
	cout<<"No. of iterations : "<<i<<"\n";
	return mn;
}

double f(double x)
{
	return x*x*x - 35;
}