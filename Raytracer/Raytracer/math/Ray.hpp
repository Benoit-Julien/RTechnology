/*
** Ray.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 11:30 2017 benoit_g
** Last update mar. déc. 11:30 2017 benoit_g
*/

#ifndef RTECHNOLOGY_RAY_HPP
#define RTECHNOLOGY_RAY_HPP

#include "Vector3.hpp"

class Ray
{
  Vector3F _origin;
  Vector3F _direction;

 public:
  Ray(const Vector3F &origin, const Vector3F &direction);
  Ray(const Ray &ray);
  Ray(Ray &&ray) noexcept;
  Ray &operator=(const Ray &ray);
  Ray &operator=(Ray &&ray) noexcept;
  ~Ray() = default;

  const Vector3F &getOrigin() const;
  const Vector3F &getDirection() const;

  void setOrigin(const Vector3F &origin);
  void setDirection(const Vector3F &direction);
};


#endif /* !RTECHNOLOGY_RAY_HPP */
