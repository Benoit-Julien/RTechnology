/*
** Light.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. mars 14:31 2018 benoit_g
** Last update sam. mars 14:31 2018 benoit_g
*/

#ifndef RTECHNOLOGY_LIGHT_HPP
#define RTECHNOLOGY_LIGHT_HPP

#include "Object/Object.hpp"
#include "AttributesUi/ColorAttribute.hpp"

class Light : public Object
{
  Q_OBJECT

 public:
  explicit Light(const std::string &name, const std::string &type, QWidget *parent);
  virtual ~Light();
};


#endif /* !RTECHNOLOGY_LIGHT_HPP */
