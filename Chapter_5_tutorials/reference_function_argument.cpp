#include <iostream>
#include <cmath>

void CalculateRealImaginary(double r, double theta,
                            double& real, 
                            double& imaginary);

int main(int argc, char* argv[])
{
    double r = 3.4, theta = 1.23, x, y;
    CalculateRealImaginary(r,theta,x,y);    

    std::cout << "Real part = " << x << "\n";
    std::cout << "Imaginary part = " << y << "\n";

    return 0;
}

void CalculateRealImaginary(double r, double theta,
                            double& real, 
                            double& imaginary)
{
    real = r*cos(theta);
    imaginary = r*sin(theta);
}