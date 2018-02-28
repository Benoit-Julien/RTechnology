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
  T _x;
  T _y;

 protected:
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
  Vector2(const Vector2<T> &vector)
  {
    this->_x = vector._x;
    this->_y = vector._y;
    this->_array = vector._array;
  }

  Vector2(Vector2<T> &&vector) noexcept
  {
    this->_x = vector._x;
    this->_y = vector._y;
    this->_array = vector._array;
  }

  Vector2 &operator=(const Vector2<T> &vector)
  {
    this->_x = vector._x;
    this->_y = vector._y;
    this->_array = vector._array;
    return *this;
  }

  Vector2 &operator=(Vector2<T> &&vector) noexcept
  {
    this->_x = vector._x;
    this->_y = vector._y;
    this->_array = vector._array;
    return *this;
  }

  ~Vector2() = default;

  Vector2<T> operator+(const Vector2<T> &vec) const
  {
    if (useGraphics)
      {
	Vector2<T> nvec;
	nvec._array = this->_array + vec._array;
	return nvec;
      }
    auto x = this->_x + vec._x;
    auto y = this->_y + vec._y;

    return Vector2<T>(x, y);
  }
  Vector2<T> &operator+=(const Vector2<T> &vec)
  {
    if (useGraphics)
      this->_array += vec._array;
    else
      {
	this->_x += vec._x;
	this->_y += vec._y;
      }
    return *this;
  }

  Vector2<T> operator+(const T &value) const
  {
    if (useGraphics)
      {
	Vector2<T> nvec;
	nvec._array = this->_array + value;
	return nvec;
      }
    auto x = this->_x + value;
    auto y = this->_y + value;

    return Vector2<T>(x, y);
  }
  Vector2<T> &operator+=(const T &value)
  {
    if (useGraphics)
      this->_array += value;
    else
      {
	this->_x += value;
	this->_y += value;
      }
    return *this;
  }

  Vector2<T> &operator-()
  {
    if (useGraphics)
      this->_array *= -1;
    else
      {
	this->_x = -this->_x;
	this->_y = -this->_y;
      }
    return *this;
  }

  Vector2<T> operator-(const Vector2<T> &vec) const
  {
    if (useGraphics)
      {
	Vector2<T> nvec;
	nvec._array = this->_array - vec._array;
	return nvec;
      }
    auto x = this->_x - vec._x;
    auto y = this->_y - vec._y;

    return Vector2<T>(x, y);
  }
  Vector2<T> &operator-=(const Vector2<T> &vec)
  {
    if (useGraphics)
      this->_array -= vec._array;
    else
      {
	this->_x -= vec._x;
	this->_y -= vec._y;
      }
    return *this;
  }

  Vector2<T> operator-(const T &value) const
  {
    if (useGraphics)
      {
	Vector2<T> nvec;
	nvec._array = this->_array - value;
	return nvec;
      }
    auto x = this->_x - value;
    auto y = this->_y - value;

    return Vector2<T>(x, y);
  }
  Vector2<T> &operator-=(const T &value)
  {
    if (useGraphics)
      this->_array -= value;
    else
      {
	this->_x -= value;
	this->_y -= value;
      }
    return *this;
  }

  Vector2<T> operator*(const Vector2<T> &vec) const
  {
    if (useGraphics)
      {
	Vector2<T> nvec;
	nvec._array = this->_array * vec._array;
	return nvec;
      }
    auto x = this->_x * vec._x;
    auto y = this->_y * vec._y;

    return Vector2<T>(x, y);
  }
  Vector2<T> &operator*=(const Vector2<T> &vec)
  {
    if (useGraphics)
      this->_array *= vec._array;
    else
      {
	this->_x *= vec._x;
	this->_y *= vec._y;
      }
    return *this;
  }

  Vector2<T> operator*(const T &value) const
  {
    if (useGraphics)
      {
	Vector2<T> nvec;
	nvec._array = this->_array * value;
	return nvec;
      }
    auto x = this->_x * value;
    auto y = this->_y * value;

    return Vector2<T>(x, y);
  }
  Vector2<T> &operator*=(const T &value)
  {
    if (useGraphics)
      this->_array *= value;
    else
      {
	this->_x *= value;
	this->_y *= value;
      }
    return *this;
  }

  Vector2<T> operator/(const Vector2<T> &vec) const
  {
    if (useGraphics)
      {
	Vector2<T> nvec;
	nvec._array = this->_array / vec._array;
	return nvec;
      }
    auto x = this->_x / vec._x;
    auto y = this->_y / vec._y;

    return Vector2<T>(x, y);
  }
  Vector2<T> &operator/=(const Vector2<T> &vec)
  {
    if (useGraphics)
      this->_array /= vec._array;
    else
      {
	this->_x /= vec._x;
	this->_y /= vec._y;
      }
    return *this;
  }

  Vector2<T> operator/(const T &value) const
  {
    if (useGraphics)
      {
	Vector2<T> nvec;
	nvec._array = this->_array / value;
	return nvec;
      }
    auto x = this->_x / value;
    auto y = this->_y / value;

    return Vector2<T>(x, y);
  }
  Vector2<T> &operator/=(const T &value)
  {
    if (useGraphics)
      this->_array /= value;
    else
      {
	this->_x /= value;
	this->_y /= value;
      }
    return *this;
  }

  Vector2<float> nomalized() const
  {
    if (useGraphics)
      {
	Vector2<float> nvec;
	nvec._array = this->_array / this->getNormArray();
	return nvec;
      }
    float norm = this->magnitude();
    float x = this->_x / norm;
    float y = this->_y / norm;

    return Vector2<float>(x, y);
  }

  bool operator<(const Vector2<T> &vec) const
  { return this->magnitude() < vec.magnitude(); }
  bool operator>(const Vector2<T> &vec) const
  { return this->magnitude() > vec.magnitude(); }
  bool operator<=(const Vector2<T> &vec) const
  { return this->magnitude() <= vec.magnitude(); }
  bool operator>=(const Vector2<T> &vec) const
  { return this->magnitude() >= vec.magnitude(); }

  void Set(const T &x, const T &y)
  {
    if (useGraphics)
      {
	this->_array(0) = x;
	this->_array(1) = y;
	return;
      }
    this->_x = x;
    this->_y = y;
  }

  void Set(T &&x, T &&y)
  {
    if (useGraphics)
      {
	this->_array(0) = x;
	this->_array(1) = y;
	return;
      }
    this->_x = x;
    this->_y = y;
  }

  bool Equal(const Vector2<T> &vec) const
  {
    return this->x() == vec.x() && this->y() == vec.y();
  }

  T x() const;

  T y() const;

  float magnitude() const;

  static float Dot(const Vector2<T> &vec1, const Vector2<T> &vec2);

  static float Distance(const Vector2<T> &vec1, const Vector2<T> &vec2);

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
