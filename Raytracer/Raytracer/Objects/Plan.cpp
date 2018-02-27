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

  if (ray.getDirection().y() != 0)
    {
      float k = (-ray.getOrigin().y() / ray.getDirection().y());

      if (k > 0)
	{
	  info.haveHit = true;
	  info.hitObject = this;
	  info.distance = k;
	  info.hitPosition = ray.getOrigin() + ray.getDirection() * k;
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
  return Color(0, 0, 255);
}
