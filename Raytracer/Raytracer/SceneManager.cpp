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

RT_NAMESPACE_BEGIN

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

  const std::vector<std::shared_ptr<Light>> &SceneManager::getLights() const
  {
    return this->_lights;
  }

  Object::HitInfo SceneManager::checkHit(const Ray &ray) const
  {
    Object::HitInfo objectHit;

    for (auto &it : this->_objects)
      {
	auto tmp = it->Hit(ray, *this);

	if (tmp.haveHit)
	  {
	    if (!objectHit.haveHit || (tmp.distance < objectHit.distance))
	      objectHit = tmp;
	  }
      }
    return objectHit;
  }

  Color SceneManager::checkHitAndGetColor(const Ray &ray) const
  {
    auto objectHit = this->checkHit(ray);

    if (!objectHit.hitObject)
      return Color();
    return objectHit.hitObject->getColorHit(objectHit, *this);
  }

  void SceneManager::parseSceneJson(const rapidjson::Document &document)
  {
    assert(document.IsObject());
    assert(document.HasMember("objects") && document["objects"].IsArray());
    assert(document.HasMember("lights") && document["lights"].IsArray());

    for (auto &m : document.GetObject())
      {
	std::cout << m.name.GetString() << std::endl;
	if (std::string(m.name.GetString()) == "objects")
	  this->parseObjects(m.value.GetArray());
	else if (std::string(m.name.GetString()) == "lights")
	  this->parseLights(m.value.GetArray());
	else
	  this->_settings.setSetting(m.name.GetString(), m.value);
      }
  }

  void SceneManager::parseLights(rapidjson::Value::ConstArray lights)
  {
    for (auto &l : lights)
      {
	assert(l.IsObject());
	auto object = l.GetObject();

	Vector3F pos;
	Vector3F rot;
	if (object.HasMember("position"))
	  pos = getVector3Of("position", object);
	if (object.HasMember("rotation"))
	  rot = getVector3Of("rotation", object);
	auto light = std::make_shared<Light>(pos, rot);

	if (object.HasMember("color"))
	  light->setColor(getColorOf("color", object));
	if (object.HasMember("type"))
	  light->setType(getLightType("type", object));
	light->setColor(Color(255, 255, 255));
	this->_lights.push_back(light);
      }
    std::cout << this->_lights.size() << std::endl;
  }

  void SceneManager::parseObjects(rapidjson::Value::ConstArray objects)
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

  void SceneManager::parseAttributeObject(std::shared_ptr<Object> obj, rapidjson::Value::ConstArray attributes)
  {
    for (auto &a : attributes)
      {
	assert(a.IsObject());
	auto attr = AttributeFactory::createAttribute(a.GetObject());

	obj->registerAttribute(attr);
      }
  }

  Vector3F SceneManager::getVector3Of(const std::string &name, rapidjson::Value::ConstObject params)
  {
    assert(params[name.c_str()].IsObject());
    assert(params[name.c_str()].HasMember("x") && params[name.c_str()]["x"].IsNumber());
    assert(params[name.c_str()].HasMember("y") && params[name.c_str()]["y"].IsNumber());
    assert(params[name.c_str()].HasMember("z") && params[name.c_str()]["z"].IsNumber());

    return Vector3F(params[name.c_str()]["x"].GetFloat(),
		    params[name.c_str()]["y"].GetFloat(),
		    params[name.c_str()]["z"].GetFloat());
  }

  Color SceneManager::getColorOf(const std::string &name, rapidjson::Value::ConstObject params)
  {
    assert(params[name.c_str()].IsObject());
    assert(params[name.c_str()].HasMember("r") && params[name.c_str()]["r"].IsInt());
    assert(params[name.c_str()].HasMember("g") && params[name.c_str()]["g"].IsInt());
    assert(params[name.c_str()].HasMember("b") && params[name.c_str()]["b"].IsInt());

    return Color(params[name.c_str()]["r"].GetUint(),
		 params[name.c_str()]["g"].GetUint(),
		 params[name.c_str()]["b"].GetUint());
  }

  Light::Type SceneManager::getLightType(const std::string &name, rapidjson::Value::ConstObject params)
  {
    static std::unordered_map<std::string, Light::Type> map = {
	    {"Point", Light::Type::POINT}
    };

    assert(params[name.c_str()].IsString());

    auto t = map.find(params[name.c_str()].GetString());
    if (t == map.end())
      return Light::Type::POINT;
    return t->second;
  }

RT_NAMESPACE_END