#include <iostream>

int main(int argc, char* argv[])
{   
    int rows = 5, cols = 3;
    double** A;

    A = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        A[i] = new double [cols];
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] A[i];
    }
    
    delete[] A;
    
    return 0;
}