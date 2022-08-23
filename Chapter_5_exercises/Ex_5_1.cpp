#include <iostream>

void PrintIntegerUsingAdress(int* x)
{
    std::cout<<*x<<"\n";
}

int main(int argc, char* argv[])
{
    int x = 10;
    PrintIntegerUsingAdress(&x);
    return 0;
}