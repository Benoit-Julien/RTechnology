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

#include "AVector.hpp"

template<typename T>
class Vector2 : public AVector<T>
{
 public:
  static const Vector2<T> up;
  static const Vector2<T> down;

  static const Vector2<T> right;
  static const Vector2<T> left;

  explicit Vector2();

  Vector2(const T &x, const T &y) : AVector<T>(af::constant(0, 2))
  {
    this->_array(0) = x;
    this->_array(1) = y;
  }

  virtual ~Vector2() = default;

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

typedef Vector2<int> Vector2Int;
typedef Vector2<float> Vector2Float;

#endif /* !RTECHNOLOGY_VECTOR2_HPP */
