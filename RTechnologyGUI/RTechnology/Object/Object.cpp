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
#include "Global.hpp"

Object::Object(const std::string &name, const std::string &type, QWidget *parent)
	: QObject(parent),
	  type(type),
	  parent(parent)
{
  this->defaultAttribute = std::make_shared<DefaultAttribute>(this->parent);
  this->defaultAttribute->hide();
  this->defaultAttribute->setName(name);
  this->defaultAttribute->setScale(rt::Vector3F(1, 1, 1));
  this->parent->layout()->addWidget(this->defaultAttribute.get());

  connect(this->defaultAttribute.get(), SIGNAL(valueChanged()), this, SLOT(updatePreview()));
}

Object::~Object()
{
  this->parent->layout()->removeWidget(this->defaultAttribute.get());
}

void Object::show()
{
  this->defaultAttribute->show();
  for (auto &attr : this->_attributes)
    attr->show();
}

void Object::hide()
{
  this->defaultAttribute->hide();
  for (auto &attr : this->_attributes)
    attr->hide();
}

rapidjson::Value Object::serialize(rapidjson::Document::AllocatorType &allocator) const
{
  rapidjson::Value obj;
  auto pos = this->defaultAttribute->getPosition();
  auto rot = this->defaultAttribute->getRotation();
  auto scal = this->defaultAttribute->getScale();

  obj.SetObject();
  obj.AddMember("type", rapidjson::Value(this->type.c_str(), this->type.size()), allocator);
  if (pos != rt::Vector3F())
    obj.AddMember("position", Object::serializeVector(pos, allocator), allocator);
  if (rot != rt::Vector3F())
    obj.AddMember("rotation", Object::serializeVector(rot, allocator), allocator);
  if (scal != rt::Vector3F(1, 1, 1))
    obj.AddMember("scale", Object::serializeVector(scal, allocator), allocator);

  if (!this->_attributes.empty())
    obj.AddMember("attributes", this->serializeAttributes(allocator), allocator);

  return obj;
}

rapidjson::Value Object::serializeVector(const rt::Vector3F &vec, rapidjson::Document::AllocatorType &allocator)
{
  rapidjson::Value obj;

  obj.SetObject();
  obj.AddMember("x", rapidjson::Value(vec.x()), allocator);
  obj.AddMember("y", rapidjson::Value(vec.y()), allocator);
  obj.AddMember("z", rapidjson::Value(vec.z()), allocator);
  return obj;
}

rapidjson::Value Object::serializeAttributes(rapidjson::Document::AllocatorType &allocator) const
{
  rapidjson::Value attr;
  attr.SetArray();
  auto array = attr.GetArray();

  for (auto &a : this->_attributes)
    array.PushBack(a->serialize(allocator), allocator);
  return attr;
}

void Object::addAttribute(std::shared_ptr<Attribute> attr)
{
  this->_attributes.push_back(attr);
  this->parent->layout()->addWidget(attr.get());
}

const std::vector<std::shared_ptr<Attribute>>& Object::getAttributes() const
{
  return this->_attributes;
}

void Object::updatePreview()
{
  Global::getSingleton().mainWindow->updatePreview();
}