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
#include "attributes/Attributes.hpp"

RT_NAMESPACE_BEGIN

  AttributeFactory::AttributeFactory()
  {
    this->_map = {
	    {"color", &AttributeFactory::makeColor}
    };
  }

  AttributeFactory &AttributeFactory::getSingleton()
  {
    static AttributeFactory factory;

    return factory;
  }

  std::shared_ptr<IAttribute> AttributeFactory::createAttribute(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject attr)
  {
    auto &factory = AttributeFactory::getSingleton();

    assert(attr.HasMember("type") && attr["type"].IsString());

    auto it = factory._map.find(attr["type"].GetString());
    if (it != factory._map.end())
      return it->second(attr);

    return nullptr;
  }

  std::shared_ptr<IAttribute> AttributeFactory::makeColor(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject attr)
  {
    return nullptr;
  }

RT_NAMESPACE_END