void M_ik(double** A, double** M, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i < n-1)&&(i > k+1))
            {
                M[i][j] = A[i][j]/A[k][k];
            }
        }
    }
}

void BackwardSubstitution(double**A, double* x, double* b, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        x[i];
    }
}

double* Gaussian_elimination_no_pivotting(double** A, double* b, int n)
{
    for (int k = 0; k < n-1; k++)
    {
        double** M = new double* [n];
        double** A_k = new double* [n];
        double* b_k = new double [n];

        for (int i = 0; i < n; i++)
        {
            M = new double* [n];
            A_k = new double* [n];
        }
    	
        M_ik(A, M, n, k);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int l = 0; l < n; l++)
                {
                    A[i][j] += A[i][j] - M[i][l]*A[l][j];
                    
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int l = 0; l < n; l++)
            {
                b[i] += b[i] - M[i][l]*b[l];
            }
        }
    }


}

int main(int argc, char* argv[])
{
    return 0;
}