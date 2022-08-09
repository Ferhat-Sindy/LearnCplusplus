#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
    int data[5];
    double average;
    std::cout << "Type in the the number of cars that drive past yput house each day for 5 consecutive days. \n";
    std::cin >> data[0] >> data[1] >> data[2] >> data[3] >> data[4];
    
    average = 1.0/double(5)*(data[0] + data[1] + data[2] + data[3] + data[4]);

    std::cout << "The average is: "<<average<<".\n";

    return 0;
}
