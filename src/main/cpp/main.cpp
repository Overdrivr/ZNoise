#include <iostream>
#include "include_all.hpp"


int main()
{
    cimg_library::CImg<unsigned char> output(256,256,1,3,0);

    // Example 0 - See scr/examples/cpp/perlin2d_greyscale.cpp
    generate_perlin(output);

    // Example 1 - See scr/examples/cpp/simplex2d_greyscale.cpp
    generate_simplex(output);

    // Example 2 - See scr/examples/cpp/simplex2d_greyscale.cpp
    generate_worley(output,WorleyFunction_F1);
    generate_worley(output,WorleyFunction_F2);
    generate_worley(output,WorleyFunction_F3);
    generate_worley(output,WorleyFunction_F4);
    return 0;
}
