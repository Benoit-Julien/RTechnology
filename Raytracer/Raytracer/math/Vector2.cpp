/*
** Vector2.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 12:03 2017 benoit_g
** Last update mar. déc. 12:03 2017 benoit_g
*/

#include "Vector2.hpp"

/*
 * int specialization
 */

template<>
Vector2<int>::Vector2() : AVector<int>(af::constant(0, 2, s32))
{}

template<>
Vector2<int>::Vector2(const int &x, const int &y) : AVector<int>(af::constant(0, 2, s32))
{
  this->_array(0) = x;
  this->_array(1) = y;
}

template<>
int Vector2<int>::x() const
{
  return this->_array(0).scalar<int>();
}

template<>
int Vector2<int>::y() const
{
  return this->_array(1).scalar<int>();
}

template<>
int Vector2<int>::magnitude() const
{
  return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<int>();
}

template<>
int Vector2<int>::Dot(const Vector2<int> &vec1, const Vector2<int> &vec2)
{
  return af::sum(vec1._array * vec1._array).scalar<int>();
}

template<>
int Vector2<int>::Distance(const Vector2<int> &vec1, const Vector2<int> &vec2)
{
  return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<int>();
}

template<>
float Vector2<int>::Angle(const Vector2<int> &vec1, const Vector2<int> &vec2)
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
Vector2<long long>::Vector2() : AVector<long long>(af::constant(0, 2, s64))
{}

template<>
Vector2<long long>::Vector2(const long long &x, const long long &y) : AVector<long long>(af::constant(0, 2, s64))
{
  this->_array(0) = x;
  this->_array(1) = y;
}

template<>
long long Vector2<long long>::x() const
{
  return this->_array(0).scalar<long long>();
}

template<>
long long Vector2<long long>::y() const
{
  return this->_array(1).scalar<long long>();
}

template<>
long long Vector2<long long>::magnitude() const
{
  return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<long long>();
}

template<>
long long Vector2<long long>::Dot(const Vector2<long long> &vec1, const Vector2<long long> &vec2)
{
  return af::sum(vec1._array * vec1._array).scalar<long long>();
}

template<>
long long Vector2<long long>::Distance(const Vector2<long long> &vec1, const Vector2<long long> &vec2)
{
  return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<long long>();
}

template<>
float Vector2<long long>::Angle(const Vector2<long long> &vec1, const Vector2<long long> &vec2)
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
Vector2<unsigned>::Vector2() : AVector<unsigned>(af::constant(0, 2, u32))
{}

template<>
Vector2<unsigned>::Vector2(const unsigned &x, const unsigned &y) : AVector<unsigned>(af::constant(0, 2, u32))
{
  this->_array(0) = x;
  this->_array(1) = y;
}

template<>
unsigned Vector2<unsigned>::x() const
{
  return this->_array(0).scalar<unsigned>();
}

template<>
unsigned Vector2<unsigned>::y() const
{
  return this->_array(1).scalar<unsigned>();
}

template<>
unsigned Vector2<unsigned>::magnitude() const
{
  return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<unsigned>();
}

template<>
unsigned Vector2<unsigned>::Dot(const Vector2<unsigned> &vec1, const Vector2<unsigned> &vec2)
{
  return af::sum(vec1._array * vec1._array).scalar<unsigned>();
}

template<>
unsigned Vector2<unsigned>::Distance(const Vector2<unsigned> &vec1, const Vector2<unsigned> &vec2)
{
  return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<unsigned>();
}

template<>
float Vector2<unsigned>::Angle(const Vector2<unsigned> &vec1, const Vector2<unsigned> &vec2)
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
Vector2<long long unsigned>::Vector2() : AVector<long long unsigned>(af::constant(0, 2, u64))
{}

template<>
Vector2<long long unsigned>::Vector2(const long long unsigned &x, const long long unsigned &y) : AVector<long long unsigned>(af::constant(0, 2, u64))
{
  this->_array(0) = x;
  this->_array(1) = y;
}

template<>
long long unsigned Vector2<long long unsigned>::x() const
{
  return this->_array(0).scalar<long long unsigned>();
}

template<>
long long unsigned Vector2<long long unsigned>::y() const
{
  return this->_array(1).scalar<long long unsigned>();
}

template<>
long long unsigned Vector2<long long unsigned>::magnitude() const
{
  return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<long long unsigned>();
}

template<>
long long unsigned Vector2<long long unsigned>::Dot(const Vector2<long long unsigned> &vec1, const Vector2<long long unsigned> &vec2)
{
  return af::sum(vec1._array * vec1._array).scalar<long long unsigned>();
}

template<>
long long unsigned Vector2<long long unsigned>::Distance(const Vector2<long long unsigned> &vec1, const Vector2<long long unsigned> &vec2)
{
  return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<long long unsigned>();
}

template<>
float Vector2<long long unsigned>::Angle(const Vector2<long long unsigned> &vec1, const Vector2<long long unsigned> &vec2)
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
Vector2<float>::Vector2() : AVector<float>(af::constant(0, 2, f32))
{}

template<>
Vector2<float>::Vector2(const float &x, const float &y) : AVector<float>(af::constant(0, 2, f32))
{
  this->_array(0) = x;
  this->_array(1) = y;
}

template<>
float Vector2<float>::x() const
{
  return this->_array(0).scalar<float>();
}

template<>
float Vector2<float>::y() const
{
  return this->_array(1).scalar<float>();
}

template<>
float Vector2<float>::magnitude() const
{
  return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<float>();
}

template<>
float Vector2<float>::Dot(const Vector2<float> &vec1, const Vector2<float> &vec2)
{
  return af::sum(vec1._array * vec1._array).scalar<float>();
}

template<>
float Vector2<float>::Distance(const Vector2<float> &vec1, const Vector2<float> &vec2)
{
  return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<float>();
}

template<>
float Vector2<float>::Angle(const Vector2<float> &vec1, const Vector2<float> &vec2)
{
  auto mul = af::sum(vec1._array * vec2._array);
  auto norm = vec1.getNormArray() * vec2.getNormArray();

  return af::acos(mul / norm).scalar<float>();
}