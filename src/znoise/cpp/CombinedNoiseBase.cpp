// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#include <cmath>
#include "CombinedNoiseBase.hpp"

CombinedNoiseBase::CombinedNoiseBase()
{
    m_lacunarity = 5.0f;
    m_hurst = 1.2f;
    m_octaves = 3.0f;
}

float CombinedNoiseBase::GetLacunarity() const
{

    return m_lacunarity;
}

float CombinedNoiseBase::GetHurstParameter() const
{
    return m_hurst;
}

float CombinedNoiseBase::GetOctaveNumber() const
{
    return m_octaves;
}

void CombinedNoiseBase::SetParameters(float hurst, float lacunarity, float octaves)
{
    m_lacunarity = lacunarity;
    m_hurst = hurst;
    m_octaves = octaves;

    float frequency = 1.0;
    m_sum = 0.f;
    for (int i(0) ; i < static_cast<int>(m_octaves) ; ++i)
    {

        m_exponent_array[i] = std::pow( frequency, -m_hurst );
        frequency *= m_lacunarity;

        m_sum += m_exponent_array[i];

    }
}
