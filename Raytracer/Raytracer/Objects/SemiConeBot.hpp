/*
** SemiConeBot.hpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 17:11 2018 each
** Last update mer. janv. 17:11 2018 each
*/

#ifndef RTECHNOLOGY_RT_SEMICONEBOT_HPP
#define RTECHNOLOGY_RT_SEMICONEBOT_HPP

#include "../Object.hpp"

RT_NAMESPACE_BEGIN

class SemiConeBot : public Object
{
  float _angle;
 public:
  explicit SemiConeBot();
  explicit SemiConeBot(const Vector3F &pos);
  SemiConeBot(const Vector3F &pos, const Vector3F &rot);
  SemiConeBot(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal);
  virtual ~SemiConeBot();

  virtual HitInfo Hit(const Ray &ray, const SceneManager &manager);
  virtual Color getColorHit(const HitInfo &info, const SceneManager &manager);

  void setAngle(const float &angle);
};

RT_NAMESPACE_END

#endif /* !RTECHNOLOGY_RT_SEMICONEBOT_HPP */
