
find_package(SFML REQUIRED COMPONENTS system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
endif()

set(SOURCES_STANDALONE
        src/main.cpp
        src/SFMLPictureDraw.cpp
        )

include_directories(${INCLUDE_DIRECTORY_RAYTRACER})
link_directories(${LIBRARY_DIRECTORY_RAYTRACER})

add_executable(raytracer_standalone ${SOURCES_STANDALONE})
target_link_libraries(raytracer_standalone raytracer ${SFML_LIBRARIES})
add_dependencies(raytracer_standalone raytracer)

add_custom_command(
        TARGET raytracer_standalone POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/scene.json
        ${CMAKE_CURRENT_BINARY_DIR}/scene.json
)

if(WIN32)
	set_target_properties(raytracer_standalone PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
	set_target_properties(raytracer_standalone PROPERTIES RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
	set_target_properties(raytracer_standalone PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
	set_target_properties(raytracer_standalone PROPERTIES MINSIZEREL "/SUBSYSTEM:WINDOWS")
endif(WIN32)