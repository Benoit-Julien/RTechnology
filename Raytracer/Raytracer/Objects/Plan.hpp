/*
** Plan.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. févr. 15:18 2018 benoit_g
** Last update sam. févr. 15:18 2018 benoit_g
*/

#ifndef RTECHNOLOGY_RT_PLAN_HPP
#define RTECHNOLOGY_RT_PLAN_HPP

#include "../Object.hpp"

RT_NAMESPACE_BEGIN

  class Plan : public Object
  {
    Vector3F _normal;

   public:
    explicit Plan();
    explicit Plan(const Vector3F &pos);
    Plan(const Vector3F &pos, const Vector3F &rot);
    virtual ~Plan();

    virtual HitInfo Hit(const Ray &ray, const SceneManager &manager);
    virtual Color getColorHit(const HitInfo &info, const SceneManager &manager);
  };

RT_NAMESPACE_END

#endif /* !RTECHNOLOGY_RT_PLAN_HPP */
