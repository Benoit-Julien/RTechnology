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
#include <arrayfire.h>

#include "../config.h"

template<typename T>
class RT_DLL Vector3
{
  //af::array _array;
  T _x;
  T _y;
  T _z;

 private:
  /*explicit Vector3(const af::array &array) : _array(array)
  {}

  explicit Vector3(af::array &&array) : _array(array)
  {}

  inline af::array getNormArray() const
  {
    return af::sqrt(af::sum(af::pow(this->_array, 2)));
  }*/

 public:
  static const Vector3<T> forward;
  static const Vector3<T> back;

  static const Vector3<T> up;
  static const Vector3<T> down;

  static const Vector3<T> right;
  static const Vector3<T> left;

  explicit Vector3()
  {}
  Vector3(const T &x, const T &y, const T &z) : _x(x), _y(y), _z(z)
  {}
  Vector3(const Vector3<T> &vector) : _x(vector._x), _y(vector._y), _z(vector._z)
  {}

  Vector3(Vector3<T> &&vector) noexcept : _x(vector._x), _y(vector._y), _z(vector._z)
  {}

  Vector3<T> &operator=(const Vector3<T> &vector)
  {
    //this->_array = vector._array;
    this->_x = vector._x;
    this->_y = vector._y;
    this->_z = vector._z;

    return *this;
  }

  Vector3<T> &operator=(Vector3<T> &&vector) noexcept
  {
    //this->_array = vector._array;
    this->_x = vector._x;
    this->_y = vector._y;
    this->_z = vector._z;

    return *this;
  }

  ~Vector3() = default;

  Vector3<T> operator+(const Vector3<T> &vec) const
  {
    auto x = this->_x + vec._x;
    auto y = this->_y + vec._y;
    auto z = this->_z + vec._z;
    //auto tmp = this->_array + vec._array;

    //return Vector3<T>(tmp);
    return Vector3<T>(x, y, z);
  }
  Vector3<T> &operator+=(const Vector3<T> &vec)
  {
    //this->_array += vec._array;
    this->_x += vec._x;
    this->_y += vec._y;
    this->_z += vec._z;

    return *this;
  }

  Vector3<T> operator+(const T &value) const
  {
    auto x = this->_x + value;
    auto y = this->_y + value;
    auto z = this->_z + value;
    //auto tmp = this->_array + value;

    return Vector3<T>(x, y, z);
  }
  Vector3<T> &operator+=(const T &value)
  {
    this->_x += value;
    this->_y += value;
    this->_z += value;
    //this->_array += value;

    return *this;
  }

  Vector3<T> &operator-()
  {
    this->_x = -this->_x;
    this->_y = -this->_y;
    this->_z = -this->_z;
    //this->_array *= -1;

    return *this;
  }

  Vector3<T> operator-(const Vector3<T> &vec) const
  {
    auto x = this->_x - vec._x;
    auto y = this->_y - vec._y;
    auto z = this->_z - vec._z;
    //auto tmp = this->_array - vec._array;

    return Vector3<T>(x, y, z);
  }
  Vector3<T> &operator-=(const Vector3<T> &vec)
  {
    this->_x -= vec._x;
    this->_y -= vec._y;
    this->_z -= vec._z;
    //this->_array -= vec._array;

    return *this;
  }

  Vector3<T> operator-(const T &value) const
  {
    auto x = this->_x - value;
    auto y = this->_y - value;
    auto z = this->_z - value;
    //auto tmp = this->_array - value;

    return Vector3<T>(x, y, z);
  }
  Vector3<T> &operator-=(const T &value)
  {
    this->_x -= value;
    this->_y -= value;
    this->_z -= value;
    //this->_array -= value;

    return *this;
  }

  Vector3<T> operator*(const Vector3<T> &vec) const
  {
    auto x = this->_x * vec._x;
    auto y = this->_y * vec._y;
    auto z = this->_z * vec._z;
    //auto tmp = this->_array * vec._array;

    return Vector3<T>(x, y, z);
  }
  Vector3<T> &operator*=(const Vector3<T> &vec)
  {
    this->_x *= vec._x;
    this->_y *= vec._y;
    this->_z *= vec._z;
    //this->_array *= vec._array;

    return *this;
  }

  Vector3<T> operator*(const T &value) const
  {
    auto x = this->_x * value;
    auto y = this->_y * value;
    auto z = this->_z * value;
    //auto tmp = this->_array * value;

    return Vector3<T>(x, y, z);
  }
  Vector3<T> &operator*=(const T &value)
  {
    this->_x *= value;
    this->_y *= value;
    this->_z *= value;
    //this->_array *= value;

    return *this;
  }

  Vector3<T> operator/(const Vector3<T> &vec) const
  {
    auto x = this->_x / vec._x;
    auto y = this->_y / vec._y;
    auto z = this->_z / vec._z;
    //auto tmp = this->_array / vec._array;

    return Vector3<T>(x, y, z);
  }
  Vector3<T> &operator/=(const Vector3<T> &vec)
  {
    this->_x /= vec._x;
    this->_y /= vec._y;
    this->_z /= vec._z;
    //this->_array /= vec._array;

    return *this;
  }

  Vector3<T> operator/(const T &value) const
  {
    auto x = this->_x / value;
    auto y = this->_y / value;
    auto z = this->_z / value;
    //auto tmp = this->_array / value;

    return Vector3<T>(x, y, z);
  }
  Vector3<T> &operator/=(const T &value)
  {
    this->_x /= value;
    this->_y /= value;
    this->_z /= value;
    //this->_array /= value;

    return *this;
  }

  Vector3<float> normalized() const
  {
    float norm = this->magnitude();
    float x = this->_x / norm;
    float y = this->_y / norm;
    float z = this->_z / norm;
    //return Vector3<float>(this->_array / this->magnitude());
    return Vector3<float>(x, y, z);
  }

  bool operator<(const Vector3<T> &vec) const
  { return this->magnitude() < vec.magnitude(); }
  bool operator>(const Vector3<T> &vec) const
  { return this->magnitude() > vec.magnitude(); }
  bool operator<=(const Vector3<T> &vec) const
  { return this->magnitude() <= vec.magnitude(); }
  bool operator>=(const Vector3<T> &vec) const
  { return this->magnitude() >= vec.magnitude(); }

  void Set(const T &x, const T &y, const T &z)
  {
    this->_x = x;
    this->_y = y;
    this->_z = z;
    //this->_array(0) = x;
    //this->_array(1) = y;
    //this->_array(2) = z;
  }

  void Set(T &&x, T &&y, T &&z)
  {
    this->_x = x;
    this->_y = y;
    this->_z = z;
    //this->_array(0) = x;
    //this->_array(1) = y;
    //this->_array(2) = z;
  }

  bool Equal(const Vector3<T> &vec) const
  {
    return this->_x == vec._x && this->_y == vec._y && this->_z == vec._z;
  }

  T x() const
  { return this->_x; }

  T y() const
  { return this->_y; }

  T z() const
  { return this->_z; }

  float magnitude() const
  {
    auto x = this->_x * this->_x;
    auto y = this->_y * this->_y;
    auto z = this->_z * this->_z;
    return std::sqrt(x + y + z);
  }

  static T Dot(const Vector3<T> &vec1, const Vector3<T> &vec2)
  {
//return af::sum(vec1._array * vec1._array).scalar<float>();
    auto v = vec1 * vec2;
    //auto y = vec1._y * vec2._y;
    //auto z = vec1._z * vec2._z;
    return v._x + v._y + v._z;
  }

  static Vector3<T> Cross(const Vector3<T> &vec1, const Vector3<T> &vec2)
  {
    auto x = vec1._y * vec2._z - vec1._z * vec2._y;
    auto y = vec1._z * vec2._x - vec1._x * vec2._z;
    auto z = vec1._x * vec2._y - vec1._y * vec2._x;

    return Vector3<T>(x, y, z);
    /*Vector3<T> newvec;


    newvec._array(0) = vec1._array(1) * vec2._array(2) - vec1._array(2) * vec2._array(1);
    newvec._array(1) = vec1._array(2) * vec2._array(0) - vec1._array(0) * vec2._array(2);
    newvec._array(2) = vec1._array(0) * vec2._array(1) - vec1._array(1) * vec2._array(0);

    return newvec;*/
  }

  static T Distance(const Vector3<T> &vec1, const Vector3<T> &vec2)
  {
    auto vec = vec1 - vec2;
    return vec.magnitude();
  }

  static float Angle(const Vector3<T> &vec1, const Vector3<T> &vec2)
  {
    /*
     *


  auto mul = af::sum(newVec1._array * newVec2._array);
//  auto norm = newVec1.getNormArray() * newVec1.getNormArray();

  //return af::acos(mul / norm).scalar<float>();
  return af::acos(mul).scalar<float>();
     */
    auto newVec1 = vec1.normalized();
    auto newVec2 = vec2.normalized();

    auto v = newVec1 * newVec2;
    return std::acos(v._x + v._y + v._z);

  }

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
    auto x = std::pow(this->_x, value);
    auto y = std::pow(this->_y, value);
    auto z = std::pow(this->_z, value);

    return x + y + z;

    /*af::array tmp = af::sum(af::pow(this->_array, value));
    return tmp.scalar<float>();*/
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
