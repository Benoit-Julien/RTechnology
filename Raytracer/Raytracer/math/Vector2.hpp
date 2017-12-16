/*
** Vector2.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. déc. 17:43 2017 benoit_g
** Last update mer. déc. 17:43 2017 benoit_g
*/

#ifndef RTECHNOLOGY_VECTOR2_HPP
#define RTECHNOLOGY_VECTOR2_HPP

#include <cmath>
#include <iostream>
#include <af/array.h>
#include <af/arith.h>
#include <arrayfire.h>

#include "../config.h"

template<typename T>
class Vector2
{
 private:
  af::array _array;

  explicit Vector2(const af::array &array) : _array(array)
  {}

  explicit Vector2(af::array &&array) : _array(array)
  {}

 public:
  explicit Vector2();

  Vector2(const T &x, const T &y) : _array(af::constant(0, 2))
  {
    this->_array(0) = x;
    this->_array(1) = y;
  }

  Vector2(const Vector2 &vector) : _array(vector._array)
  {}

  Vector2(Vector2 &&vector) noexcept : _array(vector._array)
  {}

  Vector2 &operator=(const Vector2 &vector)
  {
    this->_array = vector._array;

    return *this;
  }

  Vector2 &operator=(Vector2 &&vector) noexcept
  {
    this->_array = vector._array;

    return *this;
  }

  ~Vector2() = default;

  inline void Set(const T &x, const T &y)
  {
    this->_array(0) = x;
    this->_array(1) = y;
  }

  inline void Set(T &&x, T &&y)
  {
    this->_array(0) = x;
    this->_array(1) = y;
  }

  inline void Normalize()
  {
    this->_array /= this->magnitude();
  }

  T x() const;

  T y() const;

  inline T magnitude() const
  {
    return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar();
  }

  Vector2 operator+(const Vector2<T> &vec) const
  {
    auto tmp = this->_array + vec._array;

    return Vector2(tmp);
  }
  Vector2 &operator+=(const Vector2<T> &vec)
  {
    this->_array += vec._array;

    return *this;
  }

  Vector2 operator+(const T &value) const
  {
    auto tmp = this->_array + value;

    return Vector2(tmp);
  }
  Vector2 &operator+=(const T &value)
  {
    this->_array += value;

    return *this;
  }

  Vector2 &operator-()
  {
    this->_array *= -1;

    return *this;
  }

  Vector2 operator-(const Vector2<T> &vec) const
  {
    auto tmp = this->_array - vec._array;

    return Vector2(tmp);
  }
  Vector2 &operator-=(const Vector2<T> &vec)
  {
    this->_array -= vec._array;

    return *this;
  }

  Vector2 operator-(const T &value) const
  {
    auto tmp = this->_array - value;

    return Vector2(tmp);
  }
  Vector2 &operator-=(const T &value)
  {
    this->_array -= value;

    return *this;
  }

  Vector2 operator*(const Vector2<T> &vec) const
  {
    auto tmp = this->_array * vec._array;

    return Vector2(tmp);
  }
  Vector2 &operator*=(const Vector2<T> &vec)
  {
    this->_array *= vec._array;

    return *this;
  }

  Vector2 operator*(const T &value) const
  {
    auto tmp = this->_array * value;

    return Vector2(tmp);
  }
  Vector2 &operator*=(const T &value)
  {
    this->_array *= value;

    return *this;
  }

  Vector2 operator/(const Vector2<T> &vec) const
  {
    auto tmp = this->_array / vec._array;

    return Vector2(tmp);
  }
  Vector2 &operator/=(const Vector2<T> &vec)
  {
    this->_array /= vec._array;

    return *this;
  }

  Vector2 operator/(const T &value) const
  {
    auto tmp = this->_array / value;

    return Vector2(tmp);
  }
  Vector2 operator/=(const T &value)
  {
    this->_array /= value;

    return *this;
  }

  bool operator==(const Vector2<T> &vec) const
  {
    return this->x() == vec.x()
	   && this->y() == vec.y();
  }
  bool operator!=(const Vector2<T> &vec) const
  {
    return this->x() != vec.x()
	   || this->y() != vec.y();
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vector2<T> &vec)
{
  os << "Vector2 :" << std::endl;
  os << "\tx = " << vec.x() << std::endl;
  os << "\ty = " << vec.y();

  return os;
}

#ifndef INT_SPECIALIZATION
  #define INT_SPECIALIZATION

template<>
Vector2<int>::Vector2() : _array(af::constant(0, 2, s32))
{}

template<>
Vector2<int>::Vector2(const int &x, const int &y) : _array(af::constant(0, 2, s32))
{
  this->_array(0) = x;
  this->_array(1) = y;
}

template<>
int Vector2<int>::x() const
{
  return this->_array(0).scalar<int>();
}

template<>
int Vector2<int>::y() const
{
  return this->_array(1).scalar<int>();
}
#endif

#ifndef LONG_SPECIALIZATION
  #define LONG_SPECIALIZATION
  #ifdef ENVIRONMENT64

template<>
Vector2<long>::Vector2() : _array(af::constant(0, 2, s64))
{}

template<>
Vector2<long>::Vector2(const long &x, const long &y) : _array(af::constant(0, 2, s64))
{
  this->_array(0) = x;
  this->_array(1) = y;
}

template<>
long Vector2<long>::x() const
{
  return this->_array(0).scalar<long>();
}

template<>
long Vector2<long>::y() const
{
  return this->_array(1).scalar<long>();
}
  #endif
#endif

#ifndef UNSIGNED_SPECIALIZATION
  #define UNSIGNED_SPECIALIZATION

template<>
Vector2<unsigned>::Vector2() : _array(af::constant(0, 2, u32))
{}

template<>
Vector2<unsigned>::Vector2(const unsigned &x, const unsigned &y) : _array(af::constant(0, 2, u32))
{
  this->_array(0) = x;
  this->_array(1) = y;
}

template<>
unsigned Vector2<unsigned>::x() const
{
  return this->_array(0).scalar<unsigned>();
}

template<>
unsigned Vector2<unsigned>::y() const
{
  return this->_array(1).scalar<unsigned>();
}
#endif

#ifndef FLOAT_SPECIALIZATION
  #define FLOAT_SPECIALIZATION

template<>
Vector2<float>::Vector2() : _array(af::constant(0, 2, f32))
{}

template<>
Vector2<float>::Vector2(const float &x, const float &y) : _array(af::constant(0, 2, f32))
{
  this->_array(0) = x;
  this->_array(1) = y;
}

template<>
float Vector2<float>::x() const
{
  return this->_array(0).scalar<float>();
}

template<>
float Vector2<float>::y() const
{
  return this->_array(1).scalar<float>();
}
#endif

#ifndef DOUBLE_SPECIALIZATION
  #define DOUBLE_SPECIALIZATION
  #ifdef ENVIRONMENT64

template<>
Vector2<double>::Vector2() : _array(af::constant(0, 2, f64))
{}

template<>
Vector2<double>::Vector2(const double &x, const double &y) : _array(af::constant(0, 2, f64))
{
  this->_array(0) = x;
  this->_array(1) = y;
}

template<>
double Vector2<double>::x() const
{
  return this->_array(0).scalar<double>();
}

template<>
double Vector2<double>::y() const
{
  return this->_array(1).scalar<double>();
}
  #endif
#endif

typedef Vector2<int> Vector2Int;
typedef Vector2<real_t> Vector2Real;

#endif /* !RTECHNOLOGY_VECTOR2_HPP */
