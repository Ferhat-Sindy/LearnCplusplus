//Given C++ code

double x, y, z;

if ((x > y) || (x < 5.0))
{
    z = 4.0;
}
else
{
    z = 2.0;
}

//1. The code above compares the floats x and y. If x > y or x < 5.0 the float z gets the value 5 assigned 
//   otherwise z =2.0.

//2. (a) z = 4.0
//   (b) z = 2.0
//   (c) z = 4.0

//3. modified code

//Given C++ code

double x, y, z;

if ((x >= y) || (x < 5.0))
{
    z = 4.0;
}
else
{
    z = 2.0;
}
