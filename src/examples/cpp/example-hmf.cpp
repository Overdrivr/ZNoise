#include <iostream>
#include <sstream>
#include "Simplex.hpp"
#include "HybridMultiFractal.hpp"
#include "include_all.hpp"

void generate_hmf(cimg_library::CImg<unsigned char> & image, float hurst, float lacunarity, float baseScale)
{
    /* Use simplex as source */
    Simplex simplex;
    simplex.Shuffle(10);

    HybridMultiFractal hmf(simplex);
    hmf.SetParameters(hurst,lacunarity,5.f);

    for(int x = 0 ; x < image.width() ; x++)
        for(int y = 0 ; y < image.height() ; y++)
        {
            float value =  hmf.Get({x , y}, baseScale);

            unsigned int greyscale = static_cast<unsigned int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    std::stringstream name;
    name << "hybridmultifractal_h" << hurst << "_l" << lacunarity << ".bmp";
    image.save(name.str().c_str());
    std::cout<<"Saved "<<name.str() <<std::endl;
}
