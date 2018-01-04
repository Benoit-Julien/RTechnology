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
  explicit Cylinder();
  explicit Cylinder(const Vector3Float &pos);
  Cylinder(const Vector3Float &pos, const Vector3Float &rot);
  Cylinder(const Vector3Float &pos, const Vector3Float &rot, const Vector3Float &scal);
  virtual ~Cylinder();

  virtual bool Hit(const Ray &ray);
  virtual Color GetColorHit() const;
};


#endif /* !RTECHNOLOGY_CYLINDER_HPP */
