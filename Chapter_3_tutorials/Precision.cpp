#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
    double x = 1.8364238;
    std::ofstream write_output("Output.dat");

    write_output.precision(3);
    write_output << x << "\n";

    write_output.precision(5);
    write_output << x << "\n";

    write_output.precision(10);
    write_output << x << "\n";

    return 0;
}