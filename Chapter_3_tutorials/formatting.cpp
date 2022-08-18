#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    std::ofstream write_file("OutputFormatted.dat");

    write_file.setf(std::ios::scientific);
    write_file.setf(std::ios::showpos);
    write_file.precision(13);

    double x = 3.4, y = 0.0000855, z = 984.424;
    write_file << x << " " << y << " " << z << "\n";

    write_file.close();
    return 0;
}