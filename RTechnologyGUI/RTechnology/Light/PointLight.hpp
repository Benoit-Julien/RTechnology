/*
** PointLight.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. mars 14:44 2018 benoit_g
** Last update sam. mars 14:44 2018 benoit_g
*/

#ifndef RTECHNOLOGY_POINTLIGHT_HPP
#define RTECHNOLOGY_POINTLIGHT_HPP

#include "Light.hpp"

class PointLight : public Light
{
 Q_OBJECT

 public:
  explicit PointLight(QWidget *parent);
  virtual ~PointLight();
};


#endif /* !RTECHNOLOGY_POINTLIGHT_HPP */
