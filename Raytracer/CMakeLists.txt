
find_package(ArrayFire REQUIRED)
if (ArrayFire_FOUND)
    include_directories(${ArrayFire_INCLUDE_DIRS})
    set(EXTRA_LIBS ${ArrayFire_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
endif()

find_package(OpenGL REQUIRED)

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
        Raytracer/objects/Cone.cpp
        Raytracer/objects/Plan.cpp
        Raytracer/objects/Cylinder.cpp
        Raytracer/objects/Parallelepiped.cpp
        Raytracer/objects/SemiConeBot.cpp
        Raytracer/objects/SemiConeTop.cpp
        Raytracer/objects/Sphere.cpp)

include_directories(${INCLUDE_DIRECTORY_RAPIDJSON})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(raytracer SHARED ${SOURCES_RAYTRACER})
target_link_libraries(raytracer ${EXTRA_LIBS} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(raytracer ${OPENGL_LIBRARIES})


add_subdirectory(Standalone)