cmake_minimum_required(VERSION 3.17)

project(CHESSBOARDCOVERAGE LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(MINGW_PATH "d:/Development/Qt/6.5.2/mingw_64")
set(MSVC_PATH "D:/Development/Qt/6.5.2/msvc2019_64")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MINGW)
  set(CMAKE_PREFIX_PATH ${MINGW_PATH})
endif()

if(MSVC)
  set(CMAKE_PREFIX_PATH ${MSVC_PATH}) 
  
  add_compile_options(/Zc:__cplusplus)
  add_compile_options(/permissive-)
  #add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
  #add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
  add_compile_options(/utf-8)
  
endif()

add_subdirectory(ChessboardCoverage)