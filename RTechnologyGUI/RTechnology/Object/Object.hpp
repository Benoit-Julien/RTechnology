/*
** Object.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  dim. mars 19:56 2018 benoit_g
** Last update dim. mars 19:56 2018 benoit_g
*/

#ifndef RTECHNOLOGY_OBJECT_HPP
#define RTECHNOLOGY_OBJECT_HPP

#include <string>
#include <memory>
#include <Raytracer/math/Vector3.hpp>
#include <QWidget>

#include "AttributesUi/DefaultAttribute.hpp"

class Object
{
 protected:
  QWidget *parent;
  std::shared_ptr<DefaultAttribute> defaultAttribute;

 public:
  explicit Object(const std::string &name, QWidget *parent);
  virtual ~Object();

  void show();
  void hide();

  inline const std::string getName() const
  { return this->defaultAttribute->getName(); }
};

#endif /* !RTECHNOLOGY_OBJECT_HPP */
