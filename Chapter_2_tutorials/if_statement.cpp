#include <iostream>

int main(int argc, char* argv[])
{
    double x;

    std::cout << "Type a number and press enter. If the number is smaller than 2.0 it returns 0 \n otherwise it outputs the number itself \n";
    std::cin >> x;

    if (x < 2.0){
        x = 0.0;
    }

    std::cout << "the output is: " << x;

    return 0;
}
