#include <iostream>

int main(int argc, char* argv[])
{
    double y;
    double *p_x;

    y = 3.0;
    p_x = &y;

    std::cout << "y = " << y << "\n";
    *p_x = 1.0; 
    std::cout << "y = " << y << "\n";    
}