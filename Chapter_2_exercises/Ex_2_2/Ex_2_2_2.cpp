#include <iostream>

int main(int argc, char* argv[])
{
    double p, q, x, y;
    int j;

    std::cout << "Type in three floats (p,q,y) and press enter, thereafter type in an integer (j) and press enter. \n";
    std::cin >>p>>q>>y>>j;

    if ((y >= q)&&(j = 20))
    {
        x = 5;
    }
    else{
        x = p;
    }
    
    std::cout << "x: " << x <<"\n";

    return 0;
}
