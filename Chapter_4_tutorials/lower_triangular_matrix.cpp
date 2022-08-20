int main(int argc, char* argv[])
{
    int** A;
    A = new int* [1000];

    for (int i = 0; i < 1000; i++)
    {
        A[i] = new int [i+1];
    }
}