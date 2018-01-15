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
#include "objects/Objects.hpp"

ObjectFactory::ObjectFactory()
{
  this->_map = {
	  {"sphere",         &ObjectFactory::makeSphere},
	  {"plane",          &ObjectFactory::makePlane},
	  {"cone",           &ObjectFactory::makeCone},
	  {"semi_cone_bot",  &ObjectFactory::makeSemiConeBot},
	  {"semi_cone_top",  &ObjectFactory::makeSemiConeTop},
	  {"parallelepiped", &ObjectFactory::makeParallelepiped},
	  {"cylinder",       &ObjectFactory::makeCylinder}
  };
}

ObjectFactory &ObjectFactory::getSingleton()
{
  static ObjectFactory factory;

  return factory;
}

std::shared_ptr<Object> ObjectFactory::createObject(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params)
{
  auto &factory = ObjectFactory::getSingleton();

  assert(params.HasMember("type") && params["type"].IsString());

  auto it = factory._map.find(params["type"].GetString());
  if (it != factory._map.end())
    return it->second(params);

  return nullptr;
}

Vector3Float
ObjectFactory::getVector3Of(const std::string &name, rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params)
{
  assert(params[name.c_str()].IsObject());
  assert(params[name.c_str()].HasMember("x") && params[name.c_str()]["x"].IsNumber());
  assert(params[name.c_str()].HasMember("y") && params[name.c_str()]["y"].IsNumber());
  assert(params[name.c_str()].HasMember("z") && params[name.c_str()]["z"].IsNumber());

  return Vector3Float(params[name.c_str()]["x"].GetFloat(),
		      params[name.c_str()]["y"].GetFloat(),
		      params[name.c_str()]["z"].GetFloat());
}

std::array<Vector3Float, 3> ObjectFactory::getPosRotScal(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params)
{
  std::array<Vector3Float, 3> vec = {
	  Vector3Float(0, 0, 0),
	  Vector3Float(0, 0, 0),
	  Vector3Float(1, 1, 1)
  };

  if (params.HasMember("position"))
    vec[0] = getVector3Of("position", params);
  if (params.HasMember("rotation"))
    vec[1] = getVector3Of("rotation", params);
  if (params.HasMember("scale"))
    vec[2] = getVector3Of("scale", params);

  return vec;
}

std::shared_ptr<Object> ObjectFactory::makeSphere(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params)
{
  auto vec = getPosRotScal(params);

  return std::make_shared<Sphere>(vec[0], vec[1], vec[2]);
}

std::shared_ptr<Object> ObjectFactory::makePlane(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params)
{
  auto vec = getPosRotScal(params);

  return nullptr;
}

std::shared_ptr<Object> ObjectFactory::makeCone(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params)
{
  auto vec = getPosRotScal(params);

  auto cone = std::make_shared<Cone>(vec[0], vec[1], vec[2]);

  if (params.HasMember("angle"))
    {
      assert(params["angle"].IsFloat());
      cone->setAngle(params["angle"].GetFloat());
    }

  return cone;
}

std::shared_ptr<Object> ObjectFactory::makeCylinder(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params)
{
  auto vec = getPosRotScal(params);

  return std::make_shared<Cylinder>(vec[0], vec[1], vec[2]);
}

std::shared_ptr<Object> ObjectFactory::makeSemiConeTop(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params)
{
  auto vec = getPosRotScal(params);

  auto cone = std::make_shared<SemiConeTop>(vec[0], vec[1], vec[2]);

  if (params.HasMember("angle"))
    {
      assert(params["angle"].IsFloat());
      cone->setAngle(params["angle"].GetFloat());
    }
  return cone;
}

std::shared_ptr<Object> ObjectFactory::makeSemiConeBot(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params)
{
  auto vec = getPosRotScal(params);

  auto cone = std::make_shared<SemiConeBot>(vec[0], vec[1], vec[2]);

  if (params.HasMember("angle"))
    {
      assert(params["angle"].IsFloat());
      cone->setAngle(params["angle"].GetFloat());
    }
  return cone;
}

std::shared_ptr<Object> ObjectFactory::makeParallelepiped(
	rapidjson::GenericValue<rapidjson::UTF8<>>::ConstObject params)
{
  auto vec = getPosRotScal(params);

  return nullptr;
}