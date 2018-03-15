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

class Object : public QObject
{
  Q_OBJECT

  std::vector<std::shared_ptr<Attribute>> _attributes;

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

  virtual rapidjson::Value serialize(rapidjson::Document::AllocatorType &allocator) const;

  void addAttribute(std::shared_ptr<Attribute> attr);
  const std::vector<std::shared_ptr<Attribute>> &getAttributes() const;

  inline std::shared_ptr<DefaultAttribute> getDefaultAttribute() const
  { return this->defaultAttribute; }

 private:
  static rapidjson::Value serializeVector(const rt::Vector3F &vec, rapidjson::Document::AllocatorType &allocator);
  rapidjson::Value serializeAttributes(rapidjson::Document::AllocatorType &allocator) const;

 private slots:
  void updatePreview();
};

#endif /* !RTECHNOLOGY_OBJECT_HPP */
