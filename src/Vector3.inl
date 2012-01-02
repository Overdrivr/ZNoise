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

template <typename T>
inline Vector3<T>::Vector3()
{
    X = 0;
    Y = 0;
    Z = 0;
}
template <typename T>
inline Vector3<T>::Vector3(T aX, T aY, T aZ) : X(aX),Y(aY),Z(aZ)
{

}
template <typename T>
inline Vector3<T>::Vector3(const Vector3<T> & v)
{
    X = v.X;
    Y = v.Y;
    Z = v.Z;
}
template <typename T>
inline Vector3<T>::Vector3(const Vector3<T> & from,const Vector3<T> & to)
{
    X = to.X - from.X;
    Y = to.Y - from.Y;
    Z = to.Z - from.Z;
}

//////////////////////////////////////////////////////////////////////////////

template<typename T>
inline Vector3<T>& operator += (Vector3<T>& u, const Vector3<T> & v)
{
    u.X += v.X;
    u.Y += v.Y;
    u.Z += v.Z;
    return u;
}

template<typename T>
inline Vector3<T> operator+ (Vector3<T>& u, const Vector3<T> & v)
{
    u += v;
    return u;
}

template<typename T>
inline Vector3<T> & operator-= (Vector3<T>& u, const Vector3<T> & v)
{
    u.X -= v.X;
    u.Y -= v.Y;
    u.Z -= v.Z;
    return u;
}

template<typename T>
inline Vector3<T> operator- (Vector3<T>& u, const Vector3<T> & v)
{
    u -= v;
    return u;
}

template<typename T>
inline Vector3<T> & operator*= (Vector3<T>& u, const double a)
{
    u.X *= a;
    u.Y *= a;
    u.Z *= a;
    return u;
}

template<typename T>
inline Vector3<T> operator* (Vector3<T>& u, const double a)
{
    u *= a;
    return u;
}

template<typename T>
inline Vector3<T> & operator/= (Vector3<T>& u, const double a)
{
    u.X /= a;
    u.Y /= a;
    u.Z /= a;
    return u;
}

template<typename T>
inline Vector3<T> operator/ (Vector3<T>& u, const double a)
{
    u /= a;
    return u;
}

template<typename T>
inline Vector3<T> Vector3<T>::crossProduct(const Vector3<T> & v)
{
    Vector3<T> t;
    t.X = Y*v.Z - Z*v.Y;
    t.Y = Z*v.X - X*v.Z;
    t.Z = X*v.Y - Y*v.X;
    return t;
}

template<typename T>
inline double Vector3<T>::length()
{
    return sqrt( X*X + Y*Y + Z*Z);
}

template<typename T>
inline Vector3<T> & Vector3<T>::normalize()
{
    (*this) /= length();
    return (*this);
}

template<typename T>
inline float Vector3<T>::dotProduct(const Vector3<T> & v)
{
    return (X*v.X + Y*v.Y + Z*v.Z);
}
