// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#ifndef SIMPLEX3D_HPP
#define SIMPLEX3D_HPP

#include "NoiseBase.hpp"

class Simplex3D : public NoiseBase
{
    public:
        Simplex3D();
        Simplex3D(unsigned int seed);
        ~Simplex3D() = default;

        float Get();

        void Set(float X, float Y, float Z);

    protected:
        float x;
        float y;
        float z;
    private:
        float xc, yc, zc;
        int ii,jj,kk;
        int gi0,gi1,gi2,gi3;
        int skewedCubeOriginx,skewedCubeOriginy,skewedCubeOriginz;
        int off1x,off1y,off1z;
        int off2x,off2y,off2z;
        float n1,n2,n3,n4;
        float c1,c2,c3,c4;
        float gradient3[12][3];
        float UnskewCoeff3D;
        float SkewCoeff3D;
        float sum;
        float unskewedCubeOriginx,unskewedCubeOriginy,unskewedCubeOriginz;
        float unskewedDistToOriginx,unskewedDistToOriginy,unskewedDistToOriginz;
        float d1x,d1y,d1z;
        float d2x,d2y,d2z;
        float d3x,d3y,d3z;
        float d4x,d4y,d4z;
};

#endif // SIMPLEX3D_HPP

