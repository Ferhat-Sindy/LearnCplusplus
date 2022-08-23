#include <iostream>
#include <cmath>

double Mean(int n, double* x)
{
    double mean;
    for (int i = 0; i < n; i++)
    {
        mean += x[i];
    }  

    mean /= n;

    return mean;
}

double StandardDeviation(int n, double* x)
{
    double sigma;
    double x_bar = Mean(n,x);

    for (int i = 0; i < n; i++)
    {
        sigma += pow(x[i] - x_bar,2);
    }
    
    return sqrt(sigma/(double(n)-1.0));
}

int main(int argc, char* argv[])
{   
    int n = 5;
    double* x = new double [n];

    x[0] = 1, x[1] = 2, x[2] = 3, x[3] = 4, x[4] = 5;
    
    std::cout<<Mean(n,x)<<"\n";
    std::cout<<StandardDeviation(n,x)<<"\n";

    delete[] x; 
    
    return 0;
}