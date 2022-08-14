#include <iostream>

int main(int argc, char* argv[])
{
    double p, q, x;
    int j;

    std::cout << "Type in two floats (p,q) and press enter, thereafter type in an integer (j) and press enter. \n";
    std::cin >>p>>q>>j;

    if ((p >= q)||(j != 10))
    {
        x = 5;
    }
    
    std::cout << "x: " << x <<"\n";

    return 0;
}
