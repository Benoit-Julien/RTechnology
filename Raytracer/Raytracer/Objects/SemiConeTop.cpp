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
#include "../SceneManager.hpp"

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
  const auto &V = ray.getDirection();
  const auto &C = ray.getOrigin();
  const auto &O = this->position;

  float delta;
  float a;
  float b;
  float c;
  float k;
  float ratio;

  ratio = this->_angle / 100;
  a = (V.x() * V.x()) + (V.z() * V.z()) - ((ratio * ratio) * (V.y() * V.y()));
  b = 2 * ((V.x() * O.x()) + (V.z() * O.z()) - ((ratio * ratio) * (V.y() * O.y())));
  c = (O.x() * O.x()) + (O.z() * O.z()) - ((ratio * ratio) * (O.y() * O.y()));
  delta = (b * b) - (4 * (a * c));
  k = checkDelta(a, b, delta);

  HitInfo info;
  if (k > 0)
    {
      Vector3F hitPosition = C + (V * k);
      if (this->position.y() <= hitPosition.y())
	{
	  info.haveHit = true;
	  info.hitObject = this;
	  info.distance = k;
	  info.hitPosition = hitPosition;
	  info.normal = info.hitPosition + this->position;
	  info.normal *= Vector3F(1, 0, 1);
	  float my_y = info.normal.magnitude() * sin((this->_angle * af::Pi / 360) / 2);
	  if (this->position.y() < info.hitPosition.y())
	    my_y *= -1;
	  info.normal += Vector3F(0, my_y, 0);
	}
      else
	info.haveHit = false;
    }
  else
    info.haveHit = false;

  return info;
}

Color SemiConeTop::getColorHit(const HitInfo &info, const SceneManager &manager)
{
  Color color(255, 0, 0);

  for (auto &l : manager.getLights())
    {
      Ray my_ray(info.hitPosition, l->getPosition() - info.hitPosition);
      auto objectHit = manager.checkHit(my_ray);
      if (objectHit.haveHit && objectHit.hitObject != this)
	return Color();
      auto angle = Vector3F::Angle(info.normal, my_ray.getDirection());
      if (angle >= af::Pi / 2)
	return Color();
      float coeff = angle / (af::Pi / 2);
      color.r = color.r - (color.r * coeff);
      color.g = color.g - (color.g * coeff);
      color.b = color.b - (color.b * coeff);
    }
  return color;

}

void SemiConeTop::setAngle(const float &angle)
{
  this->_angle = angle;
}