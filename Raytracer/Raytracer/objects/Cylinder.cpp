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

Cylinder::Cylinder(const Vector3Float &pos) : Object(pos)
{}

Cylinder::Cylinder(const Vector3Float &pos, const Vector3Float &rot) : Object(pos, rot)
{}

Cylinder::Cylinder(const Vector3Float &pos, const Vector3Float &rot, const Vector3Float &scal) : Object(pos, rot, scal)
{}

Cylinder::~Cylinder()
{}

bool Cylinder::Hit(const Ray &ray)
{
  return false;
}

Color Cylinder::GetColorHit() const
{
  return Color();
}