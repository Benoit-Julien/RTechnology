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

Object::HitInfo::HitInfo()
	: haveHit(false),
	  nbRepeatRay(0),
	  distance(0),
	  hitObject(nullptr)
{}

Object::Object()
	: position(0, 0, 0),
	  rotation(0, 0, 0),
	  scale(1, 1, 1)
{}

Object::Object(const Vector3F &pos)
	: position(pos),
	  rotation(0, 0, 0),
	  scale(1, 1, 1)
{}

Object::Object(const Vector3F &pos, const Vector3F &rot)
	: position(pos),
	  rotation(rot),
	  scale(1, 1, 1)
{}

Object::Object(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal)
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

const Vector3F &Object::getPosition() const
{
  return this->position;
}

const Vector3F &Object::getRotation() const
{
  return this->rotation;
}

const Vector3F &Object::getScale() const
{
  return this->scale;
}

void Object::registerAttribute(std::shared_ptr<IAttribute> attribute)
{
  this->attributes.push_back(attribute);
}