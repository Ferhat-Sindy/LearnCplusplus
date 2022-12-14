double** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory(int numRows, double** matrix);

int main(int argc, char* argv[])
{
    double** A;
    A = AllocateMatrixMemory(5, 3);
    A[0][1] = 2.0;
    A[4][2] = 4.0;
    FreeMatrixMemory(5, A);
}

double** AllocateMatrixMemory(int numRows, int numCols)
{
    double** matrix;
    matrix = new double* [numRows];

    for (int i = 0; i < numRows; i++)
    {
        matrix[i] = new double [numCols];
    }
    return matrix;    
}

void FreeMatrixMemory(int numRows, double** matrix)
{
    for (int i = 0; i < numRows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
