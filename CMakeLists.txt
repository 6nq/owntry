cmake_minimum_required(VERSION 3.10)

#set project name and version
project(bus_System VERSION 1.0)

#configure a header file to pass the version number to the source code:
configure_file(bus_System_Config.h.in bus_System_Config.h)


#specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#extern main files
add_executable(bus_System bus_System.cpp)

#Since the configured file will be writed into the binary tree, we must add that direcotry to the list of paths to search for include files.Add the following lines to the end of the CMakeLists.txt File :
#此行必须放在最后
target_include_directories(bus_System PUBLIC
                            "${PROJECT_BINARY_DIR}")
