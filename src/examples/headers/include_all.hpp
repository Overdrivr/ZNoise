#ifndef INCLUDE_ALL_EXAMPLES_HPP
#define INCLUDE_ALL_EXAMPLES_HPP

#include "CImg.h"
#include "Enums.hpp"

void generate_perlin(cimg_library::CImg<unsigned char> & image);
void generate_perlin_3dslice(cimg_library::CImg<unsigned char> & image);
void generate_perlin_4dslice(cimg_library::CImg<unsigned char> & image);
void generate_simplex(cimg_library::CImg<unsigned char> & image);
void generate_worley_F1(cimg_library::CImg<unsigned char> & image,WorleyFunction worleyFunc);

#endif
