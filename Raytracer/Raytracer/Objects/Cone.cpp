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
#include "../SceneManager.hpp"

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
      info.haveHit = true;
      info.hitObject = this;
      info.distance = k;
      info.hitPosition = C + (V * k);
      info.normal = info.hitPosition + this->position;
      info.normal *= Vector3F(1, 0, 1);
      float my_y = info.normal.magnitude() * sin((this->_angle * af::Pi / 360) / 2);
      if (this->position.y() < info.hitPosition.y())
	my_y *= -1;
      info.normal = info.normal + Vector3F(0, my_y, 0);
      info.reflect = calculateReflect(ray, info.normal);
    }
  else
    info.haveHit = false;

  return info;
}

Color Cone::getColorHit(const HitInfo &info, const SceneManager &manager)
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

void Cone::setAngle(const float &angle)
{
  this->_angle = angle;
}

