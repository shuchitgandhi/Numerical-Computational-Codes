#include <iostream>
#include <cmath>

using namespace std;

double f(double);
double regula_falsi_method(double (*f)(double), double, double, double);

int main(int argc, char const *argv[])
{
	cout<<"Root of cos(x)-(xe^x) is : "<<regula_falsi_method(f, 0.0, 1.0, 0.00001)<<"\n";
	return 0;
}

double regula_falsi_method(double (*f)(double), double a, double b, double e)
{
	int i = 0;
	if(f(a)==0)
		return a;
	if(f(b)==0)
		return b;
	if(f(a)*f(b) > 0)
		return INFINITY;
	double an = a, bn = b, wn, wn_1;
	wn = (f(bn)*an - f(an)*bn)/(f(bn)-f(an));
	while(fabs(f(wn))>e || fabs(wn-wn_1)>e)
	{
		if(f(an)*f(wn)<0)
			bn = wn;
		else if(f(bn)*f(wn)<0)
			an = wn;
		wn_1 = wn;
		wn = (f(bn)*an - f(an)*bn)/(f(bn)-f(an));
		i++;
	}
//	cout<<"No. of iterations : "<<i<<"\n";
	return wn;
}

double f(double x)
{
	return cos(x) - (x*exp(x));
}