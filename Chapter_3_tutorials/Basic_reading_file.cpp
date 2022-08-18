#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    double x[6], y[6];
    std::ifstream read_file("Output.dat");

    for (int i = 0; i < 6; i++)
    {
        read_file >> x[i] >> y[i];
    }
    
    read_file.close();
    return 0;
}