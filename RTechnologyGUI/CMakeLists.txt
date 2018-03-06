find_package(ArrayFire REQUIRED)
if (ArrayFire_FOUND)
    include_directories(${ArrayFire_INCLUDE_DIRS})
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
if (Qt5Core_FOUND)
    include_directories(${Qt5Core_INCLUDE_DIRS})
    link_directories(${Qt5Core_LIBRARY_DIRS})

    find_package(Qt5Widgets REQUIRED)
    if (Qt5Gui_FOUND)
        include_directories(${Qt5Gui_INCLUDE_DIRS})
        link_directories(${Qt5Gui_LIBRARY_DIRS})
    endif()

    find_package(Qt5OpenGL)
    if (Qt5OpenGL_FOUND)
        include_directories(${Qt5OpenGL_INCLUDE_DIRS})
        link_directories(${Qt5OpenGL_LIBRARY_DIRS})
    endif()
endif()

set(SOURCES_GUI
        RTechnology/main.cpp
        RTechnology/mainwindow.cpp
        RTechnology/Object/Object.cpp
        RTechnology/Object/Sphere.cpp
        RTechnology/Object/Cylinder.cpp
        RTechnology/AttributesUi/DefaultAttribute.cpp)

include_directories(./RTechnology)

include_directories(${INCLUDE_DIRECTORY_RAPIDJSON})
include_directories(./GeneratedFiles)
include_directories(${ArrayFire_LIBRARIES})

include_directories(${INCLUDE_DIRECTORY_RAYTRACER})
link_directories(${LIBRARY_DIRECTORY_RAYTRACER})

add_executable(RTechnology ${SOURCES_GUI})
target_link_libraries(RTechnology Qt5::Core Qt5::Gui Qt5::OpenGL raytracer)
add_dependencies(RTechnology raytracer)

if(WIN32)
	set_target_properties(RTechnology PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
	set_target_properties(RTechnology PROPERTIES RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
	set_target_properties(RTechnology PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
	set_target_properties(RTechnology PROPERTIES MINSIZEREL "/SUBSYSTEM:WINDOWS")
endif(WIN32)