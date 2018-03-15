/*
** Attribute.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. mars 12:49 2018 benoit_g
** Last update sam. mars 12:49 2018 benoit_g
*/

#ifndef RTECHNOLOGY_ATTRIBUTE_HPP
#define RTECHNOLOGY_ATTRIBUTE_HPP

#include <QWidget>
#include <rapidjson/document.h>

class Attribute : public QWidget
{
 Q_OBJECT

 public:
  explicit Attribute(QWidget *parent = nullptr);
  virtual ~Attribute();

  virtual rapidjson::Value serialize(rapidjson::Document::AllocatorType &allocator) = 0;

 signals:
  void valueChanged();
};

#endif /* !RTECHNOLOGY_ATTRIBUTE_HPP */
