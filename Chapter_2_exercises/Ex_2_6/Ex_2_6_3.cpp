#include <iostream>
#include <cassert>
#include <cmath>

//Newton iteration scheme: x_next = x_prev - ( e^x_prev + x_prev^3 - 5 )/( e^x_prev + 3x_prev^2 )
//initial guess

int main(int argc, char* argv[])
{
    
    double x[101];
    x[0] = 0;

    std::cout << "i: "<<0<<" , x_i: "<<x[0]<<"\n";

    for (int i = 1; i <= 100; i++)
    {
        x[i] = x[i-1] - (exp(x[i-1]) + pow(x[i-1],3) - 5)/(exp(x[i-1]) + 3*pow(x[i-1],2));
        std::cout << "i: "<<i<<", x_i: "<<x[i]<<"\n";
        
        if (fabs(x[i]-x[i-2])<1e-16)
        {
            break;
        }
    }
    

    return 0;
}