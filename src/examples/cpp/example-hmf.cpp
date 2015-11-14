#include <iostream>
#include "Simplex.hpp"
#include "HybridMultiFractal.hpp"
#include "include_all.hpp"

void generate_hmf(cimg_library::CImg<unsigned char> & image)
{
    /* Use simplex as source */
    Simplex simplex;
    simplex.Shuffle(10);

    HybridMultiFractal hmf(simplex);

    for(int x = 0 ; x < image.width() ; x++)
        for(int y = 0 ; y < image.height() ; y++)
        {
            float value =  hmf.Get({x , y},0.01f);

            unsigned int greyscale = static_cast<unsigned int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    image.save("hybridmultifractal.bmp");
    std::cout<<"Saved hmf.bmp"<<std::endl;
}
