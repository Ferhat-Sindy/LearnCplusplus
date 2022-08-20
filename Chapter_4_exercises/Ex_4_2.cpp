#include <iostream>

int main()
{
    int x = 4, y = 5;
    int *p_x, *p_y, *p_z;

    std::cout << "BEFORE, x = " << x << " and y = "<< y <<"\n";

    p_x = &x;
    p_y = &y;
    p_z = new int;
    *p_z = x;

    *p_x = *p_y;

    *p_y = *p_z;
    
    std::cout << "AFTER, x = " << x << " and y = "<< y <<"\n";

}