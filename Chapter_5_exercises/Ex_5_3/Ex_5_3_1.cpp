#include <iostream>

void SwapValues(double* x, double* y)
{
    double z = *x;
    *x = *y;
    *y = z;
}

int main(int argc, char* argv[])
{
    double *x, *y;
    x = new double;
    y = new double;
    *x = 1.0;
    *y = 2.0;

    std::cout<<"BEFORE: x = "<<*x<<"\n";
    std::cout<<"BEFORE: y = "<<*y<<"\n";

    SwapValues(x,y);
    std::cout<<"AFTER: x = "<<*x<<"\n";
    std::cout<<"AFTER: y = "<<*y<<"\n";

    delete x;
    delete y;
}