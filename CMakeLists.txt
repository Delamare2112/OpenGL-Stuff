cmake_minimum_required(VERSION 3.7)
project(HelloWindow)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        Engine/Component.cpp
        Engine/Component.hpp
        Engine/Entity.cpp
        Engine/Entity.hpp
        Engine/Game.cpp
        Engine/Game.hpp
        Engine/PackedDynamicArray.hpp
        Engine/Shader.cpp
        Engine/Shader.hpp
        BackgroundColorChanger.cpp
        BackgroundColorChanger.hpp
        main.cpp
        Cube.cpp
        Cube.hpp
        Triangle.cpp
        Triangle.hpp Engine/Camera.cpp Engine/Camera.hpp Engine/Transform.hpp Engine/Transform.cpp FPSInput.cpp FPSInput.h Engine/Material.cpp Engine/Material.hpp Engine/Mesh.cpp Engine/Mesh.hpp Engine/Renderer.cpp Engine/Renderer.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -lSOIL -lassimp")

add_executable(HelloWindow ${SOURCE_FILES})
