/*
** SceneSettings.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. janv. 12:44 2018 benoit_g
** Last update mar. janv. 12:44 2018 benoit_g
*/

#include <Raytracer/math/Vector3.hpp>
#include "SceneSettings.hpp"

SceneSettings::Settings::Settings()
	: defaultLight(10),
	  viewPlaneDistance(1),
	  viewPlaneWidth(0.5),
	  viewPlaneHeight(0.35)
{}

SceneSettings::Settings::Settings(const Settings &settings)
{}

SceneSettings::Settings::Settings(Settings &&settings) noexcept
{}

SceneSettings::Settings &SceneSettings::Settings::operator=(const Settings &settings)
{}

SceneSettings::Settings &SceneSettings::Settings::operator=(Settings &&settings) noexcept
{}

SceneSettings::Settings::~Settings()
{}


SceneSettings::SceneSettings()
{
  this->_map = {
	  {"defaultLight", &SceneSettings::setDefaultLight},
	  {"camera", &SceneSettings::setCamera},
	  {"viewPlaneDistance", &SceneSettings::setViewPlaneDistance},
	  {"viewPlaneWidth", &SceneSettings::setViewPlaneWidth},
	  {"viewPlaneHeight", &SceneSettings::setViewPlaneHeight}
  };
}

SceneSettings::~SceneSettings()
{}

const SceneSettings::Settings &SceneSettings::getSettings() const
{
  return this->_settings;
}

void SceneSettings::setSetting(const std::string &name, const rapidjson::Value &value)
{
  auto it = this->_map.find(name);

 if (it != this->_map.end())
   (this->*it->second)(value);
}

void SceneSettings::setDefaultLight(const rapidjson::Value &value)
{
  assert(value.IsInt());
  this->_settings.defaultLight = value.GetInt();
}

void SceneSettings::setCamera(const rapidjson::Value &value)
{
  assert(value.IsObject());
  if (value.HasMember("position"))
    {
      assert(value["position"].IsObject());
      assert(value["position"].HasMember("x") && value["position"]["x"].IsNumber());
      assert(value["position"].HasMember("y") && value["position"]["y"].IsNumber());
      assert(value["position"].HasMember("z") && value["position"]["z"].IsNumber());
      this->_settings.cameraPosition = Vector3F(value["position"]["x"].GetFloat(),
						    value["position"]["y"].GetFloat(),
						    value["position"]["z"].GetFloat());
      std::cout << "set position" << std::endl;
    }
  else if (value.HasMember("rotation"))
    {
      assert(value["rotation"].IsObject());
      assert(value["rotation"].HasMember("x") && value["rotation"]["x"].IsNumber());
      assert(value["rotation"].HasMember("y") && value["rotation"]["y"].IsNumber());
      assert(value["rotation"].HasMember("z") && value["rotation"]["z"].IsNumber());
      this->_settings.cameraRotation = Vector3F(value["rotation"]["x"].GetFloat(),
						    value["rotation"]["y"].GetFloat(),
						    value["rotation"]["z"].GetFloat());
    }
}

void SceneSettings::setViewPlaneDistance(const rapidjson::Value &value)
{
  assert(value.IsNumber());
  this->_settings.viewPlaneDistance = value.GetFloat();
}

void SceneSettings::setViewPlaneWidth(const rapidjson::Value &value)
{
  assert(value.IsNumber());
  this->_settings.viewPlaneWidth = value.GetFloat();
}

void SceneSettings::setViewPlaneHeight(const rapidjson::Value &value)
{
  assert(value.IsNumber());
  this->_settings.viewPlaneHeight = value.GetFloat();
}
