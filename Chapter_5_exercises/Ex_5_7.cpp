#include <cmath>
#include <iostream>

double CalculateNorm(double* x, int s, int p = 2)
{
    double a = 0.0;
    for (int i=0; i<s; i++)
    {
        double temp = fabs(x[i]);
        a += pow(temp, p);
    }
    return pow(a, 1.0/p);
}

int main(int argc, char* argv[])
{
    int n = 4;
    double* x = new double [10];
    for (int i = 0; i < n; i++)
    {
        x[i] = i;
    }
    
    std::cout<<"The 2-norm of x = "<<CalculateNorm(x,n)<<"\n";
    delete[] x;
}