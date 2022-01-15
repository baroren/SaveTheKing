cmake_minimum_required (VERSION 3.20)

project (ex02)

# New CMake versions map C++20 to /std:c++20 instead of c++latest, so <format>
# and other unstable ABI features aren't supported. Use C++23 for such versions
if (MSVC AND CMAKE_VERSION VERSION_GREATER_EQUAL 3.21)
    set(CMAKE_CXX_STANDARD 23)
else ()
    set(CMAKE_CXX_STANDARD 20)
endif ()

set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()

add_executable (${CMAKE_PROJECT_NAME} "src/main.cpp" "src/GameObject.cpp" "include/GameObject.h" "src/Moving.cpp" "include/Moving.h" "include/Dwarf.h" "src/Dwarf.cpp" "src/Player.cpp" "include/Player.h" "src/King.cpp" "include/Mage.h" "src/Thief.cpp" "src/Warrior.cpp" "include/King.h" "src/Mage.cpp" "include/Thief.h" "include/Warrior.h" "src/Static.cpp" "include/Static.h" "src/Key.cpp" "include/Key.h" "src/Throne.cpp" "include/Throne.h" "src/Wall.cpp" "include/Wall.h" "src/Fire.cpp" "include/Fire.h" "src/Orc.cpp" "include/Orc.h" "src/Gate.cpp" "include/Gate.h" "src/Gift.cpp" "include/Gift.h" "src/AddTime.cpp" "include/AddTime.h" "src/SubTime.cpp" "include/SubTime.h" "src/DestDwarf.cpp" "include/DestDwarf.h" "src/Window.cpp" "include/Window.h" "src/Board.cpp" "include/Board.h" "src/Menu.cpp" "include/Menu.h" "src/GameController.cpp" "include/GameController.h" "include/Teleporter.h" "src/Teleporter.cpp" include/Macros.cpp include/Macros.h)

#target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)

add_subdirectory (include)
add_subdirectory (src)
add_subdirectory (resources)

if( APPLE )
    #this is for macos=======================
    include_directories(/usr/local/include)

    find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
    if (SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIRS})
        target_link_libraries(ex02 sfml-window sfml-graphics sfml-audio sfml-network)
    endif()
    #=========================================
else()
    #this is for windows==============================
    set (SFML_STATIC_LIBRARIES TRUE)
    set (SFML_DIR "C:/SFML/SFML-2.5.1/lib/cmake/SFML")

    find_package (SFML 2.5 COMPONENTS graphics audio network REQUIRED)

    set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

    target_link_libraries (ex02 sfml-graphics sfml-audio sfml-network sfml-main)

    configure_file (C:/SFML/SFML-2.5.1/bin/openal32.dll ${CMAKE_BINARY_DIR} COPYONLY)
    #=========================================
endif()
