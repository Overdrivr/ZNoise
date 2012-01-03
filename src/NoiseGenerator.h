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

#ifndef NOISEGENERATOR_H
#define NOISEGENERATOR_H

#include "Vector4.h"

#define MAX_OCTAVES 15

class NoiseGenerator
{
    public:
        NoiseGenerator(int seed = 0,double sigma = 1, double mu = 0);

        //Just change the current seed, doesn't update permutation tables, call MixPermutationTable() for that
        void SetNewSeed(int seed);
        //Return each time called a new pseudo-random number comprised between -2147483648 to 2147483647
            //Generated numbers follow a uniform law
            int GetUniformRandomValue();
            //Generated numbers follow a normal law
            double GetNormalRandomValue();
            //Setup the normal law values
            //If sigma == 0, sigma = 1
            void SetupNormalLaw(double sigma, double mu);
        //Shuffles pseudo-randomly the Permutation table (used by all noise sources and complex noises as well) according to the current seed
        void MixPermutationTable();

        //------  Coherent noises   -----

        //Perlin noise
        float Get1DPerlinNoiseValue(float x, float res);
        float Get2DPerlinNoiseValue(float x, float y, float res);
        float Get3DPerlinNoiseValue(float x, float y, float z, float res);
        float Get4DPerlinNoiseValue(float x, float y, float z, float w, float res);

        //Simplex noise
        float Get2DSimplexNoiseValue(float x, float y, float resolution);
        float Get3DSimplexNoiseValue(float x, float y, float z, float resolution);
        float Get4DSimplexNoiseValue(float x, float y, float z, float w, float resolution);

        //Cell Noise
        float Get2DCellNoiseValue(float x, float y, float res);
        float Get3DCellNoiseValue(float x, float y, float z, float res);
        float Get4DCellNoiseValue(float x, float y, float z, float w, float res);


        //Worley Noise (?)


        //----------     COMPLEX NOISES    ----------------
        /*
        *****  fractionnal Brownian motion noise fBm  *****
        H : fractal increment
        lacunarity : gap between successive frequencies
        octaves : number of frequencies
        */
        float Get2DFBMNoiseValue(float x, float y, double H, double lacunarity, double octaves, double resolution);
        float Get3DFBMNoiseValue(float x, float y,float z,double H, double lacunarity, double octaves, double resolution);
        float Get2DHybridMultiFractalNoiseValue(float x, float y,double H, double lacunarity, double octaves, double resolution);
        float Get3DHybridMultiFractalNoiseValue(float x, float y, float z, double H, double lacunarity, double octaves, double resolution);



        //Probability Density function
        double pdf(double x);
        //Pour tronquer les nombres
        int fastfloor(float n);
        void DisplayExtremes();
        float GetMax();
        float GetMin();

        ~NoiseGenerator();
    private:
        double pi;
        float max;
        float min;
        int perm[512];
        int PermutationTemp[256];
        int gradient3[16][3];
        int gradient4[32][4];
        int lookupTable4D[64][4];

        //multiplicative congruential generator
        int UcurrentSeed;
        int Ua,Uc,Um;
        int Uprevious;
        int Ulast;

        //normal random number generator
        double zn;
        double rectanglesX[128];
        double rectanglesY[128];
        double m_sigma;
        double m_mu;

        //Simplex variables
        double n1, n2, n3, n4, n5; //Contribution des sommets au bruit total
        Vector4<double> A;//Les points de la grille englobant le point
        Vector4<int> Origin;
        Vector4<double> d1,d2,d3,d4,d5;
        Vector4<int> off1, off2,off3;//Les offsets des points
        Vector4<double> IsoOriginDist;
        Vector4<double> H[5];//Les valeurs renvoyées par la fonction Random3D pour chaque sommet

        double SkewCoeff2D;
        double UnskewCoeff2D;
        int ii,jj,kk,ll;

        int gi0,gi1,gi2,gi3,gi4,gi5,gi6,gi7,gi8,gi9,gi10,gi11,gi12,gi13,gi14,gi15;
        float lenght;
        float c1,c2,c3,c4,c5,c6;
        int c;

        double SkewCoeff3D;
        double UnskewCoeff3D;

        double SkewCoeff4D;
        double UnskewCoeff4D;

        //Perlin Variables
        float Li1,Li2,Li3,Li4,Li5,Li6,Li7,Li8,Li9,Li10,Li11,Li12,Li13,Li14;//résultats intermédiaires de lissage
        int x0,y0,z0,w0;
        float s[4],t[4],u[4],v[4]; //Les sommets
        float Cx, Cy, Cz, Cw;//Les coeffs de lissage
        Vector4<float> temp;
        float final;
        float dist;
        float nx,ny,nz,nw;
        double tmp;

        //fBm variables
        double exponent_array[MAX_OCTAVES];
        bool first;

        float smax;
        float smin;
};

#endif // NOISEGENERATOR_H
