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

Cylinder::Cylinder()
{}

Cylinder::Cylinder(const Vector3F &pos) : Object(pos)
{}

Cylinder::Cylinder(const Vector3F &pos, const Vector3F &rot) : Object(pos, rot)
{}

Cylinder::Cylinder(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal) : Object(pos, rot, scal)
{}

Cylinder::~Cylinder()
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
      //A MODIFIER
      info.hitPosition = C + (V * k);
    }
  else
    info.haveHit = false;

  return info;
}

Color Cylinder::getColorHit(const HitInfo &info, const SceneManager &manager)
{
  Vector3F normal = info.hitPosition + this->position;
  normal = normal * Vector3F(1, 0, 1);
  Color color(255, 0, 0);

  for (auto &l : manager.getLights())
    {
      Ray my_ray(info.hitPosition, l->getPosition() - info.hitPosition);
      auto objectHit = manager.checkHit(my_ray);
      if (objectHit.haveHit && objectHit.hitObject != this)
	return Color();
      auto angle = Vector3F::Angle(normal, my_ray.getDirection());
      std::cout << angle * 180 / af::Pi << std::endl;
      if (angle >= af::Pi / 2)
	return Color();
      float coeff = angle / (af::Pi / 2);
      color.r = color.r - (color.r * coeff);
      color.g = color.g - (color.g * coeff);
      color.b = color.b - (color.b * coeff);
    }
  return color;
}

void Cylinder::setRadius(const float &radius)
{
  this->_radius = radius;
}