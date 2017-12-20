/*
** main.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. nov. 21:05 2017 benoit_g
** Last update mar. nov. 21:05 2017 benoit_g
*/

#include "SFMLPictureDraw.hpp"
#include <Raytracer/Raytracer.hpp>


#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>

#if WINDOWS && !_DEBUG
# include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main()
#endif
{
  auto draw = std::make_shared<SFMLPictureDraw>(1280, 720);
  Raytracer raytracer(draw);

  std::string filename = "scene.json";
  std::ifstream file(filename);
  std::string json;

  if (!file)
    return -1;

  std::string tmp;
  while (std::getline(file, tmp))
    json.append(tmp);

  file.close();

  raytracer.initialiseScene(json);
  raytracer.renderer();

  draw->updateWindow();
  while (draw->windowIsOpen());

  return 0;
}