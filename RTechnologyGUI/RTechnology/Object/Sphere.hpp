/*
** Sphere.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  dim. mars 20:12 2018 benoit_g
** Last update dim. mars 20:12 2018 benoit_g
*/

#ifndef RTECHNOLOGY_SPHERE_HPP
#define RTECHNOLOGY_SPHERE_HPP

#include <QWidget>
#include "Object.hpp"

class Sphere : public Object
{
 public:
  explicit Sphere(QWidget *parent);
  virtual ~Sphere();
};


#endif /* !RTECHNOLOGY_SPHERE_HPP */
