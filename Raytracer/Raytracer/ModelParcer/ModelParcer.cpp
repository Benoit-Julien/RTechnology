/*
** ModelParcer.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. févr. 14:00 2018 benoit_g
** Last update mer. févr. 14:00 2018 benoit_g
*/

#include "ObjModel.hpp"

#include "ModelParcer.hpp"

RT_NAMESPACE_BEGIN

  std::unordered_map<std::string, bool (ModelParcer::*)(const std::string &)> ModelParcer::_loaders = {
	  {".obj", &ModelParcer::loadObj}
  };

  ModelParcer &ModelParcer::getSingleton()
  {
    static ModelParcer modelParcer;
    return modelParcer;
  }

  ModelParcer::ModelParcer()
  {}

  ModelParcer::~ModelParcer()
  {}

  bool ModelParcer::loadModel(const std::string &filename)
  {
    if (this->_models.find(filename) != this->_models.end())
      return true;

    auto ppos = filename.rfind(".");
    if (ppos == std::string::npos)
      return false;
    auto extension = filename.substr(ppos);

    std::cout << "Model extension : " << extension << std::endl;

    auto loader = this->_loaders.find(extension);
    if (loader != this->_loaders.end())
      return (this->*loader->second)(filename);
    return false;
  }

  bool ModelParcer::removeModel(const std::string &filename)
  {
    auto model = this->_models.find(filename);
    if (model == this->_models.end())
      return false;
    this->_models.erase(model);
    return true;
  }

  void ModelParcer::reloadModels()
  {
    for (auto &m : this->_models)
      m.second->reload();
  }

  bool ModelParcer::compute(const std::string &filename, std::shared_ptr<Model> model)
  {
    if (!this->loadModel(filename))
      return false;

    this->_models[filename]->compute(model);
    return true;
  }

  bool ModelParcer::loadObj(const std::string &filename)
  {
    auto obj = std::make_shared<ObjModel>(this->_scenePath + "/" + filename);
    if (obj->load())
      return false;
    this->_models[filename] = obj;
    return true;
  }

RT_NAMESPACE_END