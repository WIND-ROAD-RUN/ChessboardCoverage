set(WORKPLACE_DIR_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(source_files_path ${CMAKE_CURRENT_SOURCE_DIR}/source)

source_group("src" FILES ${source_files_path}/src/*.cpp)
source_group("include" FILES ${source_files_path}/include/*.h)
source_group("ui" FILES ${source_files_path}/ui/*.ui)
source_group("qrc" FILES ${source_files_path}/ui/*.qrc)

find_package(Qt6 COMPONENTS Widgets REQUIRED) # Qt COMPONENTS

list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS ${source_files_path}/ui)

aux_source_directory(${source_files_path}/src srcs)
file(GLOB include_files ${source_files_path}/include/*.h)



set(EXECUTABLE_OUTPUT_PATH ${WORKPLACE_DIR_PATH}/bin)
add_executable(ChessboardCoverage
    WIN32 # If you need a terminal for debug, please comment this statement 
    ${srcs} ${include_files}
) 
target_include_directories(ChessboardCoverage PRIVATE ${source_files_path}/include)
target_link_libraries(ChessboardCoverage PRIVATE Qt6::Widgets) # Qt6 Shared Library