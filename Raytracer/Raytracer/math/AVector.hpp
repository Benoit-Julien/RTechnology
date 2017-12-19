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

  AVector<float> nomalized() const
  {
    AVector<float> norm;

    norm._array = this->_array / this->getNormArray();
    return norm;
  }

  bool operator<(const AVector<T> &vec) const;
  bool operator>(const AVector<T> &vec) const;
  bool operator<=(const AVector<T> &vec) const;
  bool operator>=(const AVector<T> &vec) const;
};

#endif /* !RTECHNOLOGY_AVECTOR_HPP */
