#include <iostream>
#include "../../examples/common/CImg.h"
#include "../../include/Perlin2D.hpp"
#include "../../include/Simplex2D.hpp"
#include "../../include/Worley2D.hpp"

using namespace std;
using namespace cimg_library;

void generate_perlin(CImg<unsigned char> & image);
void generate_simplex(CImg<unsigned char> & image);
void generate_worley(CImg<unsigned char> & image,WorleyFunction worleyFunc);

// You need to add libgdi32.a in your IDE linker options

int main()

{
    CImg<unsigned char> image(128,128,1,3,0);
    generate_perlin(image);
    generate_simplex(image);
    generate_worley(image,WorleyFunction_F1);

    return 0;
}

void generate_perlin(CImg<unsigned char> & image)
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

void generate_simplex(CImg<unsigned char> & image)
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

void generate_worley(CImg<unsigned char> & image,WorleyFunction worleyFunc)
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
