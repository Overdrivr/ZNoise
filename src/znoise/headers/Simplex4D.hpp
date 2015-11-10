// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#ifndef SIMPLEX4D_HPP
#define SIMPLEX4D_HPP

#include "NoiseBase.hpp"

class Simplex4D : public NoiseBase
{
    public:
        Simplex4D();
        Simplex4D(unsigned int seed);
        ~Simplex4D() = default;

        float Get();

        void Set(float X, float Y, float Z, float W);

    protected:
        float x;
        float y;
        float z;
        float w;
    private:
        float xc,yc,zc,wc;
        int ii,jj,kk,ll;
        int gi0,gi1,gi2,gi3,gi4;
        int skewedCubeOriginx,skewedCubeOriginy,skewedCubeOriginz,skewedCubeOriginw;
        int off1x,off1y,off1z,off1w;
        int off2x,off2y,off2z,off2w;
        int off3x,off3y,off3z,off3w;
        int lookupTable4D[64][4];
        int c;
        float n1,n2,n3,n4,n5;
        float c1,c2,c3,c4,c5,c6;
        float gradient4[32][4];
        float UnskewCoeff4D;
        float SkewCoeff4D;
        float sum;
        float unskewedCubeOriginx,unskewedCubeOriginy,unskewedCubeOriginz,unskewedCubeOriginw;
        float unskewedDistToOriginx,unskewedDistToOriginy,unskewedDistToOriginz,unskewedDistToOriginw;
        float d1x,d2x,d3x,d4x,d5x;
        float d1y,d2y,d3y,d4y,d5y;
        float d1z,d2z,d3z,d4z,d5z;
        float d1w,d2w,d3w,d4w,d5w;
};

#endif // SIMPLEX4D_H

