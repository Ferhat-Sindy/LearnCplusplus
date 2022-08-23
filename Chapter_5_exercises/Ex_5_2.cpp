#include <iostream>

void ChangeValue(int* x)
{   
    *x = 10;
}

int main(int argc, char* argv[])
{
    int x = 3;
    ChangeValue(&x);
    std::cout<<x<<"\n";

    return 0;
}