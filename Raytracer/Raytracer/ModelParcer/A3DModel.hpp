/*
** A3DModel.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. févr. 14:13 2018 benoit_g
** Last update mer. févr. 14:13 2018 benoit_g
*/

#ifndef RTECHNOLOGY_RT_A3DMODEL_HPP
#define RTECHNOLOGY_RT_A3DMODEL_HPP

#include <string>
#include "../Objects/Model.hpp"

RT_NAMESPACE_BEGIN

  class A3DModel
  {
   protected:
    const std::string filepath;

   public:
    explicit A3DModel(const std::string &filepath) : filepath(filepath)
    {}

    A3DModel(const A3DModel &) = delete;
    A3DModel(A3DModel &&) noexcept = delete;
    A3DModel &operator=(const A3DModel &) = delete;
    A3DModel &operator=(A3DModel &&) noexcept = delete;
    virtual ~A3DModel() = default;

    virtual bool load() = 0;
    virtual void reload() = 0;
    virtual void compute(std::shared_ptr<Model> model) = 0;

    inline const std::string &getFilename() const
    { return this->filepath; }
  };

RT_NAMESPACE_END

#endif /* !RTECHNOLOGY_RT_A3DMODEL_HPP */
