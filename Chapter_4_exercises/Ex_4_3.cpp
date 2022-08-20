#include <iostream>

int main(int argc, char* argv[])
{

    for (int i = 0; i < 1000000000; i++)
    {
        double *x;
        double *y;
        double z;
        x = new double[3];
        y = new double[3];

        x[0] = 1, x[1] = 1, x[2] = 1;
        y[0] = 1, y[1] = 1, y[2] = 1;

        for (int i = 0; i < 3; i++)
        {
            z = z + y[i]*x[i];
        }

        std::cout << "The inner product = " << z << ". \n";
        
        z = 0;
        delete[] x;
        delete[] y;
    }
    return 0;
}