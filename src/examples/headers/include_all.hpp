#ifndef INCLUDE_ALL_EXAMPLES_HPP
#define INCLUDE_ALL_EXAMPLES_HPP

#include "CImg.h"
#include "Enums.hpp"

void generate_perlin(cimg_library::CImg<unsigned char> & image);
void generate_perlin_3dslice(cimg_library::CImg<unsigned char> & image);
void generate_perlin_4dslice(cimg_library::CImg<unsigned char> & image);
void generate_simplex(cimg_library::CImg<unsigned char> & image);
void generate_simplex_3dslice(cimg_library::CImg<unsigned char> & image);
void generate_simplex_4dslice(cimg_library::CImg<unsigned char> & image);
void generate_worley(cimg_library::CImg<unsigned char> & image,WorleyFunction worleyFunc);
void generate_fbm(cimg_library::CImg<unsigned char> & image, float hurst, float lacunarity, float baseScale);
void generate_hmf(cimg_library::CImg<unsigned char> & image, float hurst, float lacunarity, float baseScale);

#endif
