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
#include <af/array.h>
#include <af/arith.h>
#include <arrayfire.h>

#include "../config.h"

template<typename T>
class RT_DLL Vector2
{
  af::array _array;

 private:
  explicit Vector2(const af::array &array) : _array(array)
  {}

  explicit Vector2(af::array &&array) : _array(array)
  {}

  inline af::array getNormArray() const
  {
    return af::sqrt(af::sum(af::pow(this->_array, 2)));
  }

 public:
  static const Vector2<T> up;
  static const Vector2<T> down;

  static const Vector2<T> right;
  static const Vector2<T> left;

  explicit Vector2();

  Vector2(const T &x, const T &y);

  Vector2(const Vector2<T> &vector) : _array(vector._array)
  {}

  Vector2(Vector2<T> &&vector) noexcept : _array(vector._array)
  {}

  Vector2 &operator=(const Vector2<T> &vector)
  {
    this->_array = vector._array;
    return *this;
  }

  Vector2 &operator=(Vector2<T> &&vector) noexcept
  {
    this->_array = vector._array;
    return *this;
  }

  ~Vector2() = default;

  Vector2<T> operator+(const Vector2<T> &vec) const
  {
    auto tmp = this->_array + vec._array;

    return Vector2<T>(tmp);
  }
  Vector2<T> &operator+=(const Vector2<T> &vec)
  {
    this->_array += vec._array;

    return *this;
  }

  Vector2<T> operator+(const T &value) const
  {
    auto tmp = this->_array + value;

    return Vector2<T>(tmp);
  }
  Vector2<T> &operator+=(const T &value)
  {
    this->_array += value;

    return *this;
  }

  Vector2<T> &operator-()
  {
    this->_array *= -1;

    return *this;
  }

  Vector2<T> operator-(const Vector2<T> &vec) const
  {
    auto tmp = this->_array - vec._array;

    return Vector2<T>(tmp);
  }
  Vector2<T> &operator-=(const Vector2<T> &vec)
  {
    this->_array -= vec._array;

    return *this;
  }

  Vector2<T> operator-(const T &value) const
  {
    auto tmp = this->_array - value;

    return Vector2<T>(tmp);
  }
  Vector2<T> &operator-=(const T &value)
  {
    this->_array -= value;

    return *this;
  }

  Vector2<T> operator*(const Vector2<T> &vec) const
  {
    auto tmp = this->_array * vec._array;

    return Vector2<T>(tmp);
  }
  Vector2<T> &operator*=(const Vector2<T> &vec)
  {
    this->_array *= vec._array;

    return *this;
  }

  Vector2<T> operator*(const T &value) const
  {
    auto tmp = this->_array * value;

    return Vector2<T>(tmp);
  }
  Vector2<T> &operator*=(const T &value)
  {
    this->_array *= value;

    return *this;
  }

  Vector2<T> operator/(const Vector2<T> &vec) const
  {
    auto tmp = this->_array / vec._array;

    return Vector2<T>(tmp);
  }
  Vector2<T> &operator/=(const Vector2<T> &vec)
  {
    this->_array /= vec._array;

    return *this;
  }

  Vector2<T> operator/(const T &value) const
  {
    auto tmp = this->_array / value;

    return Vector2<T>(tmp);
  }
  Vector2<T> &operator/=(const T &value)
  {
    this->_array /= value;

    return *this;
  }

  Vector2<float> nomalized() const
  {
    Vector2<float> norm;

    norm._array = this->_array / this->getNormArray();
    return norm;
  }

  bool operator<(const Vector2<T> &vec) const;
  bool operator>(const Vector2<T> &vec) const;
  bool operator<=(const Vector2<T> &vec) const;
  bool operator>=(const Vector2<T> &vec) const;

  void Set(const T &x, const T &y)
  {
    this->_array(0) = x;
    this->_array(1) = y;
  }

  void Set(T &&x, T &&y)
  {
    this->_array(0) = x;
    this->_array(1) = y;
  }

  bool Equal(const Vector2<T> &vec) const
  {
    return this->x() == vec.x() && this->y() == vec.y();
  }

  T x() const;

  T y() const;

  T magnitude() const;

  static T Dot(const Vector2<T> &vec1, const Vector2<T> &vec2);

  static T Distance(const Vector2<T> &vec1, const Vector2<T> &vec2);

  static float Angle(const Vector2<T> &vec1, const Vector2<T> &vec2);

  bool operator==(const Vector2<T> &vec) const
  {
    return this->Equal(vec);
  }

  bool operator!=(const Vector2<T> &vec) const
  {
    return !this->Equal(vec);
  }
};

template<typename T>
const Vector2<T> Vector2<T>::up = Vector2(0, 1);

template<typename T>
const Vector2<T> Vector2<T>::down = Vector2(0, -1);

template<typename T>
const Vector2<T> Vector2<T>::right = Vector2(1, 0);

template<typename T>
const Vector2<T> Vector2<T>::left = Vector2(-1, 0);

template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector2<T> &vec)
{
  os << "Vector2 :" << std::endl;
  os << "\tx = " << vec.x() << std::endl;
  os << "\ty = " << vec.y();

  return os;
}

typedef Vector2<int> Vector2I;
typedef Vector2<float> Vector2F;

#endif /* !RTECHNOLOGY_VECTOR2_HPP */
