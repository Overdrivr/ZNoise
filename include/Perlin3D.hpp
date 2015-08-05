// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#ifndef PERLIN3D_HPP
#define PERLIN3D_HPP

#include "NoiseBase.hpp"

class Perlin3D : public NoiseBase
{
    public:
        Perlin3D();
        Perlin3D(unsigned int seed);
        ~Perlin3D() = default;

        float Get();

        void Set(float X, float Y, float Z);

    protected:
        float x;
        float y;
        float z;
    private:
        float xc, yc, zc;
        int x0,y0,z0;
        int gi0,gi1,gi2,gi3,gi4,gi5,gi6,gi7;
        int ii,jj,kk;
        float gradient3[16][3];
        float Li1,Li2,Li3,Li4,Li5,Li6;
        float s[2],t[2],u[2],v[2];
        float Cx,Cy,Cz;
        float nx,ny,nz;
        float tmp;
        float tempx,tempy,tempz;
};

#endif // PERLIN3D_HPP
