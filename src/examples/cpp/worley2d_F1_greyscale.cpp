#include <iostream>
#include "Worley2D.hpp"
#include "include_all.hpp"

void generate_worley_F1(cimg_library::CImg<unsigned char> & image, WorleyFunction worleyFunc)
{
    /* Generate Simplex 2D */
    Worley2D worley2d(worleyFunc);
    worley2d.Shuffle(10);

    for(int x = 0 ; x < image.width() ; x++)
        for(int y = 0 ; y < image.height() ; y++)
        {
            worley2d.Set(x,y);
            float value =  worley2d.Get();

            unsigned int greyscale = static_cast<unsigned int>((value + 1.f) / 2.f * 255.f);

            image(x,y,0) = greyscale;
            image(x,y,1) = greyscale;
            image(x,y,2) = greyscale;
        }

    image.save("worley2d.bmp");
    std::cout<<"Saved worley2d.bmp"<<std::endl;
}
