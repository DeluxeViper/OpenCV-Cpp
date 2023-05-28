cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0012 NEW)
PROJECT(opencv_c++_project)
SET(CMAKE_CXX_STANDARD 11)

# Requires OpenCV
FIND_PACKAGE (OpenCV 4.0.0 REQUIRED)
MESSAGE("OpenCV version: ${OpenCV_VERSION}")

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

ADD_EXECUTABLE(sample r_w_images.cpp)
ADD_EXECUTABLE(window window.cpp)
TARGET_LINK_LIBRARIES(window ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(sample ${OpenCV_LIBS})

