#include <iostream>

int main(int argc, char* argv[])
{
    double x;

    std::cout << "Type a number and press enter. If the number is smaller than -1.0 it returns -1.0 and 1.0 if it is bigger than 1.0 \n otherwise it outputs 0 \n";
    std::cin >> x;

    if (x < -1.0){
        x = -1.0;
    }
    else if(x > 1.0){
        x = 1.0;
    }
    else{
        x = 0;
    }

    std::cout << "the output is: " << x;

    return 0;
}
