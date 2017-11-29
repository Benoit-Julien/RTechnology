#include <iostream>
#include <rapidjson/reader.h>
#include <Raytracer/Raytracer.h>

#if _WIN64 && !_DEBUG
# include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main()
#endif
{
  std::cout << "Hello, World!  " << std::endl;
  entry_point();
  return 0;
}