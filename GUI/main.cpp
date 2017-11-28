#include <iostream>
#include <rapidjson/reader.h>
#include <Raytracer/Raytracer.h>

int main(int ac, char **av)
{
  std::cout << "Hello, World!  " << std::endl;
  entry_point(ac > 1 ? atoi(av[1]) : 0);
  return 0;
}