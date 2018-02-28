/*
** Model.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. févr. 14:16 2018 benoit_g
** Last update mer. févr. 14:16 2018 benoit_g
*/

#include "Model.hpp"

Model::Model()
{}

Model::Model(const Vector3F &pos) : Object(pos)
{}

Model::Model(const Vector3F &pos, const Vector3F &rot) : Object(pos, rot)
{}

Model::Model(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal) : Object(pos, rot, scal)
{}

Model::~Model()
{}

Object::HitInfo Model::Hit(const Ray &ray, const SceneManager &manager)
{
  return HitInfo();
}

Color Model::getColorHit(const HitInfo &info, const SceneManager &manager)
{
  return Color();
}