#include <iostream>

int main(int argc, char* argv[])
{   
    int number1, number2, number3; //variable declaration
    std::cout << "This programm asks for two integer as input, and outputs the multiplication of both intergers\n" <<
    "type a integer, and press enter to type a second integer\n"; //text prompted to user
    std::cin >> number1 >> number2; //input of user
    number3 = number1*number2; //multiplication of integers
    std::cout << "The multiplication is given by: " << number3 << "\n"; //prompting the output to user

    return 0;
}