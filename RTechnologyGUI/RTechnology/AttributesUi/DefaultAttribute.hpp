/*
** DefaultAttribute.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  dim. mars 21:52 2018 benoit_g
** Last update dim. mars 21:52 2018 benoit_g
*/

#ifndef RTECHNOLOGY_DEFAULTATTRIBUTE_HPP
#define RTECHNOLOGY_DEFAULTATTRIBUTE_HPP

#include <QWidget>
#include <memory>
#include <Raytracer/math/Vector3.hpp>
#include "ui_defaultattribute.h"

class DefaultAttribute : public QWidget
{
 Q_OBJECT

  std::shared_ptr<Ui::DefaultAttribute> ui;

 public:
  explicit DefaultAttribute(QWidget *parent = nullptr);
  ~DefaultAttribute();

  void setName(const std::string &name);
  const std::string getName() const;

  void setPosition(const Vector3F &position);
  const Vector3F getPosition() const;

  void setRotation(const Vector3F &rotation);
  const Vector3F getRotation() const;

  void setScale(const Vector3F &scale);
  const Vector3F getScale() const;
};

#endif /* !RTECHNOLOGY_DEFAULTATTRIBUTE_HPP */
