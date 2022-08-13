#include <iostream>

int main(int argc, char* argv[])
{   
    double x = 10.0;
    int count;

    while (x > 1.0)
    {
        std::cout << "x: "<< x <<" and count: "<<count<<" before \n";
        x *= 0.5;
        count++;
        std::cout << "x: "<< x <<" and count: "<<count<<" after \n \n";
    }
    
    std::cout << "The output is equal to: " << x << "\n";
}