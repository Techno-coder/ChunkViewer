cmake_minimum_required(VERSION 3.8)
project(ChunkViewer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/lib)

FILE(GLOB_RECURSE SOURCE_FILES
        src/*.cpp
        src/*.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(SFML 2.4 COMPONENTS SYSTEM WINDOW GRAPHICS NETWORK AUDIO REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/ DESTINATION ${CMAKE_BINARY_DIR}/resources/)
