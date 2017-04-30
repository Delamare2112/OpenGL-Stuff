cmake_minimum_required(VERSION 3.7)
project(HelloWindow)

set(CMAKE_CXX_STANDARD 14)

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
        Rectangle.cpp
        Rectangle.hpp
        Triangle.cpp
        Triangle.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -lSOIL")

add_executable(HelloWindow ${SOURCE_FILES})