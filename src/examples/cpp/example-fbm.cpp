#include <iostream>
#include "Simplex.hpp"
#include "FBM.hpp"
#include "include_all.hpp"

void generate_fbm(cimg_library::CImg<unsigned char> & image)
{
    /* Use simplex as source */
    Simplex simplex;
    simplex.Shuffle(10);

    FBM fbm(simplex);

    for(int x = 0 ; x < image.width() ; x++)
        for(int y = 0 ; y < image.height() ; y++)
        {
            float value =  fbm.Get({x , y},0.01f);

            unsigned int greyscale = static_cast<unsigned int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    image.save("fbm2d.bmp");
    std::cout<<"Saved fbm2d.bmp"<<std::endl;
}
