#include <iostream>
#include <cassert>
#include <cmath>

int main(int argc, char* argv[])
{
    double A[2][2] = {{4, 10},{1,1}};
    double B[2][2], det;
    
    det = A[0][0]*A[1][1] - A[0][1]*A[1][0];

    assert(fabs(det) > 1e-16);

    B[0][0] = A[1][1]/det;
    B[1][1] = A[0][0]/det;
    B[1][0] = -A[1][0]/det;
    B[0][1] = -A[0][1]/det;

    std::cout<< "D = [["<<B[0][0]<<", "<<B[0][1]<<"],["<<B[1][0]<<", "<<B[1][1]<<"]]\n";

    return 0;
}
