cmake_minimum_required(VERSION 3.17)

project(CHESSBOARDCOVERAGE LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_PREFIX_PATH "d:/Development/Qt/6.5.2/mingw_64") # Qt Kit Dir
set(CMAKE_PREFIX_PATH "D:/Development/Qt/6.5.2/msvc2019_64") # Qt Kit Dir

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 对 MSVC 编译器添加特定编译选项
if(MSVC)
  add_compile_options(/Zc:__cplusplus)
  add_compile_options(/permissive-)
  #add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
  #add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
  add_compile_options(/utf-8)
endif()

find_package(Qt6 COMPONENTS Widgets REQUIRED) # Qt COMPONENTS

list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS "ui")

include_directories(./source/include)
aux_source_directory(./source/src srcs)

add_executable(ChessboardCoverage
    WIN32 # If you need a terminal for debug, please comment this statement 
    ${srcs} 
) 
target_link_libraries(ChessboardCoverage PRIVATE Qt6::Widgets) # Qt6 Shared Library