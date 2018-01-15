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
{}

Sphere::Sphere(const Vector3Float &pos) : Object(pos)
{}

Sphere::Sphere(const Vector3Float &pos, const Vector3Float &rot) : Object(pos, rot)
{}

Sphere::Sphere(const Vector3Float &pos, const Vector3Float &rot, const Vector3Float &scal) : Object(pos, rot, scal)
{}

Sphere::~Sphere()
{}

Object::HitInfo Sphere::Hit(const Ray &ray)
{
  return HitInfo();
}