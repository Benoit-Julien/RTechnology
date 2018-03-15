/*
** Sphere.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  dim. mars 20:12 2018 benoit_g
** Last update dim. mars 20:12 2018 benoit_g
*/

#include "Sphere.hpp"

Sphere::Sphere(QWidget *parent) : Object("sphere", "sphere", parent)
{}

Sphere::~Sphere()
{}

rapidjson::Value Sphere::serialize(rapidjson::Document::AllocatorType &allocator) const
{
  auto value = Object::serialize(allocator);
  value.AddMember("radius", rapidjson::Value(10), allocator);
  return value;
}