/*
** Plan.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. févr. 15:18 2018 benoit_g
** Last update sam. févr. 15:18 2018 benoit_g
*/

#include "Plan.hpp"
#include "../SceneManager.hpp"

Plan::Plan()
{
  this->_normal = Vector3F::up - this->position;
}

Plan::Plan(const Vector3F &pos) : Object(pos)
{
  this->_normal = Vector3F::up - this->position;
}

Plan::Plan(const Vector3F &pos, const Vector3F &rot) : Object(pos, rot)
{
  this->_normal = Vector3F::up - this->position;
}

Plan::~Plan()
{}

Object::HitInfo Plan::Hit(const Ray &ray, const SceneManager &manager)
{
  HitInfo info;

  if (std::abs(ray.getOrigin().y() - this->position.y()) > 0.001)
    {
      Vector3F my_vector = ray.getDirection().normalized();

      float k = (ray.getOrigin().y() - this->position.y()) / my_vector.y();

      if (k > 0)
	{
	  info.haveHit = true;
	  info.hitObject = this;
	  info.distance = k;
	  info.hitPosition = ray.getOrigin() + ray.getDirection() * k;
	  info.normal = Vector3F(0, 1, 0);
	}
      else
	info.haveHit = false;
    }
  else
    info.haveHit = false;

  return info;
}

Color Plan::getColorHit(const HitInfo &info, const SceneManager &manager)
{
  Color color(255, 255, 255);

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
