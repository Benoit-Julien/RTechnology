/*
** Cylinder.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  dim. mars 20:17 2018 benoit_g
** Last update dim. mars 20:17 2018 benoit_g
*/

#include "Cylinder.hpp"

Cylinder::Cylinder(QWidget *parent) : Object("cylinder", "cylinder", parent)
{}

Cylinder::~Cylinder()
{}

rapidjson::Value Cylinder::serialize(rapidjson::Document::AllocatorType &allocator) const
{
  auto value = Object::serialize(allocator);
  value.AddMember("radius", rapidjson::Value(10), allocator);
  return value;
}