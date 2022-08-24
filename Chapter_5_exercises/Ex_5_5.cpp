#include <cassert>
#include <iostream>

void Multiply(double** A, double** B, double** C,int n_1, int n_2)
{
    assert(n_1 == n_2);

    for (int i = 0; i < n_1; i++)
    {
        for (int j = 0; j < n_1; j++)
        {
            for (int k = 0; k < n_1; k++)
            {
                C[i][j] = A[i][k]*B[k][j];
            }
        }
    }
}

void Multiply(double** A, double* x, double* b,int n_1, int n_2)
{
    assert(n_1 == n_2);
    for (int i = 0; i < n_1; i++)
    {
        for (int k = 0; k < n_1; k++)
        {
            b[i] += A[i][k]*x[k];
        }
    }
}

void Multiply(double*x, double** A, double* b,int n_1, int n_2)
{
    assert(n_1 == n_2);
    for (int i = 0; i < n_1; i++)
    {
        for (int k = 0; k < n_1; k++)
        {
            b[i] += A[k][i]*x[k];
        }
    }
}

void Multiply(double scalar, double** A, double** C,int n_1)
{
    for (int i = 0; i < n_1; i++)
    {
        for (int j = 0; j < n_1; j++)
        {
            C[i][j] = scalar*A[i][j];
        }
    }
}

void Multiply(double** A, double scalar, double** C,int n_1)
{
    for (int i = 0; i < n_1; i++)
    {
        for (int j = 0; j < n_1; j++)
        {
            C[i][j] = A[i][j]*scalar;
        }
    }
}

int main(int argc, char* argv[])
{
    int n_1 = 10;
    int n_2 = 10;
    double** A = new double* [n_1];
    double** B = new double* [n_2];
    double** C = new double* [n_2];
    double* x = new double [n_2];
    double* b = new double [n_2];
    double scalar = 3.0;

    for (int i = 0; i < n_1; i++)
    {
        A[i] = new double [n_1];
        B[i] = new double [n_2];
        C[i] = new double [n_2];
    }

    for (int i = 0; i < n_1; i++)
    {
        for (int j = 0; j < n_1; j++)
        {
            B[i][j] = i*j;
            A[i][j] = i;
        }
    }
    
    Multiply(A,B,C,n_1,n_2);
    Multiply(A,x,b,n_1,n_2);
    Multiply(x,A,b,n_1,n_2);
    Multiply(scalar,A,C,n_1);
    Multiply(A,scalar,C,n_1);

    for (int i = 0; i < n_1; i++)
    {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];       
    }
        
    delete A;
    delete B;
    delete C;
}