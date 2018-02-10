/*
** Sphere.cpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 16:16 2018 each
** Last update mer. janv. 16:16 2018 each
*/

#include "Sphere.hpp"

Sphere::Sphere()
	: _radius(1)
{}

Sphere::Sphere(const Vector3F &pos)
	: Object(pos),
	  _radius(1)
{}

Sphere::Sphere(const Vector3F &pos, const Vector3F &rot)
	: Object(pos, rot),
	  _radius(1)
{}

Sphere::Sphere(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal)
	: Object(pos, rot, scal),
	  _radius(1)
{}

Sphere::~Sphere()
{}

Object::HitInfo Sphere::Hit(const Ray &ray, const SceneSettings &settings)
{
  const auto &V = ray.getDirection();
  const auto &C = ray.getOrigin();
  const auto &O = this->position;

  float a = V.magnitude();
  float b = 2 * (V.x() * (O.x() - C.x()) + V.y() * (O.y() - C.y()) + V.z() * (O.z() - C.z()));
  float c = ((O - C)^2) - this->_radius * this->_radius;

  float det;
  if (a == 0.25f)
    det = b * b - 4*c;
  else
    det = b * b - 4*a*c;

  HitInfo info;
  if (det >= 0)
    {
      info.haveHit = true;
      info.hitObject = this;
    }
  else
    info.haveHit = false;

  return info;
/*

  float delta;
  float k;

  auto vec = ray.getDirection();
  auto O = ray.getOrigin();

  float a = vec.magnitude();
  float b = 2 * (vec.x() * (O.x() - this->position.x()) + vec.y() * (O.y() - this->position.y()) + vec.z() * (O.z() - this->position.z()));
  float c = ((O - this->position)^2) - this->_radius * this->_radius;

  delta = (b * b) - (4 * (a * c));
  k = checkDelta(a, b, delta);

  HitInfo hitInfo;

  if (k == -1)
    hitInfo.haveHit = false;
  else
    {
      hitInfo.haveHit = true;
      hitInfo.hitObject = this;
      hitInfo.nbRepeatRay = k;
      //hitInfo.hitPosition =
      hitInfo.distance = k * ray.getDirection().magnitude();
    }

  return hitInfo;
  */
}

Color Sphere::getColorHit(const HitInfo &info)
{
  return Color(255, 255, 255);
}

float Sphere::checkDelta(const float &a, const float &b, const float &delta)
{
  float s1;
  float s2;

  if (delta > 0) {
      s1 = (-b + std::sqrt(delta)) / (2 * a);
      s2 = (-b - std::sqrt(delta)) / (2 * a);
      if (s2 > s1) {
	  if (s1 > 0)
	    return s1;
	  else
	    return s2;
	} else {
	  if (s2 > 0)
	    return s2;
	  else
	    return s1;
	}
    }
  return -1;
}

void Sphere::setRadius(const float &radius)
{
  this->_radius = radius;
}