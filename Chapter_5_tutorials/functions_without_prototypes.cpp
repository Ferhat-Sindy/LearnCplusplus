#include <iostream>

double Square(double x)
{
    return x*x;
}

int main(int argc, char* argv[])
{
    std::cout<< "Square of 2 = "<<Square(2)<<"\n";
    return 0;
}

