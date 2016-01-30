#include <iostream>
#include <cmath>

using namespace std;

double f(double);
double modified_regula_falsi_method(double (*f)(double), double, double, double);

int main(int argc, char const *argv[])
{
	cout<<"Cube root of 35 is : "<<modified_regula_falsi_method(f, 0.0, 4.0, 0.00001)<<"\n";
	return 0;
}

double modified_regula_falsi_method(double (*f)(double), double a, double b, double e)
{
	int i = 0;
	if(f(a)==0)
		return a;
	if(f(b)==0)
		return b;
	if(f(a)*f(b) > 0)
		return INFINITY;
	double an = a, bn = b, wn, wn_1, F, G;
	F = f(an); G = f(bn); wn_1 = an;
	while(fabs(f(wn))>e || fabs(wn-wn_1)>e)
	{
		wn = (G*an - F*bn)/(G-F);
		if(F*f(wn)<=0)
		{
			bn = wn;
			G = f(wn);
			if(f(wn_1)*f(wn) > 0)
				F /= 2;
		}
		else
		{
			an = wn;
			F = f(wn);
			if(f(wn_1)*f(wn) > 0)
				G /= 2;
		}
		wn_1 = wn;
		i++;
	}
	cout<<"No. of iterations : "<<i<<"\n";
	return wn;
}

double f(double x)
{
	return x*x*x - 35;
}