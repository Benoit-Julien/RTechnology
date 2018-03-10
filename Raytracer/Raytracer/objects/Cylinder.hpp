/*
** Cylinder.hpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 16:55 2018 each
** Last update mer. janv. 16:55 2018 each
*/

#ifndef RTECHNOLOGY_CYLINDER_HPP
#define RTECHNOLOGY_CYLINDER_HPP

#include "../Object.hpp"

class Cylinder : public Object
{
  float _radius;
 public:
  explicit Cylinder();
  explicit Cylinder(const Vector3F &pos);
  Cylinder(const Vector3F &pos, const Vector3F &rot);
  Cylinder(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal);
  virtual ~Cylinder();

  virtual HitInfo Hit(const Ray &ray, const SceneManager &manager);
  virtual Color getColorHit(const HitInfo &info, const SceneManager &manager);

  void setRadius(const float &radius);
};


#endif /* !RTECHNOLOGY_CYLINDER_HPP */
