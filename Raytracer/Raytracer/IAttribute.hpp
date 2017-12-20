/*
** IAttribute.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 12:08 2017 benoit_g
** Last update mar. déc. 12:08 2017 benoit_g
*/

#ifndef RTECHNOLOGY_IATTRIBUTE_HPP
#define RTECHNOLOGY_IATTRIBUTE_HPP

#include "Color.hpp"

class IAttribute
{
 public:
  virtual ~IAttribute() = default;

  virtual void affectColor(Color &currentColor) const = 0;
};


#endif /* !RTECHNOLOGY_IATTRIBUTE_HPP */
