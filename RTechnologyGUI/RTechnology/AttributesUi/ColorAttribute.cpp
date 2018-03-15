/*
** ColorAttribute.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. mars 14:15 2018 benoit_g
** Last update sam. mars 14:15 2018 benoit_g
*/

#include "ColorAttribute.hpp"

ColorAttribute::ColorAttribute(QWidget *parent) : Attribute(parent)
{
  ui = std::make_shared<Ui::ColorAttribute>();
  ui->setupUi(this);

  connect(ui->color_r_value, SIGNAL(valueChanged(int)), this, SLOT(valueUpdate(int)));
  connect(ui->color_g_value, SIGNAL(valueChanged(int)), this, SLOT(valueUpdate(int)));
  connect(ui->color_b_value, SIGNAL(valueChanged(int)), this, SLOT(valueUpdate(int)));
}

ColorAttribute::~ColorAttribute()
{}

void ColorAttribute::setRed(const u_char &value)
{
  ui->color_r_value->setValue((int)value);
}

const u_char ColorAttribute::getRed() const
{
  return (u_char)ui->color_r_value->value();
}

void ColorAttribute::setGreen(const u_char &value)
{
  ui->color_g_value->setValue((int)value);
}

const u_char ColorAttribute::getGreen() const
{
  return (u_char)ui->color_g_value->value();
}

void ColorAttribute::setBlue(const u_char &value)
{
  ui->color_b_value->setValue((int)value);
}

const u_char ColorAttribute::getBlue() const
{
  return (u_char)ui->color_b_value->value();
}

rapidjson::Value ColorAttribute::serialize(rapidjson::Document::AllocatorType &allocator)
{
  rapidjson::Value color;
  color.SetObject();

  color.AddMember("r", rapidjson::Value(this->getRed()), allocator);
  color.AddMember("g", rapidjson::Value(this->getGreen()), allocator);
  color.AddMember("b", rapidjson::Value(this->getBlue()), allocator);

  return color;
}

void ColorAttribute::valueUpdate(int)
{
  emit this->valueChanged();
}