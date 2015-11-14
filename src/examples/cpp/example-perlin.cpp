#include <iostream>
#include "Perlin.hpp"
#include "include_all.hpp"

void generate_perlin(cimg_library::CImg<unsigned char> & image)
{
    /* Generate Perlin 2D */
    Perlin perlin;
    perlin.Shuffle(10);

    for(int x = 0 ; x < image.width() ; x++)
        for(int y = 0 ; y < image.height() ; y++)
        {
            float value =  perlin.Get({x , y},0.01f);

            unsigned int greyscale = static_cast<unsigned int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    image.save("perlin2d.bmp");
    std::cout<<"Saved perlin2d.bmp"<<std::endl;
}

void generate_perlin_3dslice(cimg_library::CImg<unsigned char> & image)
{
    /* Generate Perlin 3D */
    Perlin perlin;
    perlin.Shuffle(10);

    for(int x = 0 ; x < image.width() ; x++)
        for(int y = 0 ; y < image.height() ; y++)
        {
            float value =  perlin.Get({x , y, 0.f},0.01f);

            unsigned int greyscale = static_cast<unsigned int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    image.save("perlin3d.bmp");
    std::cout<<"Saved perlin3d.bmp"<<std::endl;
}

void generate_perlin_4dslice(cimg_library::CImg<unsigned char> & image)
{
    /* Generate Perlin 4D */
    Perlin perlin;
    perlin.Shuffle(10);

    for(int x = 0 ; x < image.width() ; x++)
        for(int y = 0 ; y < image.height() ; y++)
        {
            float value =  perlin.Get({x , y, 0.f, 1.f},0.01f);

            unsigned int greyscale = static_cast<unsigned int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    image.save("perlin4d.bmp");
    std::cout<<"Saved perlin4d.bmp"<<std::endl;
}
