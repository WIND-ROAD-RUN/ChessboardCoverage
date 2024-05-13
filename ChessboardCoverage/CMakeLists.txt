set(WORKPLACE_DIR_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../)

find_package(Qt6 COMPONENTS Widgets REQUIRED) # Qt COMPONENTS

list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/source/ui)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/source/include)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/source/src srcs)

set(EXECUTABLE_OUTPUT_PATH ${WORKPLACE_DIR_PATH}/bin)

add_executable(ChessboardCoverage
    WIN32 # If you need a terminal for debug, please comment this statement 
    ${srcs} 
) 
target_include_directories(ChessboardCoverage PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/include)

target_link_libraries(ChessboardCoverage PRIVATE Qt6::Widgets) # Qt6 Shared Library