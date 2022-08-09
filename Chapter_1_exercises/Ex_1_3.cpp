#include <cmath>
#include <iostream>

int main(int argc, char* argv[])
{   double arr1[3],arr2[3],dot_product,p_norm_1,p_norm_2;
    int p;

    std::cout << "Type the entries of the first array of size 3 and press enter \n";
    std::cin >> arr1[0] >> arr1[1] >> arr1[2];
    std::cout << "Type the entries of the second array of size 3 and press enter \n";
    std::cin >> arr2[0] >> arr2[1] >> arr2[2];

    dot_product = arr1[0]*arr2[0] + arr1[1]*arr2[1] + arr1[2]*arr2[2];

    std::cout << "the dot product of the two vectors is: " << dot_product << "\n";

    std::cout << "Calculate p norm of both vectors. First type an integer p and press enter \n";
    std::cin >> p;
    p_norm_1 = pow((pow(fabs(arr1[0]),p) + pow(fabs(arr1[1]),p) + pow(fabs(arr1[2]),p)),1.0/double(p));
    p_norm_2 = pow((pow(fabs(arr2[0]),p) + pow(fabs(arr2[1]),p) + pow(fabs(arr2[2]),p)),1.0/double(p));
    std::cout << "The "<<p<<"-norm of vector 1 is "<<p_norm_1<<"\n";
    std::cout << "The "<<p<<"-norm of vector 2 is "<<p_norm_2<<"\n";

    return 0;
}