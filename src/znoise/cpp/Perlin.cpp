// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#include "Perlin.hpp"
#include "NoiseTools.hpp"
#include <iostream>
#include <exception>
#include <stdexcept>

Perlin::Perlin()
{
    float grad2Temp[][2] = {
		{1.f,1.f},
		{-1.f,1.f},
		{1.f,-1.f},
		{-1.f,-1.f},

		{1.f,0.f},
		{-1.f,0.f},
		{0.f,1.f},
		{0.f,-1.f}
	};

    /*for(int i(0) ; i < 8 ; ++i)
        for(int j(0) ; j < 2 ; ++j)
            gradient2[i][j] = grad2Temp[i][j];*/
}

Perlin::Perlin(unsigned int seed) : Perlin()
{
    SetSeed(seed);
    Shuffle();
}

float Perlin::Get(std::initializer_list<float> coordinates, float scale) const
{
    switch(coordinates.size())
    {
        case 2:
          return this->_2D(coordinates,scale);
        case 3:
          return this->_3D(coordinates,scale);
        case 4:
          return this->_4D(coordinates,scale);
        default:
          throw std::invalid_argument("Number of coordinates elements not comprised between 2 and 4");
    }
}

float Perlin::_2D(std::initializer_list<float> coordinates, float scale) const
{
    std::initializer_list<float>::const_iterator it = coordinates.begin();
    std::cout << "Perlin2D(" << *(it);
    std::cout << "," << *(++it) << ")" << std::endl;
    return 0.f;
}

float Perlin::_3D(std::initializer_list<float> coordinates, float scale) const
{
    std::initializer_list<float>::const_iterator it = coordinates.begin();
    std::cout << "Perlin3D(" << *(it);
    std::cout << "," << *(++it) << ",";
    std::cout << *(++it) << ")" << std::endl;
    return 0.f;
}

float Perlin::_4D(std::initializer_list<float> coordinates, float scale) const
{
    std::initializer_list<float>::const_iterator it = coordinates.begin();
    std::cout << "Perlin4D(" << *(it);
    std::cout << "," << *(++it) << ",";
    std::cout << *(++it) << ",";
    std::cout << *(++it) << ")" << std::endl;
    return 0.f;
}
