/*
** AVector.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 18:43 2017 benoit_g
** Last update mar. déc. 18:43 2017 benoit_g
*/

#ifndef RTECHNOLOGY_AVECTOR_HPP
#define RTECHNOLOGY_AVECTOR_HPP

#include <cmath>
#include <af/array.h>
#include <af/arith.h>
#include <arrayfire.h>

#include "../config.h"

template<typename T>
class AVector
{
 protected:
  af::array _array;

  explicit AVector(const af::array &array) : _array(array)
  {}

  explicit AVector(af::array &&array) : _array(array)
  {}

  inline af::array getNormArray() const
  {
    return af::sqrt(af::sum(af::pow(this->_array, 2)));
  }

 public:
  explicit AVector() = default;

  AVector(const AVector &vector) : _array(vector._array)
  {}

  AVector(AVector &&vector) noexcept : _array(vector._array)
  {}

  AVector &operator=(const AVector &vector)
  {
    this->_array = vector._array;

    return *this;
  }

  AVector &operator=(AVector &&vector) noexcept
  {
    this->_array = vector._array;

    return *this;
  }

  virtual ~AVector() = default;

  AVector<T> operator+(const AVector<T> &vec) const
  {
    auto tmp = this->_array + vec._array;

    return AVector<T>(tmp);
  }
  AVector<T> &operator+=(const AVector<T> &vec)
  {
    this->_array += vec._array;

    return *this;
  }

  AVector<T> operator+(const T &value) const
  {
    auto tmp = this->_array + value;

    return AVector<T>(tmp);
  }
  AVector<T> &operator+=(const T &value)
  {
    this->_array += value;

    return *this;
  }

  AVector &operator-()
  {
    this->_array *= -1;

    return *this;
  }

  AVector<T> operator-(const AVector<T> &vec) const
  {
    auto tmp = this->_array - vec._array;

    return AVector<T>(tmp);
  }
  AVector<T> &operator-=(const AVector<T> &vec)
  {
    this->_array -= vec._array;

    return *this;
  }

  AVector<T> operator-(const T &value) const
  {
    auto tmp = this->_array - value;

    return AVector<T>(tmp);
  }
  AVector<T> &operator-=(const T &value)
  {
    this->_array -= value;

    return *this;
  }

  AVector<T> operator*(const AVector<T> &vec) const
  {
    auto tmp = this->_array * vec._array;

    return AVector<T>(tmp);
  }
  AVector<T> &operator*=(const AVector<T> &vec)
  {
    this->_array *= vec._array;

    return *this;
  }

  AVector<T> operator*(const T &value) const
  {
    auto tmp = this->_array * value;

    return AVector<T>(tmp);
  }
  AVector<T> &operator*=(const T &value)
  {
    this->_array *= value;

    return *this;
  }

  AVector<T> operator/(const AVector<T> &vec) const
  {
    auto tmp = this->_array / vec._array;

    return AVector<T>(tmp);
  }
  AVector<T> &operator/=(const AVector<T> &vec)
  {
    this->_array /= vec._array;

    return *this;
  }

  AVector<T> operator/(const T &value) const
  {
    auto tmp = this->_array / value;

    return AVector<T>(tmp);
  }
  AVector<T> &operator/=(const T &value)
  {
    this->_array /= value;

    return *this;
  }

  static T Dot(const AVector<T> &vec1, const AVector<T> &vec2);

  AVector<real_t> nomalized() const
  {
    AVector<real_t> norm;

    norm._array = this->_array / this->getNormArray();
    return norm;
  }
};

template<>
int AVector<int>::Dot(const AVector<int> &vec1, const AVector<int> &vec2)
{
  return af::dot(vec1._array, vec2._array).scalar<int>();
}

template<>
long long AVector<long long>::Dot(const AVector<long long> &vec1, const AVector<long long> &vec2)
{
  return af::dot(vec1._array, vec2._array).scalar<long long>();
}

template<>
unsigned AVector<unsigned>::Dot(const AVector<unsigned> &vec1, const AVector<unsigned> &vec2)
{
  return af::dot(vec1._array, vec2._array).scalar<unsigned>();
}

template<>
long long unsigned AVector<long long unsigned>::Dot(const AVector<long long unsigned> &vec1, const AVector<long long unsigned> &vec2)
{
  return af::dot(vec1._array, vec2._array).scalar<long long unsigned>();
}

template<>
float AVector<float>::Dot(const AVector<float> &vec1, const AVector<float> &vec2)
{
  return af::dot(vec1._array, vec2._array).scalar<float>();
}

template<>
double AVector<double>::Dot(const AVector<double> &vec1, const AVector<double> &vec2)
{
  return af::dot(vec1._array, vec2._array).scalar<double>();
}

#endif /* !RTECHNOLOGY_AVECTOR_HPP */
