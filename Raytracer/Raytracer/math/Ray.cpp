/*
** Ray.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 11:30 2017 benoit_g
** Last update mar. déc. 11:30 2017 benoit_g
*/

#include "Ray.hpp"

Ray::Ray(const Vector3Float &origin, const Vector3Float &direction)
	: _origin(origin),
	  _direction(direction)
{}

Ray::Ray(const Ray &ray)
	: _origin(ray._origin),
	  _direction(ray._direction)
{}

Ray::Ray(Ray &&ray) noexcept
	: _origin(ray._origin),
	  _direction(ray._direction)
{}

Ray &Ray::operator=(const Ray &ray)
{
  this->_origin = ray._origin;
  this->_direction = ray._direction;

  return *this;
}

Ray &Ray::operator=(Ray &&ray) noexcept
{
  this->_origin = ray._origin;
  this->_direction = ray._direction;

  return *this;
}

const Vector3Float &Ray::getOrigin() const
{
  return this->_origin;
}

const Vector3Float &Ray::getDirection() const
{
  return this->_direction;
}