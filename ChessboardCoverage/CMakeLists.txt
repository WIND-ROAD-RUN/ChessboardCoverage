set(WORKPLACE_DIR_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(source_files_path ${CMAKE_CURRENT_SOURCE_DIR}/source)

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


file(GLOB SRC_FILES ${source_files_path}/src/*.cpp)
file(GLOB INCLUDE_FILES ${source_files_path}/include/*.h)
file(GLOB UI_FILES ${source_files_path}/ui/*.ui)
file(GLOB QRC_FILES ${source_files_path}/ui/*.qrc)


source_group("src" FILES ${SRC_FILES})
source_group("include" FILES ${INCLUDE_FILES})
source_group("q_ui" FILES ${UI_FILES})
source_group("q_qrc" FILES ${QRC_FILES})