#include <iostream>
#include "Worley.hpp"
#include "include_all.hpp"

void generate_worley(cimg_library::CImg<unsigned char> & image, WorleyFunction worleyFunc)
{
    /* Generate Simplex 2D */
    Worley worley;
    worley.Shuffle(10);

    for(int x = 0 ; x < image.width() ; x++)
        for(int y = 0 ; y < image.height() ; y++)
        {
            float value =  worley.Get({x,y},0.01f);

            unsigned int greyscale = static_cast<unsigned int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    image.save("worley2d.bmp");
    std::cout<<"Saved worley2d.bmp"<<std::endl;
}
