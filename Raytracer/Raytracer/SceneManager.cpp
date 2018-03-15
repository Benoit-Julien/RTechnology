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

const std::vector<std::shared_ptr<Light>>& SceneManager::getLights() const
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
 // Color color = raytracer(ray, 5);
  auto objectHit = this->checkHit(ray);

  if (!objectHit.hitObject)
    return Color();
  return objectHit.hitObject->getColorHit(objectHit, *this);

 // return  color;
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
      this->_lights.push_back(light);
    }
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

Color SceneManager::raytracer(const Ray &ray, int depth) const
{
  if (depth > 10)
    return Color();

  auto objectHit = this->checkHit(ray);
  if (!objectHit.hitObject)
    return Color();

  /*
   * Color ambient() = Color Object * Coeff;
   */

  /*
   * Color object() =
   *
   * Equivalent de getColorHit à faire de façon générale et à ne pas limiter aux object (le faire ici quoi)
   */

  /*
   * Color specular() = ce qui est présent dans getColorHit #
   *
   *  auto angleSpec = Vector3F::Angle(objectHit.reflect, my_ray.getDirection());
      if (angleSpec < af::Pi / 20)
	{
	  float coeffSpec = angleSpec / (af::Pi / 20);
	  specular.r = 255 - (255 - color.r) * coeffSpec;
	  specular.g = 255 - (255 - color.g) * coeffSpec;
	  specular.b = 255 - (255 - color.b) * coeffSpec;
	}
   */

  /*
   * Color reflect() = raytracer(ray, depth + 1);
   */

  /*
   * Color final() = final.r = maxi(ambient.r(), object.r(), specular.r(), reflect.r());
   */

  return Color();
}