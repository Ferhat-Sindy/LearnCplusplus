#include <iostream>
#include <cassert>
#include <cmath>

//Newton iteration scheme: x_next = x_prev - ( e^x_prev + x_prev^3 - 5 )/( e^x_prev + 3x_prev^2 )
//initial guess

int main(int argc, char* argv[])
{
    
    double x_prev = 0, x_next;

    std::cout << "i: "<<0<<" , x_i: "<<x_prev<<"\n";

    for (int i = 1; i <= 100; i++)
    {
        x_next = x_prev - (exp(x_prev) + pow(x_prev,3) - 5)/(exp(x_prev) + 3*pow(x_prev,2));
        std::cout << "i: "<<i<<", x_i: "<<x_next<<"\n";
        
        if (fabs(x_next-x_prev)<1e-16)
        {
            break;
        }

        x_prev = x_next;
    }
    

    return 0;
}