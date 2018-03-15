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

RT_NAMESPACE_BEGIN

  SemiConeTop::SemiConeTop()
  {}

  SemiConeTop::SemiConeTop(const Vector3F &pos) : Object(pos)
  {}

  SemiConeTop::SemiConeTop(const Vector3F &pos, const Vector3F &rot) : Object(pos, rot)
  {}

  SemiConeTop::SemiConeTop(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal) : Object(pos, rot, scal)
  {}

  SemiConeTop::~SemiConeTop()
  {}

  Object::HitInfo SemiConeTop::Hit(const Ray &ray, const SceneManager &manager)
  {
    return HitInfo();
  }

  Color SemiConeTop::getColorHit(const HitInfo &info, const SceneManager &manager)
  {
    return Color();
  }

  void SemiConeTop::setAngle(const float &angle)
  {
    this->angle = angle;
  }

RT_NAMESPACE_END