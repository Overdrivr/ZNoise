//
// ZNoise - C++ Noise and Random Numbers library
// Copyright (C) 2011-2013 BEGES Rémi (remi.beges@gmail.com)
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

#include <iostream>

template<typename T>
class Vector3;


template<typename T>
class Vector3
{
    public:
        T X;
        T Y;
        T Z;

        Vector3()
        {
            X = 0;
            Y = 0;
            Z = 0;
        }
        Vector3(T aX, T aY, T aZ) : X(aX),Y(aY),Z(aZ)
        {}
        Vector3(const Vector3<T> & v)
        {
            X = v.X;
            Y = v.Y;
            Z = v.Z;
        }
        Vector3(const Vector3<T> & from,const Vector3<T> & to)
        {
            X = to.X - from.X;
            Y = to.Y - from.Y;
            Z = to.Z - from.Z;
        }
        ~Vector3()
        {

        }

        double length();
        Vector3<T> & normalize();
        Vector3<T> crossProduct(const Vector3<T> & v);
        float dotProduct(const Vector3<T> & v);

        Vector3<T> & operator=  (const Vector3<T> & v);
        Vector3<T> & operator+= (const Vector3<T> & v);
        Vector3<T>   operator+  (const Vector3<T> & v);
        Vector3<T> & operator-= (const Vector3<T> & v);
        Vector3<T>   operator-  (const Vector3<T> & v);
        Vector3<T> & operator*= (const double a);
        Vector3<T>   operator*  (const double a);
        Vector3<T> & operator/= (const double a);
        Vector3<T>   operator/  (const double a);
    private:
};




template<typename T>
Vector3<T> & Vector3<T>::operator= (const Vector3<T> & v)
{
    X = v.X;
    Y = v.Y;
    Z = v.Z;
    return *this;
}

template<typename T>
Vector3<T> & Vector3<T>::operator+= (const Vector3<T> & v)
{
    X += v.X;
    Y += v.Y;
    Z += v.Z;
    return *this;
}

template<typename T>
Vector3<T> Vector3<T>::operator+ (const Vector3<T> & v)
{
    Vector3<T> t = *this;
    t += v;
    return t;
}

template<typename T>
Vector3<T> & Vector3<T>::operator-= (const Vector3<T> & v)
{
    X -= v.X;
    Y -= v.Y;
    Z -= v.Z;
    return *this;
}

template<typename T>
Vector3<T> Vector3<T>::operator- (const Vector3<T> & v)
{
    Vector3<T> t = *this;
    t -= v;
    return t;
}

template<typename T>
Vector3<T> & Vector3<T>::operator*= (const double a)
{
    X *= a;
    Y *= a;
    Z *= a;
    return *this;
}

template<typename T>
Vector3<T> Vector3<T>::operator* (const double a)
{
    Vector3<T> t = *this;
    t *= a;
    return t;
}

template<typename T>
Vector3<T> & Vector3<T>::operator/= (const double a)
{
    X /= a;
    Y /= a;
    Z /= a;
    return *this;
}

template<typename T>
Vector3<T> Vector3<T>::operator/ (const double a)
{
    Vector3<T> t = *this;
    t /= a;
    return t;
}

template<typename T>
Vector3<T> Vector3<T>::crossProduct(const Vector3<T> & v)
{
    Vector3<T> t;
    t.X = Y*v.Z - Z*v.Y;
    t.Y = Z*v.X - X*v.Z;
    t.Z = X*v.Y - Y*v.X;
    return t;
}

template<typename T>
double Vector3<T>::length()
{
    return sqrt( X*X + Y*Y + Z*Z);
}

template<typename T>
Vector3<T> & Vector3<T>::normalize()
{
    (*this) /= length();
    return (*this);
}

template<typename T>
float Vector3<T>::dotProduct(const Vector3<T> & v)
{
    return (X*v.X + Y*v.Y + Z*v.Z);
}

/*template<typename T>
std::ostream& operator<< (std::ostream& flux,const Vector3<T>& v)
{
    flux<<"("<<v.X<<","<<v.Y<<","<<v.Z<<")";
    return flux;
}*/


/*----------------        Operateurs    ------------------------------*/

/*template<typename T>
bool operator==(const Vector3<T>& a, const Vector3<T>& b)
{

}*/


#endif // VECTOR3_H
