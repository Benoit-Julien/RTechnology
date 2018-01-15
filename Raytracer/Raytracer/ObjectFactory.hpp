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
#include <rapidjson/document.h>

#include "config.h"
#include "Object.hpp"
#include "EnumClassHash.hh"

class ObjectFactory
{
 private:
  typedef std::function<std::shared_ptr<Object>(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject)> MakeFuncType;

  std::unordered_map<std::string, MakeFuncType> _map;

  ObjectFactory();
  static ObjectFactory &getSingleton();

 public:
  ObjectFactory(const ObjectFactory &factory) = delete;
  ObjectFactory(ObjectFactory &&factory) = delete;
  ObjectFactory &operator=(const ObjectFactory &factory) = delete;
  ObjectFactory &operator=(ObjectFactory &&factory) = delete;
  ~ObjectFactory() = default;

  static std::shared_ptr<Object> createObject(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params);

 private:
  static Vector3Float getVector3Of(const std::string &name, rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params);
  static std::array<Vector3Float, 3> getPosRotScal(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params);

 private:
  static std::shared_ptr<Object> makeSphere(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params);
  static std::shared_ptr<Object> makePlane(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params);
  static std::shared_ptr<Object> makeCone(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params);
  static std::shared_ptr<Object> makeCylinder(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params);
  static std::shared_ptr<Object> makeSemiConeBot(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params);
  static std::shared_ptr<Object> makeSemiConeTop(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params);
  static std::shared_ptr<Object> makeParallelepiped(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params);

};

#endif /* !RTECHNOLOGY_OBJECTFACTORY_HPP */
