#include <iostream>
#include <string>
#include <sstream>
#include "Worley2D.hpp"
#include "include_all.hpp"

void generate_worley(cimg_library::CImg<unsigned char> & image, WorleyFunction worleyFunc)
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

    std::ostringstream path;
    path << "worley2d_F" << worleyFunc + 1 << ".bmp";
    image.save(path.str().c_str());
    std::cout<<"Saved "<< path.str()<<std::endl;
}
