set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
if (Qt5Core_FOUND)
    include_directories(${Qt5Core_INCLUDE_DIRS})
    link_directories(${Qt5Core_LIBRARY_DIRS})

    find_package(Qt5Widgets REQUIRED)
    if (Qt5Widgets_FOUND)
        include_directories(${Qt5Widgets_INCLUDE_DIRS})
        link_directories(${Qt5Widgets_LIBRARY_DIRS})
    endif()
endif()

set(SOURCES_GUI
        Sources/main.cpp
		Sources/RTechnologyGUI.cpp
        )

include_directories(${INCLUDE_DIRECTORY_RAPIDJSON})
include_directories(./GeneratedFiles)

include_directories(${INCLUDE_DIRECTORY_RAYTRACER})
link_directories(${LIBRARY_DIRECTORY_RAYTRACER})

add_executable(RTechnology ${SOURCES_GUI})
target_link_libraries(RTechnology Qt5::Core Qt5::Widgets raytracer)
add_dependencies(RTechnology raytracer)

if(WIN32)
	set_target_properties(RTechnology PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
	set_target_properties(RTechnology PROPERTIES RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
	set_target_properties(RTechnology PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
	set_target_properties(RTechnology PROPERTIES MINSIZEREL "/SUBSYSTEM:WINDOWS")
endif(WIN32)