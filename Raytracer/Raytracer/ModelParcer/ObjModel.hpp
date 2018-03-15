/*
** ObjModel.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. févr. 16:03 2018 benoit_g
** Last update mer. févr. 16:03 2018 benoit_g
*/

#ifndef RTECHNOLOGY_RT_OBJMODEL_HPP
#define RTECHNOLOGY_RT_OBJMODEL_HPP

#include "A3DModel.hpp"
#include "../math/Vector3.hpp"
#include "../math/Vector2.hpp"

RT_NAMESPACE_BEGIN

  class ObjModel : public A3DModel
  {
   public:
    struct PointIndex
    {
      explicit PointIndex(const long &vertice = -1, const long &vertexNormal = -1, const long &textCoord = -1)
	      : vertice(vertice), vertexNormal(vertexNormal), textCoord(textCoord)
      {}

      friend std::ostream &operator<<(std::ostream &os, const PointIndex &index);

      const long vertice;
      const long vertexNormal;
      const long textCoord;
    };

    struct Face
    {
     private:
      std::vector<PointIndex> points;

     public:
      explicit Face() = default;

      void addPoint(const PointIndex &point)
      { this->points.push_back(point); }

      const std::vector<PointIndex> &getPoints() const
      { return this->points; }

      friend std::ostream &operator<<(std::ostream &os, const Face &face);
    };

   private:
    static std::unordered_map<std::string, bool (ObjModel::*)(const std::string &)> _map;

    std::vector<Vector3F> _vertices;
    std::vector<Vector3F> _vertexNormals;
    std::vector<Vector2F> _textCoords;
    std::vector<Face> _faces;

    const std::string _filepath;

   public:
    explicit ObjModel(const std::string &filepath);
    virtual ~ObjModel();

    virtual bool load();
    virtual void reload();
    virtual void compute(std::shared_ptr<Model> model);

   private:
    bool parceVertice(const std::string &line);
    bool parceVertexNormal(const std::string &line);
    bool parceTextCoord(const std::string &line);
    bool parceFace(const std::string &line);

    static std::vector<std::string> split(const std::string &line, const char &delim, const bool &ignoreEmpty);
    static bool getIndex(long &value, const std::string &str, const std::size_t &max);
  };

RT_NAMESPACE_END

#endif /* !RTECHNOLOGY_RT_OBJMODEL_HPP */
