// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#include "../include/CombinedNoiseBase.hpp"
#include "../include/FBM.hpp"

FBM::FBM(NoiseBase& source): m_source(source)
{
}

float FBM::Get()
{
    m_value = 0.0;

    float initialScale = m_source.GetScale();

    for (int i(0); i < m_octaves; ++i)
    {
        m_value += m_source.Get() * m_exponent_array[i];
        m_scale *= m_lacunarity;
        m_source.SetScale(m_scale);
    }
    m_remainder = m_octaves - static_cast<int>(m_octaves);

    if(std::fabs(m_remainder) > 0.01f)
      m_value += m_remainder * m_source.Get() * m_exponent_array[static_cast<int>(m_octaves-1)];

    m_source.SetScale(initialScale);

    return m_value/m_sum;
}
