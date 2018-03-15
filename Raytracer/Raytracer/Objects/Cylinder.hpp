/*
** Cylinder.hpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 16:55 2018 each
** Last update mer. janv. 16:55 2018 each
*/

#ifndef RTECHNOLOGY_RT_CYLINDER_HPP
#define RTECHNOLOGY_RT_CYLINDER_HPP

#include "../Object.hpp"

RT_NAMESPACE_BEGIN

  class Cylinder : public Object
  {
   public:
    explicit Cylinder();
    explicit Cylinder(const Vector3F &pos);
    Cylinder(const Vector3F &pos, const Vector3F &rot);
    Cylinder(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal);
    virtual ~Cylinder();

    virtual HitInfo Hit(const Ray &ray, const SceneManager &manager);
    virtual Color getColorHit(const HitInfo &info, const SceneManager &manager);
  };

RT_NAMESPACE_END

#endif /* !RTECHNOLOGY_RT_CYLINDER_HPP */
