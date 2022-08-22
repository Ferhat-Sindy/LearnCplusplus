#include <iostream>
int i = 5; //global i

int main(int argc, char* argv[])
{
    int j = 5;
    std::cout << i << "\n" ;

    {
        int i = 10, j = 11;
        std::cout << i << "\n";
        std::cout << ::i << "\n";
        std::cout << j << "\n";
    }

    std::cout << j << "\n";

    return 0;
}