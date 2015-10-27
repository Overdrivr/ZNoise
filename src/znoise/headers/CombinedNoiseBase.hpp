// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#ifndef COMBINEDNOISEBASE_HPP
#define COMBINEDNOISEBASE_HPP

#include "NoiseBase.hpp""
#include <array>

class CombinedNoiseBase : public NoiseBase
{
    public:
        CombinedNoiseBase();
        ~CombinedNoiseBase() = default;

        float GetHurstParameter() const;
        float GetLacunarity() const;
        float GetOctaveNumber() const;
        void SetParameters(float hurst, float lacunarity, float octaves);

    protected:
        float m_lacunarity;
        float m_hurst;
        float m_octaves;
        std::vector<float> m_exponent_array;
        float m_sum;
};

#endif // COMBINEDNOISEBASE_HPP
