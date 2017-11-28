
find_package(SFML REQUIRED COMPONENTS system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
endif()

set(SOURCES_STANDALONE
        src/main.cpp
        )

include_directories(${INCLUDE_DIRECTORY_RAYTRACER})
link_directories(${LIBRARY_DIRECTORY_RAYTRACER})

add_executable(raytracer_standalone ${SOURCES_STANDALONE})
target_link_libraries(raytracer_standalone raytracer ${SFML_LIBRARIES})
add_dependencies(raytracer_standalone raytracer)
