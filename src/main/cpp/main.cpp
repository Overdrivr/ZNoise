#include <iostream>
#include "include_all.hpp"


int main()
{
    cimg_library::CImg<unsigned char> output(128,128,1,3,0);

    // Example 0 - See scr/examples/cpp/perlin2d_greyscale.cpp
    generate_perlin(output);

    // Example 1 - See scr/examples/cpp/simplex2d_greyscale.cpp
    generate_simplex(output);

    // Example 2 - See scr/examples/cpp/simplex2d_greyscale.cpp
    generate_worley_F1(output,WorleyFunction_F1);
    return 0;
}
