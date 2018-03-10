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
#include <rapidjson/document.h>

#include "AttributesUi/DefaultAttribute.hpp"

class Object
{
 protected:
  const std::string type;

  QWidget *parent;
  std::shared_ptr<DefaultAttribute> defaultAttribute;

 public:
  explicit Object(const std::string &name, const std::string &type, QWidget *parent);
  virtual ~Object();

  void show();
  void hide();

  inline const std::string getName() const
  { return this->defaultAttribute->getName(); }

  rapidjson::Value serialize(rapidjson::Document::AllocatorType &allocator) const;
 private:
  static rapidjson::Value serializeVector(const Vector3F &vec, rapidjson::Document::AllocatorType &allocator);
};

#endif /* !RTECHNOLOGY_OBJECT_HPP */
