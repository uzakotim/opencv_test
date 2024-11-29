cmake_minimum_required(VERSION 3.10)
project(CameraCapture)

find_package(OpenCV REQUIRED)

add_executable(camera_capture src/main.cpp)
target_link_libraries(camera_capture ${OpenCV_LIBS})
