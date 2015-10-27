// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#include "../include/Simplex3D.hpp"
#include "../include/NoiseTools.hpp"

Simplex3D::Simplex3D()
{
    SkewCoeff3D = 1/3.f;
    UnskewCoeff3D = 1/6.f;

    float grad3Temp[][3] = {
		{1.f,1.f,0.f},
		{-1.f,1.f,0.f},
		{1.f,-1.f,0.f},
		{-1.f,-1.f,0.f},

		{1.f,0.f,1.f},
		{-1.f,0.f,1.f},
		{1.f,0.f,-1.f},
		{-1.f,0.f,-1.f},

		{0.f,1.f,1.f},
		{0.f,-1.f,1.f},
		{0.f,1.f,-1.f},
		{0.f,-1.f,-1.f}
	};

    for(int i(0) ; i < 12 ; ++i)
        for(int j(0) ; j < 3 ; ++j)
            gradient3[i][j] = grad3Temp[i][j];
}

Simplex3D::Simplex3D(unsigned int seed) : Simplex3D()
{
    SetSeed(seed);
    Shuffle();
}

float Simplex3D::Get()
{
    xc = x * m_scale;
    yc = y * m_scale;
    zc = z * m_scale;

    sum = (xc + yc + zc) * SkewCoeff3D;
    skewedCubeOriginx = fastfloor(xc + sum);
    skewedCubeOriginy = fastfloor(yc + sum);
    skewedCubeOriginz = fastfloor(zc + sum);

    sum = (skewedCubeOriginx + skewedCubeOriginy + skewedCubeOriginz) * UnskewCoeff3D;
    unskewedCubeOriginx = skewedCubeOriginx - sum;
    unskewedCubeOriginy = skewedCubeOriginy - sum;
    unskewedCubeOriginz = skewedCubeOriginz - sum;

    unskewedDistToOriginx = x - unskewedCubeOriginx;
    unskewedDistToOriginy = y - unskewedCubeOriginy;
    unskewedDistToOriginz = z - unskewedCubeOriginz;

    if(unskewedDistToOriginx >= unskewedDistToOriginy)
    {
        if(unskewedDistToOriginy >= unskewedDistToOriginz)
        {
            off1x = 1;
            off1y = 0;
            off1z = 0;
            off2x = 1;
            off2y = 1;
            off2z = 0;
        }
        else if(unskewedDistToOriginx >= unskewedDistToOriginz)
        {
            off1x = 1;
            off1y = 0;
            off1z = 0;
            off2x = 1;
            off2y = 0;
            off2z = 1;
        }
        else
        {
            off1x = 0;
            off1y = 0;
            off1z = 1;
            off2x = 1;
            off2y = 0;
            off2z = 1;
        }
    }
    else
    {
        if(unskewedDistToOriginy < unskewedDistToOriginz)
        {
            off1x = 0;
            off1y = 0;
            off1z = 1;
            off2x = 0;
            off2y = 1;
            off2z = 1;
        }
        else if(unskewedDistToOriginx < unskewedDistToOriginz)
        {
            off1x = 0;
            off1y = 1;
            off1z = 0;
            off2x = 0;
            off2y = 1;
            off2z = 1;
        }
        else
        {
            off1x = 0;
            off1y = 1;
            off1z = 0;
            off2x = 1;
            off2y = 1;
            off2z = 0;
        }
    }

    d1x = unskewedDistToOriginx;
    d1y = unskewedDistToOriginy;
    d1z = unskewedDistToOriginz;

    d2x = d1x - off1x + UnskewCoeff3D;
    d2y = d1y - off1y + UnskewCoeff3D;
    d2z = d1z - off1z + UnskewCoeff3D;

    d3x = d1x - off2x + 2.f*UnskewCoeff3D;
    d3y = d1y - off2y + 2.f*UnskewCoeff3D;
    d3z = d1z - off2z + 2.f*UnskewCoeff3D;

    d4x = d1x - 1.f + 3.f*UnskewCoeff3D;
    d4y = d1y - 1.f + 3.f*UnskewCoeff3D;
    d4z = d1z - 1.f + 3.f*UnskewCoeff3D;

    ii = skewedCubeOriginx & 255;
    jj = skewedCubeOriginy & 255;
    kk = skewedCubeOriginz & 255;

    gi0 = perm[ii +         perm[jj +         perm[kk         ]]] % 12;
    gi1 = perm[ii + off1x + perm[jj + off1y + perm[kk + off1z ]]] % 12;
    gi2 = perm[ii + off2x + perm[jj + off2y + perm[kk + off2z ]]] % 12;
    gi3 = perm[ii + 1 +     perm[jj + 1 +     perm[kk + 1     ]]] % 12;

    c1 = 0.6f - d1x * d1x - d1y * d1y - d1z * d1z;
    c2 = 0.6f - d2x * d2x - d2y * d2y - d2z * d2z;
    c3 = 0.6f - d3x * d3x - d3y * d3y - d3z * d3z;
    c4 = 0.6f - d4x * d4x - d4y * d4y - d4z * d4z;

    if(c1 < 0)
        n1 = 0;
    else
        n1 = c1*c1*c1*c1*(gradient3[gi0][0] * d1x + gradient3[gi0][1] * d1y + gradient3[gi0][2] * d1z);

    if(c2 < 0)
        n2 = 0;
    else
        n2 = c2*c2*c2*c2*(gradient3[gi1][0] * d2x + gradient3[gi1][1] * d2y + gradient3[gi1][2] * d2z);

    if(c3 < 0)
        n3 = 0;
    else
        n3 = c3*c3*c3*c3*(gradient3[gi2][0] * d3x + gradient3[gi2][1] * d3y + gradient3[gi2][2] * d3z);

    if(c4 < 0)
        n4 = 0;
    else
        n4 = c4*c4*c4*c4*(gradient3[gi3][0] * d4x + gradient3[gi3][1] * d4y + gradient3[gi3][2] * d4z);

    return (n1+n2+n3+n4)*32;
}

void Simplex3D::Set(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}
