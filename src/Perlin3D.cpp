// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#include "../include/Perlin3D.hpp"
#include "../include/NoiseTools.hpp"

Perlin3D::Perlin3D()
{
    float grad3Temp[][3] = {
        {1,1,0},{-1,1,0},{1,-1,0},{-1,-1,0},
        {1,0,1},{-1,0,1},{1,0,-1},{-1,0,-1},
        {0,1,1},{0,-1,1},{0,1,-1},{0,-1,-1},
        {1,1,0},{-1,1,0},{0,-1,1},{0,-1,-1}
    };

    for(int i(0) ; i < 16 ; ++i)
        for(int j(0) ; j < 3 ; ++j)
            gradient3[i][j] = grad3Temp[i][j];
}

Perlin3D::Perlin3D(unsigned int seed) : Perlin3D()
{
    SetSeed(seed);
    Shuffle();
}

float Perlin3D::Get()
{
    xc = x * m_scale;
    yc = y * m_scale;
    zc = z * m_scale;

    x0 = fastfloor(xc);
    y0 = fastfloor(yc);
    z0 = fastfloor(zc);

    ii = x0 & 255;
    jj = y0 & 255;
    kk = z0 & 255;

    gi0 = perm[ii +     perm[jj +     perm[kk]]] & 15;
    gi1 = perm[ii + 1 + perm[jj +     perm[kk]]] & 15;
    gi2 = perm[ii +     perm[jj + 1 + perm[kk]]] & 15;
    gi3 = perm[ii + 1 + perm[jj + 1 + perm[kk]]] & 15;

    gi4 = perm[ii +     perm[jj +     perm[kk + 1]]] & 15;
    gi5 = perm[ii + 1 + perm[jj +     perm[kk + 1]]] & 15;
    gi6 = perm[ii +     perm[jj + 1 + perm[kk + 1]]] & 15;
    gi7 = perm[ii + 1 + perm[jj + 1 + perm[kk + 1]]] & 15;

    tempx = xc - x0;
    tempy = yc - y0;
    tempz = zc - z0;

    Cx = tempx * tempx * tempx * (tempx * (tempx * 6 - 15) + 10);
    Cy = tempy * tempy * tempy * (tempy * (tempy * 6 - 15) + 10);
    Cz = tempz * tempz * tempz * (tempz * (tempz * 6 - 15) + 10);

    s[0] = gradient3[gi0][0]*tempx + gradient3[gi0][1]*tempy + gradient3[gi0][2]*tempz;

    tempx = xc - (x0 + 1);
    t[0] = gradient3[gi1][0]*tempx + gradient3[gi1][1]*tempy + gradient3[gi1][2]*tempz;

    tempy = yc - (y0 + 1);
    v[0] = gradient3[gi3][0]*tempx + gradient3[gi3][1]*tempy + gradient3[gi3][2]*tempz;

    tempx = xc - x0;
    u[0] = gradient3[gi2][0]*tempx + gradient3[gi2][1]*tempy + gradient3[gi2][2]*tempz;

    tempy = yc - y0;
    tempz = zc - (z0 + 1);
    s[1] = gradient3[gi4][0]*tempx + gradient3[gi4][1]*tempy + gradient3[gi4][2]*tempz;

    tempx = xc - (x0 + 1);
    t[1] = gradient3[gi5][0]*tempx + gradient3[gi5][1]*tempy + gradient3[gi5][2]*tempz;

    tempy = yc - (y0 + 1);
    v[1] = gradient3[gi7][0]*tempx + gradient3[gi7][1]*tempy + gradient3[gi7][2]*tempz;

    tempx = xc - x0;
    u[1] = gradient3[gi6][0]*tempx + gradient3[gi6][1]*tempy + gradient3[gi6][2]*tempz;

    Li1 = s[0] + Cx*(t[0]-s[0]);
    Li2 = u[0] + Cx*(v[0]-u[0]);
    Li3 = s[1] + Cx*(t[1]-s[1]);
    Li4 = u[1] + Cx*(v[1]-u[1]);

    Li5 = Li1 + Cy * (Li2-Li1);
    Li6 = Li3 + Cy * (Li4-Li3);

    return Li5 + Cz * (Li6-Li5);
}

void Perlin3D::Set(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}
