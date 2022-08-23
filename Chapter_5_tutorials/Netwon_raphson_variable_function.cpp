#include <iostream>
#include <cmath>

double SolveNewton(double (*pFunc)(double),
                   double (*pFuncprime)(double),
                   double x)
{
    double step;
    do
    {
        step = (*pFunc)(x)/(*pFuncprime)(x);
        x-=step;
    } while (fabs(step) > 1.0e-5);
    return x;
}

double Sqrt10(double x)
{
    return sqrt(x) - 10.0;
}

double Sqrt10Prime(double x)
{
    return 1.0/(2.0*sqrt(x));
}

double Cube10(double x)
{
    return x*x*x - 10.0;
}

double Cube10Prime(double x)
{
    return 3.0*x*x;
}

int main(int argc, char* argv[])
{
    std::cout<<"Root sqrt(x) = 10, with guess 1.0 is "
             << SolveNewton(Sqrt10,Sqrt10Prime,1.0) <<"\n";
    std::cout<<"Root sqrt(x) = 10, with guess 1.0 is "
             << SolveNewton(Cube10,Cube10Prime,1.0) <<"\n";
}