#include <iostream>
#include "include_all.hpp"

int main()
{
    cimg_library::CImg<unsigned char> output(512,512,1,3,0);

    // Example 0 - See scr/examples/cpp/example-perlin.cpp
    generate_perlin(output);
    generate_perlin_3dslice(output);
    generate_perlin_4dslice(output);

    // Example 1 - See scr/examples/cpp/example-simplex.cpp
    generate_simplex(output);
    generate_simplex_3dslice(output);
    generate_simplex_4dslice(output);

    // Example 2 - See scr/examples/cpp/example-worley.cpp
    generate_worley(output,WorleyFunction_F1);

    // Example 3 - See scr/examples/cpp/example-fbm.cpp
    generate_fbm(output);

    return 0;
}
