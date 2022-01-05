cmake_minimum_required(VERSION 3.14)

project(libnotify-cpp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(libnotify REQUIRED libnotify)

set(SOURCES
    src/notify.cpp)
set(HEADERS
    include/notify.hpp)

add_library(libnotify-cpp STATIC
    ${SOURCES}
    ${HEADERS}
)

add_subdirectory(test-app)

target_compile_definitions(${PROJECT_NAME} PRIVATE LIBNOTIFYCPP_LIBRARY)
target_link_libraries(${PROJECT_NAME} PRIVATE ${libnotify_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${libnotify_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include)
