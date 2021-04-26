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


list(APPEND library_references
   acme
   apex
   aqua
   aura
   axis
   base
   )


add_executable(app_simple_application ${app_simple_application_source} )


target_precompile_headers(app_simple_application PRIVATE framework.h)


set_target_properties(app_simple_application PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(app_simple_application PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(app_simple_application PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_libraries(app_simple_application PRIVATE ${library_references})
    target_link_options(app_simple_application PRIVATE "/SUBSYSTEM:WINDOWS")
elseif(LINUX)
    target_compile_options(app_simple_application PRIVATE -fpermissive)
    target_link_options(app_simple_application PRIVATE -Wl,-rpath=\$ORIGIN)
    target_link_libraries(app_simple_application PRIVATE ${library_references})
    target_link_options(app_simple_application PRIVATE -Wl,-z,defs)
endif()


add_dependencies(app_simple_application experience_core)
add_dependencies(app_simple_application ${default_draw2d})
add_dependencies(app_simple_application ${default_imaging})
add_dependencies(app_simple_application ${default_write_text})
add_dependencies(app_simple_application ${app_common_dependencies})


target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(app_simple_application PRIVATE _APP_SIMPLE_APPLICATION_LIBRARY)



