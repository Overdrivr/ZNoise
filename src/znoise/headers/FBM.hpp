// Copyright (C) 2015 Rémi Bèges
// This file is part of ZNoise - a C++ noise library
// For conditions of distribution and use, see LICENSE file

#ifndef FBM_HPP
#define FBM_HPP

#include "CombinedNoiseBase.hpp"
#include "Enums.hpp"

class FBM : public CombinedNoiseBase
{
    public:
        FBM(NoiseBase& source);
        FBM(const FBM&) = delete;
        ~FBM() = default;

        float Get();

        FBM & operator=(const FBM&) = delete;

    protected:
    private:
        NoiseBase& m_source;
        float m_value;
        float m_remainder;
};

#endif // FBM_HPP
