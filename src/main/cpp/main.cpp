#include <iostream>
#include "include_all.hpp"

int main()
{
    cimg_library::CImg<unsigned char> output(512,512,1,3,0);

    // Example 0 - See scr/examples/cpp/perlin2d_greyscale.cpp
    generate_perlin(output);
    generate_perlin_3dslice(output);
    generate_perlin_4dslice(output);

    // Example 1 - See scr/examples/cpp/simplex2d_greyscale.cpp
    generate_simplex(output);
    generate_simplex_3dslice(output);
    generate_simplex_4dslice(output);

    // Example 2 - See scr/examples/cpp/simplex2d_greyscale.cpp
    generate_worley(output,WorleyFunction_F1);
    return 0;
}
