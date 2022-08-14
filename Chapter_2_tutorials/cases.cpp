#include <iostream>

int main(int argc, char* argv[])
{
    int i;

    std::cout << "Type an integer i and press enter. \n";
    std::cin >> i;

    switch (i)
    {
    case 1:
        std::cout << "i: " << i << "\n";
        break;
    
    case 20:
        std::cout << "i: " << i << "\n";
        break;

    default:
        std::cout << "i is not equal to 1 or 20";
    }
}