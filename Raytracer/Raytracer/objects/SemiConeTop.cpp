/*
** SemiConeTop.cpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 17:03 2018 each
** Last update mer. janv. 17:03 2018 each
*/

#include "SemiConeTop.hpp"

SemiConeTop::SemiConeTop()
{}

SemiConeTop::SemiConeTop(const Vector3Float &pos) : Object(pos)
{}

SemiConeTop::SemiConeTop(const Vector3Float &pos, const Vector3Float &rot) : Object(pos, rot)
{}

SemiConeTop::SemiConeTop(const Vector3Float &pos, const Vector3Float &rot, const Vector3Float &scal) : Object(pos, rot,
													      scal)
{}

SemiConeTop::~SemiConeTop()
{}

Object::HitInfo SemiConeTop::Hit(const Ray &ray)
{
  return HitInfo();
}

void SemiConeTop::setAngle(const float &angle)
{
  this->angle = angle;
}