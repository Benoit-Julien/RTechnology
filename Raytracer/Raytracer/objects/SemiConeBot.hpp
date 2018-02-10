/*
** SemiConeBot.hpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 17:11 2018 each
** Last update mer. janv. 17:11 2018 each
*/

#ifndef RTECHNOLOGY_SEMICONEBOT_HPP
#define RTECHNOLOGY_SEMICONEBOT_HPP

#include "../Object.hpp"

class SemiConeBot : public Object
{
  float angle;
 public:
  explicit SemiConeBot();
  explicit SemiConeBot(const Vector3F &pos);
  SemiConeBot(const Vector3F &pos, const Vector3F &rot);
  SemiConeBot(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal);
  virtual ~SemiConeBot();

  virtual HitInfo Hit(const Ray &ray, const SceneSettings &settings);
  virtual Color getColorHit(const HitInfo &info);

  void setAngle(const float &angle);
};


#endif /* !RTECHNOLOGY_SEMICONEBOT_HPP */
