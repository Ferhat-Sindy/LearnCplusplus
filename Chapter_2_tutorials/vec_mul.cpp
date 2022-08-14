#include <iostream>

int main(int argc, char* argv[])
{       
    double x[2] = {1,1}, y[2] = {1,1};
    double z;

    for (int i = 0; i < 2; i++)
    {
        z += x[i]*y[i];
    }
    
    std::cout << z <<"\n";
}