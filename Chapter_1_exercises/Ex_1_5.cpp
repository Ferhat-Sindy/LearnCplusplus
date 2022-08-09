#include <iostream>

int main(int argc, char* argv[])
{    
    std::string firstname, lastname;

    std::cout << "Type in your first name and press enter to type in your last name. \n";
    std::cin >> firstname >> lastname;

    std::cout << "Your full name is: "<<firstname<<" "<<lastname<<"\n";

    return 0;
}
