/*
** Cone.cpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 16:41 2018 each
** Last update mer. janv. 16:41 2018 each
*/

#include "Cone.hpp"

Cone::Cone()
{}

Cone::Cone(const Vector3Float &pos) : Object(pos)
{}

Cone::Cone(const Vector3Float &pos, const Vector3Float &rot) : Object(pos, rot)
{}

Cone::Cone(const Vector3Float &pos, const Vector3Float &rot, const Vector3Float &scal) : Object(pos, rot, scal)
{}

Cone::~Cone()
{}

Object::HitInfo Cone::Hit(const Ray &ray)
{
  return HitInfo();
}

void Cone::setAngle(const float &angle)
{
  this->angle = angle;
}

