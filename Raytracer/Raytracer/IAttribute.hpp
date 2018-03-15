/*
** IAttribute.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 12:08 2017 benoit_g
** Last update mar. déc. 12:08 2017 benoit_g
*/

#ifndef RTECHNOLOGY_RT_IATTRIBUTE_HPP
#define RTECHNOLOGY_RT_IATTRIBUTE_HPP

#include "Color.hpp"

RT_NAMESPACE_BEGIN

  class IAttribute
  {
   public:
    virtual ~IAttribute() = default;

    virtual void affectColor(Color &currentColor) const = 0;
  };

RT_NAMESPACE_END

#endif /* !RTECHNOLOGY_RT_IATTRIBUTE_HPP */
