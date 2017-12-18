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

/*
 * int specialization
 */

template<>
Vector3<int>::Vector3() : AVector<int>(af::constant(0, 3, s32))
{}

template<>
Vector3<int>::Vector3(const int &x, const int &y, const int &z) : AVector<int>(af::constant(0, 3, s32))
{
  this->_array(0) = x;
  this->_array(1) = y;
  this->_array(2) = z;
}

template<>
int Vector3<int>::x() const
{
  return this->_array(0).scalar<int>();
}

template<>
int Vector3<int>::y() const
{
  return this->_array(1).scalar<int>();
}

template<>
int Vector3<int>::z() const
{
  return this->_array(2).scalar<int>();
}

template<>
int Vector3<int>::magnitude() const
{
  return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<int>();
}

template<>
int Vector3<int>::Dot(const Vector3<int> &vec1, const Vector3<int> &vec2)
{
  return af::sum(vec1._array * vec1._array).scalar<int>();
}

template<>
int Vector3<int>::Distance(const Vector3<int> &vec1, const Vector3<int> &vec2)
{
  return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<int>();
}

template<>
float Vector3<int>::Angle(const Vector3<int> &vec1, const Vector3<int> &vec2)
{
  auto mul = af::sum(vec1._array * vec2._array);
  auto norm = vec1.getNormArray() * vec2.getNormArray();

  return af::acos(mul / norm).scalar<float>();
}

/*
 * long long specialization
 */

#ifdef ENVIRONMENT64

template<>
Vector3<long long>::Vector3() : AVector<long long>(af::constant(0, 3, s64))
{}

template<>
Vector3<long long>::Vector3(const long long &x, const long long &y, const long long &z) : AVector<long long>(af::constant(0, 3, s64))
{
  this->_array(0) = x;
  this->_array(1) = y;
  this->_array(2) = z;
}

template<>
long long Vector3<long long>::x() const
{
  return this->_array(0).scalar<long long>();
}

template<>
long long Vector3<long long>::y() const
{
  return this->_array(1).scalar<long long>();
}

template<>
long long Vector3<long long>::z() const
{
  return this->_array(2).scalar<long long>();
}

template<>
long long Vector3<long long>::magnitude() const
{
  return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<long long>();
}

template<>
long long Vector3<long long>::Dot(const Vector3<long long> &vec1, const Vector3<long long> &vec2)
{
  return af::sum(vec1._array * vec1._array).scalar<long long>();
}

template<>
long long Vector3<long long>::Distance(const Vector3<long long> &vec1, const Vector3<long long> &vec2)
{
  return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<long long>();
}

template<>
float Vector3<long long>::Angle(const Vector3<long long> &vec1, const Vector3<long long> &vec2)
{
  auto mul = af::sum(vec1._array * vec2._array);
  auto norm = vec1.getNormArray() * vec2.getNormArray();

  return af::acos(mul / norm).scalar<float>();
}
#endif

/*
 * unsigned specialization
 */

template<>
Vector3<unsigned>::Vector3() : AVector<unsigned>(af::constant(0, 3, u32))
{}

template<>
Vector3<unsigned>::Vector3(const unsigned &x, const unsigned &y, const unsigned &z) : AVector<unsigned>(af::constant(0, 3, u32))
{
  this->_array(0) = x;
  this->_array(1) = y;
  this->_array(2) = z;
}

template<>
unsigned Vector3<unsigned>::x() const
{
  return this->_array(0).scalar<unsigned>();
}

template<>
unsigned Vector3<unsigned>::y() const
{
  return this->_array(1).scalar<unsigned>();
}

template<>
unsigned Vector3<unsigned>::z() const
{
  return this->_array(2).scalar<unsigned>();
}

template<>
unsigned Vector3<unsigned>::magnitude() const
{
  return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<unsigned>();
}

template<>
unsigned Vector3<unsigned>::Dot(const Vector3<unsigned> &vec1, const Vector3<unsigned> &vec2)
{
  return af::sum(vec1._array * vec1._array).scalar<unsigned>();
}

template<>
unsigned Vector3<unsigned>::Distance(const Vector3<unsigned> &vec1, const Vector3<unsigned> &vec2)
{
  return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<unsigned>();
}

template<>
float Vector3<unsigned>::Angle(const Vector3<unsigned> &vec1, const Vector3<unsigned> &vec2)
{
  auto mul = af::sum(vec1._array * vec2._array);
  auto norm = vec1.getNormArray() * vec2.getNormArray();

  return af::acos(mul / norm).scalar<float>();
}

/*
 * long long unsigned specialization
 */

#ifdef ENVIRONMENT64

template<>
Vector3<long long unsigned>::Vector3() : AVector<long long unsigned>(af::constant(0, 3, u64))
{}

template<>
Vector3<long long unsigned>::Vector3(const long long unsigned &x, const long long unsigned &y, const long long unsigned &z) : AVector<long long unsigned>(af::constant(0, 3, u64))
{
  this->_array(0) = x;
  this->_array(1) = y;
  this->_array(2) = z;
}

template<>
long long unsigned Vector3<long long unsigned>::x() const
{
  return this->_array(0).scalar<long long unsigned>();
}

template<>
long long unsigned Vector3<long long unsigned>::y() const
{
  return this->_array(1).scalar<long long unsigned>();
}

template<>
long long unsigned Vector3<long long unsigned>::z() const
{
  return this->_array(2).scalar<long long unsigned>();
}

template<>
long long unsigned Vector3<long long unsigned>::magnitude() const
{
  return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<long long unsigned>();
}

template<>
long long unsigned Vector3<long long unsigned>::Dot(const Vector3<long long unsigned> &vec1, const Vector3<long long unsigned> &vec2)
{
  return af::sum(vec1._array * vec1._array).scalar<long long unsigned>();
}

template<>
long long unsigned Vector3<long long unsigned>::Distance(const Vector3<long long unsigned> &vec1, const Vector3<long long unsigned> &vec2)
{
  return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<long long unsigned>();
}

template<>
float Vector3<long long unsigned>::Angle(const Vector3<long long unsigned> &vec1, const Vector3<long long unsigned> &vec2)
{
  auto mul = af::sum(vec1._array * vec2._array);
  auto norm = vec1.getNormArray() * vec2.getNormArray();

  return af::acos(mul / norm).scalar<float>();
}
#endif

/*
 * float specialization
 */

template<>
Vector3<float>::Vector3() : AVector<float>(af::constant(0, 3, f32))
{}

template<>
Vector3<float>::Vector3(const float &x, const float &y, const float &z) : AVector<float>(af::constant(0, 3, f32))
{
  this->_array(0) = x;
  this->_array(1) = y;
  this->_array(2) = z;
}

template<>
float Vector3<float>::x() const
{
  return this->_array(0).scalar<float>();
}

template<>
float Vector3<float>::y() const
{
  return this->_array(1).scalar<float>();
}

template<>
float Vector3<float>::z() const
{
  return this->_array(2).scalar<float>();
}

template<>
float Vector3<float>::magnitude() const
{
  return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<float>();
}

template<>
float Vector3<float>::Dot(const Vector3<float> &vec1, const Vector3<float> &vec2)
{
  return af::sum(vec1._array * vec1._array).scalar<float>();
}

template<>
float Vector3<float>::Distance(const Vector3<float> &vec1, const Vector3<float> &vec2)
{
  return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<float>();
}

template<>
float Vector3<float>::Angle(const Vector3<float> &vec1, const Vector3<float> &vec2)
{
  auto mul = af::sum(vec1._array * vec2._array);
  auto norm = vec1.getNormArray() * vec2.getNormArray();

  return af::acos(mul / norm).scalar<float>();
}

typedef Vector3<int> Vector3Int;
typedef Vector3<float> Vector3Float;

#endif /* !RTECHNOLOGY_VECTOR3_HPP */
