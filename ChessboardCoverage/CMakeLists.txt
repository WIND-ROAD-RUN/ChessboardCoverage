find_package(Qt6 COMPONENTS Widgets REQUIRED) # Qt COMPONENTS

list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS "ui")

include_directories(./source/include)
aux_source_directory(./source/src srcs)

add_executable(ChessboardCoverage
    WIN32 # If you need a terminal for debug, please comment this statement 
    ${srcs} 
) 
target_link_libraries(ChessboardCoverage PRIVATE Qt6::Widgets) # Qt6 Shared Library