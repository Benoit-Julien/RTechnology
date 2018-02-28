
find_package(ArrayFire REQUIRED)
if (ArrayFire_FOUND)
    include_directories(${ArrayFire_INCLUDE_DIRS})
endif()

find_package(OpenGL REQUIRED)
find_package(FreeImage REQUIRED)

set(SOURCES_RAYTRACER
        Raytracer/Color.cpp
        Raytracer/Light.cpp
        Raytracer/Object.cpp
        Raytracer/ObjectFactory.cpp
        Raytracer/AttributeFactory.cpp
        Raytracer/APictureDraw.cpp
        Raytracer/Raytracer.cpp
        Raytracer/SceneSettings.cpp
        Raytracer/SceneManager.cpp
        Raytracer/math/Vector2.cpp
        Raytracer/math/Vector3.cpp
        Raytracer/math/Ray.cpp
        Raytracer/Objects/Cone.cpp
        Raytracer/Objects/Plan.cpp
        Raytracer/Objects/Cylinder.cpp
        Raytracer/Objects/Parallelepiped.cpp
        Raytracer/Objects/SemiConeBot.cpp
        Raytracer/Objects/SemiConeTop.cpp
        Raytracer/Objects/Sphere.cpp
        Raytracer/Objects/Model.cpp
        Raytracer/ModelParcer/ModelParcer.cpp
        Raytracer/ModelParcer/ObjModel.cpp)

include_directories(${INCLUDE_DIRECTORY_RAPIDJSON})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${FreeImage_INCLUDE_DIRS})

link_directories(${FreeImage_LIBRARY_DIRS})

add_library(raytracer SHARED ${SOURCES_RAYTRACER})
target_link_libraries(raytracer ${ArrayFire_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(raytracer ${OPENGL_LIBRARIES})
target_link_libraries(raytracer ${FreeImage_LIBRARIES})

add_subdirectory(Standalone)