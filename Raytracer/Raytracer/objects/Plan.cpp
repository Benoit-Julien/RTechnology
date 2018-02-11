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
{}

Plan::Plan(const Vector3F &pos) : Object(pos)
{}

Plan::Plan(const Vector3F &pos, const Vector3F &rot) : Object(pos, rot)
{}

Plan::~Plan()
{}

Object::HitInfo Plan::Hit(const Ray &ray, const SceneSettings &settings)
{

}

Color Plan::getColorHit(const HitInfo &info)
{
  return Color(0, 255);
}
