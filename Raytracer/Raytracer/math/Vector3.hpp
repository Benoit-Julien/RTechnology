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
  explicit Vector3();

  Vector3(const T &x, const T &y, const T &z) : AVector<T>(af::constant(0, 3))
  {
    this->_array(0) = x;
    this->_array(1) = y;
    this->_array(2) = z;
  }

  ~Vector3() = default;

  virtual void Set(const T &x, const T &y, const T &z)
  {
    this->_array(0) = x;
    this->_array(1) = y;
    this->_array(2) = z;
  }

  virtual void Set(T &&x, T &&y, T &&z)
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

  bool operator==(const Vector3<T> &vec) const
  {
    return this->Equal(vec);
  }

  bool operator!=(const Vector3<T> &vec) const
  {
    return !this->Equal(vec);
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vector3<T> &vec)
{
  os << "Vector3 :" << std::endl;
  os << "\tx = " << vec.x() << std::endl;
  os << "\ty = " << vec.y() << std::endl;
  os << "\tz = " << vec.z();

  return os;
}

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
#endif

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
#endif

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

#ifdef ENVIRONMENT64

template<>
Vector3<double>::Vector3() : AVector<double>(af::constant(0, 3, f64))
{}

template<>
Vector3<double>::Vector3(const double &x, const double &y, const double &z) : AVector<double>(af::constant(0, 3, f64))
{
  this->_array(0) = x;
  this->_array(1) = y;
  this->_array(2) = z;
}

template<>
double Vector3<double>::x() const
{
  return this->_array(0).scalar<double>();
}

template<>
double Vector3<double>::y() const
{
  return this->_array(1).scalar<double>();
}

template<>
double Vector3<double>::z() const
{
  return this->_array(2).scalar<double>();
}

template<>
double Vector3<double>::magnitude() const
{
  return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<double>();
}
#endif

typedef Vector3<int> Vector3Int;
typedef Vector3<real_t> Vector3Real;

#endif /* !RTECHNOLOGY_VECTOR3_HPP */
