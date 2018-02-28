/*
** Vector2.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 12:03 2017 benoit_g
** Last update mar. déc. 12:03 2017 benoit_g
*/

#include "Vector2_test.hpp"

/*
 * int specialization
 */

template<>
Vector2<int>::Vector2()
{
  if (useGraphics)
    this->_array = af::constant(0, 2, s32);
}

template<>
Vector2<int>::Vector2(const int &x, const int &y)
{
  if (useGraphics)
    {
      this->_array = _array(af::constant(0, 2, s32)),
	      this->_array(0) = x;
      this->_array(1) = y;
      return;
    }
  this->_x = x;
  this->_y = y;
}

template<>
int Vector2<int>::x() const
{
  if (useGraphics)
    return this->_array(0).scalar<int>();
  return this->_x;
}

template<>
int Vector2<int>::y() const
{
  if (useGraphics)
    return this->_array(1).scalar<int>();
  return this->_y;
}

template<>
float Vector2<int>::magnitude() const
{
  if (useGraphics)
    return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<float>();
  auto x = this->_x * this->_x;
  auto y = this->_y * this->_y;
  return std::sqrt(x + y);
}

template<>
float Vector2<int>::Dot(const Vector2<int> &vec1, const Vector2<int> &vec2)
{
  if (useGraphics)
    return af::sum(vec1._array * vec1._array).scalar<float>();
  auto v = vec1 * vec2;
  return v._x + v._y;
}

template<>
float Vector2<int>::Distance(const Vector2<int> &vec1, const Vector2<int> &vec2)
{
  if (useGraphics)
    return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<float>();
  auto vec = vec1 - vec2;
  return vec.magnitude();
}

template<>
float Vector2<int>::Angle(const Vector2<int> &vec1, const Vector2<int> &vec2)
{
  if (useGraphics)
    {
      auto mul = af::sum(vec1._array * vec2._array);
      auto norm = vec1.getNormArray() * vec2.getNormArray();

      return af::acos(mul / norm).scalar<float>();
    }
  auto newVec1 = vec1.nomalized();
  auto newVec2 = vec2.nomalized();

  auto v = newVec1 * newVec2;
  return std::acos(v.x() + v.y());
}

/*
 * long long specialization
 */

#ifdef ENVIRONMENT64

template<>
Vector2<long long>::Vector2()
{
  if (useGraphics)
    this->_array = af::constant(0, 2, s64);
}

template<>
Vector2<long long>::Vector2(const long long &x, const long long &y)
{
  if (useGraphics)
    {
      this->_array = af::constant(0, 2, s64);
      this->_array(0) = x;
      this->_array(1) = y;
      return;
    }
  this->_x = x;
  this->_y = y;
}

template<>
long long Vector2<long long>::x() const
{
  if (useGraphics)
    return this->_array(0).scalar<long long>();
  return this->_x;
}

template<>
long long Vector2<long long>::y() const
{
  if (useGraphics)
    return this->_array(1).scalar<long long>();
  return this->_y;
}

template<>
float Vector2<long long>::magnitude() const
{
  if (useGraphics)
    return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<float>();
  auto x = this->_x * this->_x;
  auto y = this->_y * this->_y;
  return std::sqrt(x + y);
}

template<>
float Vector2<long long>::Dot(const Vector2<long long> &vec1, const Vector2<long long> &vec2)
{
  if (useGraphics)
    return af::sum(vec1._array * vec1._array).scalar<float>();
  auto v = vec1 * vec2;
  return v._x + v._y;
}

template<>
float Vector2<long long>::Distance(const Vector2<long long> &vec1, const Vector2<long long> &vec2)
{
  if (useGraphics)
    return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<float>();
  auto vec = vec1 - vec2;
  return vec.magnitude();
}

template<>
float Vector2<long long>::Angle(const Vector2<long long> &vec1, const Vector2<long long> &vec2)
{
  if (useGraphics)
    {
      auto mul = af::sum(vec1._array * vec2._array);
      auto norm = vec1.getNormArray() * vec2.getNormArray();

      return af::acos(mul / norm).scalar<float>();
    }
  auto newVec1 = vec1.nomalized();
  auto newVec2 = vec2.nomalized();

  auto v = newVec1 * newVec2;
  return std::acos(v.x() + v.y());
}

#endif

/*
 * unsigned specialization
 */

template<>
Vector2<unsigned>::Vector2()
{
  if (useGraphics)
    this->_array = af::constant(0, 2, u32);
}

template<>
Vector2<unsigned>::Vector2(const unsigned &x, const unsigned &y)
{
  if (useGraphics)
    {
      this->_array = af::constant(0, 2, u32);
      this->_array(0) = x;
      this->_array(1) = y;
      return;
    }
  this->_x = x;
  this->_y = y;
}

template<>
unsigned Vector2<unsigned>::x() const
{
  if (useGraphics)
    return this->_array(0).scalar<unsigned>();
  return this->_x;
}

template<>
unsigned Vector2<unsigned>::y() const
{
  if (useGraphics)
    return this->_array(1).scalar<unsigned>();
  return this->_y;
}

template<>
float Vector2<unsigned>::magnitude() const
{
  if (useGraphics)
    return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<float>();
  auto x = this->_x * this->_x;
  auto y = this->_y * this->_y;
  return std::sqrt(x + y);
}

template<>
float Vector2<unsigned>::Dot(const Vector2<unsigned> &vec1, const Vector2<unsigned> &vec2)
{
  if (useGraphics)
    return af::sum(vec1._array * vec1._array).scalar<float>();
  auto v = vec1 * vec2;
  return v._x + v._y;
}

template<>
float Vector2<unsigned>::Distance(const Vector2<unsigned> &vec1, const Vector2<unsigned> &vec2)
{
  if (useGraphics)
    return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<float>();
  auto vec = vec1 - vec2;
  return vec.magnitude();
}

template<>
float Vector2<unsigned>::Angle(const Vector2<unsigned> &vec1, const Vector2<unsigned> &vec2)
{
  if (useGraphics)
    {
      auto mul = af::sum(vec1._array * vec2._array);
      auto norm = vec1.getNormArray() * vec2.getNormArray();

      return af::acos(mul / norm).scalar<float>();
    }
  auto newVec1 = vec1.nomalized();
  auto newVec2 = vec2.nomalized();

  auto v = newVec1 * newVec2;
  return std::acos(v.x() + v.y());
}

/*
 * long long unsigned specialization
 */

#ifdef ENVIRONMENT64

template<>
Vector2<long long unsigned>::Vector2()
{
  if (useGraphics)
    this->_array = af::constant(0, 2, u64);
}

template<>
Vector2<long long unsigned>::Vector2(const long long unsigned &x, const long long unsigned &y) : _array(af::constant(0, 2, u64))
{
  if (useGraphics)
    {
      this->_array = af::constant(0, 2, u64);
      this->_array(0) = x;
      this->_array(1) = y;
      return;
    }
  this->_x = x;
  this->_y = y;
}

template<>
long long unsigned Vector2<long long unsigned>::x() const
{
  if (useGraphics)
    return this->_array(0).scalar<long long unsigned>();
  return this->_x;
}

template<>
long long unsigned Vector2<long long unsigned>::y() const
{
  if (useGraphics)
    return this->_array(1).scalar<long long unsigned>();
  return this->_y;
}

template<>
float Vector2<long long unsigned>::magnitude() const
{
  if (useGraphics)
    return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<float>();
  auto x = this->_x * this->_x;
  auto y = this->_y * this->_y;
  return std::sqrt(x + y);
}

template<>
float Vector2<long long unsigned>::Dot(const Vector2<long long unsigned> &vec1, const Vector2<long long unsigned> &vec2)
{
  if (useGraphics)
    return af::sum(vec1._array * vec1._array).scalar<float>();
  auto v = vec1 * vec2;
  return v._x + v._y;
}

template<>
float Vector2<long long unsigned>::Distance(const Vector2<long long unsigned> &vec1, const Vector2<long long unsigned> &vec2)
{
  if (useGraphics)
    return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<float>();
  auto vec = vec1 - vec2;
  return vec.magnitude();
}

template<>
float Vector2<long long unsigned>::Angle(const Vector2<long long unsigned> &vec1, const Vector2<long long unsigned> &vec2)
{
  if (useGraphics)
    {
      auto mul = af::sum(vec1._array * vec2._array);
      auto norm = vec1.getNormArray() * vec2.getNormArray();

      return af::acos(mul / norm).scalar<float>();
    }
  auto newVec1 = vec1.nomalized();
  auto newVec2 = vec2.nomalized();

  auto v = newVec1 * newVec2;
  return std::acos(v.x() + v.y());
}

#endif

/*
 * float specialization
 */

template<>
Vector2<float>::Vector2()
{
  if (useGraphics)
    this->_array = af::constant(0, 2, f32);
}

template<>
Vector2<float>::Vector2(const float &x, const float &y)
{
  if (useGraphics)
    {
      this->_array = af::constant(0, 2, f32);
      this->_array(0) = x;
      this->_array(1) = y;
      return;
    }
  this->_x = x;
  this->_y = y;
}

template<>
float Vector2<float>::x() const
{
  if (useGraphics)
    return this->_array(0).scalar<float>();
  return this->_x;
}

template<>
float Vector2<float>::y() const
{
  if (useGraphics)
    return this->_array(1).scalar<float>();
  return this->_y;
}

template<>
float Vector2<float>::magnitude() const
{
  if (useGraphics)
    return af::sqrt(af::sum(af::pow(this->_array, 2))).scalar<float>();
  auto x = this->_x * this->_x;
  auto y = this->_y * this->_y;
  return std::sqrt(x + y);
}

template<>
float Vector2<float>::Dot(const Vector2<float> &vec1, const Vector2<float> &vec2)
{
  if (useGraphics)
    return af::sum(vec1._array * vec1._array).scalar<float>();
  auto v = vec1 * vec2;
  return v._x + v._y;
}

template<>
float Vector2<float>::Distance(const Vector2<float> &vec1, const Vector2<float> &vec2)
{
  if (useGraphics)
    return af::sqrt(af::sum(af::pow(vec1._array * vec2._array, 2))).scalar<float>();
  auto vec = vec1 - vec2;
  return vec.magnitude();
}

template<>
float Vector2<float>::Angle(const Vector2<float> &vec1, const Vector2<float> &vec2)
{
  if (useGraphics)
    {
      auto mul = af::sum(vec1._array * vec2._array);
      auto norm = vec1.getNormArray() * vec2.getNormArray();

      return af::acos(mul / norm).scalar<float>();
    }
  auto newVec1 = vec1.nomalized();
  auto newVec2 = vec2.nomalized();

  auto v = newVec1 * newVec2;
  return std::acos(v._x + v._y);
}
