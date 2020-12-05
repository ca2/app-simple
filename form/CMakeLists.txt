cmake_minimum_required(VERSION 3.17)
project(app_simple_form CXX)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")


if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
   set(LINUX TRUE)
   set(PLATFORM_NAME "linux")
   include(FindPkgConfig)
elseif (WIN32)
   set(PLATFORM_NAME "windows")
endif ()


set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../time-${PLATFORM_NAME}/cmake)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../time-${PLATFORM_NAME}/cmake)


list(APPEND app_simple_application_source
   _.h
   001.cpp
   002.cpp
   application.cpp
   application.h
   document.cpp
   document.h
   frame.cpp
   frame.h
   framework.cpp
   framework.h
   main_frame.cpp
   main_frame.h
   main_view.cpp
   main_view.h
   simple_form.cpp
   simple_form.h
   tab_view.cpp
   tab_view.h
   view.cpp
   view.h
   )


if (MSVC)
   set(LIBCXX_TARGETING_MSVC ON)
else ()
   set(LIBCXX_TARGETING_MSVC OFF)
endif ()


add_executable(app_simple_form ${app_simple_application_source})

target_precompile_headers(app_simple_form PRIVATE framework.h)

set_target_properties(app_simple_form PROPERTIES LINKER_LANGUAGE CXX)

if (MSVC)
   target_compile_options(app_simple_form PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_form PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_form PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(app_simple_form PRIVATE acme apex aqua aura axis base)
   add_dependencies(app_simple_form draw2d_gdiplus imaging_wic)
elseif (LINUX)
   target_compile_options(app_simple_form PRIVATE -fpermissive)
   target_link_options(app_simple_form PRIVATE -Wl,-rpath=\$ORIGIN)
   target_link_libraries(app_simple_form PRIVATE acme apex aqua aura axis base)
   target_link_options(app_simple_form PRIVATE -Wl,-z,defs)
   add_dependencies(app_simple_form draw2d_cairo imaging_freeimage)
endif ()

add_dependencies(app_simple_form experience_tranquillum)


target_link_directories(app_simple_form PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/library/x64/basis)
target_link_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/third/library/x64/basis)


target_include_directories(app_simple_form PRIVATE .)
target_include_directories(app_simple_form PRIVATE $ENV{HOME}/__config)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app/_include)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/include)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME})
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME}/_include)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/include)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include/include)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(app_simple_form PRIVATE _APP_SIMPLE_FORM_LIBRARY)
target_compile_definitions(app_simple_form PRIVATE UNICODE)
target_compile_definitions(app_simple_form PRIVATE _UNICODE)



