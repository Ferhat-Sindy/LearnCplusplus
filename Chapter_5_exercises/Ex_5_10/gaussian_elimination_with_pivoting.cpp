#include <iostream>
#include <cassert>
#include <cmath>

void Multiply(double** A, double** B, double**C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void Multiply(double** A, double* x, double* b, int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = 0.0;
        for (int k = 0; k < n; k++)
        {
            b[i] += A[i][k]*x[k];
        }
    }
}

int find_index_i(double** A, double a, int n, int j)
{
    for (int i = 0; i < n; i++)
    {
        if (fabs(a - A[i][j]) < 1e-16)
        {
            return i;
        }
    }
    return 0;
}

void Permutation_matrix(double** P, int k, int l, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i!=k)&&(i!=l)&&(i == j))
            {
                P[i][j] = 1.0;
            }
            else if ((i == k)&&(j == l))
            {
                P[i][j] = 1.0;
            }
            else if ((i == l)&&(j == k))
            {
                P[i][j] = 1.0;
            }
            else
            {
                P[i][j] = 0.0;
            }
        }   
    }
}

double find_max_i(double**A, int i,int n)
{
    double max = 0.0;
    for (int j = 0; j < n; j++)
    {
        if (fabs(A[j][i]) > fabs(max)&&(j>=i))
        {
            max = A[j][i];
        }
    }
    return max; 
}

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

void Gaussian_elimination_with_pivotting(double** A, double* x, double* b, int n)
{
    for (int k = 0; k < n-1; k++)
    {
        double* M = new double [n-1-k];
        double** P = new double* [n];
        double** PA = new double* [n];
        double* Pb = new double [n];

        for (int i = 0; i < n; i++)
        {
             P[i] = new double [n];
             PA[i] = new double [n];
        }
        
        Permutation_matrix(P,k,find_index_i(A,find_max_i(A,k,n),n,k),n);
        Multiply(P,A,PA,n);
        Multiply(P,b,Pb,n);
        A = PA;
        b = Pb;

        M_ik(A, M, n, k);

        for (int j = k; j < n; j++)
        {
            for (int i = k+1; i < n; i++)
            {
                A[i][j] = A[i][j] - M[i]*A[k][j];    
            }
        }

        for (int i = k; i < n; i++)
        {
            b[i] = b[i] - M[i]*b[k];
        }

        std::cout<<"P with k = "<<k<<"\n";
        std::cout<<P[0][0]<<" "<<P[0][1]<<" "<<P[0][2]<<"\n";
        std::cout<<P[1][0]<<" "<<P[1][1]<<" "<<P[1][2]<<"\n";
        std::cout<<P[2][0]<<" "<<P[2][1]<<" "<<P[2][2]<<"\n";
        std::cout<<"A with k = "<<k<<"\n";
        std::cout<<A[0][0]<<" "<<A[0][1]<<" "<<A[0][2]<<"\n";
        std::cout<<A[1][0]<<" "<<A[1][1]<<" "<<A[1][2]<<"\n";
        std::cout<<A[2][0]<<" "<<A[2][1]<<" "<<A[2][2]<<"\n";
        std::cout<<"M with k = "<<k<<"\n";
        std::cout<<M[0]<<" "<<M[1]<<" "<<M[2]<<" "<<"\n";
        std::cout<<"b = \n";
        std::cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<"\n";


        delete[] M;
        delete[] Pb;
        for (int i = 0; i < n; i++)
        {
             delete[] PA[i];
        }
        delete[] PA;     
    }

    BackwardSubstitution(A, x, b, n);
}

int main(int argc, char* argv[])
{
    std::cout<<"start\n";
    std::cout.flush();
    int n = 3;
    double** A = new double* [n];
    double** P = new double* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double [n];
        P[i] = new double [n];
    }
    
    A[0][0] = 4, A[0][1] = -3, A[0][2] = 1;
    A[1][0] = -2, A[1][1] = 1, A[1][2] = -3;
    A[2][0] = 1, A[2][1] = -1, A[2][2] = 2;

    double* b = new double [n];
    double* x = new double [n];

    b[0] = -8, b[1] = -4, b[2] = 3;

    //std::cout<<"The max = "<<find_max_i(A,0,n);std::cout.flush()<<"\n";
    //std::cout<<"The max_index = "<<find_index_i(A,find_max_i(A,0,n),n,0);std::cout.flush()<<"\n";
    //Permutation_matrix(P,0,2,n);
    // Multiply(A,A,P,n);
    // std::cout<<"P = \n";std::cout.flush();
    // std::cout<<P[0][0]<<" "<<P[0][1]<<" "<<P[0][2]<<"\n";std::cout.flush();
    // std::cout<<P[1][0]<<" "<<P[1][1]<<" "<<P[1][2]<<"\n";std::cout.flush();
    // std::cout<<P[2][0]<<" "<<P[2][1]<<" "<<P[2][2]<<"\n";std::cout.flush();

    std::cout<<"created tests A,b\n";
    std::cout.flush();
    
    Gaussian_elimination_with_pivotting(A, x, b, n); 
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