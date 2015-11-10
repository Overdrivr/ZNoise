// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#ifndef HYBRIDMULTIFRACTAL_HPP
#define HYBRIDMULTIFRACTAL_HPP

#include "CombinedNoiseBase.hpp"
#include "Enums.hpp"

class HybridMultiFractal : public CombinedNoiseBase
{
    public:
        HybridMultiFractal(NoiseBase& source);
        HybridMultiFractal(const HybridMultiFractal&) = delete;
        ~HybridMultiFractal() = default;

        float Get();

        HybridMultiFractal & operator=(const HybridMultiFractal&) = delete;

    protected:
    private:
        NoiseBase& m_source;
        float m_value;
        float m_remainder;
        float m_offset;
        float m_weight;
        float m_signal;
};

#endif // HYBRIDMULTIFRACTAL_HPP

