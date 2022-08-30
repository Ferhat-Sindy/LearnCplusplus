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

void LU(double** A, double**L, int n)
{
    for (int k = 0; k < n-1; k++)
    {
        double* M = new double [n-1-k];    	
        M_ik(A, M, n, k);

        for (int j = k; j < n; j++)
        {
            for (int i = k+1; i < n; i++)
            {
                A[i][j] = A[i][j] - M[i]*A[k][j];    
            }
        }

        for (int i = k+1; i < n; i++)
        {
            L[i][k] = M[i];
        }
        delete[] M;        
    }    
}

int main(int argc, char* argv[])
{
    int n = 3;
    double** A = new double* [n];
    double** L = new double* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double [n];
        L[i] = new double [n];
    }
    
    A[0][0] = 3, A[0][1] = 0, A[0][2] = 5;
    A[1][0] = 4, A[1][1] = -5, A[1][2] = 1;
    A[2][0] = 1, A[2][1] = -2, A[2][2] = -3;

    LU(A, L, n); 

    
    std::cout<<"U = \n";std::cout.flush();
    std::cout<<A[0][0]<<" "<<A[0][1]<<" "<<A[0][2]<<"\n";std::cout.flush();
    std::cout<<A[1][0]<<" "<<A[1][1]<<" "<<A[1][2]<<"\n";std::cout.flush();
    std::cout<<A[2][0]<<" "<<A[2][1]<<" "<<A[2][2]<<"\n";std::cout.flush();

    //This part is not neccesary, just to have a  fancy output for L matrix
    ////////////////////////////////////////////////////////
    for (int i = 0; i < n; i++)                           //
    {                                                     //  
        for (int j = 0; j < n; j++)                       //
        {                                                 //          
            if (i == j)                                   //      
            {                                             //  
                L[i][j] = 1.0;                            //  
            }                                             //      
            else if (i < j)                               //  
            {                                             //      
                L[i][j] = 0.0;                            //  
            }                                             //      
        }                                                 //      
    }                                                     //  
    ////////////////////////////////////////////////////////

    std::cout<<"L = \n";std::cout.flush();
    std::cout<<L[0][0]<<" "<<L[0][1]<<" "<<L[0][2]<<"\n";std::cout.flush();
    std::cout<<L[1][0]<<" "<<L[1][1]<<" "<<L[1][2]<<"\n";std::cout.flush();
    std::cout<<L[2][0]<<" "<<L[2][1]<<" "<<L[2][2]<<"\n";std::cout.flush();

    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
        delete[] L[i];
    }
    delete A;
    delete L;
    return 0;
}