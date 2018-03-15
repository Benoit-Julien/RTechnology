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

#include <memory>
#include <Raytracer/math/Vector3.hpp>
#include "Attribute.hpp"
#include "ui_defaultattribute.h"

class DefaultAttribute : public Attribute
{
 Q_OBJECT

  std::shared_ptr<Ui::DefaultAttribute> ui;

 public:
  explicit DefaultAttribute(QWidget *parent = nullptr);
  virtual ~DefaultAttribute();

  void setName(const std::string &name);
  const std::string getName() const;

  void setPosition(const rt::Vector3F &position);
  const rt::Vector3F getPosition() const;

  void setRotation(const rt::Vector3F &rotation);
  const rt::Vector3F getRotation() const;

  void setScale(const rt::Vector3F &scale);
  const rt::Vector3F getScale() const;

  virtual rapidjson::Value serialize(rapidjson::Document::AllocatorType &allocator);

  inline std::shared_ptr<Ui::DefaultAttribute> getUi()
  { return this->ui; }

 private slots:
  void valueUpdate(double);
};

#endif /* !RTECHNOLOGY_DEFAULTATTRIBUTE_HPP */
