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
#include "Objects/Objects.hpp"
#include "ModelParcer/ModelParcer.hpp"

ObjectFactory::ObjectFactory()
{
  this->_map = {
	  {"sphere",         &ObjectFactory::makeSphere},
	  {"plane",          &ObjectFactory::makePlane},
	  {"cone",           &ObjectFactory::makeCone},
	  {"semi_cone_bot",  &ObjectFactory::makeSemiConeBot},
	  {"semi_cone_top",  &ObjectFactory::makeSemiConeTop},
	  {"parallelepiped", &ObjectFactory::makeParallelepiped},
	  {"cylinder",       &ObjectFactory::makeCylinder},
	  {"model",          &ObjectFactory::makeModel}
  };
}

ObjectFactory &ObjectFactory::getSingleton()
{
  static ObjectFactory factory;

  return factory;
}

std::shared_ptr<Object> ObjectFactory::createObject(rapidjson::Value::ConstObject params)
{
  auto &factory = ObjectFactory::getSingleton();

  assert(params.HasMember("type") && params["type"].IsString());

  auto it = factory._map.find(params["type"].GetString());
  if (it != factory._map.end())
    return it->second(params);

  return nullptr;
}

Vector3F ObjectFactory::getVector3Of(const std::string &name, rapidjson::Value::ConstObject params)
{
  assert(params[name.c_str()].IsObject());
  assert(params[name.c_str()].HasMember("x") && params[name.c_str()]["x"].IsNumber());
  assert(params[name.c_str()].HasMember("y") && params[name.c_str()]["y"].IsNumber());
  assert(params[name.c_str()].HasMember("z") && params[name.c_str()]["z"].IsNumber());

  return Vector3F(params[name.c_str()]["x"].GetFloat(),
		  params[name.c_str()]["y"].GetFloat(),
		  params[name.c_str()]["z"].GetFloat());
}

Vector3F ObjectFactory::getPosition(rapidjson::Value::ConstObject params)
{
  Vector3F vec(0, 0, 0);

  if (params.HasMember("position"))
    vec = getVector3Of("position", params);
  return vec;
}

Vector3F ObjectFactory::getRotation(rapidjson::Value::ConstObject params)
{
  Vector3F vec(0, 0, 0);

  if (params.HasMember("rotation"))
    vec = getVector3Of("rotation", params);
  return vec;
}

Vector3F ObjectFactory::getScale(rapidjson::Value::ConstObject params)
{
  Vector3F vec(1, 1, 1);

  if (params.HasMember("scale"))
    vec = getVector3Of("scale", params);
  return vec;
}

std::shared_ptr<Object> ObjectFactory::makeSphere(rapidjson::Value::ConstObject params)
{
  auto pos = getPosition(params);
  auto rot = getRotation(params);
  auto scal = getScale(params);
  auto sphere = std::make_shared<Sphere>(pos, rot, scal);

  if (params.HasMember("radius"))
    {
      assert(params["radius"].IsNumber());
      sphere->setRadius(params["radius"].GetFloat());
    }

  return sphere;
}

std::shared_ptr<Object> ObjectFactory::makePlane(rapidjson::Value::ConstObject params)
{
  auto pos = getPosition(params);
  auto rot = getRotation(params);

  return std::make_shared<Plan>(pos, rot);
}

std::shared_ptr<Object> ObjectFactory::makeCone(rapidjson::Value::ConstObject params)
{
  auto pos = getPosition(params);
  auto rot = getRotation(params);
  auto scal = getScale(params);

  auto cone = std::make_shared<Cone>(pos, rot, scal);

  if (params.HasMember("angle"))
    {
      assert(params["angle"].IsNumber());
      cone->setAngle(params["angle"].GetFloat());
    }

  return cone;
}

std::shared_ptr<Object> ObjectFactory::makeCylinder(rapidjson::Value::ConstObject params)
{
  auto pos = getPosition(params);
  auto rot = getRotation(params);
  auto scal = getScale(params);

  auto cylinder = std::make_shared<Cylinder>(pos, rot, scal);

  if (params.HasMember("radius"))
    {
      assert(params["radius"].IsNumber());
      cylinder->setRadius(params["radius"].GetFloat());
    }
  return cylinder;
}

std::shared_ptr<Object> ObjectFactory::makeSemiConeTop(rapidjson::Value::ConstObject params)
{
  auto pos = getPosition(params);
  auto rot = getRotation(params);
  auto scal = getScale(params);

  auto cone = std::make_shared<SemiConeTop>(pos, rot, scal);

  if (params.HasMember("angle"))
    {
      assert(params["angle"].IsNumber());
      cone->setAngle(params["angle"].GetFloat());
    }
  return cone;
}

std::shared_ptr<Object> ObjectFactory::makeSemiConeBot(rapidjson::Value::ConstObject params)
{
  auto pos = getPosition(params);
  auto rot = getRotation(params);
  auto scal = getScale(params);

  auto cone = std::make_shared<SemiConeBot>(pos, rot, scal);

  if (params.HasMember("angle"))
    {
      assert(params["angle"].IsNumber());
      cone->setAngle(params["angle"].GetFloat());
    }
  return cone;
}

std::shared_ptr<Object> ObjectFactory::makeParallelepiped(rapidjson::Value::ConstObject params)
{
  auto pos = getPosition(params);
  auto rot = getRotation(params);
  auto scal = getScale(params);

  return nullptr;
}

std::shared_ptr<Object> ObjectFactory::makeModel(rapidjson::Value::ConstObject params)
{
  auto pos = getPosition(params);
  auto rot = getRotation(params);
  auto scal = getScale(params);

  auto model = std::make_shared<Model>(pos, rot, scal);

  assert(params.HasMember("3DModel") && params["3DModel"].IsString());

  if (!ModelParcer::getSingleton().compute(params["3DModel"].GetString(), model))
    return nullptr;

  return model;
}