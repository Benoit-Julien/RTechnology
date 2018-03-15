/*
** AttributeFactory.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 18:06 2017 benoit_g
** Last update mar. déc. 18:06 2017 benoit_g
*/

#ifndef RTECHNOLOGY_RT_ATTRIBUTEFACTORY_HPP
#define RTECHNOLOGY_RT_ATTRIBUTEFACTORY_HPP

#include <unordered_map>
#include <memory>
#include <functional>
#include <rapidjson/document.h>

#include "config.h"
#include "IAttribute.hpp"
#include "EnumClassHash.hh"

RT_NAMESPACE_BEGIN

  class AttributeFactory
  {
   private:
    std::unordered_map<std::string, std::function<std::shared_ptr<IAttribute>(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject)>> _map;

    AttributeFactory();
    static AttributeFactory &getSingleton();

   public:
    AttributeFactory(const AttributeFactory &factory) = delete;
    AttributeFactory(AttributeFactory &&factory) = delete;
    AttributeFactory &operator=(const AttributeFactory &factory) = delete;
    AttributeFactory &operator=(AttributeFactory &&factory) = delete;
    ~AttributeFactory() = default;

    static std::shared_ptr<IAttribute> createAttribute(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject attr);

   private:
    static std::shared_ptr<IAttribute> makeColor(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject attr);
  };

RT_NAMESPACE_END

#endif /* !RTECHNOLOGY_RT_ATTRIBUTEFACTORY_HPP */
