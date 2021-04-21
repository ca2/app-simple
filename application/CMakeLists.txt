cmake_minimum_required(VERSION 3.17)
project(app_simple_application CXX)


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


target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(app_simple_application PRIVATE _APP_SIMPLE_APPLICATION_LIBRARY)



