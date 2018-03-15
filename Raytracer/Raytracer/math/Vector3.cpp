/*
** Vector3.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 12:04 2017 benoit_g
** Last update mar. déc. 12:04 2017 benoit_g
*/

#include "Vector3.hpp"

RT_NAMESPACE_BEGIN

/*
 * int specialization
 */
/*
template<>
Vector3<int>::Vector3() : _array(af::constant(0, 3, s32))
{}

template<>
Vector3<int>::Vector3(const int &x, const int &y, const int &z) : _array(af::constant(0, 3, s32))
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
float Vector3<int>::Angle(const Vector3<int> &vec1, const Vector3<int> &vec2)
{
  auto mul = af::sum(vec1._array * vec2._array);
  auto norm = vec1.getNormArray() * vec2.getNormArray();

  return af::acos(mul / norm).scalar<float>();
}

template<>
bool Vector3<int>::operator<(const Vector3<int> &vec) const
{
  return this->getNormArray().scalar<int>() < vec.getNormArray().scalar<int>();
}

template<>
bool Vector3<int>::operator>(const Vector3<int> &vec) const
{
  return this->getNormArray().scalar<int>() > vec.getNormArray().scalar<int>();
}

template<>
bool Vector3<int>::operator<=(const Vector3<int> &vec) const
{
  return this->getNormArray().scalar<int>() <= vec.getNormArray().scalar<int>();
}

template<>
bool Vector3<int>::operator>=(const Vector3<int> &vec) const
{
  return this->getNormArray().scalar<int>() >= vec.getNormArray().scalar<int>();
}

/*
 * long long specialization
 */
/*
#ifdef ENVIRONMENT64

template<>
Vector3<long long>::Vector3() : _array(af::constant(0, 3, s64))
{}

template<>
Vector3<long long>::Vector3(const long long &x, const long long &y, const long long &z) : _array(af::constant(0, 3, s64))
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
float Vector3<long long>::Angle(const Vector3<long long> &vec1, const Vector3<long long> &vec2)
{
  auto mul = af::sum(vec1._array * vec2._array);
  auto norm = vec1.getNormArray() * vec2.getNormArray();

  return af::acos(mul / norm).scalar<float>();
}

template<>
bool Vector3<long long>::operator<(const Vector3<long long> &vec) const
{
  return this->getNormArray().scalar<long long>() < vec.getNormArray().scalar<long long>();
}

template<>
bool Vector3<long long>::operator>(const Vector3<long long> &vec) const
{
  return this->getNormArray().scalar<long long>() > vec.getNormArray().scalar<long long>();
}

template<>
bool Vector3<long long>::operator<=(const Vector3<long long> &vec) const
{
  return this->getNormArray().scalar<long long>() <= vec.getNormArray().scalar<long long>();
}

template<>
bool Vector3<long long>::operator>=(const Vector3<long long> &vec) const
{
  return this->getNormArray().scalar<long long>() >= vec.getNormArray().scalar<long long>();
}
#endif

/*
 * unsigned specialization
 */
/*
template<>
Vector3<unsigned>::Vector3() : _array(af::constant(0, 3, u32))
{}

template<>
Vector3<unsigned>::Vector3(const unsigned &x, const unsigned &y, const unsigned &z) : _array(af::constant(0, 3, u32))
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
float Vector3<unsigned>::Angle(const Vector3<unsigned> &vec1, const Vector3<unsigned> &vec2)
{
  auto mul = af::sum(vec1._array * vec2._array);
  auto norm = vec1.getNormArray() * vec2.getNormArray();

  return af::acos(mul / norm).scalar<float>();
}

template<>
bool Vector3<unsigned>::operator<(const Vector3<unsigned> &vec) const
{
  return this->getNormArray().scalar<unsigned>() < vec.getNormArray().scalar<unsigned>();
}

template<>
bool Vector3<unsigned>::operator>(const Vector3<unsigned> &vec) const
{
  return this->getNormArray().scalar<unsigned>() > vec.getNormArray().scalar<unsigned>();
}

template<>
bool Vector3<unsigned>::operator<=(const Vector3<unsigned> &vec) const
{
  return this->getNormArray().scalar<unsigned>() <= vec.getNormArray().scalar<unsigned>();
}

template<>
bool Vector3<unsigned>::operator>=(const Vector3<unsigned> &vec) const
{
  return this->getNormArray().scalar<unsigned>() >= vec.getNormArray().scalar<unsigned>();
}

/*
 * long long unsigned specialization
 */
/*
#ifdef ENVIRONMENT64

template<>
Vector3<long long unsigned>::Vector3() : _array(af::constant(0, 3, u64))
{}

template<>
Vector3<long long unsigned>::Vector3(const long long unsigned &x, const long long unsigned &y, const long long unsigned &z) : _array(af::constant(0, 3, u64))
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
float Vector3<long long unsigned>::Angle(const Vector3<long long unsigned> &vec1, const Vector3<long long unsigned> &vec2)
{
  auto mul = af::sum(vec1._array * vec2._array);
  auto norm = vec1.getNormArray() * vec2.getNormArray();

  return af::acos(mul / norm).scalar<float>();
}

template<>
bool Vector3<long long unsigned>::operator<(const Vector3<long long unsigned> &vec) const
{
  return this->getNormArray().scalar<long long unsigned>() < vec.getNormArray().scalar<long long unsigned>();
}

template<>
bool Vector3<long long unsigned>::operator>(const Vector3<long long unsigned> &vec) const
{
  return this->getNormArray().scalar<long long unsigned>() > vec.getNormArray().scalar<long long unsigned>();
}

template<>
bool Vector3<long long unsigned>::operator<=(const Vector3<long long unsigned> &vec) const
{
  return this->getNormArray().scalar<long long unsigned>() <= vec.getNormArray().scalar<long long unsigned>();
}

template<>
bool Vector3<long long unsigned>::operator>=(const Vector3<long long unsigned> &vec) const
{
  return this->getNormArray().scalar<long long unsigned>() >= vec.getNormArray().scalar<long long unsigned>();
}
#endif

/*
 * float specialization
 */
/*
template<>
Vector3<float>::Vector3() : _array(af::constant(0, 3, f32))
{}

template<>
Vector3<float>::Vector3(const float &x, const float &y, const float &z) : _array(af::constant(0, 3, f32))
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
float Vector3<float>::Angle(const Vector3<float> &vec1, const Vector3<float> &vec2)
{
  auto newVec1 = vec1.nomalized();
  auto newVec2 = vec2.nomalized();


  auto mul = af::sum(newVec1._array * newVec2._array);
//  auto norm = newVec1.getNormArray() * newVec1.getNormArray();

  //return af::acos(mul / norm).scalar<float>();
  return af::acos(mul).scalar<float>();
}

template<>
bool Vector3<float>::operator<(const Vector3<float> &vec) const
{
  return this->getNormArray().scalar<float>() < vec.getNormArray().scalar<float>();
}

template<>
bool Vector3<float>::operator>(const Vector3<float> &vec) const
{
  return this->getNormArray().scalar<float>() > vec.getNormArray().scalar<float>();
}

template<>
bool Vector3<float>::operator<=(const Vector3<float> &vec) const
{
  return this->getNormArray().scalar<float>() <= vec.getNormArray().scalar<float>();
}

template<>
bool Vector3<float>::operator>=(const Vector3<float> &vec) const
{
  return this->getNormArray().scalar<float>() >= vec.getNormArray().scalar<float>();
}*/

RT_NAMESPACE_END