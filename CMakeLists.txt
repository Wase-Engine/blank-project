cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(wase-engine-sample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

add_definitions(-DWASE_DEBUG)

file(GLOB_RECURSE sources
    "src/*.h"
    "src/*.cpp"
)

add_executable(wase-engine-sample ${sources})

target_include_directories(wase-engine-sample PUBLIC 
    ${PROJECT_SOURCE_DIR}/src
)

foreach(source IN LISTS sources)
    get_filename_component(source_path "${source}" PATH ABSOLUTE)

    file(RELATIVE_PATH
        item_path_rel
        ${PROJECT_SOURCE_DIR}
        ${source_path})

    source_group("${item_path_rel}" FILES "${source}")
endforeach()

# Wase-Engine
add_subdirectory(E:/visual_studio_projects/wase-engine binary_dir EXCLUDE_FROM_ALL)
target_link_libraries(wase-engine-sample wase-engine)
target_include_directories(wase-engine-sample PUBLIC E:/visual_studio_projects/wase-engine/src)

# Assets folder
file(COPY assets/ DESTINATION ${CMAKE_BINARY_DIR}/assets)