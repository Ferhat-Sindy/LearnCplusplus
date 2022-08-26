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

            //std::cout<<"k: "<<k<<" result: "<<result<<" B: "<<B[0][0]<<"\n";

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


int main(int argc, char* argv[])
{
    //creating test 2x2 matrix
    int n = 2;
    double** A = new double* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double [n];
    }
    
    A[0][0] = 1, A[0][1] = 1, A[1][0] = 1, A[1][1] = 2;
    std::cout<<"Det = "<<determinant(A,n)<<"\n";
    std::cout.flush();

    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
    }
    delete[] A;
    return 0;
}
