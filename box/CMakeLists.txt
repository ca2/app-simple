cmake_minimum_required(VERSION 3.17)
project(app_simple_box CXX)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(LINUX TRUE)
    set(PLATFORM_NAME "linux")
    include(FindPkgConfig)
elseif(WIN32)
    set(PLATFORM_NAME "windows")
endif()


set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../time-${PLATFORM_NAME}/cmake)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../time-${PLATFORM_NAME}/cmake)


list(APPEND app_simple_box_source
        _.h
        application.cpp
        application.h
        framework.cpp
        framework.h
   )


if (MSVC)
    set(LIBCXX_TARGETING_MSVC ON)
else()
    set(LIBCXX_TARGETING_MSVC OFF)
endif()


add_executable(app_simple_box ${app_simple_box_source})

target_precompile_headers(app_simple_box PRIVATE framework.h)

set_target_properties(app_simple_box PROPERTIES LINKER_LANGUAGE CXX)

if (MSVC)
    target_compile_options(app_simple_box PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(app_simple_box PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(app_simple_box PRIVATE "/SUBSYSTEM:WINDOWS")
    target_link_libraries(app_simple_box PRIVATE acme apex aqua aura axis base)
    add_dependencies(app_simple_box draw2d_gdiplus imaging_wic)
elseif(LINUX)
    target_compile_options(app_simple_box PRIVATE -fpermissive)
    target_link_options(app_simple_box PRIVATE -Wl,-rpath=\$ORIGIN)
    target_link_libraries(app_simple_box PRIVATE acme apex aqua aura axis base)
    target_link_options(app_simple_box PRIVATE -Wl,-z,defs)
    add_dependencies(app_simple_box draw2d_cairo imaging_freeimage)
endif()

add_dependencies(app_simple_box experience_core)


target_link_directories(app_simple_box PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_directories(app_simple_box PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/library/x64/basis)
target_link_directories(app_simple_box PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/third/library/x64/basis)


target_include_directories(app_simple_box PRIVATE .)
target_include_directories(app_simple_box PRIVATE $ENV{HOME}/__config)
target_include_directories(app_simple_box PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(app_simple_box PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(app_simple_box PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source)
target_include_directories(app_simple_box PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app)
target_include_directories(app_simple_box PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app/_include)
target_include_directories(app_simple_box PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/include)
target_include_directories(app_simple_box PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME})
target_include_directories(app_simple_box PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME}/_include)
target_include_directories(app_simple_box PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/include)
target_include_directories(app_simple_box PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include)
target_include_directories(app_simple_box PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include/include)
target_include_directories(app_simple_box PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(app_simple_box PRIVATE _APP_SIMPLE_BOX_LIBRARY)
target_compile_definitions(app_simple_box PRIVATE UNICODE)
target_compile_definitions(app_simple_box PRIVATE _UNICODE)





