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
  float _radius;

 public:
  explicit Sphere();
  explicit Sphere(const Vector3F &pos);
  Sphere(const Vector3F &pos, const Vector3F &rot);
  Sphere(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal);
  virtual ~Sphere();

  virtual HitInfo Hit(const Ray &ray, const SceneManager &manager);
  virtual Color getColorHit(const HitInfo &info, const SceneManager &manager);

  void setRadius(const float &radius);
};


#endif /* !RTECHNOLOGY_SPHERE_HPP */
