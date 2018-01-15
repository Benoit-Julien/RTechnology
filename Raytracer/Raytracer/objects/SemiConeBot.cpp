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

SemiConeBot::SemiConeBot(const Vector3Float &pos) : Object(pos)
{}

SemiConeBot::SemiConeBot(const Vector3Float &pos, const Vector3Float &rot) : Object(pos, rot)
{}

SemiConeBot::SemiConeBot(const Vector3Float &pos, const Vector3Float &rot, const Vector3Float &scal) : Object(pos, rot,
													      scal)
{}

SemiConeBot::~SemiConeBot()
{}

bool SemiConeBot::Hit(const Ray &ray)
{
  return false;
}

Object::HitInfo SemiConeBot::Hit(const Ray &ray)
{
  return HitInfo();
}

void SemiConeBot::setAngle(const float &angle)
{
  this->angle = angle;
}