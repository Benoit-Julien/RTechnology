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

Object::Object(const std::string &name, QWidget *parent) : parent(parent)
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
