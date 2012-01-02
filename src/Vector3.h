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

#ifndef VECTOR3_H
#define VECTOR3_H

template<typename T>
class Vector3;


template<typename T>
class Vector3
{
    public:
        Vector3();
        Vector3(T aX, T aY, T aZ);
        explicit Vector3(const Vector3<T> & v);
        explicit Vector3(const Vector3<T> & from,const Vector3<T> & to);

        T X;
        T Y;
        T Z;

        double length();
        Vector3<T> & normalize();
        Vector3<T> crossProduct(const Vector3<T> & v);
        float dotProduct(const Vector3<T> & v);

};

template<typename T>
Vector3<T>& operator+= (Vector3<T>& u, const Vector3<T> & v);

template<typename T>
Vector3<T>   operator+  (Vector3<T>& u, const Vector3<T> & v);

template<typename T>
Vector3<T> & operator-= (Vector3<T>& u, const Vector3<T> & v);

template<typename T>
Vector3<T>   operator-  (Vector3<T>& u, const Vector3<T> & v);

template<typename T>
Vector3<T> & operator*= (Vector3<T>& u, const double a);

template<typename T>
Vector3<T>   operator*  (Vector3<T>& u, const double a);

template<typename T>
Vector3<T> & operator/= (Vector3<T>& u, const double a);

template<typename T>
Vector3<T>   operator/  (Vector3<T>& u, const double a);

#include "Vector3.inl"

#endif // VECTOR3_H
