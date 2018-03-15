/*
** Cylinder.cpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 16:55 2018 each
** Last update mer. janv. 16:55 2018 each
*/

#include "../SceneManager.hpp"
#include "Cylinder.hpp"

RT_NAMESPACE_BEGIN

  Cylinder::Cylinder()
  {}

  Cylinder::Cylinder(const Vector3F &pos) : Object(pos)
  {}

  Cylinder::Cylinder(const Vector3F &pos, const Vector3F &rot) : Object(pos, rot)
  {}

  Cylinder::Cylinder(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal) : Object(pos, rot, scal)
  {}

Object::HitInfo Cylinder::Hit(const Ray &ray, const SceneManager &manager)
{
  const auto &V = ray.getDirection();
  const auto &C = ray.getOrigin();
  const auto &O = this->position;

  float delta;
  float a;
  float b;
  float c;
  float k;

  a = (V.x() * V.x()) + (V.z() * V.z());
  b = 2 * ((V.x() * O.x()) + (V.z() * O.z()));
  c = (O.x() + O.x()) + (O.z() * O.z()) - (this->_radius * this->_radius);
  delta = (b * b) - (4 * (a * c));
  k = this->checkDelta(a, b, delta);
  HitInfo info;

  if (k > 0)
    {
      info.haveHit = true;
      info.hitObject = this;
      info.distance = k;
      info.hitPosition = C + (V * k);
      info.normal = info.hitPosition + this->position;
      info.normal *=  Vector3F(1, 0, 1);
      info.reflect = calculateReflect(ray, info.normal);
    }
  else
    info.haveHit = false;

  return info;
}

Color Cylinder::getColorHit(const HitInfo &info, const SceneManager &manager)
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

      auto angleSpec = Vector3F::Angle(info.reflect, my_ray.getDirection());
      if (angleSpec < af::Pi / 20)
	{
	  float coeffSpec = angleSpec / (af::Pi / 20);
	  color.r = 255 - (255 - color.r) * coeffSpec;
	  color.g = 255 - (255 - color.g) * coeffSpec;
	  color.b = 255 - (255 - color.b) * coeffSpec;
	}
    }
  return color;
}

void Cylinder::setRadius(const float &radius)
{
  this->_radius = radius;
}
RT_NAMESPACE_END
