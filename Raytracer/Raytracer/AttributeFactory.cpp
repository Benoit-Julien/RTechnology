/*
** AttributeFactory.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 18:06 2017 benoit_g
** Last update mar. déc. 18:06 2017 benoit_g
*/

#include "AttributeFactory.hpp"

AttributeFactory::AttributeFactory()
{
  this->_map = {
	  {AttributeFactory::AttributeType::COLOR, &AttributeFactory::makeColor}
  };
}

AttributeFactory &AttributeFactory::getSingleton()
{
  static AttributeFactory factory;

  return factory;
}

std::shared_ptr<IAttribute> AttributeFactory::createAttribute(const AttributeFactory::AttributeType &type)
{
  auto &factory = AttributeFactory::getSingleton();

  for (auto &it : factory._map)
    {
      if (it.first == type)
	return it.second();
    }
  return nullptr;
}

std::shared_ptr<IAttribute> AttributeFactory::makeColor()
{
  return nullptr;
}
