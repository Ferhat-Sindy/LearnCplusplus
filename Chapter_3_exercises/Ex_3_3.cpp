#include <iostream>
#include <cstdlib>
#include <cassert>
#include <fstream>

int main(int argc, char*argv[]){

    int N = atoi(argv[1]);
    assert(N > 1);

    double h = double(1)/(double(N)-1);
    double x = 0, y = 1;

    std::ofstream write_file("xy.dat");
    assert(write_file.is_open());

    write_file.setf(std::ios::scientific);
    write_file.setf(std::ios::showpos);
    write_file.precision(13);

    write_file << x << " " << y << "\n";

    for (int i = 1; i < N; i++)
    {
        x += h;
        y += y/(1+h);
        write_file << x << " " << y << "\n";
    }

    write_file.close();
    

    return 0;
}