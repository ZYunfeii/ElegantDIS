cmake_minimum_required(VERSION 2.9)

project(DISClient C CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

set(CXX_FLAGS
-g
-std=c++11)

if(CMAKE_BUILD_BITS EQUAL 32)
  list(APPEND CXX_FLAGS "-m32")
endif()

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}") # https://www.zhihu.com/search?type=content&q=cmake%20string

include_directories(.)
include_directories(../CMD)
include_directories(../ElegantDISClient)
include_directories(../logger)

set(SRC_LIST
../CMD/command.cpp
disclient.cpp
main.cpp
pubsub.cpp
../ElegantDISClient/codec.cpp
../logger/buffer.cpp
../logger/log.cpp
)

add_executable(DISClient ${SRC_LIST})

target_link_libraries(DISClient muduo_net muduo_base pthread jsoncpp) # 有顺序要求

