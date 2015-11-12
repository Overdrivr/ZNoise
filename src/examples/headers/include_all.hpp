#include "CImg.h"
#include "Enums.hpp"

void generate_perlin(cimg_library::CImg<unsigned char> & image);
void generate_simplex(cimg_library::CImg<unsigned char> & image);
void generate_worley(cimg_library::CImg<unsigned char> & image,WorleyFunction worleyFunc);
