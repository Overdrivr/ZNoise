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
    // lacunarity must be > 1, and should be > 2 to avoid scaling artifacts
    float hurst[] = {0.2f, 0.5f, 0.8f};
    float lacunarity[] = {2.5f, 3.5f, 4.5f};
    float baseScale = 0.005f;

    for(auto& h : hurst)
      for(auto& l : lacunarity)
        generate_fbm(output, h, l, baseScale);

    // Example 4 - See scr/examples/cpp/example-fbm.cpp
    for(auto& h : hurst)
      for(auto& l : lacunarity)
        generate_hmf(output, h, l, baseScale);

    return 0;
}
