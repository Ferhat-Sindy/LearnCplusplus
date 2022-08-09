#include <iostream>
#include <iostream>

int main(int argc, char* argv[])
{   double A[2][2], B[2][2], C[2][2], D[2][2]; 

    std::cout << "Input the entries of two, two by two matrices (row-wise format starting from the top) \n";
    std::cout << "Input for the first matrix \n";
    std::cin >> A[0][0] >> A[0][1] >> A[1][0] >> A[1][1]; 
    std::cout << "Input for the second matrix \n";
    std::cin >> B[0][0] >> B[0][1] >> B[1][0] >> B[1][1]; 

    C[0][0] = A[0][0] + B[0][0];
    C[0][1] = A[0][1] + B[0][1];
    C[1][0] = A[1][0] + B[1][0];
    C[1][1] = A[1][1] + B[1][1];

    std::cout << "The sum of the matrices is equal to [["<<C[0][0]<<" , "<<C[0][1]<<"],["<<C[1][0]<<" , "<<C[1][1]<<"]]\n";    

    D[0][0] = A[0][0] * B[0][0];
    D[0][1] = A[0][1] * B[0][1];
    D[1][0] = A[1][0] * B[1][0];
    D[1][1] = A[1][1] * B[1][1];

    std::cout << "The element wise product of the matrices is equal to [["<<D[0][0]<<" , "<<D[0][1]<<"],["<<D[1][0]<<" , "<<D[1][1]<<"]]\n";    

    return 0;
}