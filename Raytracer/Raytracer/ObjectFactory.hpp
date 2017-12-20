/*
** ObjectFactory.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 17:25 2017 benoit_g
** Last update mar. déc. 17:25 2017 benoit_g
*/

#ifndef RTECHNOLOGY_OBJECTFACTORY_HPP
#define RTECHNOLOGY_OBJECTFACTORY_HPP

#include <unordered_map>
#include <memory>
#include <functional>

#include "config.h"
#include "Object.hpp"
#include "EnumClassHash.hh"

class ObjectFactory
{
 public:
  enum class ObjectType : unsigned int
  {
    PLANE,
    SPHERE
  };

 private:
  std::unordered_map<ObjectFactory::ObjectType, std::function<std::shared_ptr<Object>(void)>, EnumClassHash<unsigned int>> _map;

  ObjectFactory();
  static ObjectFactory &getSingleton();

 public:
  ObjectFactory(const ObjectFactory &factory) = delete;
  ObjectFactory(ObjectFactory &&factory) = delete;
  ObjectFactory &operator=(const ObjectFactory &factory) = delete;
  ObjectFactory &operator=(ObjectFactory &&factory) = delete;
  ~ObjectFactory() = default;

  static std::shared_ptr<Object> createObject(const ObjectFactory::ObjectType &type);

 private:
  static std::shared_ptr<Object> makeSphere();
  static std::shared_ptr<Object> makePlane();
};

#endif /* !RTECHNOLOGY_OBJECTFACTORY_HPP */
