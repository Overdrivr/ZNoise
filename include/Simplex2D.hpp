// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#ifndef SIMPLEX2D_HPP
#define SIMPLEX2D_HPP

#include "NoiseBase.hpp"

class Simplex2D : public NoiseBase
{
    public:
        Simplex2D();
        Simplex2D(unsigned int seed);
        virtual ~Simplex2D() = default;

        float Get();

        void Set(float X, float Y);

    protected:
        float x;
        float y;
    private:
        float xc,yc;
        int ii,jj;
        int gi0,gi1,gi2;
        int skewedCubeOriginx,skewedCubeOriginy;
        int off1x,off1y;
        float n1,n2,n3;
        float c1,c2,c3;
        float gradient2[8][2];
        float UnskewCoeff2D;
        float SkewCoeff2D;
        float sum;
        float unskewedCubeOriginx,unskewedCubeOriginy;
        float unskewedDistToOriginx,unskewedDistToOriginy;
        float d1x,d1y;
        float d2x,d2y;
        float d3x,d3y;
};

#endif // SIMPLEX2D_HPP

