
find_package(ArrayFire REQUIRED)
if (ArrayFire_FOUND)
    include_directories(${ArrayFire_INCLUDE_DIRS})
endif()

if (USE_GRAPHICS)
    set(EXTRA_LIBS ${ArrayFire_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
else()
    set(EXTRA_LIBS ${ArrayFire_CPU_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
endif()

set(SOURCES_RAYTRACER
        Raytracer/Color.cpp
        Raytracer/Object.cpp
        Raytracer/ObjectFactory.cpp
        Raytracer/AttributeFactory.cpp
        Raytracer/APictureDraw.cpp
        Raytracer/math/AVector.cpp
        Raytracer/math/Vector2.cpp
        Raytracer/math/Vector3.cpp
        Raytracer/math/Ray.cpp)

include_directories(${INCLUDE_DIRECTORY_RAPIDJSON})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(raytracer SHARED ${SOURCES_RAYTRACER})
target_link_libraries(raytracer ${EXTRA_LIBS})

add_subdirectory(Standalone)