#include <iostream>

int main(int argc, char* argv[])
{
    for (int i = 0; i < 1000000; i++)
    {
        double** A;
        double** B;
        //double** C;
        double C[3][3];

        A = new double* [3];
        B = new double* [3];
        //C = new double* [3];

        for (int i = 0; i < 3; i++)
        {
            A[i] = new double [3];
            B[i] = new double [3];
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                A[i][j] = 1;
                B[i][j] = 1;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                C[i][j] = A[i][j] + B[i][j];
            }
        }

        //std::cout<< "C = [[" << C[0][0] << ", " << C[0][1] << ", " << C[0][2] << "], [" << C[1][0] << ", " << C[1][1] << ", " << C[1][2] << "], [" << C[2][0] << ", " << C[2][1] << ", " << C[2][2] << "]]"<<"\n";
        
        for (int i = 0; i < 3; i++)
        {
            delete[] A[i];
            delete[] B[i];
            //delete[] C[i];
        }
        delete[] A;
        delete[] B;
        //delete[] C;
    }
    
    return 0;
}