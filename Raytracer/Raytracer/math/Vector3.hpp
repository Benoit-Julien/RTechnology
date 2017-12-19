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

#include "AVector.hpp"

template<typename T>
class Vector3 : public AVector<T>
{
 public:
  static const Vector3<T> forward;
  static const Vector3<T> back;

  static const Vector3<T> up;
  static const Vector3<T> down;

  static const Vector3<T> right;
  static const Vector3<T> left;

  explicit Vector3();

  Vector3(const T &x, const T &y, const T &z) : AVector<T>(af::constant(0, 3))
  {
    this->_array(0) = x;
    this->_array(1) = y;
    this->_array(2) = z;
  }

  virtual ~Vector3() = default;

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

  static T Distance(const Vector3<T> &vec1, const Vector3<T> &vec2);

  static float Angle(const Vector3<T> &vec1, const Vector3<T> &vec2);

  bool operator==(const Vector3<T> &vec) const
  {
    return this->Equal(vec);
  }

  bool operator!=(const Vector3<T> &vec) const
  {
    return !this->Equal(vec);
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
const Vector3<T> Vector3<T>::right = Vector3(1, 0, 0);

template<typename T>
const Vector3<T> Vector3<T>::left = Vector3(-1, 0, 0);

template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector3<T> &vec)
{
  os << "Vector3 :" << std::endl;
  os << "\tx = " << vec.x() << std::endl;
  os << "\ty = " << vec.y() << std::endl;
  os << "\tz = " << vec.z();

  return os;
}

typedef Vector3<int> Vector3Int;
typedef Vector3<float> Vector3Float;

#endif /* !RTECHNOLOGY_VECTOR3_HPP */
