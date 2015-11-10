// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#include "Simplex4D.hpp"
#include "NoiseTools.hpp"

Simplex4D::Simplex4D()
{
    SkewCoeff4D = (std::sqrt(5.f) - 1.f)/4.f;
    UnskewCoeff4D = (5.f - std::sqrt(5.f))/20.f;

    int lookupTemp4D[][4] =
    {
        {0,1,2,3},{0,1,3,2},{0,0,0,0},{0,2,3,1},{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,2,3,0},
        {0,2,1,3},{0,0,0,0},{0,3,1,2},{0,3,2,1},{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,3,2,0},
        {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
        {1,2,0,3},{0,0,0,0},{1,3,0,2},{0,0,0,0},{0,0,0,0},{0,0,0,0},{2,3,0,1},{2,3,1,0},
        {1,0,2,3},{1,0,3,2},{0,0,0,0},{0,0,0,0},{0,0,0,0},{2,0,3,1},{0,0,0,0},{2,1,3,0},
        {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
        {2,0,1,3},{0,0,0,0},{0,0,0,0},{0,0,0,0},{3,0,1,2},{3,0,2,1},{0,0,0,0},{3,1,2,0},
        {2,1,0,3},{0,0,0,0},{0,0,0,0},{0,0,0,0},{3,1,0,2},{0,0,0,0},{3,2,0,1},{3,2,1,0}
    };

    for(int i(0) ; i < 64 ; ++i)
        for(int j(0) ; j < 4 ; ++j)
            lookupTable4D[i][j] = lookupTemp4D[i][j];

    float grad4Temp[][4] =
    {
        {0.f,1.f,1.f,1.f}, {0.f,1.f,1.f,-1.f}, {0.f,1.f,-1.f,1.f}, {0.f,1.f,-1.f,-1.f},
        {0.f,-1.f,1.f,1.f},{0.f,-1.f,1.f,-1.f},{0.f,-1.f,-1.f,1.f},{0.f,-1.f,-1.f,-1.f},
        {1.f,0.f,1.f,1.f}, {1.f,0.f,1.f,-1.f}, {1.f,0.f,-1.f,1.f}, {1.f,0.f,-1.f,-1.f},
        {-1.f,0.f,1.f,1.f},{-1.f,0.f,1.f,-1.f},{-1.f,0.f,-1.f,1.f},{-1.f,0.f,-1.f,-1.f},
        {1.f,1.f,0.f,1.f}, {1.f,1.f,0.f,-1.f}, {1.f,-1.f,0.f,1.f}, {1.f,-1.f,0.f,-1.f},
        {-1.f,1.f,0.f,1.f},{-1.f,1.f,0.f,-1.f},{-1.f,-1.f,0.f,1.f},{-1.f,-1.f,0.f,-1.f},
        {1.f,1.f,1.f,0.f}, {1.f,1.f,-1.f,0.f}, {1.f,-1.f,1.f,0.f}, {1.f,-1.f,-1.f,0.f},
        {-1.f,1.f,1.f,0.f},{-1.f,1.f,-1.f,0.f},{-1.f,-1.f,1.f,0.f},{-1.f,-1.f,-1.f,0.f}
    };

    for(int i(0) ; i < 32 ; ++i)
        for(int j(0) ; j < 4 ; ++j)
            gradient4[i][j] = grad4Temp[i][j];
}

Simplex4D::Simplex4D(unsigned int seed) : Simplex4D()
{
    SetSeed(seed);
    Shuffle();
}

float Simplex4D::Get()
{
    xc = x * m_scale;
    yc = y * m_scale;
    zc = z * m_scale;
    wc = w * m_scale;

    sum = (xc + yc + zc + wc) * SkewCoeff4D;
    skewedCubeOriginx = fastfloor(xc + sum);
    skewedCubeOriginy = fastfloor(yc + sum);
    skewedCubeOriginz = fastfloor(zc + sum);
    skewedCubeOriginw = fastfloor(wc + sum);

    sum = (skewedCubeOriginx + skewedCubeOriginy + skewedCubeOriginz + skewedCubeOriginw) * UnskewCoeff4D;
    unskewedCubeOriginx = skewedCubeOriginx - sum;
    unskewedCubeOriginy = skewedCubeOriginy - sum;
    unskewedCubeOriginz = skewedCubeOriginz - sum;
    unskewedCubeOriginw = skewedCubeOriginw - sum;

    unskewedDistToOriginx = x - unskewedCubeOriginx;
    unskewedDistToOriginy = y - unskewedCubeOriginy;
    unskewedDistToOriginz = z - unskewedCubeOriginz;
    unskewedDistToOriginw = w - unskewedCubeOriginw;

    c1 = (unskewedDistToOriginx > unskewedDistToOriginy) ? 32 : 0;
    c2 = (unskewedDistToOriginx > unskewedDistToOriginz) ? 16 : 0;
    c3 = (unskewedDistToOriginy > unskewedDistToOriginz) ? 8  : 0;
    c4 = (unskewedDistToOriginx > unskewedDistToOriginw) ? 4  : 0;
    c5 = (unskewedDistToOriginy > unskewedDistToOriginw) ? 2  : 0;
    c6 = (unskewedDistToOriginz > unskewedDistToOriginw) ? 1  : 0;
    c = c1 + c2 + c3 + c4 + c5 + c6;

    off1x = lookupTable4D[c][0] >= 3 ? 1 : 0;
    off1y = lookupTable4D[c][1] >= 3 ? 1 : 0;
    off1z = lookupTable4D[c][2] >= 3 ? 1 : 0;
    off1w = lookupTable4D[c][3] >= 3 ? 1 : 0;

    off2x = lookupTable4D[c][0] >= 2 ? 1 : 0;
    off2y = lookupTable4D[c][1] >= 2 ? 1 : 0;
    off2z = lookupTable4D[c][2] >= 2 ? 1 : 0;
    off2w = lookupTable4D[c][3] >= 2 ? 1 : 0;

    off3x = lookupTable4D[c][0] >= 1 ? 1 : 0;
    off3y = lookupTable4D[c][1] >= 1 ? 1 : 0;
    off3z = lookupTable4D[c][2] >= 1 ? 1 : 0;
    off3w = lookupTable4D[c][3] >= 1 ? 1 : 0;

    d1x = unskewedDistToOriginx;
    d1y = unskewedDistToOriginy;
    d1z = unskewedDistToOriginz;
    d1w = unskewedDistToOriginw;

    d2x = d1x - off1x + UnskewCoeff4D;
    d2y = d1y - off1y + UnskewCoeff4D;
    d2z = d1z - off1z + UnskewCoeff4D;
    d2w = d1w - off1w + UnskewCoeff4D;

    d3x = d1x - off2x + 2.f*UnskewCoeff4D;
    d3y = d1y - off2y + 2.f*UnskewCoeff4D;
    d3z = d1z - off2z + 2.f*UnskewCoeff4D;
    d3w = d1w - off2w + 2.f*UnskewCoeff4D;

    d4x = d1x - off3x + 3.f*UnskewCoeff4D;
    d4y = d1y - off3y + 3.f*UnskewCoeff4D;
    d4z = d1z - off3z + 3.f*UnskewCoeff4D;
    d4w = d1w - off3w + 3.f*UnskewCoeff4D;

    d5x = d1x - 1.f + 4*UnskewCoeff4D;
    d5y = d1y - 1.f + 4*UnskewCoeff4D;
    d5z = d1z - 1.f + 4*UnskewCoeff4D;
    d5w = d1w - 1.f + 4*UnskewCoeff4D;

    ii = skewedCubeOriginx & 255;
    jj = skewedCubeOriginy & 255;
    kk = skewedCubeOriginz & 255;
    ll = skewedCubeOriginw & 255;

    gi0 = perm[ii +         perm[jj +         perm[kk +         perm[ll        ]]]] & 31;
    gi1 = perm[ii + off1x + perm[jj + off1y + perm[kk + off1z + perm[ll + off1w]]]] & 31;
    gi2 = perm[ii + off2x + perm[jj + off2y + perm[kk + off2z + perm[ll + off2w]]]] & 31;
    gi3 = perm[ii + off3x + perm[jj + off3y + perm[kk + off3z + perm[ll + off3w]]]] & 31;
    gi4 = perm[ii + 1 +     perm[jj + 1 +     perm[kk + 1 +     perm[ll + 1    ]]]] % 32;

    c1 = 0.6f - d1x*d1x - d1y*d1y - d1z*d1z - d1w*d1w;
    c2 = 0.6f - d2x*d2x - d2y*d2y - d2z*d2z - d2w*d2w;
    c3 = 0.6f - d3x*d3x - d3y*d3y - d3z*d3z - d3w*d3w;
    c4 = 0.6f - d4x*d4x - d4y*d4y - d4z*d4z - d4w*d4w;
    c5 = 0.6f - d5x*d5x - d5y*d5y - d5z*d5z - d5w*d5w;

    if(c1 < 0)
        n1 = 0;
    else
        n1 = c1*c1*c1*c1*(gradient4[gi0][0]*d1x + gradient4[gi0][1]*d1y + gradient4[gi0][2]*d1z + gradient4[gi0][3]*d1w);

    if(c2 < 0)
        n2 = 0;
    else
        n2 = c2*c2*c2*c2*(gradient4[gi1][0]*d2x + gradient4[gi1][1]*d2y + gradient4[gi1][2]*d2z + gradient4[gi1][3]*d2w);

    if(c3 < 0)
        n3 = 0;
    else
        n3 = c3*c3*c3*c3*(gradient4[gi2][0]*d3x + gradient4[gi2][1]*d3y + gradient4[gi2][2]*d3z + gradient4[gi2][3]*d3w);

    if(c4 < 0)
        n4 = 0;
    else
        n4 = c4*c4*c4*c4*(gradient4[gi3][0]*d4x + gradient4[gi3][1]*d4y + gradient4[gi3][2]*d4z + gradient4[gi3][3]*d4w);

    if(c5 < 0)
        n5 = 0;
    else
        n5 = c5*c5*c5*c5*(gradient4[gi4][0]*d5x + gradient4[gi4][1]*d5y + gradient4[gi4][2]*d5z + gradient4[gi4][3]*d5w);

    return (n1+n2+n3+n4+n5)*27.f;
}

void Simplex4D::Set(float X, float Y, float Z, float W)
{
    x = X;
    y = Y;
    z = Z;
    w = W;
}
