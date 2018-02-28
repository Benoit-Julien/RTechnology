/*
** ObjModel.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. févr. 16:03 2018 benoit_g
** Last update mer. févr. 16:03 2018 benoit_g
*/

#include <fstream>
#include "ObjModel.hpp"

std::ostream &operator<<(std::ostream &os, const ObjModel::PointIndex &index)
{
  os << "Point Index:" << std::endl;
  os << "\t" << "vertice: " << index.vertice << std::endl;
  os << "\t" << "vertex normal: " << index.vertexNormal << std::endl;
  os << "\t" << "texture coord: " << index.textCoord << std::endl;
  return os;
}

std::ostream &operator<<(std::ostream &os, const ObjModel::Face &face)
{
  int index = 0;
  for (auto &p : face.points)
    os << index++ << ":" << p << std::endl;
  return os;
}

std::unordered_map<std::string, bool (ObjModel::*)(const std::string &)> ObjModel::_map = {
	{"v", &ObjModel::parceVertice},
	{"vn", &ObjModel::parceVertexNormal},
	{"vt", &ObjModel::parceTextCoord},
	{"f", &ObjModel::parceFace}
};

ObjModel::ObjModel(const std::string &filepath) : A3DModel(filepath)
{}

ObjModel::~ObjModel()
{}

bool ObjModel::load()
{
  std::ifstream file(this->filepath);

  if (!file)
    return false;

  std::string line;
  int l = 0;
  while (std::getline(file, line))
    {
      if (line[0] == '#' || line.empty())
	continue;

      std::string hint;
      std::stringstream(line) >> hint;

      auto func = this->_map.find(hint);
      if (func != this->_map.end())
	{
	  if (!(this->*func->second)(line))
	    return false;
	}
      else
	std::cerr << "Obj: instruction ("<< hint << ") not implemented." << std::endl;
    }
}

void ObjModel::reload()
{
  this->_vertices = std::vector<Vector3F>();
  this->_vertexNormals = std::vector<Vector3F>();
  this->_textCoords = std::vector<Vector2F>();
  this->_faces = std::vector<Face>();

  this->load();
}

void ObjModel::compute(std::shared_ptr<Model> model)
{}

bool ObjModel::parceVertice(const std::string &line)
{
  auto tab = this->split(line, ' ', true);
  if (tab.size() != 4)
    return false;

  float x, y, z;
  std::stringstream(tab[1]) >> x;
  std::stringstream(tab[2]) >> y;
  std::stringstream(tab[3]) >> z;

  this->_vertices.emplace_back(Vector3F(x, y, z));
  return true;
}

bool ObjModel::parceVertexNormal(const std::string &line)
{
  auto tab = this->split(line, ' ', true);
  if (tab.size() != 4)
    return false;

  float x, y, z;
  std::stringstream(tab[1]) >> x;
  std::stringstream(tab[2]) >> y;
  std::stringstream(tab[3]) >> z;

  this->_vertexNormals.emplace_back(Vector3F(x, y, z));
  return true;
}

bool ObjModel::parceTextCoord(const std::string &line)
{
  auto tab = this->split(line, ' ', true);
  if (tab.size() != 3)
    return false;

  float x, y;
  std::stringstream(tab[1]) >> x;
  std::stringstream(tab[2]) >> y;

  this->_textCoords.emplace_back(Vector2F(x, y));
  return true;
}

bool ObjModel::parceFace(const std::string &line)
{
  auto tab = this->split(line, ' ', true);
  tab.erase(tab.begin());
  Face face;

  for (auto &it : tab)
    {
      auto index = this->split(it, '/', false);
      if (index.empty() || index.size() > 3)
	return false;

      switch (index.size())
	{
	  case 1:
	    {
	      if (index[0].empty())
		return false;
	      long i;
	      if (!this->getIndex(i, index[0], this->_vertices.size()))
		return false;
	      face.addPoint(PointIndex(i));
	      break;
	    }
	  case 2:
	    {
	      if (index[0].empty() || index[1].empty())
		return false;
	      long vi;
	      long vni;
	      if (!this->getIndex(vi, index[0], this->_vertices.size())
		  || !this->getIndex(vni, index[1], this->_vertexNormals.size()))
		return false;
	      face.addPoint(PointIndex(vi, vni));
	      break;
	    }
	  case 3:
	    {
	      if (index[0].empty() || index[2].empty())
		return false;
	      else if (index[1].empty())
		{
		  long vi;
		  long vti;
		  if (!this->getIndex(vi, index[0], this->_vertices.size())
		      || !this->getIndex(vti, index[2], this->_textCoords.size()))
		    return false;
		  face.addPoint(PointIndex(vi, -1, vti));
		}
	      else
		{
		  long vi;
		  long vni;
		  long vti;
		  if (!this->getIndex(vi, index[0], this->_vertices.size())
		      || !this->getIndex(vni, index[1], this->_vertexNormals.size())
		      || !this->getIndex(vti, index[2], this->_textCoords.size()))
		    return false;
		  face.addPoint(PointIndex(vi, vni, vti));
		}
	      break;
	    }
	  default:
	    break;
	}
    }
  this->_faces.emplace_back(face);
  return true;
}

std::vector<std::string> ObjModel::split(const std::string &line, const char &delim, const bool &ignoreEmpty)
{
  std::vector<std::string> tab;
  std::stringstream st(line);
  std::string word;

  while (std::getline(st, word, delim))
    {
      if (!ignoreEmpty)
	tab.push_back(word);
      else if (!word.empty())
	tab.push_back(word);
    }

  return tab;
}

bool ObjModel::getIndex(long &value, const std::string &str, const std::size_t &max)
{
  long i;

  std::stringstream(str) >> i;
  if (i > max)
    return false;
  value = i;
  return true;
}