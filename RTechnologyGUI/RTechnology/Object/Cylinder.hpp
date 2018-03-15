/*
** Cylinder.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  dim. mars 20:17 2018 benoit_g
** Last update dim. mars 20:17 2018 benoit_g
*/

#ifndef RTECHNOLOGY_CYLINDER_HPP
#define RTECHNOLOGY_CYLINDER_HPP

#include "Object.hpp"

class Cylinder : public Object
{
 Q_OBJECT

 public:
  explicit Cylinder(QWidget *parent);
  virtual ~Cylinder();

  virtual rapidjson::Value serialize(rapidjson::Document::AllocatorType &allocator) const;
};


#endif /* !RTECHNOLOGY_CYLINDER_HPP */
