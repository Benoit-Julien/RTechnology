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

  virtual HitInfo Hit(const Ray &ray, const SceneSettings &settings);
  virtual Color getColorHit(const HitInfo &info);

  void setRadius(const float &radius);

 private:
  float checkDelta(const float &a, const float &b, const float &delta);
};


#endif /* !RTECHNOLOGY_SPHERE_HPP */
