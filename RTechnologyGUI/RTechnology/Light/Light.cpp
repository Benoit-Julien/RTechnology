/*
** Light.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. mars 14:31 2018 benoit_g
** Last update sam. mars 14:31 2018 benoit_g
*/

#include "Light.hpp"

Light::Light(const std::string &name, const std::string &type, QWidget *parent) : Object(name, type, parent)
{
  auto color = std::make_shared<ColorAttribute>(this->parent);
  color->setRed(255);
  color->setGreen(255);
  color->setBlue(255);
  color->hide();

  this->addAttribute(color);

  this->defaultAttribute->getUi()->scale_label->setEnabled(false);
  this->defaultAttribute->getUi()->scale_x_label->setEnabled(false);
  this->defaultAttribute->getUi()->scale_x_value->setEnabled(false);
  this->defaultAttribute->getUi()->scale_y_label->setEnabled(false);
  this->defaultAttribute->getUi()->scale_y_value->setEnabled(false);
  this->defaultAttribute->getUi()->scale_z_label->setEnabled(false);
  this->defaultAttribute->getUi()->scale_z_value->setEnabled(false);
}

Light::~Light()
{}