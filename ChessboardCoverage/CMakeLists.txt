set(WORKPLACE_DIR_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../)

find_package(Qt6 COMPONENTS Widgets REQUIRED) # Qt COMPONENTS

list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS "ui")

include_directories(./source/include)
aux_source_directory(./source/src srcs)

set(EXECUTABLE_OUTPUT_PATH ${WORKPLACE_DIR_PATH}/bin)

add_executable(ChessboardCoverage
    WIN32 # If you need a terminal for debug, please comment this statement 
    ${srcs} 
) 
target_link_libraries(ChessboardCoverage PRIVATE Qt6::Widgets) # Qt6 Shared Library