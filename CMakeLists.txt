cmake_minimum_required(VERSION 3.10)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Release)

# set the project name
project(FractalBitmapGenerator VERSION 1.0.0)

# add the executable
add_executable(Pong
                ./src/main.cpp
                ./src/Paddle.cpp
                ./src/GameManager.cpp
                ./src/Ball.cpp)

