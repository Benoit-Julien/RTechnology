/*
** AttributeFactory.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 18:06 2017 benoit_g
** Last update mar. déc. 18:06 2017 benoit_g
*/

#ifndef RTECHNOLOGY_ATTRIBUTEFACTORY_HPP
#define RTECHNOLOGY_ATTRIBUTEFACTORY_HPP

#include <unordered_map>
#include <memory>
#include <functional>

#include "config.h"
#include "IAttribute.hpp"
#include "EnumClassHash.hh"

class AttributeFactory
{
 public:
  enum class AttributeType : unsigned int
  {
    COLOR
  };

 private:
  std::unordered_map<AttributeFactory::AttributeType, std::function<std::shared_ptr<IAttribute>(void)>, EnumClassHash<unsigned int>> _map;

  AttributeFactory();
  static AttributeFactory &getSingleton();

 public:
  AttributeFactory(const AttributeFactory &factory) = delete;
  AttributeFactory(AttributeFactory &&factory) = delete;
  AttributeFactory &operator=(const AttributeFactory &factory) = delete;
  AttributeFactory &operator=(AttributeFactory &&factory) = delete;
  ~AttributeFactory() = default;

  static std::shared_ptr<IAttribute> createAttribute(const AttributeFactory::AttributeType &type);

 private:
  static std::shared_ptr<IAttribute> makeColor();
};


#endif /* !RTECHNOLOGY_ATTRIBUTEFACTORY_HPP */
