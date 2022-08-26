#include <cmath>
#include <iostream>

void minor_ij(double** A, double** B, int l, int k,int n)
{
    //Calculates the minor_{lk} of matrix A of size nxn 
    //and stores it in matrix B (n-1)x(n-1).
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //Checking the seperate cases, which are the four smaller block matrices
            //that emerge when deleting row l and column k from matrix A.
            //
            if ((i<l)&&(j<k))
            {
                B[i][j] = A[i][j];
            }
            else if ((i>l)&&(j<k))
            {
                B[i-1][j] = A[i][j];
            }
            else if ((i<l)&&(j>k))
            {
                B[i][j-1] = A[i][j];
            }
            else if ((i>l)&&(j>k))
            {
                B[i-1][j-1] = A[i][j];
            }
        }
    }
}

double determinant(double** A, int n)
{
    if (n == 1)
    {
        //base case.
        return A[0][0];
    }
    else
    {
        double result = 0;
        for (int k = 0; k <= n-1; k++)
        {
            //creating pointer to store the minor_0k.
            double** B = new double* [n-1];
            for (int i = 0; i < n-1; i++)
            {
                B[i] = new double [n-1];
            }

            minor_ij(A,B,0,k,n);

            //using recursion. Note result is returned later.
            result+= pow(-1,k+2)*A[0][k]*determinant(B,n-1);

            //deleting pointer which stores minor_0k.
            for (int i = 0; i < n-1; i++)
            {
                delete[] B[i];
            }
            delete[] B;
        }
        return result;     
    }   
}

void A_k(double** A, double**B, double* b, int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == k)
            {
                B[i][j] = b[i];
            }
            else
            {
                B[i][j] = A[i][j];
            } 
        }
    }
}

void SolveLinearSystem(double** A, double* x, double* b, int n)
{
    for (int k = 0; k < n; k++)
    {
        double** B = new double* [n];
        for (int i = 0; i < n; i++)
        {
            B[i] = new double [n];
        }

        A_k(A,B,b,k,n);
        x[k] = determinant(B,n)/determinant(A,n);

        for (int i = 0; i < n; i++)
        {
            delete[] B[i];
        }
        delete[] B;        
    }
}

int main(int argc, char* argv[])
{
    int n = 3;
    double** A = new double* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double [n];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                A[i][j] = 1;   
            }
            else
            {
                A[i][j] = 0;
            }
        }
    }

    double* b = new double [n];
    double* x = new double [n];
    for (int i = 0; i < n; i++)
    {
        b[i] = 3;
    }

    SolveLinearSystem(A, x, b, n);  
    std::cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<"\n";
}