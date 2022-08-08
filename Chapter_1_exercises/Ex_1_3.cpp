#include <cmath>
#include <iostream>

int main(int argc, char* argv[])
{   double arr1[3],arr2[3],dot_product;

    std::cout << "Type the entries of the first array of size 3 and press enter \n";
    std::cin >> arr1[0] >> arr1[1] >> arr1[2];
    std::cout << "Type the entries of the second array of size 3 and press enter \n";
    std::cin >> arr2[0] >> arr2[1] >> arr2[2];

    dot_product = arr1[0]*arr1[0] + arr1[1]*arr1[1] + arr1[2]*arr1[2];

    std::cout << "the dot product of the two vectors is: " << dot_product << "\n";

    return 0;
}