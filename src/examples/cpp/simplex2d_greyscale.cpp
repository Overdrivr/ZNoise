#include <iostream>
#include "Simplex2D.hpp"
#include "include_all.hpp"

void generate_simplex(cimg_library::CImg<unsigned char> & image)
{
    /* Generate Simplex 2D */
    Simplex2D simplex2d;
    simplex2d.Shuffle(10);

    for(int x = 0 ; x < image.width() ; x++)
        for(int y = 0 ; y < image.height() ; y++)
        {
            simplex2d.Set(x,y);
            float value =  simplex2d.Get();

            unsigned int greyscale = static_cast<unsigned int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    image.save("simplex2d.bmp");
    std::cout<<"Saved simplex2d.bmp"<<std::endl;
}
