#include <iostream>

int main(int argc, char* argv[])
{
    int x,count = 1,y=0; 


    std::cout << "Calculates the sum of a collection of positive integers.\n"<<
                "Enter each integer followed by the return key, and enter −1 at the end of the list of integers to be added."
                <<"The sum can be reset if you type -2. \n";
    
    while ((x != -1)&&(count <= 10))
    {
        std::cin >>x;
        y += x;
        count++;

        if (x == -2)
        {
            y = 0;
            count = 1;
        }
        
    }
    
    if (count <= 10)
    {
        y++;
    }
    

    std::cout << "The sum equals: "<<y<<"\n";

    return 0;
}
