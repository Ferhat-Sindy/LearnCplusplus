#include <cmath>
#include <iostream>

void minor_ij(double** A, double** B, int l, int k,int n)
{
    std::cout<<"nice \n";
    std::cout.flush();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout<<i<<" "<<j<<"\n";
            std::cout.flush();
            if ((i<l)&&(j<k))
            {
                B[i][j] = A[i][j];
                std::cout<<"nice_1 \n";
                std::cout.flush();
            }
            else if ((i>l)&&(j<k))
            {
                B[i-1][j] = A[i][j];
                std::cout<<"nice_2 \n";
                std::cout.flush();
            }
            else if ((i<l)&&(j>k))
            {
                B[i][j-1] = A[i][j];
                std::cout<<"nice_3 \n";
                std::cout.flush();
            }
            else if ((i>l)&&(j>k))
            {
                B[i-1][j-1] = A[i][j];
                std::cout<<"nice_4 \n";
                std::cout.flush();
            }
        }
    }
}

double determinant(double** A, int n)
{
    if (n == 1)
    {
        return A[0][0];
    }
    else
    {
        double result = 0;
        for (int k = 0; k < n-1; k++)
        {
            double** B = new double* [n-1];
            for (int i = 0; i < n-1; i++)
            {
                B[i] = new double [n-1];
            }

            minor_ij(A,B,0,k,n-1);
            result+= pow(-1,k+2)*determinant(B,n-1);

            for (int i = 0; i < n-1; i++)
            {
                delete[] B[i];
            }
            delete[] B;
        }
            //std::cout<<"Reaches before return statement \n";
            //std::cout.flush();
        return result;     
    }   
}


int main(int argc, char* argv[])
{
    int n = 2;
    double** A = new double* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double [n];
    }
    
    A[0][0] = 1, A[0][1] = 2, A[1][0] = 3, A[1][1] = 4;
    //std::cout<<"Det = "<<determinant(A,n)<<"\n";
    //std::cout.flush();

    double** B = new double* [n-1];
    for (int i = 0; i < n-1; i++)
    {
        B[i] = new double [n-1];
    }
    
    minor_ij(A,B,1,0,2);
    std::cout<<B[0][0]<<"\n";
    std::cout.flush();

    return 0;
}
