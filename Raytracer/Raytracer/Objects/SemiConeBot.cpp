/*
** SemiConeBot.cpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 17:11 2018 each
** Last update mer. janv. 17:11 2018 each
*/

#include "SemiConeBot.hpp"

SemiConeBot::SemiConeBot()
{}

SemiConeBot::SemiConeBot(const Vector3F &pos) : Object(pos)
{}

SemiConeBot::SemiConeBot(const Vector3F &pos, const Vector3F &rot) : Object(pos, rot)
{}

SemiConeBot::SemiConeBot(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal) : Object(pos, rot,
													      scal)
{}

SemiConeBot::~SemiConeBot()
{}

Object::HitInfo SemiConeBot::Hit(const Ray &ray, const SceneManager &manager)
{
  return HitInfo();
}

Color SemiConeBot::getColorHit(const HitInfo &info, const SceneManager &manager)
{
  return Color();
}

void SemiConeBot::setAngle(const float &angle)
{
  this->angle = angle;
}