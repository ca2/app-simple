cmake_minimum_required(VERSION 3.17)
project(app_simple_application CXX)


add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")



set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../time-${PLATFORM_NAME}/cmake)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../time-${PLATFORM_NAME}/cmake)


list(APPEND app_simple_application_source
        _.cpp
        _.h
        _user.h
        application.cpp
        application.h
        document.cpp
        document.h
        framework.cpp
        framework.h
        main_frame.cpp
        main_frame.h
        view.cpp
        view.h)


if (MSVC)
    set(LIBCXX_TARGETING_MSVC ON)
else()
    set(LIBCXX_TARGETING_MSVC OFF)
endif()


add_executable(app_simple_application ${app_simple_application_source} )

target_precompile_headers(app_simple_application PRIVATE framework.h)

set_target_properties(app_simple_application PROPERTIES LINKER_LANGUAGE CXX)

if (MSVC)
    target_compile_options(app_simple_application PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(app_simple_application PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(app_simple_application PRIVATE "/SUBSYSTEM:WINDOWS")
    target_link_libraries(app_simple_application PRIVATE acme apex aqua aura axis base)
    add_dependencies(app_simple_application draw2d_gdiplus imaging_wic)
elseif(LINUX)
    target_compile_options(app_simple_application PRIVATE -fpermissive)
    target_link_options(app_simple_application PRIVATE -Wl,-rpath=\$ORIGIN)
    target_link_libraries(app_simple_application PRIVATE acme apex aqua aura axis base)
    target_link_options(app_simple_application PRIVATE -Wl,-z,defs)
    add_dependencies(app_simple_application draw2d_cairo imaging_freeimage write_text_pango)
endif()


add_dependencies(app_simple_application experience_core)
add_dependencies(app_simple_application ${app_common_dependencies})


target_link_directories(app_simple_application PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/library/x64/basis)
target_link_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/third/library/x64/basis)


target_include_directories(app_simple_application PRIVATE .)
target_include_directories(app_simple_application PRIVATE $ENV{HOME}/__config)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app/_include)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/include)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME})
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME}/_include)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/include)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include/include)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(app_simple_application PRIVATE _APP_SIMPLE_APPLICATION_LIBRARY)
target_compile_definitions(app_simple_application PRIVATE UNICODE)
target_compile_definitions(app_simple_application PRIVATE _UNICODE)






