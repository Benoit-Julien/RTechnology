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
  explicit Cone(const Vector3F &pos);
  Cone(const Vector3F &pos, const Vector3F &rot);
  Cone(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal);
  virtual ~Cone();

  virtual HitInfo Hit(const Ray &ray, const SceneManager &manager);
  virtual Color getColorHit(const HitInfo &info, const SceneManager &manager);
  void setAngle(const float &angle);
};


#endif /* !RTECHNOLOGY_CONE_HPP */
