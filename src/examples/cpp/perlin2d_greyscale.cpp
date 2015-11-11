#include <iostream>
#include "Perlin2D.hpp"
#include "include_all.hpp"

void generate_perlin(cimg_library::CImg<unsigned char> & image)
{
    /* Generate Perlin 2D */
    Perlin2D perlin2d;
    perlin2d.Shuffle(10);

    for(int x = 0 ; x < image.width() ; x++)
        for(int y = 0 ; y < image.height() ; y++)
        {
            perlin2d.Set(x,y);
            float value =  perlin2d.Get();

            unsigned int greyscale = static_cast<unsigned int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    image.save("perlin2d.bmp");
    std::cout<<"Saved perlin2d.bmp"<<std::endl;
}
