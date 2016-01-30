#include <iostream>
#include <math.h>

using namespace std;

double g(double x){
    return (double)(((-3*pow(x,3)) - (4*pow(x,2)) - 1)/4);
}

int main(){
    double x0 = -0.5, x;
    int N=25, i=1;

    while(i < N)
    {
        x = g(x0);

        if((x-x0) < 0.00001){
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