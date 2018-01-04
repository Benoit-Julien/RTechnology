/*
** Sphere.hpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 16:16 2018 each
** Last update mer. janv. 16:16 2018 each
*/

#ifndef RTECHNOLOGY_SPHERE_HPP
#define RTECHNOLOGY_SPHERE_HPP

#include "../Object.hpp"

class Sphere : public Object
{
 public:
  explicit Sphere();
  explicit Sphere(const Vector3Float &pos);
  Sphere(const Vector3Float &pos, const Vector3Float &rot);
  Sphere(const Vector3Float &pos, const Vector3Float &rot, const Vector3Float &scal);
  virtual ~Sphere();

  virtual bool Hit(const Ray &ray);
  virtual Color GetColorHit() const;
};


#endif /* !RTECHNOLOGY_SPHERE_HPP */
