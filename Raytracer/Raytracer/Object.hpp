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
#include "SceneSettings.hpp"

class Object
{
 public:
  struct HitInfo
  {
    explicit HitInfo();

    bool haveHit;
    float nbRepeatRay;
    float distance;
    Vector3F normal;
    Vector3F hitPosition;
    Object *hitObject;
  };

 protected:
  const Vector3F position;
  const Vector3F rotation;
  const Vector3F scale;

  std::vector<std::shared_ptr<IAttribute>> attributes;

 public:
  explicit Object();
  explicit Object(const Vector3F &pos);
  Object(const Vector3F &pos, const Vector3F &rot);
  Object(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal);
  Object(const Object &obj);
  Object(Object &&obj) noexcept;
  Object &operator=(const Object &obj);
  Object &operator=(Object &&obj) noexcept;
  virtual ~Object() = default;

  const Vector3F &getPosition() const;
  const Vector3F &getRotation() const;
  const Vector3F &getScale() const;

  void registerAttribute(std::shared_ptr<IAttribute> attribute);

  virtual HitInfo Hit(const Ray &ray, const SceneSettings &settings) = 0;
  virtual Color getColorHit(const HitInfo &info) = 0;
};

#endif /* !RTECHNOLOGY_OBJECT_HPP */
