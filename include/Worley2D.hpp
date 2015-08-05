// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#ifndef WORLEY2D_HPP
#define WORLEY2D_HPP


#include "NoiseBase.hpp"
#include "Enums.hpp"
#include <random>
#include <map>

class Worley2D : public NoiseBase
{
    struct vec2
    {
        float x;
        float y;
    };

    public:
        Worley2D(WorleyFunction function = WorleyFunction_F1);
        Worley2D(unsigned int seed);
        ~Worley2D() = default;

        float Get();
        //FIX ME : Rajouter fonction pour récupérer l'état complet après un calcul

        void Set(float X, float Y);
        void SetFunction(WorleyFunction function);

    protected:
        float x;
        float y;
    private:
        void SquareTest(int xi, int yi, float x, float y);

        std::map<float,vec2> featurePoints;
        std::map<float,vec2>::iterator it;
        std::minstd_rand0 randomNumberGenerator;
        float scale[4];
        WorleyFunction m_function;

        float xc, yc;
        int seed;
        int x0, y0;
        int ii, jj;
        float fractx, fracty;
};

#endif // WORLEY2D_HPP

