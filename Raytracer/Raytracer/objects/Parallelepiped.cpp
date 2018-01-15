/*
** Parallelepiped.cpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  jeu. janv. 15:42 2018 each
** Last update jeu. janv. 15:42 2018 each
*/

#include "Parallelepiped.hpp"

Parallelepiped::Parallelepiped()
{}

Parallelepiped::Parallelepiped(const Vector3Float &pos) : Object(pos)
{}

Parallelepiped::Parallelepiped(const Vector3Float &pos, const Vector3Float &rot) : Object(pos, rot)
{}

Parallelepiped::Parallelepiped(const Vector3Float &pos, const Vector3Float &rot, const Vector3Float &scal) : Object(pos,
														    rot,
														    scal)
{}

Parallelepiped::~Parallelepiped()
{}

Object::HitInfo Parallelepiped::Hit(const Ray &ray)
{
  return HitInfo();
}