cmake_minimum_required(VERSION 3.16)

# Sets project name
project(lab03 LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Sets C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specifies required Qt components
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS OpenGL)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Xml)

# Allows you to include files from within those directories, without prefixing their filepaths
include_directories(src)

# Specifies .cpp and .h files to be passed to the compiler
add_executable(${PROJECT_NAME}
  src/main.cpp

  # transforms
  src/transforms/transforms.cpp
  src/transforms/transforms.h

  src/transforms_ui/axes.cpp
  src/transforms_ui/axes.h
  src/transforms_ui/glrenderer.cpp
  src/transforms_ui/glrenderer.h
  src/transforms_ui/gridlines.cpp
  src/transforms_ui/gridlines.h
  src/transforms_ui/mainwindow.cpp
  src/transforms_ui/mainwindow.h

  # parsing
  src/parsing/scenedata.h
  src/parsing/scenefilereader.cpp
  src/parsing/scenefilereader.h
  src/parsing/sceneparser.cpp
  src/parsing/sceneparser.h

  src/parsing_ui/glwidget.cpp
  src/parsing_ui/glwidget.h
  src/parsing_ui/mainwindow.cpp
  src/parsing_ui/mainwindow.h
  src/parsing_ui/mainwindow.ui
)

# Specifies other files
qt_add_resources(${PROJECT_NAME} "resources"
  PREFIX
  "/"
  FILES
  resources/shaders/arrow.vert
  resources/shaders/arrow.frag
  resources/shaders/axes.vert
  resources/shaders/axes.frag
  resources/shaders/grid.vert
  resources/shaders/grid.frag
  resources/scenefiles/ambient_total.json
  resources/scenefiles/directional_light.json
  resources/scenefiles/primitive_salad.json
)

# GLEW: this creates its library and allows you to `#include "GL/glew.h"`
add_library(StaticGLEW STATIC glew/src/glew.c)
include_directories(${PROJECT_NAME} PRIVATE glew/include)

# GLM: this creates its library and allows you to `#include "glm/..."`
add_subdirectory(glm)

# Specifies libraries to be linked (Qt components, glew, etc)
target_link_libraries(${PROJECT_NAME} PRIVATE
  Qt::Core
  Qt::Widgets
  Qt::OpenGL
  Qt::OpenGLWidgets
  Qt::Gui
  Qt::Xml
  StaticGLEW
)

# GLEW: this provides support for Windows (including 64-bit)
if (WIN32)
  add_compile_definitions(GLEW_STATIC)
  target_link_libraries(${PROJECT_NAME} PRIVATE
    opengl32
    glu32
  )
endif()

# Set this flag to silence warnings on Windows
if (MSVC OR MSYS OR MINGW)
  set(CMAKE_CXX_FLAGS "-Wno-volatile")
endif()

# Set this flag to silence warnings on MacOS
if (APPLE)
  set(CMAKE_CXX_FLAGS "-Wno-deprecated-volatile")
endif()
