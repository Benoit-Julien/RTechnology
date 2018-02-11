/*
** Plan.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. févr. 15:18 2018 benoit_g
** Last update sam. févr. 15:18 2018 benoit_g
*/

#ifndef RTECHNOLOGY_PLAN_HPP
#define RTECHNOLOGY_PLAN_HPP

#include "../Object.hpp"

class Plan : public Object
{
 public:
  explicit Plan();
  explicit Plan(const Vector3F &pos);
  Plan(const Vector3F &pos, const Vector3F &rot);
  virtual ~Plan();

  virtual HitInfo Hit(const Ray &ray, const SceneSettings &settings);
  virtual Color getColorHit(const HitInfo &info);
};


#endif /* !RTECHNOLOGY_PLAN_HPP */
