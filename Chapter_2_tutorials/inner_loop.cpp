#include <iostream>

int main(int argc, char* argv[])
{   
    double x = 10.0;
    int count;

    for (int i = 1; i < 5; i++)
    {
        for (int j = 5; j > i; j--)
        {
            std::cout << "i: "<< i <<" and j: "<< j <<"\n";    
        }
    }

}