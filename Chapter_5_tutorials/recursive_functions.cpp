#include <iostream>
#include <cassert>

int CalculateFactorial(int n);

int main(int argc, char* argv[])
{
    int n = 3;
    std::cout<<"The factorial of "<<n<<" is "<<CalculateFactorial(n)<<"\n";

    return 0;
}

int CalculateFactorial(int n)
{
    assert(n>0);
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return CalculateFactorial(n-1)*n;
    }
}