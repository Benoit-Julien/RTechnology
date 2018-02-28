/*
** Cylinder.cpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 16:55 2018 each
** Last update mer. janv. 16:55 2018 each
*/

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
  return HitInfo();
}

Color Cylinder::getColorHit(const HitInfo &info, const SceneManager &manager)
{
  return Color();
}