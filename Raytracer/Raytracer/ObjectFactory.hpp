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
  typedef std::function<std::shared_ptr<Object>(rapidjson::Value::ConstObject)> MakeFuncType;

  std::unordered_map<std::string, MakeFuncType> _map;

  ObjectFactory();
  static ObjectFactory &getSingleton();

 public:
  ObjectFactory(const ObjectFactory &factory) = delete;
  ObjectFactory(ObjectFactory &&factory) = delete;
  ObjectFactory &operator=(const ObjectFactory &factory) = delete;
  ObjectFactory &operator=(ObjectFactory &&factory) = delete;
  ~ObjectFactory() = default;

  static std::shared_ptr<Object> createObject(rapidjson::Value::ConstObject params);

 private:
  static Vector3F getVector3Of(const std::string &name, rapidjson::Value::ConstObject params);
  static Vector3F getPosition(rapidjson::Value::ConstObject params);
  static Vector3F getRotation(rapidjson::Value::ConstObject params);
  static Vector3F getScale(rapidjson::Value::ConstObject params);

 private:
  static std::shared_ptr<Object> makeSphere(rapidjson::Value::ConstObject params);
  static std::shared_ptr<Object> makePlane(rapidjson::Value::ConstObject params);
  static std::shared_ptr<Object> makeCone(rapidjson::Value::ConstObject params);
  static std::shared_ptr<Object> makeCylinder(rapidjson::Value::ConstObject params);
  static std::shared_ptr<Object> makeSemiConeBot(rapidjson::Value::ConstObject params);
  static std::shared_ptr<Object> makeSemiConeTop(rapidjson::Value::ConstObject params);
  static std::shared_ptr<Object> makeParallelepiped(rapidjson::Value::ConstObject params);
  static std::shared_ptr<Object> makeModel(rapidjson::Value::ConstObject params);
};

#endif /* !RTECHNOLOGY_OBJECTFACTORY_HPP */
