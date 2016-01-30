#include <iostream>
#include <math.h>

using namespace std;

double g(double x){
    return (double)(((-3*pow(x,3)) - (4*pow(x,2)) - 1)/4);
}

double f(double x) {
    return (double)((3*pow(x,3)) + (4*pow(x,2)) + (4*x) + 1);
}

int main(){
    double x0 = -0.5, x;
    int N=25, i=1;

    while(i < N)
    {
        x = g(x0);

        if((fabs(f(x0)) + 5*fabs(x+x0)) < 0.00001){
          cout<<"\nSolution --> "<<x<<endl;
          break;
        }

        i=i+1;
        
        x0=x;
        
        if(i>N){
          cout<<"Solution not found !!";
          break;
        }
    }
    return 0;
}