#include <iostream>
#include "CImg.h"
#include "Perlin2D.hpp"

using namespace std;
using namespace cimg_library;

// You need to add libgdi32.a in your IDE linker options

int main()
{
    CImg<unsigned char> image(128,128,1,3,0);

    Perlin2D perlin2d;
    perlin2d.Shuffle(10);

    for(unsigned int x = 0 ; x < image.width() ; x++)
        for(unsigned int y = 0 ; y < image.height() ; y++)
        {
            perlin2d.Set(x,y);
            float value =  perlin2d.Get();

            unsigned int greyscale = static_cast<int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    image.save("perlin2d.bmp");
    printf("Generated perlin2d.bmp successfully.");
    return 0;
}
