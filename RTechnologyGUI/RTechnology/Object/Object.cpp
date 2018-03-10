/*
** Object.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  dim. mars 22:03 2018 benoit_g
** Last update dim. mars 22:03 2018 benoit_g
*/

#include "Object.hpp"

Object::Object(const std::string &name, const std::string &type, QWidget *parent) : type(type), parent(parent)
{
  this->defaultAttribute = std::make_shared<DefaultAttribute>(this->parent);
  this->defaultAttribute->hide();
  this->defaultAttribute->setName(name);
  this->defaultAttribute->setScale(Vector3F(1, 1, 1));
  this->parent->layout()->addWidget(this->defaultAttribute.get());
}

Object::~Object()
{
  this->parent->layout()->removeWidget(this->defaultAttribute.get());
}

void Object::show()
{
  this->defaultAttribute->show();
}

void Object::hide()
{
  this->defaultAttribute->hide();
}

rapidjson::Value Object::serialize(rapidjson::Document::AllocatorType &allocator) const
{
  rapidjson::Value obj;
  auto pos = this->defaultAttribute->getPosition();
  auto rot = this->defaultAttribute->getRotation();
  auto scal = this->defaultAttribute->getScale();

  obj.SetObject();
  obj.AddMember("type", rapidjson::Value(this->type.c_str(), this->type.size()), allocator);
  if (pos != Vector3F())
    obj.AddMember("position", this->serializeVector(pos, allocator), allocator);
  if (rot != Vector3F())
    obj.AddMember("rotation", this->serializeVector(rot, allocator), allocator);
  if (scal != Vector3F(1, 1, 1))
    obj.AddMember("scale", this->serializeVector(scal, allocator), allocator);

  return obj;
}

rapidjson::Value Object::serializeVector(const Vector3F &vec, rapidjson::Document::AllocatorType &allocator)
{
  rapidjson::Value obj;

  obj.SetObject();
  obj.AddMember("x", rapidjson::Value(vec.x()), allocator);
  obj.AddMember("y", rapidjson::Value(vec.y()), allocator);
  obj.AddMember("z", rapidjson::Value(vec.z()), allocator);
  return obj;
}