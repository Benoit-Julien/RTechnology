/*
** EnumClassHash.hh for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 18:03 2017 benoit_g
** Last update mar. déc. 18:03 2017 benoit_g
*/

#ifndef RTECHNOLOGY_ENUMCLASSHASH_HH
#define RTECHNOLOGY_ENUMCLASSHASH_HH

#include <string>

template<typename T = std::size_t>
struct EnumClassHash
{
  template <typename U>
  T operator()(const U &t) const
  {
    return static_cast<T>(t);
  }
};

#endif /* !RTECHNOLOGY_ENUMCLASSHASH_HH */
