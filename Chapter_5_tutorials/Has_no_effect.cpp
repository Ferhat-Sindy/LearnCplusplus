#include <iostream>

void HasNoEffect(double x);

int main(int argc, char* argv[])
{   
    double x = 2.0;
    HasNoEffect(x);
    std::cout << x << "\n";

    return 0;  
}

void HasNoEffect(double x)
{
    x += 1.0;
}