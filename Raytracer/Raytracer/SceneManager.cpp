/*
** SceneManager.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. janv. 11:12 2018 benoit_g
** Last update mer. janv. 11:12 2018 benoit_g
*/

#include "SceneManager.hpp"
#include "ObjectFactory.hpp"
#include "AttributeFactory.hpp"
#undef GetObject

SceneManager::SceneManager()
{}

SceneManager::~SceneManager()
{}

const SceneSettings &SceneManager::getSceneSettings() const
{
  return this->_settings;
}

const std::vector<std::shared_ptr<Object>> &SceneManager::getObjects() const
{
  return this->_objects;
}

Color SceneManager::checkHitAndGetColor(const Ray &ray) const
{
  Object::HitInfo objectHit;

  for (auto &it : this->_objects)
    {
      auto tmp = it->Hit(ray, this->_settings);
      if (tmp.haveHit)
	{
	  if (!objectHit.haveHit || (tmp.distance > 0 && tmp.distance < objectHit.distance))
	    objectHit = tmp;
	}
    }
  if (!objectHit.hitObject)
    return Color(255, 0, 0);
  return objectHit.hitObject->getColorHit(objectHit);
}

void SceneManager::parseSceneJson(const rapidjson::Document &document)
{
  assert(document.IsObject());
  assert(document.HasMember("objects"));
  assert(document["objects"].IsArray());

  for (auto &m : document.GetObject())
    {
      std::cout << m.name.GetString() << std::endl;
      if (std::string(m.name.GetString()) == "objects")
	this->parseObjects(m.value.GetArray());
      else
	this->_settings.setSetting(m.name.GetString(), m.value);
    }
}

void SceneManager::parseObjects(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstArray objects)
{
  for (auto &o : objects)
    {
      assert(o.IsObject());
      auto object = ObjectFactory::createObject(o.GetObject());
      if (object == nullptr)
	{
	  std::cout << "Object " << o["type"].GetString() << " not implemented" << std::endl;
	  continue;
	}
      /*
      if (o.HasMember("attr"))
	{
	  assert(o["attr"].IsArray());
	  this->parseAttributeObject(object, o["attr"].GetArray());
	}*/
      this->_objects.push_back(object);
    }
}

void SceneManager::parseAttributeObject(std::shared_ptr<Object> obj, rapidjson::GenericValue<rapidjson::UTF8<>>::ConstArray attributes)
{
  for (auto &a : attributes)
    {
      assert(a.IsObject());
      auto attr = AttributeFactory::createAttribute(a.GetObject());

      obj->registerAttribute(attr);
    }
}