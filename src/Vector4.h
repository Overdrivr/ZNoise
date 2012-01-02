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

#ifndef VECTOR4_H
#define VECTOR4_H

template<typename T>
class Vector4;


template<typename T>
class Vector4
{
    public:
        T X;
        T Y;
        T Z;
        T W;

        Vector4()
        {
            X = 0;
            Y = 0;
            Z = 0;
            W = 0;
        }
        Vector4(T aX, T aY, T aZ, T aW) : X(aX),Y(aY),Z(aZ),W(aW)
        {}
        Vector4(const Vector4<T> & v)
        {
            X = v.X;
            Y = v.Y;
            Z = v.Z;
            W = v.W;
        }
        Vector4(const Vector4<T> & from,const Vector4<T> & to)
        {
            X = to.X - from.X;
            Y = to.Y - from.Y;
            Z = to.Z - from.Z;
            W = to.W - from.W;
        }
        ~Vector4()
        {

        }

        double length();
        Vector4<T> & normalize();
        float dotProduct(const Vector4<T> & v);

        Vector4<T> & operator=  (const Vector4<T> & v);
        Vector4<T> & operator+= (const Vector4<T> & v);
        Vector4<T>   operator+  (const Vector4<T> & v);
        Vector4<T> & operator-= (const Vector4<T> & v);
        Vector4<T>   operator-  (const Vector4<T> & v);
        Vector4<T> & operator*= (const double a);
        Vector4<T>   operator*  (const double a);
        Vector4<T> & operator/= (const double a);
        Vector4<T>   operator/  (const double a);
    private:
};




template<typename T>
Vector4<T> & Vector4<T>::operator= (const Vector4<T> & v)
{
    X = v.X;
    Y = v.Y;
    Z = v.Z;
    W = v.W;
    return *this;
}

template<typename T>
Vector4<T> & Vector4<T>::operator+= (const Vector4<T> & v)
{
    X += v.X;
    Y += v.Y;
    Z += v.Z;
    W += v.W;
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
    X -= v.X;
    Y -= v.Y;
    Z -= v.Z;
    W -= v.W;
    return *this;
}

template<typename T>
Vector4<T> Vector4<T>::operator- (const Vector4<T> & v)
{
    Vector4<T> t = *this;
    t -= v;
    return t;
}

template<typename T>
Vector4<T> & Vector4<T>::operator*= (const double a)
{
    X *= a;
    Y *= a;
    Z *= a;
    W *= a;
    return *this;
}

template<typename T>
Vector4<T> Vector4<T>::operator* (const double a)
{
    Vector4<T> t = *this;
    t *= a;
    return t;
}

template<typename T>
Vector4<T> & Vector4<T>::operator/= (const double a)
{
    X /= a;
    Y /= a;
    Z /= a;
    W /= a;
    return *this;
}

template<typename T>
Vector4<T> Vector4<T>::operator/ (const double a)
{
    Vector4<T> t = *this;
    t /= a;
    return t;
}

template<typename T>
double Vector4<T>::length()
{
    return sqrt( X*X + Y*Y + Z*Z + W*W);
}

template<typename T>
Vector4<T> & Vector4<T>::normalize()
{
    (*this) /= length();
    return (*this);
}

template<typename T>
float Vector4<T>::dotProduct(const Vector4<T> & v)
{
    return (X*v.X + Y*v.Y + Z*v.Z + W*v.W);
}

#endif // VECTOR4_H
