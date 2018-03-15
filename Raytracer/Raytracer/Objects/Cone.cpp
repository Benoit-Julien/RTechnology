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

RT_NAMESPACE_BEGIN

  Cone::Cone()
  {}

  Cone::Cone(const Vector3F &pos) : Object(pos)
  {}

  Cone::Cone(const Vector3F &pos, const Vector3F &rot) : Object(pos, rot)
  {}

  Cone::Cone(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal) : Object(pos, rot, scal)
  {}

  Cone::~Cone()
  {}

  Object::HitInfo Cone::Hit(const Ray &ray, const SceneManager &manager)
  {
    return HitInfo();
  }

  Color Cone::getColorHit(const HitInfo &info, const SceneManager &manager)
  {
    return Color();
  }

  void Cone::setAngle(const float &angle)
  {
    this->angle = angle;
  }

RT_NAMESPACE_END