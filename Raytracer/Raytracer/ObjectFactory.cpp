/*
** ObjectFactory.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 17:25 2017 benoit_g
** Last update mar. déc. 17:25 2017 benoit_g
*/

#include "ObjectFactory.hpp"

ObjectFactory::ObjectFactory()
{
  this->_map = {
	  {ObjectFactory::ObjectType::SPHERE, &ObjectFactory::makeSphere},
	  {ObjectFactory::ObjectType::PLANE, &ObjectFactory::makePlane}
  };
}

ObjectFactory &ObjectFactory::getSingleton()
{
  static ObjectFactory factory;

  return factory;
}

std::shared_ptr<Object> ObjectFactory::createObject(const ObjectFactory::ObjectType &type)
{
  auto &factory = ObjectFactory::getSingleton();

  for (auto &it : factory._map)
    {
      if (it.first == type)
	return it.second();
    }
  return nullptr;
}

std::shared_ptr<Object> ObjectFactory::makeSphere()
{
  return nullptr;
}

std::shared_ptr<Object> ObjectFactory::makePlane()
{
  return nullptr;
}