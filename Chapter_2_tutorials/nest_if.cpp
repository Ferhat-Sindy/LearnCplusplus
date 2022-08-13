#include <iostream>

int main(int argc, char* argv[])
{
    double x,y,z;

    std::cout << "Type in three numbers each followed by Enter \n. The program returns 1 if the first number is in the interval with endpoints the latter two numbers.\n";
    std::cin >> x >> y >> z;

    if(x < z){
        if(x > y){
            x = 1;
        }
        else{
            x = 0;
        }
    }
    else{
        x = 0;
    }
    std::cout << "The output value: "<< x <<"\n";
}