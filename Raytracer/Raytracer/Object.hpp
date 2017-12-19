/*
** Object.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. déc. 17:41 2017 benoit_g
** Last update mer. déc. 17:41 2017 benoit_g
*/

#ifndef RTECHNOLOGY_OBJECT_HPP
#define RTECHNOLOGY_OBJECT_HPP

#include "config.h"
#include "math/Vector3.hpp"
#include "Color.hpp"

class Object
{
 protected:
  const Vector3Float position;
  const Vector3Float rotation;
  const Vector3Float scale;

 public:
  explicit Object();
  explicit Object(const Vector3Float &pos);
  Object(const Vector3Float &pos, const Vector3Float &rot);
  Object(const Vector3Float &pos, const Vector3Float &rot, const Vector3Float &scal);
  Object(const Object &obj);
  Object(Object &&obj) noexcept;
  Object &operator=(const Object &obj);
  Object &operator=(Object &&obj) noexcept;
  virtual ~Object() = default;

  const Vector3Float &getPosition() const;
  const Vector3Float &getRotation() const;
  const Vector3Float &getScale() const;

  virtual bool Hit() = 0;
  virtual Color GetColorHit() const = 0;
};

#endif /* !RTECHNOLOGY_OBJECT_HPP */
