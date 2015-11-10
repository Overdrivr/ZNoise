// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#ifndef PERLIN2D_HPP
#define PERLIN2D_HPP

#include "NoiseBase.hpp"

class Perlin2D : public NoiseBase
{
    public:
        Perlin2D();
        Perlin2D(unsigned int seed);
        ~Perlin2D() = default;

        float Get();

        void Set(float X, float Y);

    protected:
        float x;
        float y;
    private:
        float xc, yc;
        int x0, y0;
        int gi0,gi1,gi2,gi3;
        int ii, jj;
        float gradient2[8][2];
        float s,t,u,v;
        float Cx,Cy;
        float Li1, Li2;
        float tempx,tempy;
};

#endif // PERLIN2D_HPP

