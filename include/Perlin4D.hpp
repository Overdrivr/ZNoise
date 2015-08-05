// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#ifndef PERLIN4D_HPP
#define PERLIN4D_HPP

#include "NoiseBase.hpp"

class Perlin4D : public NoiseBase
{
    public:
        Perlin4D();
        Perlin4D(unsigned int seed);
        ~Perlin4D() = default;

        float Get();

        void Set(float X, float Y, float Z, float W);

    protected:
        float x;
        float y;
        float z;
        float w;
    private:
        float xc,yc,zc,wc;
        int x0,y0,z0,w0;
        int gi0,gi1,gi2,gi3,gi4,gi5,gi6,gi7,gi8,gi9,gi10,gi11,gi12,gi13,gi14,gi15;
        int ii,jj,kk,ll;
        float gradient4[32][4];
        float Li1,Li2,Li3,Li4,Li5,Li6,Li7,Li8,Li9,Li10,Li11,Li12,Li13,Li14;
        float s[4],t[4],u[4],v[4];
        float Cx,Cy,Cz,Cw;
        float tmp;
        float tempx,tempy,tempz,tempw;
};

#endif // PERLIN4D_HPP
