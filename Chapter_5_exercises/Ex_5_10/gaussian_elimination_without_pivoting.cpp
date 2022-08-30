#include <iostream>
#include <cassert>
#include <cmath>

void M_ik(double** A, double* M, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (i > k)
        {
            assert(fabs(A[k][k]) > 1e-6);
            M[i] = A[i][k]/A[k][k];
        }
    }
}

void BackwardSubstitution(double**A, double* x, double* b, int n)
{
    for (int k = n-1; k > -1; k--)
    {
        double sum = 0;
        for (int i = k+1; i < n; i++)
        {
            sum+=A[k][i]*x[i];
        }
        x[k] = 1/A[k][k]*(b[k] - sum);
    }
}

void Gaussian_elimination_no_pivotting(double** A, double* x, double* b, int n)
{
    for (int k = 0; k < n-1; k++)
    {
        double* M = new double [n-1-k];    	
        M_ik(A, M, n, k);

        for (int i = k+1; i < n; i++)
        {
            for (int j = k+1; j < n; j++)
            {
                A[i][j] = A[i][j] - M[i]*A[k][j];    
            }
        }

        for (int i = k+1; i < n; i++)
        {
            b[i] = b[i] - M[i]*b[k];
        }

        delete[] M;

        //std::cout<<"A with k = "<<k<<"\n";
        //std::cout<<A[0][0]<<A[0][1]<<A[0][2]<<"\n";
        //std::cout<<A[1][0]<<A[1][1]<<A[1][2]<<"\n";
        //std::cout<<A[2][0]<<A[2][1]<<A[2][2]<<"\n";
        //std::cout<<"M with k = "<<k<<"\n";
        //std::cout<<M[0]<<" "<<M[1]<<" "<<M[2]<<" "<<"\n";
        //std::cout<<"b = \n";
        //std::cout<<b[0]<<b[1]<<b[2]<<"\n";
    }

    BackwardSubstitution(A, x, b, n);
}

int main(int argc, char* argv[])
{
    std::cout<<"start\n";
    std::cout.flush();
    int n = 3;
    double** A = new double* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double [n];
    }
    
    A[0][0] = 4, A[0][1] = -3, A[0][2] = 1;
    A[1][0] = -2, A[1][1] = 1, A[1][2] = -3;
    A[2][0] = 1, A[2][1] = -1, A[2][2] = 2;

    double* b = new double [n];
    double* x = new double [n];

    b[0] = -8, b[1] = -4, b[2] = 3;

    std::cout<<"created tests A,b\n";
    std::cout.flush();
    
    Gaussian_elimination_no_pivotting(A, x, b, n); 
    std::cout<<"Gaussian elim done\n";
    std::cout.flush();
    std::cout<<"test:"<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<"\n";

    delete[] x;
    delete[] b;
    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
    }
    delete A;  

    return 0;
}