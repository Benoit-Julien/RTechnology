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
  explicit SemiConeBot(const Vector3Float &pos);
  SemiConeBot(const Vector3Float &pos, const Vector3Float &rot);
  SemiConeBot(const Vector3Float &pos, const Vector3Float &rot, const Vector3Float &scal);
  virtual ~SemiConeBot();

  virtual HitInfo Hit(const Ray &ray);
  void setAngle(const float &angle);
};


#endif /* !RTECHNOLOGY_SEMICONEBOT_HPP */
