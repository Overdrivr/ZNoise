// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#include "../include/Perlin2D.hpp"
#include "../include/NoiseTools.hpp"
#include <iostream>

Perlin2D::Perlin2D()
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

    for(int i(0) ; i < 8 ; ++i)
        for(int j(0) ; j < 2 ; ++j)
            gradient2[i][j] = grad2Temp[i][j];
}

Perlin2D::Perlin2D(unsigned int seed) : Perlin2D()
{
    SetSeed(seed);
    Shuffle();
}

float Perlin2D::Get()
{
    xc = x * m_scale;
    yc = y * m_scale;

    x0 = fastfloor(xc);
    y0 = fastfloor(yc);

    ii = x0 & 255;
    jj = y0 & 255;

    gi0 = perm[ii +     perm[jj]] & 7;
    gi1 = perm[ii + 1 + perm[jj]] & 7;
    gi2 = perm[ii +     perm[jj + 1]] & 7;
    gi3 = perm[ii + 1 + perm[jj + 1]] & 7;

    tempx = xc - x0;
    tempy = yc - y0;

    Cx = tempx * tempx * tempx * (tempx * (tempx * 6 - 15) + 10);
    Cy = tempy * tempy * tempy * (tempy * (tempy * 6 - 15) + 10);

    s = gradient2[gi0][0]*tempx + gradient2[gi0][1]*tempy;

    tempx = xc - (x0 + 1);
    t = gradient2[gi1][0]*tempx + gradient2[gi1][1]*tempy;

    tempy = yc - (y0 + 1);
    v = gradient2[gi3][0]*tempx + gradient2[gi3][1]*tempy;

    tempx = xc - x0;
    u = gradient2[gi2][0]*tempx + gradient2[gi2][1]*tempy;

    Li1 = s + Cx*(t-s);
    Li2 = u + Cx*(v-u);

    return Li1 + Cy*(Li2-Li1);
}

void Perlin2D::Set(float X, float Y)
{
    x = X;
    y = Y;
}
