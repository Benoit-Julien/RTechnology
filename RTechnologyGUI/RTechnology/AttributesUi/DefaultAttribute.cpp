/*
** DefaultAttribute.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  dim. mars 21:52 2018 benoit_g
** Last update dim. mars 21:52 2018 benoit_g
*/

#include "DefaultAttribute.hpp"
#include "Global.hpp"

DefaultAttribute::DefaultAttribute(QWidget *parent) : QWidget(parent)
{
  ui = std::make_shared<Ui::DefaultAttribute>();
  ui->setupUi(this);

  connect(ui->name_lineEdit, SIGNAL(textEdited(QString)),
	  Global::getSingleton().mainWindow.get(), SLOT(itemNameUpdate(QString)));
}

DefaultAttribute::~DefaultAttribute()
{}

void DefaultAttribute::setName(const std::string &name)
{
  ui->name_lineEdit->setText(QString::fromStdString(name));
}

const std::string DefaultAttribute::getName() const
{
  return ui->name_lineEdit->text().toStdString();
}

void DefaultAttribute::setPosition(const Vector3F &position)
{
  ui->position_x_value->setValue(position.x());
  ui->position_y_value->setValue(position.y());
  ui->position_z_value->setValue(position.z());
}

const Vector3F DefaultAttribute::getPosition() const
{
  float x, y, z;
  x = (float)ui->position_x_value->value();
  y = (float)ui->position_y_value->value();
  z = (float)ui->position_z_value->value();
  return Vector3F(x, y, z);
}

void DefaultAttribute::setRotation(const Vector3F &rotation)
{
  ui->rotation_x_value->setValue(rotation.x());
  ui->rotation_y_value->setValue(rotation.y());
  ui->rotation_z_value->setValue(rotation.z());
}

const Vector3F DefaultAttribute::getRotation() const
{
  float x, y, z;
  x = (float)ui->rotation_x_value->value();
  y = (float)ui->rotation_y_value->value();
  z = (float)ui->rotation_z_value->value();
  return Vector3F(x, y, z);
}

void DefaultAttribute::setScale(const Vector3F &scale)
{
  ui->scale_x_value->setValue(scale.x());
  ui->scale_y_value->setValue(scale.y());
  ui->scale_z_value->setValue(scale.z());
}

const Vector3F DefaultAttribute::getScale() const
{
  float x, y, z;
  x = (float)ui->scale_x_value->value();
  y = (float)ui->scale_y_value->value();
  z = (float)ui->scale_z_value->value();
  return Vector3F(x, y, z);
}