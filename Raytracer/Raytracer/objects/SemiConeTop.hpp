/*
** SemiConeTop.hpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 17:03 2018 each
** Last update mer. janv. 17:03 2018 each
*/

#ifndef RTECHNOLOGY_SEMICONETOP_HPP
#define RTECHNOLOGY_SEMICONETOP_HPP

#include "../Object.hpp"

class SemiConeTop : public Object
{
  float angle;
 public:
  explicit SemiConeTop();
  explicit SemiConeTop(const Vector3F &pos);
  SemiConeTop(const Vector3F &pos, const Vector3F &rot);
  SemiConeTop(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal);
  virtual ~SemiConeTop();

  virtual HitInfo Hit(const Ray &ray, const SceneSettings &settings);
  virtual Color getColorHit(const HitInfo &info);

  void setAngle(const float &angle);
};


#endif /* !RTECHNOLOGY_SEMICONETOP_HPP */
