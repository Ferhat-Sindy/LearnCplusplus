int main(int argc, char* argv[])
{
    double* p_x;
    
    p_x = new double;
    *p_x = 1.0;
    
    delete p_x;

    return 0;
}