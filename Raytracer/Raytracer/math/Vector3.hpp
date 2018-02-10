/*
** Vector3.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. déc. 17:43 2017 benoit_g
** Last update mer. déc. 17:43 2017 benoit_g
*/

#ifndef RTECHNOLOGY_VECTOR3_HPP
#define RTECHNOLOGY_VECTOR3_HPP

#include <cmath>
#include <af/array.h>
#include <af/arith.h>
#include <arrayfire.h>

#include "../config.h"

template<typename T>
class RT_DLL Vector3
{
  af::array _array;

 private:
  explicit Vector3(const af::array &array) : _array(array)
  {}

  explicit Vector3(af::array &&array) : _array(array)
  {}

  inline af::array getNormArray() const
  {
    return af::sqrt(af::sum(af::pow(this->_array, 2)));
  }

 public:
  static const Vector3<T> forward;
  static const Vector3<T> back;

  static const Vector3<T> up;
  static const Vector3<T> down;

  static const Vector3<T> right;
  static const Vector3<T> left;

  explicit Vector3();
  Vector3(const T &x, const T &y, const T &z);
  Vector3(const Vector3<T> &vector) : _array(vector._array)
  {}

  Vector3(Vector3<T> &&vector) noexcept : _array(vector._array)
  {}

  Vector3<T> &operator=(const Vector3<T> &vector)
  {
    this->_array = vector._array;

    return *this;
  }

  Vector3<T> &operator=(Vector3<T> &&vector) noexcept
  {
    this->_array = vector._array;

    return *this;
  }

  ~Vector3() = default;

  Vector3<T> operator+(const Vector3<T> &vec) const
  {
    auto tmp = this->_array + vec._array;

    return Vector3<T>(tmp);
  }
  Vector3<T> &operator+=(const Vector3<T> &vec)
  {
    this->_array += vec._array;

    return *this;
  }

  Vector3<T> operator+(const T &value) const
  {
    auto tmp = this->_array + value;

    return Vector3<T>(tmp);
  }
  Vector3<T> &operator+=(const T &value)
  {
    this->_array += value;

    return *this;
  }

  Vector3<T> &operator-()
  {
    this->_array *= -1;

    return *this;
  }

  Vector3<T> operator-(const Vector3<T> &vec) const
  {
    auto tmp = this->_array - vec._array;

    return Vector3<T>(tmp);
  }
  Vector3<T> &operator-=(const Vector3<T> &vec)
  {
    this->_array -= vec._array;

    return *this;
  }

  Vector3<T> operator-(const T &value) const
  {
    auto tmp = this->_array - value;

    return Vector3<T>(tmp);
  }
  Vector3<T> &operator-=(const T &value)
  {
    this->_array -= value;

    return *this;
  }

  Vector3<T> operator*(const Vector3<T> &vec) const
  {
    auto tmp = this->_array * vec._array;

    return Vector3<T>(tmp);
  }
  Vector3<T> &operator*=(const Vector3<T> &vec)
  {
    this->_array *= vec._array;

    return *this;
  }

  Vector3<T> operator*(const T &value) const
  {
    auto tmp = this->_array * value;

    return Vector3<T>(tmp);
  }
  Vector3<T> &operator*=(const T &value)
  {
    this->_array *= value;

    return *this;
  }

  Vector3<T> operator/(const Vector3<T> &vec) const
  {
    auto tmp = this->_array / vec._array;

    return Vector3<T>(tmp);
  }
  Vector3<T> &operator/=(const Vector3<T> &vec)
  {
    this->_array /= vec._array;

    return *this;
  }

  Vector3<T> operator/(const T &value) const
  {
    auto tmp = this->_array / value;

    return Vector3<T>(tmp);
  }
  Vector3<T> &operator/=(const T &value)
  {
    this->_array /= value;

    return *this;
  }

  Vector3<float> nomalized() const
  {
    Vector3<float> norm;

    norm._array = this->_array / this->getNormArray();
    return norm;
  }

  bool operator<(const Vector3<T> &vec) const;
  bool operator>(const Vector3<T> &vec) const;
  bool operator<=(const Vector3<T> &vec) const;
  bool operator>=(const Vector3<T> &vec) const;

  void Set(const T &x, const T &y, const T &z)
  {
    this->_array(0) = x;
    this->_array(1) = y;
    this->_array(2) = z;
  }

  void Set(T &&x, T &&y, T &&z)
  {
    this->_array(0) = x;
    this->_array(1) = y;
    this->_array(2) = z;
  }

  bool Equal(const Vector3<T> &vec) const
  {
    return this->x() == vec.x() && this->y() == vec.y() && this->z() == vec.z();
  }

  T x() const;

  T y() const;

  T z() const;

  T magnitude() const;

  static T Dot(const Vector3<T> &vec1, const Vector3<T> &vec2);

  static Vector3<T> Cross(const Vector3<T> &vec1, const Vector3<T> &vec2)
  {
    Vector3<T> newvec;

    newvec._array(0) = vec1._array(1) * vec2._array(2) - vec1._array(2) * vec2._array(1);
    newvec._array(1) = vec1._array(2) * vec2._array(0) - vec1._array(0) * vec2._array(2);
    newvec._array(2) = vec1._array(0) * vec2._array(1) - vec1._array(1) * vec2._array(0);

    return newvec;
  }

  static T Distance(const Vector3<T> &vec1, const Vector3<T> &vec2)
  {
    auto vec = vec1 - vec2;
    return vec.magnitude();
  }

  static float Angle(const Vector3<T> &vec1, const Vector3<T> &vec2);

  bool operator==(const Vector3<T> &vec) const
  {
    return this->Equal(vec);
  }

  bool operator!=(const Vector3<T> &vec) const
  {
    return !this->Equal(vec);
  }

  float operator^(const float &value) const
  {
    af::array tmp = af::sum(af::pow(this->_array, value));
    return tmp.scalar<float>();
  }
};

template<typename T>
const Vector3<T> Vector3<T>::forward = Vector3(0, 0, 1);

template<typename T>
const Vector3<T> Vector3<T>::back = Vector3(0, 0, -1);

template<typename T>
const Vector3<T> Vector3<T>::up = Vector3(0, 1, 0);

template<typename T>
const Vector3<T> Vector3<T>::down = Vector3(0, -1, 0);

template<typename T>
const Vector3<T> Vector3<T>::right = Vector3(-1, 0, 0);

template<typename T>
const Vector3<T> Vector3<T>::left = Vector3(1, 0, 0);

template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector3<T> &vec)
{
  os << "Vector3 :" << std::endl;
  os << "\tx = " << vec.x() << std::endl;
  os << "\ty = " << vec.y() << std::endl;
  os << "\tz = " << vec.z();

  return os;
}

typedef Vector3<int> Vector3I;
typedef Vector3<float> Vector3F;

#endif /* !RTECHNOLOGY_VECTOR3_HPP */
