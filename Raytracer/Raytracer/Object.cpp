/*
** Object.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 10:57 2017 benoit_g
** Last update mar. déc. 10:57 2017 benoit_g
*/

#include "Object.hpp"

Object::Object()
	: position(0, 0, 0),
	  rotation(0, 0, 0),
	  scale(1, 1, 1)
{}

Object::Object(const Vector3Float &pos)
	: position(pos),
	  rotation(0, 0, 0),
	  scale(1, 1, 1)
{}

Object::Object(const Vector3Float &pos, const Vector3Float &rot)
	: position(pos),
	  rotation(rot),
	  scale(1, 1, 1)
{}

Object::Object(const Vector3Float &pos, const Vector3Float &rot, const Vector3Float &scal)
	: position(pos),
	  rotation(rot),
	  scale(scal)
{}

Object::Object(const Object &obj)
	: position(obj.position),
	  rotation(obj.rotation),
	  scale(obj.scale)
{}

Object::Object(Object &&obj) noexcept
	: position(obj.position),
	  rotation(obj.rotation),
	  scale(obj.scale)
{}

Object &Object::operator=(const Object &obj)
{
  return *this;
}

Object &Object::operator=(Object &&obj) noexcept
{
  return *this;
}

const Vector3Float &Object::getPosition() const
{
  return this->position;
}

const Vector3Float &Object::getRotation() const
{
  return this->rotation;
}

const Vector3Float &Object::getScale() const
{
  return this->scale;
}

void Object::registerAttribute(std::shared_ptr<IAttribute> attribute)
{
  this->attributes.push_back(attribute);
}