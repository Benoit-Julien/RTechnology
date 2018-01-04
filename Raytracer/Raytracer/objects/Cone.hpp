/*
** Cone.hpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 16:41 2018 each
** Last update mer. janv. 16:41 2018 each
*/

#ifndef RTECHNOLOGY_CONE_HPP
#define RTECHNOLOGY_CONE_HPP

#include "../Object.hpp"

class Cone : public Object
{
  float angle;
 public:
  explicit Cone();
  explicit Cone(const Vector3Float &pos);
  Cone(const Vector3Float &pos, const Vector3Float &rot);
  Cone(const Vector3Float &pos, const Vector3Float &rot, const Vector3Float &scal);
  virtual ~Cone();

  virtual bool Hit(const Ray &ray);
  virtual Color GetColorHit() const;
  void setAngle(const float &angle);
};


#endif /* !RTECHNOLOGY_CONE_HPP */
