/*
** AVector.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 12:02 2017 benoit_g
** Last update mar. déc. 12:02 2017 benoit_g
*/

#include "AVector.hpp"

/*
 * int specialization
 */

template<>
bool AVector<int>::operator<(const AVector<int> &vec) const
{
  return this->getNormArray().scalar<int>() < vec.getNormArray().scalar<int>();
}

template<>
bool AVector<int>::operator>(const AVector<int> &vec) const
{
  return this->getNormArray().scalar<int>() > vec.getNormArray().scalar<int>();
}

template<>
bool AVector<int>::operator<=(const AVector<int> &vec) const
{
  return this->getNormArray().scalar<int>() <= vec.getNormArray().scalar<int>();
}

template<>
bool AVector<int>::operator>=(const AVector<int> &vec) const
{
  return this->getNormArray().scalar<int>() >= vec.getNormArray().scalar<int>();
}

/*
 * long long specialization
 */

#ifdef ENVIRONMENT64

template<>
bool AVector<long long>::operator<(const AVector<long long> &vec) const
{
  return this->getNormArray().scalar<long long>() < vec.getNormArray().scalar<long long>();
}

template<>
bool AVector<long long>::operator>(const AVector<long long> &vec) const
{
  return this->getNormArray().scalar<long long>() > vec.getNormArray().scalar<long long>();
}

template<>
bool AVector<long long>::operator<=(const AVector<long long> &vec) const
{
  return this->getNormArray().scalar<long long>() <= vec.getNormArray().scalar<long long>();
}

template<>
bool AVector<long long>::operator>=(const AVector<long long> &vec) const
{
  return this->getNormArray().scalar<long long>() >= vec.getNormArray().scalar<long long>();
}
#endif

/*
 * unsigned specialization
 */

template<>
bool AVector<unsigned>::operator<(const AVector<unsigned> &vec) const
{
  return this->getNormArray().scalar<int>() < vec.getNormArray().scalar<int>();
}

template<>
bool AVector<unsigned>::operator>(const AVector<unsigned> &vec) const
{
  return this->getNormArray().scalar<int>() > vec.getNormArray().scalar<int>();
}

template<>
bool AVector<unsigned>::operator<=(const AVector<unsigned> &vec) const
{
  return this->getNormArray().scalar<int>() <= vec.getNormArray().scalar<int>();
}

template<>
bool AVector<unsigned>::operator>=(const AVector<unsigned> &vec) const
{
  return this->getNormArray().scalar<int>() >= vec.getNormArray().scalar<int>();
}

/*
 * long long unsigned specialization
 */

#ifdef ENVIRONMENT64

template<>
bool AVector<long long unsigned>::operator<(const AVector<long long unsigned> &vec) const
{
  return this->getNormArray().scalar<long long unsigned>() < vec.getNormArray().scalar<long long unsigned>();
}

template<>
bool AVector<long long unsigned>::operator>(const AVector<long long unsigned> &vec) const
{
  return this->getNormArray().scalar<long long unsigned>() > vec.getNormArray().scalar<long long unsigned>();
}

template<>
bool AVector<long long unsigned>::operator<=(const AVector<long long unsigned> &vec) const
{
  return this->getNormArray().scalar<long long unsigned>() <= vec.getNormArray().scalar<long long unsigned>();
}

template<>
bool AVector<long long unsigned>::operator>=(const AVector<long long unsigned> &vec) const
{
  return this->getNormArray().scalar<long long unsigned>() >= vec.getNormArray().scalar<long long unsigned>();
}

#endif

/*
 * float specialization
 */

template<>
bool AVector<float>::operator<(const AVector<float> &vec) const
{
  return this->getNormArray().scalar<float>() < vec.getNormArray().scalar<float>();
}

template<>
bool AVector<float>::operator>(const AVector<float> &vec) const
{
  return this->getNormArray().scalar<float>() > vec.getNormArray().scalar<float>();
}

template<>
bool AVector<float>::operator<=(const AVector<float> &vec) const
{
  return this->getNormArray().scalar<float>() <= vec.getNormArray().scalar<float>();
}

template<>
bool AVector<float>::operator>=(const AVector<float> &vec) const
{
  return this->getNormArray().scalar<float>() >= vec.getNormArray().scalar<float>();
}