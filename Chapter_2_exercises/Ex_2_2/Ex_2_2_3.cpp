#include <iostream>

int main(int argc, char* argv[])
{
    double p, q, x, y;
    int j;

    std::cout << "Type in three floats (p,q,y) and press enter, thereafter type in an integer (j) and press enter. \n";
    std::cin >>p>>q>>y>>j;

    if (p > q){
        x = 0;
    }
    else if ((p <= q)&&(j = 10)){
        x = 1;
    }
    else{
        x = 2;
    }
    
    std::cout << "x: " << x <<"\n";

    return 0;
}
