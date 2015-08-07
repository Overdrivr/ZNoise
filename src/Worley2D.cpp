// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#include "../include/Worley2D.hpp"
#include "../include/NoiseTools.hpp"

Worley2D::Worley2D(WorleyFunction function)
{
    m_function = function;
    scale[0] = 1.f / std::sqrt(2);
    scale[1] = scale[0] / 2.f;
    scale[2] = scale[1];
    scale[3] = scale[2];
}

Worley2D::Worley2D(unsigned int seed) : Worley2D()
{
    SetSeed(seed);
    Shuffle();
}

float Worley2D::Get()
{
    xc = x * m_scale;
    yc = y * m_scale;

    x0 = fastfloor(xc);
    y0 = fastfloor(yc);

    fractx = xc - static_cast<float>(x0);
    fracty = yc - static_cast<float>(y0);

    featurePoints.clear();

    SquareTest(x0,y0,xc,yc);

    it = featurePoints.begin();
    std::advance(it,m_function);

    if(fractx < it->first)
        SquareTest(x0 - 1,y0,xc,yc);

    it = featurePoints.begin();
    std::advance(it,m_function);

    if(1.f - fractx < it->first)
        SquareTest(x0 + 1,y0,xc,yc);

    it = featurePoints.begin();
    std::advance(it,m_function);

    if(fracty < it->first)
        SquareTest(x0,y0 - 1,xc,yc);

    it = featurePoints.begin();
    std::advance(it,m_function);

    if(1.f - fracty < it->first)
        SquareTest(x0,y0 + 1,xc,yc);

    it = featurePoints.begin();
    std::advance(it,m_function);

    if(fractx < it->first &&
       fracty < it->first)
       SquareTest(x0 - 1, y0 - 1,xc,yc);

    it = featurePoints.begin();
    std::advance(it,m_function);

    if(1.f - fractx < it->first &&
       fracty < it->first)
       SquareTest(x0 + 1, y0 - 1,xc,yc);

    it = featurePoints.begin();
    std::advance(it,m_function);

    if(fractx < it->first &&
       1.f - fracty < it->first)
       SquareTest(x0 - 1, y0 + 1,xc,yc);

    it = featurePoints.begin();
    std::advance(it,m_function);

    if(1.f - fractx < it->first &&
       1.f - fracty < it->first)
       SquareTest(x0 + 1, y0 + 1,xc,yc);

    it = featurePoints.begin();
    std::advance(it,m_function);

    return it->first * scale[m_function];
}

void Worley2D::SetFunction(WorleyFunction function)
{
    m_function = function;
}

void Worley2D::SquareTest(int xi, int yi, float x, float y)
{
    ii = xi & 255;
    jj = yi & 255;

    seed = perm[ii +     perm[jj]];

    //On initialise notre rng avec seed
    randomNumberGenerator.seed(seed);

    //On prend un nombre de points à déterminer dans le cube, compris entre 1 et 8
    unsigned int m = (seed & 7) + 1;

    //On calcule les emplacements des différents points
    for(unsigned int i(0) ; i < m ; ++i)
    {
        vec2 featurePoint;
        featurePoint.x = (randomNumberGenerator() & 1023) / 1023.f + static_cast<float>(xi);
        featurePoint.y = (randomNumberGenerator() & 1023) / 1023.f + static_cast<float>(yi);

        // TODO : Check order is correct
        float distance = std::sqrt((featurePoint.x - x) * (featurePoint.x - x) +
                                   (featurePoint.y - y) * (featurePoint.y - y));

        //Insertion dans la liste triée
        featurePoints[distance] = featurePoint;
    }
}

void Worley2D::Set(float X, float Y)
{
    x = X;
    y = Y;
}
