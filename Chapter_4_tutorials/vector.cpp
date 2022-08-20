#include <iostream>

int main(int argc, char* argv[])
{
    double* x;
    x = new double [10];

    std::cout << x << "\n";
    std::cout << &x[0] << "\n";

    delete[] x;

    return 0;
}