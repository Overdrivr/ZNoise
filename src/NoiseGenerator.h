//
// ZNoise - C++ Noise and Random Numbers library
// Copyright (C) 2011-2013 BEGES Rémi (remi{dot}beges{at}gmail{dot}com)
//
// This library is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// You can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License as published
// by the Free Software Foundation, either version 2.1 of the License,
// or any later version.

// According to the LGPL, permission is granted to anyone to use this library for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef NOISEGENERATOR_HPP
#define NOISEGENERATOR_HPP

template<typename T>
class Vector4
{
    public:
        T x;
        T y;
        T z;
        T w;

        Vector4()
        {
            x = 0;  y = 0;  z = 0;  w = 0;
        }
        Vector4(T X, T Y, T Z, T W) : x(X),y(Y),z(Z),w(W)
        {}
        Vector4(const Vector4<T> & v)
        {
            x = v.x;    y = v.y;    z = v.z;    w = v.w;
        }
        Vector4(const Vector4<T> & from,const Vector4<T> & to)
        {
            x = to.x - from.x;
            y = to.y - from.y;
            z = to.z - from.z;
            w = to.w - from.w;
        }
        ~Vector4() = default;

        Vector4<T> & operator=  (const Vector4<T> & v);
        Vector4<T> & operator+= (const Vector4<T> & v);
        Vector4<T>   operator+  (const Vector4<T> & v);
        Vector4<T> & operator-= (const Vector4<T> & v);
        Vector4<T>   operator-  (const Vector4<T> & v);
};

typedef Vector4<float> Vector4f;
typedef Vector4<double> Vector4d;
typedef Vector4<int> Vector4i;

class NoiseGenerator
{
    public:
        NoiseGenerator(int seed = 0);
        ~NoiseGenerator() = default;

        void SetNewSeed(int seed);
        int GetUniformRandomValue();
        void ShufflePermutationTable();

        int fastfloor(float n);
        int JenkinsHash(int a, int b, int c);

        float Get2DPerlinNoiseValue (float x, float y,                   float res);
        float Get3DPerlinNoiseValue (float x, float y, float z,          float res);
        float Get4DPerlinNoiseValue (float x, float y, float z, float w, float res);

        float Get2DSimplexNoiseValue(float x, float y,                   float res);
        float Get3DSimplexNoiseValue(float x, float y, float z,          float res);
        float Get4DSimplexNoiseValue(float x, float y, float z, float w, float res);

        float Get3DCellNoiseValue(float x, float y, float z,          float res);

        float Get2DFBMNoiseValue(float x, float y,          float res);
        float Get3DFBMNoiseValue(float x, float y, float z, float res);

        float Get2DHybridMultiFractalNoiseValue(float x, float y,          float res);
        float Get3DHybridMultiFractalNoiseValue(float x, float y, float z, float res);


        void SetLacunarity(float lacunarity);
        void SetHurstParameter(float h);
        void SetOctavesNumber(float octaves);
        void RecomputeExponentArray();


    private:

        ///--------- Common Variables -----------
        int Ua, Uc, Um;
        int UcurrentSeed;
        int Uprevious, Ulast;
        int ii,jj,kk,ll;
        int gi0,gi1,gi2,gi3,gi4,gi5,gi6,gi7,gi8,gi9,gi10,gi11,gi12,gi13,gi14,gi15;
        int perm[512];

        ///--------- Complex Noise Variables ----

        float m_lacunarity;
        float m_hurst;
        float m_octaves;
        float exponent_array[30];
        float m_sum;
        bool m_parametersModified;

        float gradient2[8][2];
        int gradient3[16][3];
        int gradient4[32][4];
        int lookupTable4D[64][4];

        ///-------  Simplex variables  -----------

        float n1, n2, n3, n4, n5;
        Vector4f d1,d2,d3,d4,d5,unskewedCubeOrigin,unskewedDistToOrigin;
        Vector4i off1, off2,off3,skewedCubeOrigin;


        float c1,c2,c3,c4,c5,c6;
        int c;

        float SkewCoeff2D;
        float UnskewCoeff2D;

        float SkewCoeff3D;
        float UnskewCoeff3D;

        float SkewCoeff4D;
        float UnskewCoeff4D;

        float sum;

        ///-------  Perlin Variables  ----------

        int x0,y0,z0,w0;
        float Li1,Li2,Li3,Li4,Li5,Li6,Li7,Li8,Li9,Li10,Li11,Li12,Li13,Li14;
        float s[4],t[4],u[4],v[4];
        float Cx, Cy, Cz, Cw;
        Vector4f temp;
        float tmp;

        ///------  Complex Noise Variables -----

        bool first;
        float value;
        float remainder;
        float smax;
        float smin;


};



template<typename T>
Vector4<T> & Vector4<T>::operator= (const Vector4<T> & v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
    return *this;
}

template<typename T>
Vector4<T> & Vector4<T>::operator+= (const Vector4<T> & v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

template<typename T>
Vector4<T> Vector4<T>::operator+ (const Vector4<T> & v)
{
    Vector4<T> t = *this;
    t += v;
    return t;
}

template<typename T>
Vector4<T> & Vector4<T>::operator-= (const Vector4<T> & v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

template<typename T>
Vector4<T> Vector4<T>::operator- (const Vector4<T> & v)
{
    Vector4<T> t = *this;
    t -= v;
    return t;
}

#endif // NOISEGENERATOR_HPP
