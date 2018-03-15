/*
** ColorAttribute.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. mars 14:15 2018 benoit_g
** Last update sam. mars 14:15 2018 benoit_g
*/

#ifndef RTECHNOLOGY_COLORATTRIBUTE_HPP
#define RTECHNOLOGY_COLORATTRIBUTE_HPP

#include <memory>
#include "Attribute.hpp"
#include "ui_colorattribute.h"

class ColorAttribute : public Attribute
{
  Q_OBJECT

  std::shared_ptr<Ui::ColorAttribute> ui;

 public:
  explicit ColorAttribute(QWidget *parent = nullptr);
  virtual ~ColorAttribute();

  void setRed(const u_char &value);
  const u_char getRed() const;

  void setGreen(const u_char &value);
  const u_char getGreen() const;

  void setBlue(const u_char &value);
  const u_char getBlue() const;

  virtual rapidjson::Value serialize(rapidjson::Document::AllocatorType &allocator);

 private slots:
  void valueUpdate(int);
};


#endif /* !RTECHNOLOGY_COLORATTRIBUTE_HPP */
