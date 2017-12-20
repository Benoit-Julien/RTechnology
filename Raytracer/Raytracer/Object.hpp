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

#include <vector>
#include <memory>

#include "config.h"
#include "math/Vector3.hpp"
#include "math/Ray.hpp"
#include "Color.hpp"
#include "IAttribute.hpp"

class Object
{
 protected:
  const Vector3Float position;
  const Vector3Float rotation;
  const Vector3Float scale;

  std::vector<std::shared_ptr<IAttribute>> attributes;

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

  void registerAttribute(std::shared_ptr<IAttribute> attribute);

  virtual bool Hit(const Ray &ray) = 0;
  virtual Color GetColorHit() const = 0;
};

#endif /* !RTECHNOLOGY_OBJECT_HPP */
