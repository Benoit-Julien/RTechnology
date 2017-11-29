cmake_minimum_required(VERSION 3.8)
project(RTechnology)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIRECTORY_RAPIDJSON ${CMAKE_CURRENT_SOURCE_DIR}/RapidJSON)
set(INCLUDE_DIRECTORY_RAYTRACER ${CMAKE_CURRENT_SOURCE_DIR}/Raytracer/include)
set(LIBRARY_DIRECTORY_RAYTRACER ${CMAKE_CURRENT_BINARY_DIR}/Raytracer)

if (USE_GRAPHICS)
	message("ArrayFire use graphical card")
else()
	message("ArrayFire not use graphical card")
endif()

add_subdirectory(GUI)
add_subdirectory(Raytracer)