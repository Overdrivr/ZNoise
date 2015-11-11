#include "CImg.h"
#include "Enums.hpp"

void generate_perlin(cimg_library::CImg<unsigned char> & image);
void generate_simplex(cimg_library::CImg<unsigned char> & image);
void generate_worley_F1(cimg_library::CImg<unsigned char> & image,WorleyFunction worleyFunc);
