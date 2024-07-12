message(STATUS "Current list directory: ${CMAKE_CURRENT_LIST_DIR}")

find_package(Qt6 REQUIRED COMPONENTS Core Widgets) # Qt COMPONENTS

set(SOURCE_PATH ${CMAKE_CURRENT_LIST_DIR}/source)
list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS ${SOURCE_PATH}/ui)

include_directories(${SOURCE_PATH}/include)

aux_source_directory(${SOURCE_PATH}/src srcs)
file(GLOB include_files ${SOURCE_PATH}/include/*.h)

set(EXECUTABLE_OUTPUT_PATH ${WORKPLACE_DIR_PATH}/out/bin)
add_executable(ChessboardCoverage ${srcs} ${include_files}) 
target_include_directories(ChessboardCoverage PRIVATE ${SOURCE_PATH}/include)
target_link_libraries(ChessboardCoverage PRIVATE Qt6::Widgets) # Qt6 Shared Library