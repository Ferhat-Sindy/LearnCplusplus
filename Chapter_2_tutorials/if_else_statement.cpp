#include <iostream>

int main(int argc, char* argv[])
{
    int i;
    double y;

    std::cout << "Type a number and press enter. If the number is negative than -1.0 is returned \n otherwise (if the input is postive) it returns 1.0 \n";
    std::cin >> i;

    if (i < 0){
        y = -1.0 ;
    }
    else {
        y = 1.0;
    }

    std::cout << "the output is: " << y;

    return 0;
}
