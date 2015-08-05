// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#include "../include/Simplex2D.hpp"
#include "../include/NoiseTools.hpp"

Simplex2D::Simplex2D()
{
    float grad2Temp[][2] = {{1,1},{-1,1},{1,-1},{-1,-1},
                        {1,0},{-1,0},{0,1},{0,-1}};

    for(int i(0) ; i < 8 ; ++i)
        for(int j(0) ; j < 2 ; ++j)
            gradient2[i][j] = grad2Temp[i][j];

    SkewCoeff2D = 0.5f*(std::sqrt(3.f) - 1.f);
    UnskewCoeff2D  = (3.f-std::sqrt(3.f))/6.f;
}

Simplex2D::Simplex2D(unsigned int seed) : Simplex2D()
{
    SetSeed(seed);
    Shuffle();
}

float Simplex2D::Get()
{
    xc = x * m_scale;
    yc = y * m_scale;

    sum = (xc + yc) * SkewCoeff2D;
    skewedCubeOriginx = fastfloor(xc + sum);
    skewedCubeOriginy = fastfloor(yc + sum);

    sum = (skewedCubeOriginx + skewedCubeOriginy) * UnskewCoeff2D;
    unskewedCubeOriginx = skewedCubeOriginx - sum;
    unskewedCubeOriginy = skewedCubeOriginy - sum;

    unskewedDistToOriginx = xc - unskewedCubeOriginx;
    unskewedDistToOriginy = yc - unskewedCubeOriginy;

    if(unskewedDistToOriginx > unskewedDistToOriginy)
    {
        off1x = 1;
        off1y = 0;
    }
    else
    {
        off1x = 0;
        off1y = 1;
    }

    d1x = - unskewedDistToOriginx;
    d1y = - unskewedDistToOriginy;

    d2x = d1x + off1x - UnskewCoeff2D;
    d2y = d1y + off1y - UnskewCoeff2D;

    d3x = d1x + 1.f - 2.f * UnskewCoeff2D;
    d3y = d1y + 1.f - 2.f * UnskewCoeff2D;

    ii = skewedCubeOriginx & 255;
    jj = skewedCubeOriginy & 255;

    gi0 = perm[ii +         perm[jj         ]] & 7;
    gi1 = perm[ii + off1x + perm[jj + off1y ]] & 7;
    gi2 = perm[ii + 1 +     perm[jj + 1     ]] & 7;

    c1 = 0.5f - d1x * d1x - d1y * d1y;
    c2 = 0.5f - d2x * d2x - d2y * d2y;
    c3 = 0.5f - d3x * d3x - d3y * d3y;

    if(c1 < 0)
        n1 = 0;
    else
        n1 = c1*c1*c1*c1*(gradient2[gi0][0] * d1x + gradient2[gi0][1] * d1y);

    if(c2 < 0)
        n2 = 0;
    else
        n2 = c2*c2*c2*c2*(gradient2[gi1][0] * d2x + gradient2[gi1][1] * d2y);

    if(c3 < 0)
        n3 = 0;
    else
        n3 = c3*c3*c3*c3*(gradient2[gi2][0] * d3x + gradient2[gi2][1] * d3y);

    return (n1+n2+n3)*70.f;
}

void Simplex2D::Set(float X, float Y)
{
    x = X;
    y = Y;
}
