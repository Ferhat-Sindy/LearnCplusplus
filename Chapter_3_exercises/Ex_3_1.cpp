#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char* argv[])
{
    double x[4] = {0.0, 1.0, 1.0, 0.0};
    double y[4] = {0.0, 0.0, 1.0, 1.0};
    std::string flag;

    std::ifstream read_file("x_and_y.dat");
    assert(read_file.is_open());
    read_file.close();
    
    std::cout << "Do you want to create a new file? Type true or false. If false is chosen the existing file is appendend. \n";
    std::cin >> flag;

    if (flag == "true"){std::remove("x_and_y.dat");}

    std::ofstream write_output("x_and_y.dat",std::ios::app);   
    assert(write_output.is_open());

    write_output.setf(std::ios::scientific);
    write_output.setf(std::ios::showpos);
    write_output.precision(13);
        
    for (int i = 0; i < 4; i++){write_output << x[i] << " ";} write_output<<"\n"; write_output.flush();

    for (int i = 0; i < 4; i++){write_output << y[i] << " ";} write_output<<"\n"; write_output.flush();
    
    write_output.close();
    
    return 0;
}