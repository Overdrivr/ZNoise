#include <iostream>
#include "Simplex.hpp"
#include "include_all.hpp"

void generate_simplex(cimg_library::CImg<unsigned char> & image)
{
    /* Generate Simplex 2D */
    Simplex simplex;
    simplex.Shuffle(10);

    for(int x = 0 ; x < image.width() ; x++)
        for(int y = 0 ; y < image.height() ; y++)
        {
            float value =  simplex.Get({x,y},0.01f);

            unsigned int greyscale = static_cast<unsigned int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    image.save("simplex2d.bmp");
    std::cout<<"Saved simplex2d.bmp"<<std::endl;
}

void generate_simplex_3dslice(cimg_library::CImg<unsigned char> & image)
{
    /* Generate Simplex 3D */
    Simplex simplex;
    simplex.Shuffle(10);

    for(int x = 0 ; x < image.width() ; x++)
        for(int y = 0 ; y < image.height() ; y++)
        {
            float value =  simplex.Get({x,y,1.f},0.01f);
            
            unsigned int greyscale = static_cast<unsigned int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    image.save("simplex3d.bmp");
    std::cout<<"Saved simplex3d.bmp"<<std::endl;
}

void generate_simplex_4dslice(cimg_library::CImg<unsigned char> & image)
{
    /* Generate Simplex 4D */
    Simplex simplex;
    simplex.Shuffle(10);

    for(int x = 0 ; x < image.width() ; x++)
        for(int y = 0 ; y < image.height() ; y++)
        {
            float value =  simplex.Get({x,y,1.f,2.f},0.01f);

            unsigned int greyscale = static_cast<unsigned int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    image.save("simplex4d.bmp");
    std::cout<<"Saved simplex4d.bmp"<<std::endl;
}
